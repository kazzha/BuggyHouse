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
		static char str[512]{}; // static : 프로그램 끝날 때까지 한번만 만들고 다시 만들지 않음
		sprintf_s(str, "Failed with HRESUL : %08X\n%s\n", result, description.c_str()); // %X: 16진수, 08: 8글자 X: 대문자 x: 소문자
		return str;
	}
};

inline void ThrowIfFailed(HRESULT hr, std::string msg = "") // inline : 이 함수가 2줄밖에 안되니 굳이 호출스택을 사용하지않게
{
	if (FAILED(hr))
	{
		throw com_exception(hr, msg);
	}
}