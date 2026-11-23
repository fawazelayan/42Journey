#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <cstddef>
#include <deque>
#include <vector>

class PmergeMe
{
	public:
		// Constructors & Destructor
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		// Sorting
		void sortVector(std::vector<int>& arr);
		void sortDeque(std::deque<int>& arr);

	private:
		// Vector Helpers
		void mergeInsertVector(const std::vector<int>& arr, std::vector<size_t>& pos);
		size_t lowerPosVector(const std::vector<int>& arr, const std::vector<size_t>& chain, int value, size_t end);

		// Deque Helpers
		void mergeInsertDeque(const std::deque<int>& arr, std::deque<size_t>& pos);
		size_t lowerPosDeque(const std::deque<int>& arr, const std::deque<size_t>& chain, int value, size_t end);
};

#endif