#pragma once
#include "Pet.h"
#include <vector>
#include <algorithm>
#include <string>
#include <exception>
class RepositoryError : public std::exception
{
public:
	RepositoryError() : exception()
	{

	}
	RepositoryError(std::string error) : exception(error.c_str())
	{

	}

};
class Repository
{
	friend class FileRepository;
private:
	std::vector<Pet>* pets;
	int size;
	int capacity;
public:
	Repository();
	virtual void add_element(Pet element);
	virtual void update_element(Pet update_with);
	virtual void delete_element(Pet delete_me);
	virtual std::vector<Pet> get_elements() const;
	virtual void reset();
	virtual void save();
	~Repository();
};