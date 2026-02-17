#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
	bool initialized;

public:
	Contact();

	void SetContact(
		const std::string& first,
		const std::string& last,
		const std::string& nick,
		const std::string& phone,
		const std::string& secret
	);

	void PrintContact() const;
	bool IsInitialized() const;

	const std::string& GetFirstName() const;
	const std::string& GetLastName() const;
	const std::string& GetNickName() const;
};

#endif