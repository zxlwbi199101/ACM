#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
 
int main()
{
	const string vowel_ori="AUEOI";
	const string consonant_ori="JSBKTCLDMVNWFXGPYHQZR";
	string vowel,consonant;
	for(int i=0;i<vowel_ori.size();i++)
		for(int j=0;j<21;j++) vowel+=vowel_ori[i];
	for(int i=0;i<consonant_ori.size();i++)
		for(int j=0;j<5;j++) consonant+=consonant_ori[i];

	int groups;
	cin>>groups;
	for(int g=1;g<=groups;g++)
	{
		int count;
		cin>>count;

		string odd=vowel.substr(0,(count+1)/2 );
		string even=consonant.substr(0,count/2 );
		sort(odd.begin(),odd.end());
		sort(even.begin(),even.end());

		cout<<"Case "<<g<<": ";
		for(int i=0;i<odd.size();i++)
		{
			cout<<odd[i];
			if(i!=even.size()) cout<<even[i];
		}
		cout<<endl;
	}

	system("pause");
	return 0;
}