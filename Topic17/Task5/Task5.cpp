#include <set>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

void display(const std::string & str);
void readFileToSet(std::set<std::string> & read, char * filename);
void printToFile(const std::string & str);
std::ofstream fout("matnpat.dat");

int main()
{
	std::set<std::string> MatList, PatList;
	readFileToSet(MatList, "mat.dat");
	std::cout << "Here is Mat list:\n";
	for_each(MatList.begin(),MatList.end(), display);
	readFileToSet(PatList, "pat.dat");
	std::cout << "Here is Pat list:\n";
	for_each(PatList.begin(),PatList.end(), display);
	std::set<std::string> CommonList;
	CommonList.insert(MatList.begin(),MatList.end());
	CommonList.insert(PatList.begin(),PatList.end());
	std::cout << "Here is a common Mat&Pat List:\n";
	for_each(CommonList.begin(),CommonList.end(), display);
	std::set<std::string>::const_iterator(CommonList.begin());
	for_each(CommonList.begin(),CommonList.end(), printToFile);
	fout.close();
	std::cin.get();
}

void display(const std::string & str)
{
	std::cout << str << std::endl;
}

void readFileToSet(std::set<std::string> & for_init, char * filename)
{
	std::ifstream fin;
	fin.open(filename);
	std::string tmp;
	while ( fin >> tmp )
	{
		for_init.insert(tmp);
	}
}

void printToFile(const std::string & str)
{
	fout << str << std::endl;
}