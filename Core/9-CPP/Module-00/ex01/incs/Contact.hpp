#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNum;
		std::string	darkestSecret;
	public:
		// Setters
		void setDarkestSecret(const std::string& secret);
		void setFirstName(const std::string& first);
		void setLastName(const std::string& last);
		void setNickname(const std::string& nick);
		void setPhoneNumber(const std::string& num);
	
		// Getters
		std::string getDarkestSecret(void) const;
		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickname(void) const;
		std::string getPhoneNumber(void) const;
};

#endif