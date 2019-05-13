#include "HTMLPet.h"



HTMLPet::HTMLPet()
{
}

HTMLPet::HTMLPet(std::string name, std::string breed, std::string birthDate, int vaccines, std::string photograph) : Pet(name, breed, birthDate, vaccines, photograph)
{
}


HTMLPet::~HTMLPet()
{
}


std::istream & operator>>(std::istream & is, HTMLPet & pet)
{
	std::string whitespace;
	getline(is, whitespace);
	while (whitespace.compare("<tr>") && !is.eof()) //garbage
	{
		getline(is, whitespace);
	}
	if (is.eof())
	{	
		return is;
	}
	std::string name, breed, birth, vaccines, photo;
	getline(is, whitespace); // <td>
	getline(is, name);  // name
	getline(is, whitespace); // </td>
	getline(is, whitespace); // <td>
	getline(is, breed);  // breed
	getline(is, whitespace); // </td>
	getline(is, whitespace); // <td>
	getline(is, birth);  // birth
	getline(is, whitespace); // </td>
	getline(is, whitespace); // <td>
	getline(is, vaccines);  // vaccines
	getline(is, whitespace); // </td>
	getline(is, whitespace); // <td>
	getline(is, photo);  // photo
	getline(is, whitespace); // </td>
	getline(is, whitespace); // </tr>
	pet.set_name(name);
	pet.set_breed(breed);
	pet.set_vaccines(std::stoi(vaccines));
	pet.set_photograph(photo);
	return is;
}

std::ostream & operator<<(std::ostream & output, const HTMLPet & pet)
{
	output << "<tr>\n<td>\n" << pet.get_name() << "\n</td>\n<td>\n" << pet.get_breed() << "\n</td>\n<td>\n";
	output << pet.get_birth_date() << "\n</td>\n<td>\n" << pet.get_vaccines() << "\n</td>\n<td>\n" << pet.get_photograph() << "\n</td>\n</tr>\n";
	return output;
}
