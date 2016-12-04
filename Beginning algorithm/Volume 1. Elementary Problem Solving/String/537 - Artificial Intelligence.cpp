#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
using namespace std;

int main()
{
	int groups;
	cin>>groups;
	cin.get(); 
	for(int g=1;g<=groups;g++)
	{
		double first=0,second=0;
		char concept1,concept2;
		cout<<"Problem #"<<g<<endl;

		string source;
		getline(cin,source);
		for(int i=0;i<source.size();i++)
		{
			if(i==0 || source[i]!='=') continue;
			if(source[i-1]=='U' || source[i-1]=='I' || source[i-1]=='P')
			{
				string numstr;
				for(int j=i+1;j<source.size();j++)
				{
					if((source[j]>=48 && source[j]<=57) || source[j]==46)
					{
						numstr+=source[j];
					}
					else
					{
						double current;
						stringstream ss(numstr);
						ss>>current;
							
						if(source[j]=='m') current/=1000;
						if(source[j]=='k') current*=1000;
						if(source[j]=='M') current*=1000000;

						if(first==0)
						{
							concept1=source[i-1];
							first=current;
						}
						else 
						{
							concept2=source[i-1];
							second=current;
						}
						break;
						i=j+1;
					}//convert number end
				}//for number end
					
			}//if concept end
		}//for string end

		if((concept1=='U' && concept2=='I') || (concept1=='I' && concept2=='U'))
		{
			printf("P=%.2fW\n\n", first*second);//cout<<"P="<<setprecision(2)<<first*second<<"W"<<endl;
		}
		if(concept1=='P' && concept2=='U') printf("I=%.2fA\n\n", first/second);//cout<<"I="<<setprecision(2)<<first/second<<"A"<<endl;
		if(concept1=='P' && concept2=='I') printf("U=%.2fV\n\n", first/second);//cout<<"U="<<setprecision(2)<<first/second<<"V"<<endl;
		if(concept1=='U' && concept2=='P') printf("I=%.2fA\n\n", second/first);//cout<<"I="<<setprecision(2)<<second/first<<"A"<<endl;
		if(concept1=='I' && concept2=='P') printf("U=%.2fV\n\n", second/first);//cout<<"U="<<setprecision(2)<<second/first<<"V"<<endl;
		

	}//for group end
	
	int program_end;
	cin>>program_end;
	return 0;
}

