#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <stdexcept>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int to_find);

template <typename T>
typename T::const_iterator easyfind(const T& container, int to_find);

#include "easyfind.tpp"

#endif