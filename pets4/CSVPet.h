#pragma once
#include "Pet.h"

class CSVPet : public Pet
{
public:
	CSVPet();
	CSVPet(std::string name, std::string breed, std::string birthDate, int vaccines, std::string photograph);
	~CSVPet();
	CSVPet(Pet cpet)
	{
		this->set_name(cpet.get_name());
		this->set_breed(cpet.get_breed());
		this->set_date(cpet.get_birth_date());
		this->set_vaccines(cpet.get_vaccines());
		this->set_photograph(cpet.get_photograph());
	}

	friend std::istream& operator>>(std::istream& input, CSVPet& pet);
	friend std::ostream& operator<<(std::ostream& output, const CSVPet& pet);

};

