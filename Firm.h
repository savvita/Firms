#pragma once
#include<iostream>

class Firm
{
private:
	std::string name;
	std::string owner;
	std::string phoneNumber;
	std::string address;
	std::string occupation;

	bool _isCorrectNumber(const std::string& number) const;

public:
	Firm() = default;
	Firm(const std::string& name, const std::string& owner = "", const std::string& phoneNumber = "", const std::string& address = "", const std::string& occupation = "");

	//sets
	void setName(const std::string& name);
	void setOwner(const std::string& owner);
	void setNumber(const std::string& number);
	void setAddress(const std::string& address);
	void setOccupation(const std::string& occupation);

	//gets
	const std::string& getName() const;
	const std::string& getOwner() const;
	const std::string& getNumber() const;
	const std::string& getAddress() const;
	const std::string& getOccupation() const;

	friend bool operator==(const Firm& firm_1, const Firm& firm_2);
	friend bool operator!=(const Firm& firm_1, const Firm& firm_2);

	friend std::ostream& operator<<(std::ostream& out, const Firm& firm);
};

