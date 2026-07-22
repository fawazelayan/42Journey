#ifndef MUTANTSTACK_HPP
# error "MutantStack.tpp should only be included from MutantStack.hpp"
#endif

// Constructors & Destructor
template <typename T>
MutantStack<T>::MutantStack()
	: std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other)
	: std::stack<T>(other) {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
	if (this != &other)
		std::stack<T>::operator=(other);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

// NEW CONCEPT: exposing begin() and end() iterators
// TODO: return iterators referencing the beginning and end of the underlying container 'c'
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	// implement here
	throw std::logic_error("not implemented");
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	// implement here
	throw std::logic_error("not implemented");
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	// implement here
	throw std::logic_error("not implemented");
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	// implement here
	throw std::logic_error("not implemented");
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	// implement here
	throw std::logic_error("not implemented");
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	// implement here
	throw std::logic_error("not implemented");
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	// implement here
	throw std::logic_error("not implemented");
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	// implement here
	throw std::logic_error("not implemented");
}