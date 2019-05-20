#pragma once
#include "Service.h"
#include "CSVRepository.h"
#include "HTMLRepository.h"
#include <assert.h>
class Test
{
	Repository* repository;
	Validator* validator;
	Service* service;
	std::vector<Pet> compare_to;
	bool isEqual(std::vector<Pet> v1, std::vector<Pet> v2)
	{
		if (v1.size() != v2.size())
		{
			return false;

		}
		for (auto element : v1)
		{
			auto position = std::find(v2.begin(), v2.end(), element);
			if (position == v2.end())
				return false;
		}
		return true;
	}

	void reset_vector()
	{		
		Pet pet1("pet1", "breed1", "birthdate", 10, "pet1.jpg");
		Pet pet2("pet2", "breed2", "birthdate", 15, "pet2.jpg");
		Pet pet3("pet3", "breed3", "birthdate", 4, "pet3.jpg");
		Pet pet4("pet4", "breed4", "birthdate", 60, "pet4.jpg");
		Pet pet5("pet5", "breed2", "birthdate", 100, "pet5.jpg");
		Pet pet6("pet6", "breed2", "birthdate", 55, "pet6.jpg");
		this->compare_to.clear();
		this->compare_to.push_back(pet1);
		this->compare_to.push_back(pet2);
		this->compare_to.push_back(pet3);
		this->compare_to.push_back(pet4);
		this->compare_to.push_back(pet5);
		this->compare_to.push_back(pet6);
	}
	void test_domain()
	{
		Pet pet1("name");
		pet1.get_line();
		Pet pet2;
		pet2.get_line();
	}
	void test_add()
	{
		this->reset_vector();
		int stop_condition = 1;
		this->repository->reset();
		this->service->parse_arguments("mode A\n", stop_condition);
		this->service->parse_arguments("add pet1,breed1,birthdate,10,pet1.jpg\n", stop_condition);
		this->service->parse_arguments("add pet2,breed2,birthdate,15,pet2.jpg\n", stop_condition);
		this->service->parse_arguments("add pet3,breed1,birthdate,4,pet3.jpg\n", stop_condition);
		this->service->parse_arguments("add pet4,breed4,birthdate,60,pet4.jpg\n", stop_condition);
		this->service->parse_arguments("add pet5,breed2,birthdate,100,pet5.jpg\n", stop_condition);
		std::vector<Pet> local_repo;
		local_repo = this->repository->get_elements();
		assert(this->isEqual(local_repo, this->compare_to) == false);
		this->service->parse_arguments("add pet6,breed2,date,55,pet6.jpg\n", stop_condition);
		
		local_repo = this->repository->get_elements();

		assert(this->isEqual(local_repo, this->compare_to) == true);
		Pet pet7("pet7", "breed2", "date", 55, "pet7.jpg");
		this->compare_to.pop_back();
		this->compare_to.push_back(pet7);
		assert(this->isEqual(local_repo, this->compare_to) == false);
	}
	void test_delete()
	{
		this->reset_vector();
		int stop_condition = 1;
		this->repository->reset();
		this->service->parse_arguments("mode A\n", stop_condition);

		this->service->parse_arguments("add pet1,breed1,birthdate,10,pet1.jpg\n", stop_condition);
		this->service->parse_arguments("add pet2,breed2,birthdate,15,pet2.jpg\n", stop_condition);
		this->service->parse_arguments("add pet3,breed1,birthdate,4,pet3.jpg\n", stop_condition);
		this->service->parse_arguments("add pet4,breed4,birthdate,60,pet4.jpg\n", stop_condition);
		this->service->parse_arguments("add pet5,breed2,birthdate,100,pet5.jpg\n", stop_condition);
		this->service->parse_arguments("add pet6,breed2,birthdate,55,pet6.jpg\n", stop_condition);
		std::vector<Pet> local_repo;
		local_repo = this->service->parse_arguments("list\n", stop_condition);
		local_repo = this->repository->get_elements();
		assert(this->isEqual(local_repo, this->compare_to) == true);
		this->compare_to.erase(this->compare_to.begin() + 3);
		assert(this->isEqual(local_repo, this->compare_to) == false);
		this->service->parse_arguments("delete pet4\n", stop_condition);
		local_repo = this->service->parse_arguments("list\n", stop_condition);
		assert(this->isEqual(local_repo, this->compare_to) == true);
	}
	void test_update()
	{
		int stop_condition = 1;
		this->repository->reset();
		this->service->parse_arguments("mode A\n", stop_condition);
		this->service->parse_arguments("add pet1,breed1,birthdate,10,pet1.jpg\n", stop_condition);
		std::vector<Pet> local_repo;
		local_repo = this->service->parse_arguments("list\n", stop_condition);
		Pet pet1("pet1", "breed1", "birthdate", 10, "pet1.jpg");
		assert(local_repo.at(0).get_line() == pet1.get_line());
		this->service->parse_arguments("update pet1,breed99,birthdate,30,pet1.png\n", stop_condition);
		local_repo = this->service->parse_arguments("list\n", stop_condition);
		Pet pet2("pet1", "breed99", "birthdate", 30, "pet1.png");
		assert(local_repo.at(0).get_line() == pet2.get_line());
	}
	void test_user()
	{
		int stop_condition = 1;
		this->repository->reset();
		this->service->parse_arguments("mode A\n", stop_condition);

		this->service->parse_arguments("add pet1,breed1,birthdate,10,pet1.jpg\n", stop_condition);
		this->service->parse_arguments("add pet2,breed2,birthdate,15,pet2.jpg\n", stop_condition);
		this->service->parse_arguments("add pet3,breed1,birthdate,4,pet3.jpg\n", stop_condition);

		this->service->parse_arguments("mode B\n", stop_condition);
		std::vector<Pet> local_repo;

		this->compare_to.clear();
		Pet pet1("pet1", "breed1", "birth", 5, "pet1.jpg");
		Pet pet2("pet2", "breed2", "birth", 6, "pet2.jpg");
		Pet pet3("pet3", "breed1", "birth", 4, "pet3.jpg");
		this->compare_to.push_back(pet1);
		local_repo = this->service->parse_arguments("next\n", stop_condition);
		assert(this->isEqual(local_repo, this->compare_to) == true);
		this->compare_to.clear();
		this->compare_to.push_back(pet2);
		local_repo = this->service->parse_arguments("next\n", stop_condition);
		assert(this->isEqual(local_repo, this->compare_to) == true);
		this->compare_to.clear();
		this->compare_to.push_back(pet3);
		local_repo = this->service->parse_arguments("next\n", stop_condition);
		assert(this->isEqual(local_repo, this->compare_to) == true);
		this->compare_to.clear();
		this->compare_to.push_back(pet1);
		local_repo = this->service->parse_arguments("next\n", stop_condition);
		assert(this->isEqual(local_repo, this->compare_to) == true);
		this->compare_to.push_back(pet3);
		local_repo = this->service->parse_arguments("list breed1,11\n", stop_condition);
		assert(this->isEqual(local_repo, this->compare_to) == true);
		this->compare_to.erase(this->compare_to.begin());
		local_repo = this->service->parse_arguments("list breed1,7\n", stop_condition);
		assert(this->isEqual(local_repo, this->compare_to) == true);
		this->compare_to.clear();
		this->compare_to.push_back(pet1);
		this->compare_to.push_back(pet2);
		local_repo = this->service->parse_arguments("mylist\n", stop_condition);
		assert(this->isEqual(local_repo, this->compare_to) == false);
		this->service->parse_arguments("save pet1\n", stop_condition);
		this->service->parse_arguments("save pet2\n", stop_condition);
		local_repo = this->service->parse_arguments("mylist\n", stop_condition);
		assert(this->isEqual(local_repo, this->compare_to) == true);
	}
	void test_file()
	{
		int stop_condition = 1;
		this->repository->reset();
		this->service->parse_arguments("mode A\n", stop_condition);
		std::vector<Pet> local_repo;
		this->reset_vector();
		assert(this->isEqual(local_repo, this->compare_to) == false);
		this->service->parse_arguments("fileLocation test.txt\n", stop_condition);
		local_repo = this->service->parse_arguments("list\n", stop_condition);
		assert(this->isEqual(local_repo, this->compare_to) == true);
		this->service->parse_arguments("exit\n", stop_condition);
		CSVRepository fake_repo("nothing.txt");
		this->compare_to.clear();
		assert(this->isEqual(fake_repo.get_elements(), this->compare_to) == true);
		//fake_repo.~FileRepository();

	}
	void test_exceptions()
	{
		int stop_condition = 1;
		this->repository->reset();
		this->service->parse_arguments("mode A\n", stop_condition);
		//this->service->parse_arguments("fileLocation test.txt\n", stop_condition);

		try
		{
			this->service->parse_arguments("asdasasd\n", stop_condition);
			assert(false);
		}
		catch (ValidationError)
		{
			assert(true);
		}
		try
		{
			this->service->parse_arguments("list asd\n", stop_condition);
			assert(false);
		}
		catch (ValidationError)
		{
			assert(true);
		}
		try
		{
			this->service->parse_arguments("add 1,1,1,asd,1\n", stop_condition);
			assert(false);
		}
		catch (ValidationError)
		{
			assert(true);
		}
		try
		{
			this->service->parse_arguments("add 1\n", stop_condition);
			assert(false);
		}
		catch (ValidationError)
		{
			assert(true);
		}
		try
		{
			this->service->parse_arguments("update 1,1,1,asd,1\n", stop_condition);
			assert(false);
		}
		catch (ValidationError)
		{
			assert(true);
		}
		try
		{
			this->service->parse_arguments("update 1\n", stop_condition);
			assert(false);
		}
		catch (ValidationError)
		{
			assert(true);
		}
		try
		{
			this->service->parse_arguments("delete\n", stop_condition);
			assert(false);
		}
		catch (ValidationError)
		{
			assert(true);
		}

		try
		{
			this->service->parse_arguments("add pet1,breed,birthdate,10v,pet1.jpg\n", stop_condition);
			assert(false);
		}
		catch (RepositoryError)
		{
			assert(true);
		}
		try
		{
			this->service->parse_arguments("update pet10,breed,asd,11,asd\n", stop_condition);
			assert(false);
		}
		catch (RepositoryError)
		{
			assert(true);
		}
		try
		{
			this->service->parse_arguments("delete pet10\n", stop_condition);
			assert(false);
		}
		catch (RepositoryError)
		{
			assert(true);
		}

		this->service->parse_arguments("mode B\n", stop_condition);
		try
		{
			this->service->parse_arguments("asdfasd\n", stop_condition);
			assert(false);
		}
		catch (ValidationError)
		{
			assert(true);
		}
		try
		{
			this->service->parse_arguments("list adfg\n", stop_condition);
			assert(false);
		}
		catch (ValidationError)
		{
			assert(true);
		}
		try
		{
			this->service->parse_arguments("list 1,asd\n", stop_condition);
			assert(false);
		}
		catch (ValidationError)
		{
			assert(true);
		}
		try
		{
			this->service->parse_arguments("save asd,asf\n", stop_condition);
			assert(false);
		}
		catch (ValidationError)
		{
			assert(true);
		}
		try
		{
			this->service->parse_arguments("next asd\n", stop_condition);
			assert(false);
		}
		catch (ValidationError)
		{
			assert(true);
		}
		try
		{
			this->service->parse_arguments("mylist dfg\n", stop_condition);
			assert(false);
		}
		catch (ValidationError)
		{
			assert(true);
		}


	}
	void test_destroy()
	{
		this->repository->~Repository();
		this->validator->~Validator();
		this->service->~Service();
	}
public:
	Test()
	{
		this->repository = new Repository();
		this->validator = new Validator();
		this->service = new Service(this->repository, this->validator);
		
	}
	
	void testAll()
	{	
		this->test_domain();
		this->test_add();
		this->test_delete();
		this->test_update();
		this->test_user();
		/*
		this->test_exceptions();
		this->test_file();
		this->test_destroy();
		*/
	}
	~Test()
	{

	}
};

