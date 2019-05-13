#include "CSVPet.h"



CSVPet::CSVPet()
{
	
}

CSVPet::CSVPet(std::string name, std::string breed, std::string birthDate, int vaccines, std::string photograph) : Pet{name, breed, birthDate, vaccines, photograph}
{
}


CSVPet::~CSVPet()
{
}

std::istream & operator>>(std::istream & is, CSVPet & pet)
{
	// TODO: insert return statement here
	std::string line;
	getline(is, line);

	std::vector<std::string> tokens;
	std::stringstream ss(line);
	std::string token;
	while (getline(ss, token, ','))
		tokens.push_back(token);
	if (tokens.size() != 4)
		return is;
	pet.set_name(tokens[0]);
	pet.set_breed(tokens[1]);
	pet.set_vaccines(std::stoi(tokens[2]));
	pet.set_photograph(tokens[3]);
	return is;
}

std::ostream & operator<<(std::ostream & os, const CSVPet & pet)
{
	// TODO: insert return statement here
	os << pet.get_name() << "," << pet.get_breed() << "," << pet.get_vaccines() << "," << pet.get_photograph() << "\n";
	return os;
}
