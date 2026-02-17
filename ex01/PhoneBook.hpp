#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook {
private:
	enum { kMaxContacts = 8, kColWidth = 10 };

	Contact contacts[kMaxContacts];
	int nextIndex;

	static std::string Truncate(const std::string& s);

public:
	PhoneBook();

	void AddContact(
		const std::string& first,
		const std::string& last,
		const std::string& nick,
		const std::string& phone,
		const std::string& secret
	);

	void ListPhoneBook() const;
	bool IsContactUsed(int index) const;
	void PrintIdContact(int index) const;
};

#endif
