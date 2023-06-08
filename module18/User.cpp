#include "User.h"

std::fstream& operator >>(std::fstream& inStream, User& user)
{
	inStream >> user._name;
	inStream >> user._login;
	inStream >> user._pass;
	return inStream;
}
std::ostream& operator <<(std::ostream& outStream, const User& user)
{
	outStream << user._name;
	outStream << ' ';
	outStream << user._login;
	outStream << ' ';
	outStream << user._pass;
	return outStream;
}