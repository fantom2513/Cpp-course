#pragma once
#include<exception>
#include <string>

void reallocate(int newLength);
class Bad_lenght :public std::exception
{
public:
	Bad_lenght(const std::string& msg);
	virtual const char* what() const noexcept override;
private:
	std::string _msg;
};

class Bad_range :public std::exception
{
public:
	Bad_range(const std::string& msg);
	virtual const char* what() const noexcept override;
private:
	std::string _msg;
};




class IntArray
{
public:
	IntArray() = default;
	IntArray(int length);
	IntArray(const IntArray& other);
	~IntArray();
	void erase();
	int& operator[](int index);
	int getLength() const { return _mlength; }
	int* getData() const { return _mdata; }
	void reallocate(int newLength);
	void resize(int newLength);
	IntArray& operator=(const IntArray& other);
	void insertBefore(int value, int index);
	void remove(int index);
	void insertAtBeginning(int value) { insertBefore(value, 0); }
	void insertAtEnd(int value) { insertBefore(value, _mlength); }
private:
	int _mlength{};
	int* _mdata{};
};

