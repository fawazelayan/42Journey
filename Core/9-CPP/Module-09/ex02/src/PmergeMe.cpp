#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe&) {}

PmergeMe& PmergeMe::operator=(const PmergeMe&)
{
	return *this;
}

PmergeMe::~PmergeMe() {}

// sort the positions, then rebuild arr
void PmergeMe::sortVector(std::vector<int>& arr)
{
	std::vector<size_t> pos;
	for (size_t i = 0; i < arr.size(); i++)
		pos.push_back(i);
	mergeInsertVector(arr, pos);
	std::vector<int> result;
	for (size_t i = 0; i < pos.size(); i++)
		result.push_back(arr[pos[i]]);
	arr = result;
}

// binary search, returns where value goes
size_t PmergeMe::lowerPosVector(const std::vector<int>& arr, const std::vector<size_t>& chain, int value, size_t end)
{
	size_t lo = 0;
	size_t hi = end;
	while (lo < hi)
	{
		size_t mid = (lo + hi) / 2;
		if (arr[chain[mid]] < value)
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}

// Ford-Johnson sort
void PmergeMe::mergeInsertVector(const std::vector<int>& arr, std::vector<size_t>& pos)
{
	if (pos.size() <= 1)
		return;
	// 1. make pairs
	std::vector<size_t> bigs;
	std::vector<size_t> partner(arr.size());
	for (size_t i = 0; i + 1 < pos.size(); i += 2)
	{
		size_t big = pos[i];
		size_t small = pos[i + 1];
		if (arr[big] < arr[small])
			std::swap(big, small);
		bigs.push_back(big);
		partner[big] = small;
	}
	// 2. sort the bigs
	mergeInsertVector(arr, bigs);
	// 3. start the chain
	std::vector<size_t> chain(1, partner[bigs[0]]);
	chain.insert(chain.end(), bigs.begin(), bigs.end());
	// 4. insert the rest in Jacobsthal order (the odd one out goes last)
	size_t pend = bigs.size() + pos.size() % 2;
	size_t prev = 1;
	size_t curr = 3;
	while (prev < pend)
	{
		size_t top = std::min(curr, pend);
		for (size_t k = top; k > prev; k--)
		{
			size_t small = pos.back();
			if (k <= bigs.size())
				small = partner[bigs[k - 1]];
			// the whole group only needs the first top + prev - 1 slots
			chain.insert(chain.begin() + lowerPosVector(arr, chain, arr[small], top + prev - 1), small);
		}
		size_t next = curr + 2 * prev;
		prev = curr;
		curr = next;
	}
	pos = chain;
}

// sort the positions, then rebuild arr
void PmergeMe::sortDeque(std::deque<int>& arr)
{
	std::deque<size_t> pos;
	for (size_t i = 0; i < arr.size(); i++)
		pos.push_back(i);
	mergeInsertDeque(arr, pos);
	std::deque<int> result;
	for (size_t i = 0; i < pos.size(); i++)
		result.push_back(arr[pos[i]]);
	arr = result;
}

// binary search, returns where value goes
size_t PmergeMe::lowerPosDeque(const std::deque<int>& arr, const std::deque<size_t>& chain, int value, size_t end)
{
	size_t lo = 0;
	size_t hi = end;
	while (lo < hi)
	{
		size_t mid = (lo + hi) / 2;
		if (arr[chain[mid]] < value)
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}

// Ford-Johnson sort
void PmergeMe::mergeInsertDeque(const std::deque<int>& arr, std::deque<size_t>& pos)
{
	if (pos.size() <= 1)
		return;
	// 1. make pairs
	std::deque<size_t> bigs;
	std::deque<size_t> partner(arr.size());
	for (size_t i = 0; i + 1 < pos.size(); i += 2)
	{
		size_t big = pos[i];
		size_t small = pos[i + 1];
		if (arr[big] < arr[small])
			std::swap(big, small);
		bigs.push_back(big);
		partner[big] = small;
	}
	// 2. sort the bigs
	mergeInsertDeque(arr, bigs);
	// 3. start the chain
	std::deque<size_t> chain = bigs;
	chain.push_front(partner[bigs[0]]);
	// 4. insert the rest in Jacobsthal order (the odd one out goes last)
	size_t pend = bigs.size() + pos.size() % 2;
	size_t prev = 1;
	size_t curr = 3;
	while (prev < pend)
	{
		size_t top = std::min(curr, pend);
		for (size_t k = top; k > prev; k--)
		{
			size_t small = pos.back();
			if (k <= bigs.size())
				small = partner[bigs[k - 1]];
			// the whole group only needs the first top + prev - 1 slots
			chain.insert(chain.begin() + lowerPosDeque(arr, chain, arr[small], top + prev - 1), small);
		}
		size_t next = curr + 2 * prev;
		prev = curr;
		curr = next;
	}
	pos = chain;
}