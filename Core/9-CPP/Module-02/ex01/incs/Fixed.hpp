#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		static const int fracBits = 8;
		int rawBits;
	public:
		Fixed &operator=(const Fixed &other);
		Fixed(const Fixed &other);
		Fixed(const int val);
		Fixed(const float val);
		~Fixed();
		Fixed();
	
		void	setRawBits(int const raw);
		int		getRawBits(void) const;
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif