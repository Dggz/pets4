#pragma once
#include "Repository.h"
#include "Validator.h"
class Service
{
private:
	int mode = -1; //-1 - undefined
				   // 0 - admin
				   // 1  - user

	std::vector<Pet>::iterator iterator;
	std::vector<Pet> iterated_elements;
	Repository* user_list;
	void start_user_mode();
	Repository* repository;
	Validator* validator;
	std::vector<std::string> cut_into_words(std::string line);
	std::string cut_folder(std::string line);

	bool check_extension(const char *filename, const char *extension);

public:
	std::vector<Pet> admin_mode(std::vector<std::string> user_input);
	std::vector<Pet> user_mode(std::vector<std::string> user_input);
	Service(Repository* repository, Validator* validator);
	std::vector<Pet> parse_arguments(std::string command_line, int &stop_condition);
	~Service();
};

// \\cluj-print-srv.pentalog.com