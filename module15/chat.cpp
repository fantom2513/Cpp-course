#include <cstring>
#include "chat.h"
#include "hash.h"
#include "sha1.h"

Chat::Chat()
{
	_data = new HashTable();
}

Chat::~Chat()
{
	delete _data;
}

void Chat::reg(const char _login[LOGINLENGTH], const char _pass[], const int pass_length) {
	// ��� ���
	const uint* hash = sha1(_pass, pass_length);

	_data->add(_login, hash);
	delete[] hash;
}
bool Chat::login(const char _login[LOGINLENGTH], const char _pass[], const int pass_length) {
	// ��� ���
	// ����� ������� true � ������ ��������� ������
	const uint* saved = _data->find(_login);
	if (saved)
	{
		const uint* current = sha1(_pass, pass_length);
		bool logged = !memcmp(saved, current, SHA1HASHLENGTHBYTES);
		delete[]current;
		return logged;
	}
	return false;
}