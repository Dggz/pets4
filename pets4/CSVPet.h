#pragma once
#include "Pet.h"
class CSVPet : public Pet
{
public:
	CSVPet();
	CSVPet(std::string name, std::string breed, std::string birthDate, int vaccines, std::string photograph);
	~CSVPet();
	CSVPet(Pet normal)
	{
		this->set_name(normal.get_name());
		this->set_breed(normal.get_breed());
		this->set_date(normal.get_birth_date());
		this->set_vaccines(normal.get_vaccines());
		this->set_photograph(normal.get_photograph());
	}
	friend std::istream& operator>>(std::istream& is, CSVPet& coat);
	friend std::ostream& operator<<(std::ostream& os, const CSVPet& coat);

};

