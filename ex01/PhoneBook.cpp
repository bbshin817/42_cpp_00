#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : nextIndex(0) {}

std::string PhoneBook::Truncate(const std::string& s) {
	if (s.length() <= kColWidth)
		return s;
	return s.substr(0, kColWidth - 1) + ".";
}

void PhoneBook::AddContact(
	const std::string& first,
	const std::string& last,
	const std::string& nick,
	const std::string& phone,
	const std::string& secret
) {
	contacts[nextIndex].SetContact(first, last, nick, phone, secret);
	nextIndex++;
	if (nextIndex >= kMaxContacts)
		nextIndex = 0;
}

bool PhoneBook::IsContactUsed(int index) const {
	if (index < 0 || index >= kMaxContacts)
		return false;
	return contacts[index].IsInitialized();
}

void PhoneBook::PrintIdContact(int index) const {
	contacts[index].PrintContact();
}

void PhoneBook::ListPhoneBook() const {
	std::cout << std::right
		<< "|" << std::setw(kColWidth) << "Index"
		<< "|" << std::setw(kColWidth) << "First Name"
		<< "|" << std::setw(kColWidth) << "Last Name"
		<< "|" << std::setw(kColWidth) << "Nickname"
		<< "|\n";

	for (int i = 0; i < kMaxContacts; i++) {
		if (!contacts[i].IsInitialized())
			continue;

		std::cout
			<< "|" << std::setw(kColWidth) << i
			<< "|" << std::setw(kColWidth) << Truncate(contacts[i].GetFirstName())
			<< "|" << std::setw(kColWidth) << Truncate(contacts[i].GetLastName())
			<< "|" << std::setw(kColWidth) << Truncate(contacts[i].GetNickName())
			<< "|\n";
	}
}
