#include "Directory.h"

void Directory::addFirm(const Firm& firm)
{
	this->firms.add(firm);
}

void Directory::removeFirm(const std::string& name)
{
	this->firms.remove(Firm(name));
}

void Directory::print() const
{
	if (!this->firms.isEmpty())
		this->firms.print();
}

Firms Directory::findByName(const std::string& name) const
{
	Firms res;

	unsigned int size = this->firms.size();

	for (unsigned int i = 0; i < size; i++)
	{
		if (this->firms[i].getName() == name)
			res.add(this->firms[i]);
	}

	return res;
}

Firms Directory::findByOwner(const std::string& owner) const
{
	Firms res;

	unsigned int size = this->firms.size();

	for (unsigned int i = 0; i < size; i++)
	{
		if (this->firms[i].getOwner() == owner)
			res.add(this->firms[i]);
	}

	return res;
}

Firms Directory::findByNumber(const std::string& number) const
{
	Firms res;

	unsigned int size = this->firms.size();

	for (unsigned int i = 0; i < size; i++)
	{
		if (this->firms[i].getNumber() == number)
			res.add(this->firms[i]);
	}

	return res;
}

Firms Directory::findByOccupation(const std::string& occupation) const
{
	Firms res;

	unsigned int size = this->firms.size();

	for (unsigned int i = 0; i < size; i++)
	{
		if (this->firms[i].getOccupation() == occupation)
			res.add(this->firms[i]);
	}

	return res;
}

void Directory::save(const std::string& path) const
{
	std::ofstream file;

	file.open(path);

	if (!file.is_open())
		throw std::exception("Cannot open the file\n");

	unsigned int size = this->firms.size();

	for (unsigned int i = 0; i < size; i++)
	{
		file << this->firms[i];
	}

	file.close();
}

void Directory::load(const std::string& path)
{
	std::ifstream file;

	file.open(path);

	if (!file.is_open())
		throw std::exception("Cannot open the file\n");

	std::string str;
	std::string name = "";

	unsigned int count = -1;

	while (std::getline(file, str))
	{
		size_t pos = 0;

		pos = str.find(':');

		std::string property = str.substr(0, pos);

		if (property == "Name")
		{
			name = str.substr(pos + 2);
			this->firms.add(Firm(name));
			count++;
		}

		else if (property == "Owner")
		{
			this->firms[count].setOwner(str.substr(pos + 2));
		}

		else if (property == "Phone number")
		{
			this->firms[count].setNumber(str.substr(pos + 2));
		}

		else if (property == "Address")
		{
			this->firms[count].setAddress(str.substr(pos + 2));
		}

		else if (property == "Occupation")
		{
			this->firms[count].setOccupation(str.substr(pos + 2));
		}
	}

	file.close();
}
