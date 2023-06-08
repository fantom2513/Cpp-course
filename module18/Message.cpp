#include "Message.h"

std::fstream& operator >>(std::fstream& inStream, Message& message)
{
	inStream >> message._text;
	inStream >> message._sender;
	inStream >> message._receiver;
	return inStream;
}
std::ostream& operator <<(std::ostream& outStream, const Message& message)
{
	outStream << message._text;
	outStream << ' ';
	outStream << message._sender;
	outStream << ' ';
	outStream << message._receiver;
	return outStream;
}