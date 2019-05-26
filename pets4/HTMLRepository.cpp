#include "HTMLRepository.h"



HTMLRepository::HTMLRepository() : Repository{}
{
}

HTMLRepository::HTMLRepository(std::string path_) : Repository {}, path{ path_ }
{
	this->load_from_file(path_);
}


HTMLRepository::~HTMLRepository()
{
	this->save();
}

void HTMLRepository::load_from_file(std::string path)
{
	this->path = path;
	std::ifstream file(path);
	if (!file.is_open())
	{
		return;
	}
	HTMLPet coat;
	while (file >> coat)
	{
		try {
			this->add_element(coat);
		}
		catch(std::exception) {
			break;
		}
	}
	file.close();
}
void HTMLRepository::save()
{
	std::ofstream file(this->path);
	file << "<html>\n<head>\n</head>\n<body>\n<table border='1'>\n";
	auto pets = this->get_elements();
	for (auto coat : pets)
	{
		HTMLPet aux(coat);
		file << aux;
	}
	file << "</table>\n</body>\n</html>";
	file.close();
}
