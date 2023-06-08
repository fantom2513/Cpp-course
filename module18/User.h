#pragma once
#include <fstream>

class User {
	std::string _name;
	std::string _login;
	std::string _pass;

public:
	User(std::string name, std::string login, std::string pass) :_name(name), _login(login), _pass(pass) {}

	friend std::fstream& operator >>(std::fstream& inStream, User& user);
	friend std::ostream& operator <<(std::ostream& outStream, const User& user);
};

