#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		static const int fracBits = 8;
		int rawBits;
	public:
		Fixed &operator=(const Fixed &other);
		Fixed(const Fixed &other);
		~Fixed();
		Fixed();
	
		void	setRawBits(int const raw);
		int		getRawBits(void) const;
};

#endif