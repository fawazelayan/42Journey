# CPP Module 09 — Evaluation Notes

Common to all three exercises:
- C++98, compiled with `c++ -Wall -Wextra -Werror -std=c++98`.
- Every class is in Orthodox Canonical Form: default constructor, copy constructor, copy assignment operator, destructor.
- No function bodies in headers, include guards in every header, and each header includes what it needs.
- Makefile rules: `$(NAME) all clean fclean re`. Running `make` a second time prints "Nothing to be done" (no relink).
- A container used in one exercise is never used again in a later one:

| Exercise | Container |
|---|---|
| ex00 | `std::map` |
| ex01 | `std::list`, used as the base of a `std::stack` |
| ex02 | `std::vector` and `std::deque` |

---

## ex00 — btc (Bitcoin Exchange)

**What it does:** It reads `data.csv` (date → BTC price) and an input file of `date | value` lines. For each line it prints `value * price` on that date. If that date is not in the database, it uses the closest earlier date.

**Why `std::map<std::string, double>`:**
- A map keeps its keys sorted.
- Dates in `YYYY-MM-DD` format sort correctly as plain strings, so the string key is enough.
- A map gives a fast "closest earlier date" lookup with `upper_bound`.

**Flow:**
1. `loadDatabase("data.csv")` skips the header and splits each line at the comma: `rates[date] = atof(price)`.
2. `processInput(file)`:
   - Opens the file, or throws `Error: could not open file.`
   - Skips the first line only if it is `date | value`.
   - Sends every other line to `processLine`.
3. `processLine(line)`:
   - Splits the line at `" | "`.
   - If there is no separator, the date is invalid, or the value is not a full number, it prints `Error: bad input => <line>`.
   - If the value is below 0, it prints `Error: not a positive number.`
   - If the value is above 1000, it prints `Error: too large a number.`
   - Otherwise `upper_bound(date)` returns the first date *after* ours, and `--it` steps back to the same date or the closest earlier one.
   - If `upper_bound` already returns `begin()`, the date is before all data, and it prints a bad input error.

**Validation details:**
- `isValidDate` checks that the length is 10, there are dashes at positions 4 and 7, there are only digits otherwise, and there are exactly 2 dashes.
- It also checks that the month is 1–12 and the day exists in that month, including leap years: `y%4==0 && (y%100!=0 || y%400==0)`.
- `parseValue` reads the number with `istringstream` and requires `!fail() && eof()`. So `"1.5abc"` and `""` are rejected.

**Likely questions:**
- *Why upper_bound and not lower_bound?* `lower_bound` returns the date itself when it exists, and the next date when it does not. Then I would need two cases. `upper_bound` plus `--it` covers both cases in one step.
- *Wrong argument count?* The program prints `Error: could not open file.`, the same as the subject example.

---

## ex01 — RPN (Reverse Polish Notation)

**What it does:** It evaluates an RPN expression given as one argument, for example `"8 9 * 9 - 9 - 9 - 4 - 1 +"` → `42`.

**Why `std::stack<long, std::list<long> >`:**
- RPN is a stack algorithm.
- By default `std::stack` is built on `std::deque`. I wanted to keep `std::deque` free for ex02, so I gave the stack `std::list` as its base.
- I use `long` so the intermediate results have more room than `int`.

**Flow (`evaluate`):**
1. Read the tokens separated by spaces with `istringstream >> token`.
2. Each token must be exactly 1 character long, otherwise it is an error (so `10`, `1.5`, and `(` are rejected).
3. A digit is pushed on the stack.
4. An operator needs at least 2 numbers on the stack, otherwise it is an error.
   - Pop `num2` first, then `num1`. The order matters for `-` and `/`: the result is `num1 op num2`.
   - Dividing by 0 is an error.
   - The result is pushed back on the stack.
5. At the end, exactly 1 number must be left on the stack, otherwise it is an error. That number is the result.

**Errors:** Every error throws `std::runtime_error("Error")`. `main` catches it and prints it on **stderr** with return code 1. A wrong argument count also prints `Error`.

**Likely questions:**
- *Why pop num2 before num1?* The top of the stack is the right operand. `"5 3 -"` gives 5 − 3 = 2.
- *Brackets or decimals?* The subject says they don't need to be handled. They are rejected as errors.

---

## ex02 — PmergeMe (Ford-Johnson merge-insertion sort)

**What it does:** It sorts positive integers (≥ 3000 values, duplicates allowed) with the Ford-Johnson algorithm. It does this once with `std::vector` and once with `std::deque`, with a separate implementation for each, as the subject advises. Then it prints the input, the sorted result, and the time for each container.

**Argument check (main):**
- Each argument must contain only digits. So `-1`, `+5`, `1.5`, `abc`, `""`, and `" "` are errors.
- Its value must be > 0 and ≤ `INT_MAX`.
- I check the value with `atof`, because a double holds any of these numbers exactly. `long` is only 32 bits on Windows (mingw), so `atol` cannot see an overflow there.
- Errors print `Error` on **stderr** and return 1.

**Timing:**
- `std::clock()` starts before the container is filled and stops after the sort. So the time covers both data handling and sorting, as the subject asks.
- The time is converted to microseconds with `* 1000000.0 / CLOCKS_PER_SEC`.

### The idea: sort positions, not values
- I sort the indexes (positions) of the input, and every comparison looks at the values: `arr[a] < arr[b]`.
- Positions are unique even when values repeat. So after the recursion each big knows its own small through `partner[big]`, a direct array lookup with no search.
- At the end, `sortVector` rebuilds the values from the sorted positions: `result[i] = arr[pos[i]]`.

### The 4 steps (`mergeInsertVector` / `mergeInsertDeque`)
0. **Stop case:** If there are 0 or 1 positions, the list is already sorted.
1. **Pairs:** Take the positions two at a time. The one with the bigger value goes into `bigs`, and `partner[big] = small`. With an odd count, the last position is the leftover.
2. **Recursion:** Sort `bigs` with the same function. This is the "merge" part.
3. **Start the chain:** chain = `partner[bigs[0]]` followed by all the sorted bigs. The smallest big's partner is smaller than that big, which is the smallest value in the chain, so it goes in front with no comparison.
4. **Insert the other smalls in Jacobsthal order** with binary search (`lowerPos`):
   - The groups are (3, 2), (5, 4), (11 … 6), (21 … 12), …
   - The limits are Jacobsthal numbers 1, 3, 5, 11, 21, 43, … built with `next = curr + 2 * prev`.
   - Each small is searched only in the part of the chain **before its own big**. It is smaller than its big, so it can't belong after it.
   - Finally the leftover is inserted with a binary search over the whole chain.

**Why Jacobsthal order:** This order keeps every binary search over at most 2^k − 1 elements, which takes exactly k comparisons in the worst case. Any other order wastes comparisons. Using the fewest comparisons is the whole point of Ford-Johnson.

**`lowerPos`:** This is a classic binary search. It returns the first index in `chain[0, end)` whose value is ≥ `value`. Inserting at that index keeps the chain sorted.

**Why the deque is slower:** Each insert into the middle of a deque moves more data, and each `[]` access goes through an extra lookup. A vector is one block of memory, which suits many inserts and binary searches. On Windows `clock()` only counts whole milliseconds, so the times end in 000. On Linux they show real microseconds.

**Likely questions:**
- *Is it real Ford-Johnson?* Yes: pairs, recursive sort of the bigs, the first small placed for free, then Jacobsthal-ordered binary insertion where each search stops at the small's own big.
- *Duplicates?* They work because positions are unique. Tested against `std::sort` for sizes 0–300, 3000, and 10000 with random input and input full of duplicates: 0 failures.
- *Why no generic/template function?* The subject advises writing the algorithm once per container.
- *Why `size_t` positions?* They are indexes into the input, and `size_t` is the type of `size()`.