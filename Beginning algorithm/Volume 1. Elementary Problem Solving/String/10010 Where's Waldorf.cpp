#include <iostream>
#include <string>
using namespace std;

void toLowerCase(string& str);
bool findWaldorf(string *str,int left,int top,string word,int posX,int posY);

int main()
{
	int groups;
	cin>>groups;
	for(int g=0;g<groups;g++)
	{
		unsigned int row=1,column;
		cin>>row>>column;

		string grid[21];
		for(unsigned int r=0;r<row;r++)
		{
			cin>>grid[r];
			toLowerCase(grid[r]);
		}

		int questions;
		cin>>questions;
		for(int q=0;q<questions;q++)
		{
			string word;
			cin>>word;
			toLowerCase(word);

			for(unsigned int r=0;r<row;r++)
			{
				bool hasOutput=false;
				for(unsigned int c=0;c<column;c++)
				{
					if(grid[r][c]!=word[0]) continue;
					bool left_e = (c>=word.size()),
						 top_e = r>=word.size(),
						 right_e = (column-c)>=word.size(),
						 bottom_e = (row-r)>=word.size();
					
					if(top_e && findWaldorf(&grid[0],0,1,word,c,r)) { hasOutput=true; break; }
					if(bottom_e && findWaldorf(&grid[0],0,-1,word,c,r)) { hasOutput=true; break; }
					if(left_e && findWaldorf(&grid[0],1,0,word,c,r)) { hasOutput=true; break; }
					if(right_e && findWaldorf(&grid[0],-1,0,word,c,r)) { hasOutput=true; break; }

					if(top_e && left_e && findWaldorf(&grid[0],1,1,word,c,r)) { hasOutput=true; break; }
					if(top_e && right_e && findWaldorf(&grid[0],-1,1,word,c,r)) { hasOutput=true; break; }
					if(bottom_e && left_e && findWaldorf(&grid[0],1,-1,word,c,r)) { hasOutput=true; break; }
					if(bottom_e && right_e && findWaldorf(&grid[0],-1,-1,word,c,r)) { hasOutput=true; break; }
				}//for column end
				if(hasOutput) break;
			}//for row end
			//cout<<endl;
		}
		if(g!=groups-1) cout<<endl;
	}

	int program_end;
	cin>>program_end;
	return 0;
}


void toLowerCase(string& str)
{
    for (unsigned int i = 0; i < str.length(); ++i)
        if (str[i] >= 'A' && str[i] <= 'Z')
             str[i] += ('a' - 'A');
}
bool findWaldorf(string *str,int left,int top,string word,int posX,int posY)
{
	int ori_x=posX,ori_y=posY;
	for(unsigned int i=1;i<word.size();i++)
	{
		if(str[posY-top][posX-left]!=word[i]) return false;
		if(i==word.size()-1) 
		{
			cout<<ori_y+1<<' '<<ori_x+1<<endl;
			return true;
		}
		posY-=top;
		posX-=left;
	}
	return false;
}