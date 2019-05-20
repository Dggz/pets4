#include "UI.h"
#include <string>
#include <iostream>

UI::UI(Service* service)
{
	this->service = service;
}


UI::~UI()
{
}

void UI::run()
{
	std::vector<Pet> returned;
	char* input = new char[200];
	int i = 1;

	std::cout << "\nModes: mode A, mode B\n";
	while (i == 1) {
		try 
		{
			fgets(input, 200, stdin);
			returned = this->service->parse_arguments(input, i);
			for (auto pet : returned)
				std::cout << pet.get_line();
		}
		catch (RepositoryError e)
		{
			printf("RepositoryError: %s", e.what());
		}
		catch (ValidationError e)
		{
			printf("ValidationError: %s", e.what());
		}
		catch(std::exception e)
		{
			printf("Exception: %s", e.what());
		}
		
	}
	delete[] input;
}