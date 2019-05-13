#pragma once
#include "Service.h"

class Service;
class UI
{
	Service* service;
public:
	UI(Service* service);
	void run();
	~UI();
};