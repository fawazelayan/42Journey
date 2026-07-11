# C++ Code Formatting & Style Guidelines

This document outlines the specific code formatting, indentation, and structure rules to be followed in this repository.

---

## 1. Indentation and Alignment
* **Use Tabs Only**: Indent and align code strictly using tabs (`\t`).
* **No Mixed Spaces**: Do not combine tabs and spaces for alignment. For continuation lines, use multiple tabs (e.g., `\t\t`).
  
```cpp
// Correct (contributions use double tabs)
AForm::AForm()
	: name("Default Form"),
		isSigned(false),
		signGrade(150),
		execGrade(150) {}
```

---

## 2. Braces and Brackets `{}` Alignment
* **Allman Style**: For blocks (`if`, `else`, `try`, `catch`, loops, functions), place both the opening `{` and closing `}` on separate lines, vertically aligned with the block keyword.
* **Inline Construct Destruct Exception**: Empty constructor/destructor bodies can be written inline as ` {}` at the end of the initialization list.

```cpp
// Standard block alignment
void testNormalBureaucrat()
{
	try
	{
		// ...
	}
	catch (const std::exception& e)
	{
		// ...
	}
}
```

---

## 3. Single-Command Blocks
* **Conditional and Loop Blocks**: If an `if`, `else`, `for`, or `while` block contains exactly **one statement**, you **must omit** the braces `{}`.
* **Try/Catch Blocks**: In C++, `try` and `catch` compound statements strictly require `{}`. These braces **must not** be omitted.

```cpp
// Braces omitted for single-statement if-else
if (rand() % 2 == 0)
	std::cout << this->target << " success" << std::endl;
else
	std::cout << this->target << " failure" << std::endl;

// Braces omitted for single-statement loops
for (int i = 0; i < 3; ++i)
	delete forms[i];
```

---

## 4. Return Statements
* Do not wrap the returned expression in parentheses.
  
```cpp
// Correct
return this->name;
return *this;

// Incorrect
return (this->name);
return (*this);
```

---

## 5. Stream Output (`std::cout`, `std::cerr`, `os`)
* **Simple Outputs**: Keep simple print statements and their `std::endl` on a single line.
* **Multi-Field Outputs**: For printing structured multi-field objects, place each field insertion on a separate line, indented with tabs.

```cpp
// Simple print (kept on single line)
std::cout << "Created: " << b1 << std::endl;

// Multi-field print (split on lines using tabs)
std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "Form: " << form.getName()
		<< ", signed: " << (form.getIsSigned() ? "yes" : "no")
		<< ", sign grade required: " << form.getSignGrade()
		<< ", execute grade required: " << form.getExecGrade();
	return os;
}
```

---

## 6. Constructor Initialization Lists
* If there is more than **one member initializer**, split each initializer onto a separate line.

```cpp
Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: name(name),
		grade(grade)
{
}
```

---

## 7. Performance Include Rules
* **Header Files (`.hpp`)**: Use the lightweight `<iosfwd>` header instead of full stream headers like `<ostream>` or `<iostream>` to optimize compile times when only stream references are declared.
* **Source Files (`.cpp`)**: Include the full stream headers (`<ostream>`, `<iostream>`) inside source files where stream insertions are executed.

---

## 8. Documentation Comments
* **Headers**: Organize header files using brief section comments:
  - `// Constructors & Destructor`
  - `// Getters`
  - `// Grade Modifiers`
  - `// Form Operations`
  - `// Exception Classes`
* **Mains**: Add short, simple explanatory comments to describe test functions.

---

## 9. Additional formatting details
* **Access Specifiers Indentation**: Indent `private:` and `public:` using one tab, and indent everything under them with another tab (two tabs total).
* **Empty Class and Function Definitions**: For empty classes and empty member functions (e.g. empty constructors or destructors), place the braces inline on the same line (e.g. `class A : public Base {};` or `A::A() {}`).
* **Loops containing complex blocks**: Always include braces `{}` for loops containing `if` statements or other complex/long structures.
* **No Trailing Empty Lines**: Ensure there is no new empty line at the very end of any source or header file.