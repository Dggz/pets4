#include "Validator.h"



Validator::Validator()
{
}

void Validator::validate_admin_input(std::vector<std::string> line)
{

	std::vector<std::string> available_commands{ "add", "delete", "list", "update" };
	if (std::find(available_commands.begin(), available_commands.end(), line[0]) == available_commands.end())
		throw ValidationError("Invalid command!\n");
	if (!line[0].compare("add") || !line[0].compare("update"))
	{
		if (line.size() != 6)
			throw ValidationError("Invalid paramerer number!\n");
		for (auto character : line[4])
			if (!std::isdigit(character))
				throw ValidationError("The vaccines has to be integer value!\n");
	}
	if (!line[0].compare("delete"))
		if (line.size() != 2)
			throw ValidationError("Invalid parameter number!\n");

	if (!line[0].compare("list"))
		if (line.size() != 1)
			throw ValidationError("Invalid parameter number!\n");

}


void Validator::validate_user_input(std::vector<std::string> line)
{
	std::vector<std::string> available_commands{ "save", "next", "list", "mylist" };
	if (std::find(available_commands.begin(), available_commands.end(), line[0]) == available_commands.end())
		throw ValidationError("Invalid command!\n");

	if (!line[0].compare("list"))
	{
		if (line.size() != 3)
			throw ValidationError("Invalid paramerer number!\n");
		for (auto character : line[2])
			if (!std::isdigit(character))
				throw ValidationError("The vaccines has to be integer value!\n");
	}
	if (!line[0].compare("save"))
		if (line.size() != 2)
			throw ValidationError("Invalid parameter number!\n");

	if (!line[0].compare("next") || !line[0].compare("mylist"))
		if (line.size() != 1)
			throw ValidationError("Invalid parameter number!\n");
}

Validator::~Validator()
{

}
