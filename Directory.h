#pragma once
#include"SLinkedList.h"
#include"Firm.h"
#include <fstream>
#include<string>

using Firms = SLinkedList<Firm>;

class Directory
{
private:
	Firms firms;

public:
	Directory() = default;

	void addFirm(const Firm& firm);
	void removeFirm(const std::string& name);
	void print() const;

	Firms findByName(const std::string& name) const;
	Firms findByOwner(const std::string& owner) const;
	Firms findByNumber(const std::string& number) const;
	Firms findByOccupation(const std::string& occupation) const;

	void save(const std::string& path) const;
	void load(const std::string& path);
};



