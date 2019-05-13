#pragma once
#include "Repository.h"
#include "HTMLPet.h"
#include <string>
#include <fstream>

class HTMLRepository : public Repository
{
	std::string path;
public:
	HTMLRepository();
	HTMLRepository(std::string path);
	~HTMLRepository();
	void load_from_file(std::string path);
	void save();

};

