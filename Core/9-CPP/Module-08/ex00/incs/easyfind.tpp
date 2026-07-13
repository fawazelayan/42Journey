#ifndef EASYFIND_HPP
# error "easyfind.tpp should only be included from easyfind.hpp"
#endif

template <typename T>
typename T::iterator easyfind(T& container, int to_find)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), to_find);

	if (it != container.end())
		return it;
	else
		throw std::out_of_range("Value not found");
}

template <typename T>
typename T::const_iterator easyfind(const T& container, int to_find)
{
	typename T::const_iterator it;

	it = std::find(container.begin(), container.end(), to_find);

	if (it != container.end())
		return it;
	else
		throw std::out_of_range("Value not found");
}