#pragma once
#include <exception>
#include <string>
#include <winerror.h>
#include <stdio.h>

// COM Exception
class com_exception : public std::exception {
private:
	HRESULT result;
	std::string description;

public:
	com_exception(HRESULT hr) : result(hr), description() {}
	com_exception(HRESULT hr, std::string msg) : result(hr), description(msg) {}
	virtual const char* what() const override
	{
		static char str[512]{}; // static : ���α׷� ���� ������ �ѹ��� ����� �ٽ� ������ ����
		sprintf_s(str, "Failed with HRESUL : %08X\n%s\n", result, description.c_str()); // %X: 16����, 08: 8���� X: �빮�� x: �ҹ���
		return str;
	}
};

inline void ThrowIfFailed(HRESULT hr, std::string msg = "") // inline : �� �Լ��� 2�ٹۿ� �ȵǴ� ���� ȣ�⽺���� ��������ʰ�
{
	if (FAILED(hr))
	{
		throw com_exception(hr, msg);
	}
}