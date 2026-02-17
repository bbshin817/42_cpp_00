#include "Contact.hpp"
#include <iostream>

Contact::Contact() : initialized(false) {}

void Contact::SetContact(
	const std::string& first,
	const std::string& last,
	const std::string& nick,
	const std::string& phone,
	const std::string& secret
) {
	firstName = first;
	lastName = last;
	nickName = nick;
	phoneNumber = phone;
	darkestSecret = secret;
	initialized = true;
}

void Contact::PrintContact() const {
	std::cout << firstName << "\n";
	std::cout << lastName << "\n";
	std::cout << nickName << "\n";
	std::cout << phoneNumber << "\n";
	std::cout << darkestSecret << "\n";
}

bool Contact::IsInitialized() const {
	return initialized;
}

const std::string& Contact::GetFirstName() const {
	return firstName;
}

const std::string& Contact::GetLastName() const {
	return lastName;
}

const std::string& Contact::GetNickName() const {
	return nickName;
}