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

std::istream & operator>>(std::istream & input, CSVPet & cpet)
{
	// TODO: insert return statement here
	std::string line;
	getline(input, line);

	std::vector<std::string> tokens;
	std::stringstream ss(line);
	std::string token;
	while (getline(ss, token, ','))
		tokens.push_back(token);
	if (tokens.size() != 4)
		return input;
	cpet.set_name(tokens[0]);
	cpet.set_breed(tokens[1]);
	cpet.set_date(tokens[2]);
	cpet.set_vaccines(std::stoi(tokens[3]));
	cpet.set_photograph(tokens[4]);
	return input;
}

std::ostream & operator<<(std::ostream & output, const CSVPet & pet)
{
	output << pet.get_name() << "," << pet.get_breed() << "," << pet.get_vaccines() << "," << pet.get_photograph() << "\n";
	return output;
}
