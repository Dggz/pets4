#include "Repository.h"
#include <fstream>
#include <iostream>

Repository::Repository()
{
	this->pets = new std::vector<Pet>;
}
//adds a pet to the repository if the name is not in the repo at the moment
void Repository::add_element(Pet element)
{
	if (std::find(this->pets->begin(), this->pets->end(), element) != this->pets->end()) {
		throw RepositoryError("pet already exists!\n");
	}
	this->pets->push_back(element);
}
//tries to update a pet. The unique characteristic is the name
void Repository::update_element(Pet update_with)
{
	auto position = std::find(this->pets->begin(), this->pets->end(), update_with);
	if (position != this->pets->end())
		this->pets->at(position - this->pets->begin()) = update_with;
	else
		throw RepositoryError("pet does not exists!\n");
}
//tries to delete a pet
void Repository::delete_element(Pet delete_me)
{
	auto position = std::find(this->pets->begin(), this->pets->end(), delete_me);
	if (position != this->pets->end())
		this->pets->erase(position);
	else
		throw RepositoryError("Pet does not exists!\n");
}
//returns a char array with the output message
std::vector<Pet> Repository::get_elements() const
{
	return *this->pets;
}
void Repository::reset()
{
	delete this->pets;
	this->pets = new std::vector<Pet>;
}
void Repository::save()
{
}
//destructor
Repository::~Repository()
{
	delete this->pets;
}



