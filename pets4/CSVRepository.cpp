#include "CSVRepository.h"



CSVRepository::CSVRepository()
{

}

CSVRepository::CSVRepository(std::string path_) : Repository{}, path{path_}
{
	this->load_from_file(this->path);
}


CSVRepository::~CSVRepository()
{
	if(this->path.compare(""))
		this->save();
}

void CSVRepository::load_from_file(std::string path)
{
	this->path = path;
	std::ifstream file(path);
	if (!file.is_open())
	{
		return;
	}
	CSVPet coat;
	while (file >> coat)
	{
		this->add_element(coat);
	}
	file.close();
}

void CSVRepository::save()
{
	std::ofstream file(this->path);
	auto pets = this->get_elements();
	for (auto coat : pets)
	{
		file << CSVPet(coat);
	}
	file.close();
}
