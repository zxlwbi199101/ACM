#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	int keywords_count,excuses_count;
	int groups=1;
	while(cin>>keywords_count>>excuses_count)
	{
		cout<<"Excuse Set #"<<groups++<<endl;

		 set<string> keywords;
		 for(int k=0;k<keywords_count;k++)
		 {
			 string str;
			 cin>>str;
			 keywords.insert(str);
		 }

		 cin.get();
		 string excuses[20];
		 int appearances[20];
		 for (int e=0;e<excuses_count;e++)
		 {
			 string str;
			 getline(cin,str);

			 bool Inword=false;
			 string word;
			 int appearance=0;
			 for(int i=0;i<str.size();i++)
			 {
				 if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
				 {
					 if(Inword)
					 {
						 if(str[i]>= 'A' && str[i] <= 'Z')
							word+=str[i]+('a' - 'A');
						 else word+=str[i];
					 }
					 else
					 {
						 Inword=true;
						 if(str[i]>= 'A' && str[i] <= 'Z')
							word=str[i]+('a' - 'A');
						 else word=str[i];
					 }
				 }
				 else
				 {
					 if(Inword)
					 {
						Inword=false;
						if(keywords.find(word)!=keywords.end()) appearance++;
					 }
				 }
			 }//for excuse string end
			 excuses[e]=str;
			 appearances[e]=appearance;
		 }//for excuses end

		 int max=0;
		 for(int e=0;e<excuses_count;e++)
		 {
			 if(appearances[e]>=max)
			 {
				 max=appearances[e];
			 }
		 }
		 for(int e=0;e<excuses_count;e++)
		 {
			 if(appearances[e]==max)
				 cout<<excuses[e]<<endl;
		 }

		 cout<<endl;
	}//while group end

	int program_end;
	cin>>program_end;
	return 0;
}
