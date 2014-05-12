#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

void display(const std::string & str);
void inputSet(std::set<std::string> & list);

int main()
{
std::set<std::string> PatList, MatList;
cout << "Input Pat List: \n";
inputSet(PatList);
cout << "Show Pat List:\n";
for_each(PatList.begin(), PatList.end(), display);
cout << "Input Mat List: \n";
inputSet(MatList);
cout << "Show Mat List:\n";
for_each(MatList.begin(), MatList.end(), display);
std::set<std::string> CommonList;
std::vector<std::string> com(PatList.size() + MatList.size());
std::set<std::string>::iterator com_list_iterator = CommonList.begin();
//std::merge
std::vector<std::string>::iterator it;
it = std::set_union(MatList.begin(), MatList.end(), PatList.begin(), PatList.end(), com.begin());
//CommonList.insert(MatList.begin(),MatList.end());
//CommonList.insert(PatList.begin(),PatList.end());
for_each(CommonList.begin(), CommonList.end(), display);
cin.get();
return 0;
}

void display(const std::string & str)
{
	cout << str << ",  ";
}

void inputSet(std::set<std::string> & list)
{
	cout << "Enter name which you want to add to the list list (q to finish and show)";
	std::string tmp;
	char delim = '\n';
	getline(cin, tmp, delim);

while (tmp != "q" && tmp != " q" && tmp != "q ")
{
	list.insert(tmp);
	cout << tmp <<" added!\n";
	getline(cin,tmp, delim);
}
}