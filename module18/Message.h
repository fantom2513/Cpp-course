#pragma once
#include <fstream>

class Message {
	std::string _text;
	std::string _sender;
	std::string _receiver;
public:
	Message(std::string text, std::string sender, std::string receiver) :_text(text), _sender(sender), _receiver(receiver) {}

	friend std::fstream& operator >>(std::fstream& inStream, Message& message);
	friend std::ostream& operator <<(std::ostream& outStream, const Message& message);
};
