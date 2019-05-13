#include "Pet.h"
#include <string>
using namespace std;


Pet::Pet(std::string name, std::string breed, std::string birthDate, int vaccines, std::string photograph)
{
	this->name = name;
	this->breed = breed;
	this->birthDate = birthDate;
	this->photograph = photograph;
	this->vaccines = vaccines;
}
Pet::Pet(std::string name)
{
	this->name = name;
}

int Pet::get_vaccines() const
{
	return this->vaccines;
}

std::string Pet::get_breed() const
{
	return this->breed;
}

std::string Pet::get_name() const
{
	return this->name;
}

bool Pet::operator==(Pet is_equal)
{
	return !this->name.compare(is_equal.name);;
}

std::string Pet::get_photograph() const
{
	return this->photograph;
}

void Pet::set_vaccines(int vaccines)
{
	this->vaccines = vaccines;
}

void Pet::set_breed(std::string new_breed)
{
	this->breed = new_breed;
}

void Pet::set_name(std::string new_name)
{
	this->name = new_name;
}

void Pet::set_photograph(std::string new_photograph)
{
	this->photograph = new_photograph;
}

Pet::Pet()
{

}
std::string Pet::get_line() const
{
	if (this->vaccines == 0 && this->breed.size() == 0 && this->name.size() == 0 && this->photograph.size() == 0)
	{
		std::string empty;
		return empty;
	}
	if (this->vaccines == 0 && this->breed.size() == 0 && this->photograph.size() == 0)
	{
		return this->name;
	}
	string trench_coat;
	trench_coat = this->name;
	trench_coat += " | ";
	trench_coat += this->breed;
	trench_coat += " | ";
	trench_coat += std::to_string(this->vaccines);
	trench_coat += " | ";
	trench_coat += this->photograph;
	trench_coat += "\n";
	return trench_coat;
}
Pet::~Pet()
{
}

std::istream & operator>>(std::istream & input, Pet & coat)
{
	// TODO: insert return statement here
	string line;
	getline(input, line);

	vector<string> tokens;
	stringstream ss(line);
	string token;
	while (getline(ss, token, ','))
		tokens.push_back(token);
	if (tokens.size() != 4)
		return input;
	coat.name = tokens[0];
	coat.breed = tokens[1];
	coat.vaccines = std::stoi(tokens[2]);
	coat.photograph = tokens[3];
	return input;
}

std::ostream & operator<<(std::ostream & output, const Pet & pet)
{
	// TODO: insert return statement here
	output << pet.name << "," << pet.breed << "," << pet.birthDate << "," << pet.vaccines << "," << pet.photograph << "\n";
	return output;
}

std::string Pet::get_birth_date() const
{
	return this->birthDate;
}

void Pet::set_date(std::string new_date)
{
	this->birthDate = new_date;
}
