#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact
{
	private:
		std::string	darkestSecret;
		std::string	phoneNumber;
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
	public:
		// Setters
		void setDarkestSecret(const std::string& secret);
		void setPhoneNumber(const std::string& num);
		void setFirstName(const std::string& first);
		void setLastName(const std::string& last);
		void setNickname(const std::string& nick);
	
		// Getters
		std::string getDarkestSecret(void) const;
		std::string getPhoneNumber(void) const;
		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickname(void) const;
};

#endif