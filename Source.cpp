#include"Directory.h"

int main()
{
	Directory d;

	try
	{
		d.load("55.txt");
		d.print();
	}
	catch (std::exception& exp)
	{
		std::cout << exp.what();
	}
}