#include "UI.h"
#include <string>


UI::UI(Service* service)
{
	this->service = service;
}


UI::~UI()
{
}
//runs the program technically
void UI::run()
{
	std::vector<Pet> returned;
	char* input = new char[200];
	int i = 1;
	while (i == 1) {
		try 
		{
			fgets(input, 200, stdin);
			returned = this->service->parse_arguments(input, i);
			for (auto pet : returned)
				printf("%s", pet.get_line().c_str());
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