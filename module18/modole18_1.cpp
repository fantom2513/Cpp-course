#include "User.h"
#include "Message.h"
#include <iostream>
// file names defined in the "executeScript.txt" bash script
// File variable to store users.txt: 
#define USERFILE "users.txt"
// File variable to store messages.txt: 
#define MESSAGEFILE "messages.txt"


int main()
{
	//check User methods
	std::fstream user_file = std::fstream(USERFILE, std::ios::in | std::ios::out);
	if (!user_file)
		// If "user_file" doesn't exsist, create one
		user_file = std::fstream(USERFILE, std::ios::in | std::ios::out | std::ios::trunc);

	if (user_file) {
		User user1("John", "qwer", "123");
		User user2("Jane", "werty", "234");
		User user3("Jimmy", "qwerty", "345");
		// write data to the file
		std::cout << "Writing new users to users.txt" << std::endl;
		user_file << user1 << std::endl;
		user_file << user2 << std::endl;
		user_file << user3 << std::endl;
		// set position at the beginning for reading
		user_file.seekg(0, std::ios_base::beg);
		// read data
		User userR("x", "x", "x");
		user_file >> userR;
		std::cout << userR << std::endl;
		user_file >> userR;
		std::cout << userR << std::endl;
		user_file >> userR;
		std::cout << userR << std::endl;
	}
	else
	{
		std::cout << "Could not open file users.txt !" << '\n';
		return 0;

	}

	//check Message methods
	std::fstream message_file = std::fstream("messages.txt", std::ios::in | std::ios::out);
	if (!message_file)
		// If "message_file" doesn't exsist, create one
		message_file = std::fstream("messages.txt", std::ios::in | std::ios::out | std::ios::trunc);

	if (message_file) {
		Message message1("Text1", "sender1", "receiver1");
		Message message2("Text2", "sender2", "receiver2");
		// write data to the file
		message_file << message1 << std::endl;
		message_file << message2 << std::endl;
		// set position at the beginning for reading
		message_file.seekg(0, std::ios_base::beg);
		// read data
		Message messageR("x", "x", "x");
		message_file >> messageR;
		std::cout << messageR << std::endl;
		message_file >> messageR;
		std::cout << messageR << std::endl;
	}
	else
	{
		std::cout << "Could not open file messages.txt !" << '\n';
		return 0;

	}
}