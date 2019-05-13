#pragma once
#include <string>
#include <vector>
#include <sstream>

class Pet
{
private:
	// name, breed, birthDate, vaccinationsCount, photograph
	std::string name;
	std::string breed;
	std::string birthDate;
	std::string photograph;
	int vaccines = 0;
public:
	bool operator==(Pet is_equal);
	std::string get_line() const;
	int get_vaccines() const;
	std::string get_name() const;
	std::string get_breed() const;
	std::string get_birth_date() const;
	std::string get_photograph() const;
	void set_name(std::string new_name);
	void set_breed(std::string new_size);
	void set_date(std::string new_date);
	void set_vaccines(int new_price);
	void set_photograph(std::string new_photograph);
	Pet();
	Pet(std::string name);
	Pet(std::string name, std::string breed, std::string birthDate, int vaccines, std::string photograph);
	~Pet();

	friend std::istream& operator>>(std::istream& input, Pet& pet);
	friend std::ostream& operator<<(std::ostream& output, const Pet& pet);

};

