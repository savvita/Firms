#include "Firm.h"

bool Firm::_isCorrectNumber(const std::string& number) const
{
	size_t size = number.length();

	for (size_t i = 0; i < size; i++)
	{
		if (!isdigit(number[i]))
			return false;
	}

	return true;
}

Firm::Firm(const std::string& name, const std::string& owner, const std::string& phoneNumber, const std::string& address, const std::string& occupation):
	name{ name }, owner{ owner }, phoneNumber{ "" }, address{ address }, occupation{ occupation }
{
	this->setNumber(phoneNumber);
}

void Firm::setName(const std::string& name)
{
	this->name = name;
}

void Firm::setOwner(const std::string& owner)
{
	this->owner = owner;
}

void Firm::setNumber(const std::string& number)
{
	if (this->_isCorrectNumber(number))
		this->phoneNumber = number;
}

void Firm::setAddress(const std::string& address)
{
	this->address = address;
}

void Firm::setOccupation(const std::string& occupation)
{
	this->occupation = occupation;
}

const std::string& Firm::getName() const
{
	return this->name;
}

const std::string& Firm::getOwner() const
{
	return this->owner;
}

const std::string& Firm::getNumber() const
{
	return this->phoneNumber;
}

const std::string& Firm::getAddress() const
{
	return this->address;
}

const std::string& Firm::getOccupation() const
{
	return this->occupation;
}

bool operator==(const Firm& firm_1, const Firm& firm_2)
{
	return (firm_1.name == firm_2.name);
}

bool operator!=(const Firm& firm_1, const Firm& firm_2)
{
	return !(firm_1 == firm_2);
}

std::ostream& operator<<(std::ostream& out, const Firm& firm)
{
	out << "Name: " << firm.name << "\n";

	if (!firm.owner.empty())
		out << "Owner: " << firm.owner << "\n";

	if (!firm.phoneNumber.empty())
		out << "Phone number: " << firm.phoneNumber << "\n";

	if (!firm.address.empty())
		out << "Address: " << firm.address << "\n";

	if (!firm.occupation.empty())
		out << "Occupation: " << firm.occupation << "\n";

	return out;
}
