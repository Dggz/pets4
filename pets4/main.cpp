#include "UI.h"
#include "Test.h"
#include <string>
#include <Windows.h>
#include <crtdbg.h>
#include <iostream>

int main()
{
	/*
	Test test;
	test.testAll();*/


	Repository* repo = new Repository(); //creates the repository
	Validator* validator = new Validator();
	Service* service = new Service(repo, validator); // creates the service using the repository
	UI* ui = new UI(service); // creates the ui using the service;
	ui->run(); //runs the program
	//system("pause");
	return 0;
}
