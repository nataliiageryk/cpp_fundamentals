#include <iostream>
#include <string>

using namespace std;

int main(){
	string word;
	int word_count = 0;
	cout<<"Enter words (to stop, type the word done):\n";
	cin>>word;
	while(word!="done")
	{
		cin.get();
		word_count++;
		
		cout<<word<<endl;
		cin>>word;
	};

	//delete allreniming words from input queue
	string *ignore =  new string;
	getline(cin,*ignore);
	delete ignore;

	cout<<"You entered a total of "<<word_count<<" words.";
	cin.get();

	return 0;
}