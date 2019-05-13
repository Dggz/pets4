#pragma once
#include "Pet.h"
#include <algorithm>
#include <sstream>
#include <iterator>
class HTMLPet : public Pet
{
public:
	HTMLPet();
	HTMLPet(std::string name, std::string breed, std::string birthDate, int vaccines, std::string photograph);
	~HTMLPet();
	
	HTMLPet(Pet normal)
	{
		this->set_name(normal.get_name());
		this->set_breed(normal.get_breed());
		this->set_date(normal.get_birth_date());
		this->set_vaccines(normal.get_vaccines());
		this->set_photograph(normal.get_photograph());
	}
	friend std::istream& operator>>(std::istream& input, HTMLPet& pet);
	friend std::ostream& operator<<(std::ostream& output, const HTMLPet& pet);
};

