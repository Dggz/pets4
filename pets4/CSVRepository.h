#pragma once
#include <fstream>
#include "Repository.h"
#include "CSVPet.h"
#include <string>
class CSVRepository : public Repository
{
	std::string path;

public:
	CSVRepository();
	CSVRepository(std::string path_);
	~CSVRepository();
	void load_from_file(std::string path);
	void save();
};

