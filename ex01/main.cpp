#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <string>

static void Prompt(const std::string& label) {
	std::cout << label << "\n>> ";
}

static std::string ReadNonEmpty(const std::string& label) {
	std::string line;

	while (true) {
		Prompt(label);
		if (!std::getline(std::cin, line))
			return "";

		if (!line.empty())
			return line;

		std::cout << "You entered empty string. Try again.\n";
	}
}

static bool ParseIndex(const std::string& s, int& out) {
	std::stringstream ss(s);
	char extra;

	if (!(ss >> out))
		return false;
	if (ss >> extra)
		return false;
	return true;
}

int main() {
	PhoneBook book;
	std::string cmd;

	while (true) {
		Prompt("Please input operation.");
		if (!std::getline(std::cin, cmd))
			break;

		if (cmd == "ADD") {
			std::string first = ReadNonEmpty("First Name:");
			std::string last = ReadNonEmpty("Last Name:");
			std::string nick = ReadNonEmpty("Nickname:");
			std::string phone = ReadNonEmpty("Phone Number:");
			std::string secret = ReadNonEmpty("Darkest Secret:");

			if (first.empty() || last.empty() || nick.empty() || phone.empty() || secret.empty())
				break;

			book.AddContact(first, last, nick, phone, secret);
		}
		else if (cmd == "SEARCH") {
			book.ListPhoneBook();

			std::string s;
			int index;

			Prompt("Input index id:");
			if (!std::getline(std::cin, s))
				break;

			if (!ParseIndex(s, index) || !book.IsContactUsed(index)) {
				std::cout << "You entered invalid id.\n";
				continue;
			}
			book.PrintIdContact(index);
		}
		else if (cmd == "EXIT") {
			break;
		}
	}
	return 0;
}
