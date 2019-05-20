#include "Service.h"
#include "CSVRepository.h"
#include "HTMLRepository.h"
#include "Repository.h"
#include <string>
#include "Pet.h"

Service::Service(Repository* repository, Validator* validator)
{
	this->repository = repository;
	this->validator = validator;
	this->user_list = new Repository;
}


Service::~Service()
{
}
//all the commands that an admin can use
std::vector<Pet> Service::admin_mode(std::vector<std::string> user_input)
{
	this->validator->validate_admin_input(user_input);
	std::vector<Pet> empty_return;
	if (!user_input[0].compare("list"))
	{
		return this->repository->get_elements();
	}
	if (!user_input[0].compare("delete"))
	{
		Pet delete_me(user_input[1]);
		this->repository->delete_element(delete_me);
		return empty_return;
	}
	
	if (!user_input[0].compare("add"))
	{

		Pet pet(user_input[1], user_input[2], user_input[3], std::stoi(user_input[4]), user_input[5]);
		this->repository->add_element(pet);
		return empty_return;

	}
	if (!user_input[0].compare("update"))
	{
		Pet pet(user_input[1], user_input[2], user_input[3], std::stoi(user_input[4]), user_input[5]);
		this->repository->update_element(pet);
	}
	
	return empty_return;
}
//decides what to do and in which mode

void Service::start_user_mode()
{
	this->iterated_elements = this->repository->get_elements();
	this->iterator = this->iterated_elements.begin();
}

std::vector<std::string> Service::cut_into_words(std::string line)
{
	std::string token;
	std::vector<std::string> tokens;
	
	bool command_found = false;
	for (auto character : line)
	{
		if (!command_found && (character == ' ' || character == '\n'))
			tokens.push_back(token), command_found = true, token = "";
		else
			if (character == ',' || character == '\n' || character == ' ')
				if (token.size() == 0)
					token = "";
				else 
					tokens.push_back(token), token = "";
			else
				token += character;
	}
	return tokens;
}

std::string Service::cut_folder(std::string line)
{
	std::string token;
	
	bool command_found = false;
	for (auto character : line)
	{
		if (!command_found && (character == ' '))
			command_found = true, token = "";
		else
			if (character == '\n')
				break;	
			else
				token += character;
	}
	return token;
}

bool Service::check_extension(const char *filename, const char *extension)
{
	size_t len = strlen(filename), extlen = strlen(extension);
	return len < extlen ? false : strcmp(&filename[len - extlen], extension) == 0;
}

std::vector<Pet> Service::user_mode(std::vector<std::string> user_input)
{
	this->validator->validate_user_input(user_input);
	std::vector<Pet> empty_return;

	if (!user_input[0].compare("next"))
	{
		if(this->iterator != this->iterated_elements.end()){
		empty_return.push_back(*this->iterator);
		this->iterator = std::next(this->iterator);
		if (this->iterator == this->iterated_elements.end())
			this->iterator = this->iterated_elements.begin();
		}
		return empty_return;
	}
	if (!user_input[0].compare("mylist"))
	{
		return this->user_list->get_elements();
	}
	if (!user_input[0].compare("save"))
	{
		std::vector<Pet> elements = this->repository->get_elements();
		Pet find_me(user_input[1]);
		for (auto pet : elements)
			if (pet == find_me)
			{
				this->user_list->add_element(pet);
				return empty_return;
			}
		throw std::exception("Invalid name!");}
	if (!user_input[0].compare("list"))
	{
		std::string breed = user_input[1];
		int vaccines = std::stoi(user_input[2]);
		std::vector<Pet> elements = this->repository->get_elements();
		for (auto pet : elements)
			if (pet.get_vaccines() < vaccines && !breed.compare(pet.get_breed().c_str()))
			{
				empty_return.push_back(pet);
			}
		return empty_return;
	}
	return empty_return;
}

std::vector<Pet> Service::parse_arguments(std::string command_line, int &stop_condition)
{
	std::vector<Pet> empty_return;
	std::vector<std::string> tokens = this->cut_into_words(command_line);
	
	if (!tokens[0].compare("exit"))
	{
		stop_condition = 0;
		this->repository->save();
		this->user_list->save();
		return empty_return;
	}
	else if (!tokens[0].compare("mode"))
	{
		if (!tokens[1].compare("A"))
			this->mode = 0;
		if (!tokens[1].compare("B"))
		{
			this->mode = 1, this->start_user_mode();
		}
	}
	else if (!tokens[0].compare("fileLocation"))
	{
		std::string path = this->cut_folder(command_line);
		this->repository->save();
		delete this->repository;
		if(this->check_extension(path.c_str(), ".html"))
			this->repository = new HTMLRepository(path);
		else 
			if (this->check_extension(path.c_str(), ".csv"))
				this->repository = new CSVRepository(path);
			else
				if (this->check_extension(path.c_str(), ".txt"))
					this->repository = new CSVRepository(path);
				else
					this->repository = new CSVRepository(path);


		return empty_return;
	}
	else if (!tokens[0].compare("mylistLocation"))
	{
		std::string path = this->cut_folder(command_line);
		this->user_list->save();
		delete this->user_list;
		if (this->check_extension(path.c_str(), ".html"))
			this->user_list = new HTMLRepository(path);
		else
			if (this->check_extension(path.c_str(), ".csv"))
				this->user_list = new CSVRepository(path);
			else
				if (this->check_extension(path.c_str(), ".txt"))
					this->user_list = new CSVRepository(path);
				else
					this->user_list = new CSVRepository(path);


		return empty_return;
	}
	else if (this->mode == 0)
			return this->admin_mode(tokens);
	else if (this->mode == 1)
			return this->user_mode(tokens);

	return empty_return;
}
