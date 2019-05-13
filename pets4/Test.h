//#pragma once
//#include "Service.h"
//#include <assert.h>
//class Test
//{
//	Repository* repository;
//	Validator* validator;
//	Service* service;
//	std::vector<Pet> compare_to;
//	bool isEqual(std::vector<Pet> v1, std::vector<Pet> v2)
//	{
//		if (v1.size() != v2.size())
//		{
//			return false;
//
//		}
//		for (auto element : v1)
//		{
//			auto position = std::find(v2.begin(), v2.end(), element);
//			if (position == v2.end())
//				return false;
//		}
//		return true;
//	}
//
//	void reset_vector()
//	{		
//		Pet coat1("coat1", "size1", "size1", 10, "coat1.jpg");
//		Pet coat2("coat2", "size2", "size1", 15, "coat2.jpg");
//		Pet coat3("coat3", "size1", "size1", 4, "coat3.jpg");
//		Pet coat4("coat4", "size4", "size1", 60, "coat4.jpg");
//		Pet coat5("coat5", "size2", "size1", 100, "coat5.jpg");
//		Pet coat6("coat6", "size2", "size1", 55, "coat6.jpg");
//		this->compare_to.clear();
//		this->compare_to.push_back(coat1);
//		this->compare_to.push_back(coat2);
//		this->compare_to.push_back(coat3);
//		this->compare_to.push_back(coat4);
//		this->compare_to.push_back(coat5);
//		this->compare_to.push_back(coat6);
//	}
//	void test_domain()
//	{
//		Pet coat1("name");
//		coat1.get_line();
//		Pet coat2;
//		coat2.get_line();
//	}
//	void test_add()
//	{
//		this->reset_vector();
//		int stop_condition = 1;
//		this->repository->reset();
//		this->service->parse_arguments("mode A\n", stop_condition);
//		this->service->parse_arguments("add coat1,size1,10,coat1.jpg\n", stop_condition);
//		this->service->parse_arguments("add coat2,size2,15,coat2.jpg\n", stop_condition);
//		this->service->parse_arguments("add coat3,size1,4,coat3.jpg\n", stop_condition);
//		this->service->parse_arguments("add coat4,size4,60,coat4.jpg\n", stop_condition);
//		this->service->parse_arguments("add coat5,size2,100,coat5.jpg\n", stop_condition);
//		std::vector<Pet> local_repo;
//		local_repo = this->repository->get_elements();
//		assert(this->isEqual(local_repo, this->compare_to) == false);
//		this->service->parse_arguments("add coat6,size2,55,coat6.jpg\n", stop_condition);
//		
//		local_repo = this->repository->get_elements();
//
//		assert(this->isEqual(local_repo, this->compare_to) == true);
//		Pet coat7("coat7", "size2", 55, "coat7.jpg");
//		this->compare_to.pop_back();
//		this->compare_to.push_back(coat7);
//		assert(this->isEqual(local_repo, this->compare_to) == false);
//	}
//	void test_delete()
//	{
//		this->reset_vector();
//		int stop_condition = 1;
//		this->repository->reset();
//		this->service->parse_arguments("mode A\n", stop_condition);
//
//		this->service->parse_arguments("add coat1,size1,10,coat1.jpg\n", stop_condition);
//		this->service->parse_arguments("add coat2,size2,15,coat2.jpg\n", stop_condition);
//		this->service->parse_arguments("add coat3,size1,4,coat3.jpg\n", stop_condition);
//		this->service->parse_arguments("add coat4,size4,60,coat4.jpg\n", stop_condition);
//		this->service->parse_arguments("add coat5,size2,100,coat5.jpg\n", stop_condition);
//		this->service->parse_arguments("add coat6,size2,55,coat6.jpg\n", stop_condition);
//		std::vector<Pet> local_repo;
//		local_repo = this->service->parse_arguments("list\n", stop_condition);
//		local_repo = this->repository->get_elements();
//		assert(this->isEqual(local_repo, this->compare_to) == true);
//		this->compare_to.erase(this->compare_to.begin() + 3);
//		assert(this->isEqual(local_repo, this->compare_to) == false);
//		this->service->parse_arguments("delete coat4\n", stop_condition);
//		local_repo = this->service->parse_arguments("list\n", stop_condition);
//		assert(this->isEqual(local_repo, this->compare_to) == true);
//	}
//	void test_update()
//	{
//		int stop_condition = 1;
//		this->repository->reset();
//		this->service->parse_arguments("mode A\n", stop_condition);
//		this->service->parse_arguments("add coat1,size1,10,coat1.jpg\n", stop_condition);
//		std::vector<Pet> local_repo;
//		local_repo = this->service->parse_arguments("list\n", stop_condition);
//		Pet coat1("coat1", "size1", 10, "coat1.jpg");
//		assert(local_repo.at(0).get_line() == coat1.get_line());
//		this->service->parse_arguments("update coat1,size99,30,coat1.png\n", stop_condition);
//		local_repo = this->service->parse_arguments("list\n", stop_condition);
//		Pet coat2("coat1", "size99", 30, "coat1.png");
//		assert(local_repo.at(0).get_line() == coat2.get_line());
//	}
//	void test_user()
//	{
//		int stop_condition = 1;
//		this->repository->reset();
//		this->service->parse_arguments("mode A\n", stop_condition);
//
//		this->service->parse_arguments("add coat1,size1,10,coat1.jpg\n", stop_condition);
//		this->service->parse_arguments("add coat2,size2,15,coat2.jpg\n", stop_condition);
//		this->service->parse_arguments("add coat3,size1,4,coat3.jpg\n", stop_condition);
//
//		this->service->parse_arguments("mode B\n", stop_condition);
//		std::vector<Pet> local_repo;
//
//		this->compare_to.clear();
//		Pet coat1("coat1", "size1", 10, "coat1.jpg");
//		Pet coat2("coat2", "size2", 15, "coat2.jpg");
//		Pet coat3("coat3", "size1", 4, "coat3.jpg");
//		this->compare_to.push_back(coat1);
//		local_repo = this->service->parse_arguments("next\n", stop_condition);
//		assert(this->isEqual(local_repo, this->compare_to) == true);
//		this->compare_to.clear();
//		this->compare_to.push_back(coat2);
//		local_repo = this->service->parse_arguments("next\n", stop_condition);
//		assert(this->isEqual(local_repo, this->compare_to) == true);
//		this->compare_to.clear();
//		this->compare_to.push_back(coat3);
//		local_repo = this->service->parse_arguments("next\n", stop_condition);
//		assert(this->isEqual(local_repo, this->compare_to) == true);
//		this->compare_to.clear();
//		this->compare_to.push_back(coat1);
//		local_repo = this->service->parse_arguments("next\n", stop_condition);
//		assert(this->isEqual(local_repo, this->compare_to) == true);
//		this->compare_to.push_back(coat3);
//		local_repo = this->service->parse_arguments("list size1,11\n", stop_condition);
//		assert(this->isEqual(local_repo, this->compare_to) == true);
//		this->compare_to.erase(this->compare_to.begin());
//		local_repo = this->service->parse_arguments("list size1,10\n", stop_condition);
//		assert(this->isEqual(local_repo, this->compare_to) == true);
//		this->compare_to.clear();
//		this->compare_to.push_back(coat1);
//		this->compare_to.push_back(coat2);
//		local_repo = this->service->parse_arguments("mylist\n", stop_condition);
//		assert(this->isEqual(local_repo, this->compare_to) == false);
//		this->service->parse_arguments("save coat1\n", stop_condition);
//		this->service->parse_arguments("save coat2\n", stop_condition);
//		local_repo = this->service->parse_arguments("mylist\n", stop_condition);
//		assert(this->isEqual(local_repo, this->compare_to) == true);
//	}
//	void test_file()
//	{
//		int stop_condition = 1;
//		this->repository->reset();
//		this->service->parse_arguments("mode A\n", stop_condition);
//		std::vector<Pet> local_repo;
//		this->reset_vector();
//		assert(this->isEqual(local_repo, this->compare_to) == false);
//		this->service->parse_arguments("fileLocation test.txt\n", stop_condition);
//		local_repo = this->service->parse_arguments("list\n", stop_condition);
//		assert(this->isEqual(local_repo, this->compare_to) == true);
//		this->service->parse_arguments("exit\n", stop_condition);
//		CSVRepository fake_repo("nothing.txt");
//		this->compare_to.clear();
//		assert(this->isEqual(fake_repo.get_elements(), this->compare_to) == true);
//		//fake_repo.~FileRepository();
//
//	}
//	void test_exceptions()
//	{
//		int stop_condition = 1;
//		this->repository->reset();
//		this->service->parse_arguments("mode A\n", stop_condition);
//		this->service->parse_arguments("fileLocation test.txt\n", stop_condition);
//
//		try
//		{
//			this->service->parse_arguments("asdasasd\n", stop_condition);
//			assert(false);
//		}
//		catch (ValidationError)
//		{
//			assert(true);
//		}
//		try
//		{
//			this->service->parse_arguments("list asd\n", stop_condition);
//			assert(false);
//		}
//		catch (ValidationError)
//		{
//			assert(true);
//		}
//		try
//		{
//			this->service->parse_arguments("add 1,1,asd,1\n", stop_condition);
//			assert(false);
//		}
//		catch (ValidationError)
//		{
//			assert(true);
//		}
//		try
//		{
//			this->service->parse_arguments("add 1\n", stop_condition);
//			assert(false);
//		}
//		catch (ValidationError)
//		{
//			assert(true);
//		}
//		try
//		{
//			this->service->parse_arguments("update 1,1,asd,1\n", stop_condition);
//			assert(false);
//		}
//		catch (ValidationError)
//		{
//			assert(true);
//		}
//		try
//		{
//			this->service->parse_arguments("update 1\n", stop_condition);
//			assert(false);
//		}
//		catch (ValidationError)
//		{
//			assert(true);
//		}
//		try
//		{
//			this->service->parse_arguments("delete\n", stop_condition);
//			assert(false);
//		}
//		catch (ValidationError)
//		{
//			assert(true);
//		}
//
//		try
//		{
//			this->service->parse_arguments("add coat1,size1,10,coat1.jpg\n", stop_condition);
//			assert(false);
//		}
//		catch (RepositoryError)
//		{
//			assert(true);
//		}
//		try
//		{
//			this->service->parse_arguments("update coat10,asd,11,asd\n", stop_condition);
//			assert(false);
//		}
//		catch (RepositoryError)
//		{
//			assert(true);
//		}
//		try
//		{
//			this->service->parse_arguments("delete coat10\n", stop_condition);
//			assert(false);
//		}
//		catch (RepositoryError)
//		{
//			assert(true);
//		}
//
//		this->service->parse_arguments("mode B\n", stop_condition);
//		try
//		{
//			this->service->parse_arguments("asdfasd\n", stop_condition);
//			assert(false);
//		}
//		catch (ValidationError)
//		{
//			assert(true);
//		}
//		try
//		{
//			this->service->parse_arguments("list adfg\n", stop_condition);
//			assert(false);
//		}
//		catch (ValidationError)
//		{
//			assert(true);
//		}
//		try
//		{
//			this->service->parse_arguments("list 1,asd\n", stop_condition);
//			assert(false);
//		}
//		catch (ValidationError)
//		{
//			assert(true);
//		}
//		try
//		{
//			this->service->parse_arguments("save asd,asf\n", stop_condition);
//			assert(false);
//		}
//		catch (ValidationError)
//		{
//			assert(true);
//		}
//		try
//		{
//			this->service->parse_arguments("next asd\n", stop_condition);
//			assert(false);
//		}
//		catch (ValidationError)
//		{
//			assert(true);
//		}
//		try
//		{
//			this->service->parse_arguments("mylist dfg\n", stop_condition);
//			assert(false);
//		}
//		catch (ValidationError)
//		{
//			assert(true);
//		}
//
//
//	}
//	void test_destroy()
//	{
//		this->repository->~Repository();
//		this->validator->~Validator();
//		this->service->~Service();
//	}
//public:
//	Test()
//	{
//		this->repository = new Repository();
//		this->validator = new Validator();
//		this->service = new Service(this->repository, this->validator);
//		
//	}
//	
//	void testAll()
//	{
//		this->test_domain();
//		this->test_add();
//		this->test_delete();
//		this->test_update();
//		this->test_user();
//		this->test_file();
//		this->test_exceptions();
//		this->test_destroy();
//	}
//	~Test()
//	{
//
//	}
//};
//
