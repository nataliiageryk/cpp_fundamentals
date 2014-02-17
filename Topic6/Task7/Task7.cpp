#include <iostream>
#include <cctype>

using namespace std;

int main()
{
	int count_other = 0, count_vowel = 0, count_consonant = 0;
	
	const char * ch = "q";
	cout<<"Enter words (q to quit):\n";
	char word[30];  
	cin>>(word);
	cout<<word<<endl;
	while (strcmp(word,ch))
	{
		if(isalpha(word[0]))
		{
			switch(word[0])
			{
			case 'a':
			case 'A':
			case 'e':
			case 'E':
			case 'y':
			case 'Y':
			case 'u':
			case 'U':
			case 'i':
			case 'I':
			case 'o':
			case 'O': count_vowel++; break;
			default: count_consonant++; break;
			}
		}
		else count_other++;
		cin>>word;
	}
	cout<<count_vowel<<" words begin with vowels.\n";
	cout<<count_consonant<<" words begin with consonants. \n";
	cout<<count_other<<" others.\n";
cin.get();
cin.get();
return 0;
}