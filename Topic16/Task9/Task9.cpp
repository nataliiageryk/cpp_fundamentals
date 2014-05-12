//Create a large vector<int> object vi0, using rand() to provide initial values.
//b. Create a second vector<int> object vi and a list<int> object li of the same size as the original and initialize them to values in the original vector.
//c. Time how long the program takes to sort vi using the STL sort() algorithm, then time how long it takes to sort li using the list sort() method.
//d. Reset li to the unsorted contents of vi0.Time the combined operation of copying li to vi, sorting vi, and copying the result back to li.
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
inline int random_value() {return rand()%INT_MAX;}
void display(const int & val);
static const int SIZE = 300;

int main()
{
	srand(time(NULL));
	vector<int> vi0(SIZE);
	generate_n(vi0.begin(),SIZE,random_value);
	for_each(vi0.begin(), vi0.end(), display);
	cout << endl;
	vector<int> vi(vi0);
	list<int> li(vi0.begin(),vi0.end());
	double time_vector_sort = 0, time_list_sort = 0, time_list_byvector_sort = 0;
	for_each(vi.begin(), vi.end(), display);
	cout << endl;
	for_each(li.begin(), li.end(), display);
	cout << endl;
	clock_t start = clock();
	sort(vi.begin(),vi.end());
	clock_t end = clock();
	time_vector_sort = end - start;
	for_each(vi.begin(), vi.end(), display);
	cout << start << " " << end << " time " << time_vector_sort << endl;
	cout << "Time for vector sorting: " << time_vector_sort << endl;
	start = clock();
//	sort(li.begin(), li.end());
	li.sort();
	end = clock();
	time_list_sort = end - start;
	cout << "Time for list sorting: " << time_list_sort << endl;
	li.assign(vi0.begin(),vi0.end());
	start = clock();
	vi.assign(li.begin(),li.end());
	sort(vi.begin(),vi.end());
	li.assign(vi.begin(),vi.end());
	end = clock();
	time_list_byvector_sort = end - start;
	for_each(li.begin(), li.end(), display);
	cout << "\nTime for list(by vector) sorting: " << time_list_byvector_sort << endl;
	cout << endl;
	cin.get();
}

void display(const int & val)
{
	cout << val << " ";
}