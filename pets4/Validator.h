#pragma once
#include <exception>
#include <string>
#include <cctype>
#include <vector>
class ValidationError : public std::exception
{
public:
	ValidationError() : exception() { }
	ValidationError(std::string error) : exception(error.c_str()) {	}
};
class Validator
{
public:
	Validator();
	void validate_admin_input(std::vector<std::string> line);
	void validate_user_input(std::vector<std::string> line);
	~Validator();
};

