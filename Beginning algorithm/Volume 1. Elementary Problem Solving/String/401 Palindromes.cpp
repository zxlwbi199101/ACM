#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<char,char> mirrorDictionary;
	mirrorDictionary['A']='A';
	mirrorDictionary['E']='3';
	mirrorDictionary['H']='H';
	mirrorDictionary['I']='I';
	mirrorDictionary['J']='L';
	mirrorDictionary['L']='J';
	mirrorDictionary['M']='M';
	mirrorDictionary['O']='O';
	mirrorDictionary['S']='2';
	mirrorDictionary['T']='T';
	mirrorDictionary['U']='U';
	mirrorDictionary['V']='V';
	mirrorDictionary['X']='X';
	mirrorDictionary['Y']='Y';
	mirrorDictionary['Z']='5';
	mirrorDictionary['1']='1';
	mirrorDictionary['2']='S';
	mirrorDictionary['3']='E';
	mirrorDictionary['5']='Z';
	mirrorDictionary['8']='8';

	string outputs[4]={" -- is not a palindrome." ," -- is a regular palindrome." ," -- is a mirrored string." ," -- is a mirrored palindrome."};

	string words;
	while(cin>>words)
	{
		int palindrome=1,mirrored=2;
		for(int i=0;i<(words.size()+1)/2;i++)
		{
			if(palindrome && words[i]!=words[words.size()-i-1])
				palindrome=0;
			if(mirrored && mirrorDictionary[words[i]]!=words[words.size()-i-1])
				mirrored=0;
		}
		cout<<words<<outputs[palindrome+mirrored]<<endl<<endl;

	}

	int program_end;
	cin>>program_end;
	return 0;
}