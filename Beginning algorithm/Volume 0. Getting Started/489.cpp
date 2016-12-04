
#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
	int round;
	while(cin>>round && round!=-1)
	{
		cout<<"Round "<<round<<endl;

		string puzzle,guess;
		cin>>puzzle>>guess;

		set<char> puzzle_set;
		for(int i=0;i<puzzle.size();i++)
		{
			puzzle_set.insert(puzzle[i]);
		}

		int stroke=0;
		for(int i=0;i<guess.size();i++)
		{
			if(puzzle_set.find(guess[i])!=puzzle_set.end())
			{
				puzzle_set.erase(guess[i]);
			}
			else
			{
				stroke++;
			}
			if(stroke==7)
			{
				cout<<"You lose."<<endl;
				break;
			}
			if(puzzle_set.empty())
			{
				cout<<"You win."<<endl;
				break;
			}
			if(i==guess.size()-1)
				cout<<"You chickened out."<<endl;
		}
	}
	
	int program_end;
	cin>>program_end;
	return 0;
}