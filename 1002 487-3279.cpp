/* 
    Description
Businesses like to have memorable telephone numbers. One way to make a telephone number memorable is to have it spell a memorable word or phrase. For example, you can call the University of Waterloo by dialing the memorable TUT-GLOP. Sometimes only part of the number is used to spell a word. When you get back to your hotel tonight you can order a pizza from Gino's by dialing 310-GINO. Another way to make a telephone number memorable is to group the digits in a memorable way. You could order your pizza from Pizza Hut by calling their ``three tens'' number 3-10-10-10.

The standard form of a telephone number is seven decimal digits with a hyphen between the third and fourth digits (e.g. 888-1200). The keypad of a phone supplies the mapping of letters to numbers, as follows:

A, B, and C map to 2
D, E, and F map to 3
G, H, and I map to 4
J, K, and L map to 5
M, N, and O map to 6
P, R, and S map to 7
T, U, and V map to 8
W, X, and Y map to 9

There is no mapping for Q or Z. Hyphens are not dialed, and can be added and removed as necessary. The standard form of TUT-GLOP is 888-4567, the standard form of 310-GINO is 310-4466, and the standard form of 3-10-10-10 is 310-1010.

Two telephone numbers are equivalent if they have the same standard form. (They dial the same number.)

Your company is compiling a directory of telephone numbers from local businesses. As part of the quality control process you want to check that no two (or more) businesses in the directory have the same telephone number.

Input
The input will consist of one case. The first line of the input specifies the number of telephone numbers in the directory (up to 100,000) as a positive integer alone on the line. The remaining lines list the telephone numbers in the directory, with each number alone on a line. Each telephone number consists of a string composed of decimal digits, uppercase letters (excluding Q and Z) and hyphens. Exactly seven of the characters in the string will be digits or letters.

Output
Generate a line of output for each telephone number that appears more than once in any form. The line should give the telephone number in standard form, followed by a space, followed by the number of times the telephone number appears in the directory. Arrange the output lines by telephone number in ascending lexicographical order. If there are no duplicates in the input print the line:

No duplicates.

Sample Input

12
4873279
ITS-EASY
888-4567
3-10-10-10
888-GLOP
TUT-GLOP
967-11-11
310-GINO
F101010
888-1200
-4-8-7-3-2-7-9-
487-3279

Sample Output

310-1010 2
487-3279 4
888-4567 3
*/



#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;
 
int main()
{
	int count;
	cin>>count;
			
	map<char,char> dictionary;
	dictionary['A']='2';
	dictionary['B']='2';
	dictionary['C']='2';
	dictionary['D']='3';
	dictionary['E']='3';
	dictionary['F']='3';
	dictionary['G']='4';
	dictionary['H']='4';
	dictionary['I']='4';
	dictionary['J']='5';
	dictionary['K']='5';
	dictionary['L']='5';
	dictionary['M']='6';
	dictionary['N']='6';
	dictionary['O']='6';
	dictionary['P']='7';
	dictionary['R']='7';
	dictionary['S']='7';
	dictionary['T']='8';
	dictionary['U']='8';
	dictionary['V']='8';
	dictionary['W']='9';
	dictionary['X']='9';
	dictionary['Y']='9';

	map<string,int> content;
	for(int i=0;i<count;i++)
	{
		string str,newstr;
		cin>>str;
		for(int j=0;j<str.size();j++)
		{
			char c=str[j];
			if(c>=48 && c<=57)
				newstr+=c;
			else if(c>=65 && c<=90 && dictionary.find(c)!=dictionary.end())
			{
				newstr+=dictionary[c];
			}
		}
		if(content.find(newstr)==content.end())
			content[newstr]=1;
		else content[newstr]+=1;
	}
	map<string,int>::iterator it;
	bool hasValue=false;
    for(it=content.begin();it!=content.end();++it)
	{
		if(it->second >1)
		{
			hasValue=true;
			string temp=it->first;
			temp.insert(3,"-");
			cout<<temp<<' '<<it->second<<endl;
		}
	}
	if(!hasValue)cout<<"No duplicates."<<endl;

	/*int program_end;
	cin>>program_end;*/
	return 0;
}