#include "Fixed.hpp"

Fixed::Fixed() : rawBits(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called\n";
	this -> rawBits = val << fracBits;
}

Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called\n";
	this -> rawBits = roundf(val * (1 << fracBits));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

int Fixed::toInt(void) const
{
	return rawBits >> fracBits;
}

float Fixed::toFloat(void) const
{
	return rawBits / (float)(1 << fracBits);
}

Fixed &Fixed::operator=(const Fixed& other)
{
	std::cout <<"Copy assignment operator called\n";
	if (this != &other)
		this->rawBits = other.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return this -> rawBits;
}

void Fixed::setRawBits(int const raw)
{
	this -> rawBits = raw;
}
