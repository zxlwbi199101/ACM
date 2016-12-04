#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

string toLowerCase(string str);
struct team
{
	string name;
	int wins,ties,losses,scored,against;
	team()
	{
		wins=ties=losses=scored=against=0;
	}
	int points() const
	{
		return wins*3+ties;
	}
	int played() const
	{
		return wins+ties+losses;
	}
	int difference() const
	{
		return scored-against;
	}
};

bool compare(team * a, team * b)
{
	if(a->points()!=b->points()) return a->points() < b->points();
	if(a->wins!=b->wins) return a->wins<b->wins;
	if(a->difference()!=b->difference()) return a->difference()<b->difference();
	if(a->scored!=b->scored) return a->scored<b->scored;
	if(a->played()!=b->played()) return a->played()>b->played(); //less game played
	return toLowerCase(a->name)>toLowerCase(b->name); //name sort reserve
}


int main()
{
	short groups;
	cin>>groups;
	cin.get();
	for(int g=0;g<groups;g++)
	{
		string tournament;
		getline(cin,tournament);
		cout<<tournament<<endl;

		vector<team*> teams;
		short team_count;
		cin>>team_count;
		cin.get();
		for(int t=0;t<team_count;t++)
		{
			string team_name;
			getline(cin,team_name);

			team *tm=new team;
			tm->name=team_name;
			teams.push_back(tm);
		}

		short played;
		cin>>played;
		cin.get();

		string p1,p2;
		short score1,score2;
		for(int p=0;p<played;p++)
		{
			string game;
			getline(cin,game);

			int sharp1=game.find('#');
			int sharp2=game.rfind('#');
			int mid=game.find('@');

			p1=game.substr(0,sharp1);
			p2=game.substr(sharp2+1);
			
			istringstream iss(game.substr(sharp1+1,mid-sharp1-1));
			iss>>score1;
			
			istringstream iss1(game.substr(mid+1,sharp2-mid-1));
			iss1>>score2;

			team* t1;
			team* t2;
			for(int i=0;i<teams.size();i++)
			{
				if(teams[i]->name==p1) t1=teams[i];
				if(teams[i]->name==p2) t2=teams[i];
			}
			if(score1>score2)
			{
				t1->wins++;
				t2->losses++;
			}
			if(score1==score2)
			{
				t1->ties++;
				t2->ties++;
			}
			if(score1<score2)
			{
				t1->losses++;
				t2->wins++;
			}
			t1->scored+=score1;
			t1->against+=score2;
			t2->scored+=score2;
			t2->against+=score1;
		}

		short counter=1;
		for(int i=0;i<teams.size();i++)
		{
			for(int j=i+1;j<teams.size();j++)
			{
				if(compare(teams[i],teams[j]))
				{
					team *temp=teams[i];
					teams[i]=teams[j];
					teams[j]=temp;
				}
			}
			cout<<(counter++)<<") "<<teams[i]->name<<" "<<teams[i]->points()<<"p, "
				<<teams[i]->played()<<"g ("
				<<teams[i]->wins<<"-"<<teams[i]->ties<<"-"<<teams[i]->losses<<"), "
				<<teams[i]->difference()<<"gd ("<<teams[i]->scored<<'-'<<teams[i]->against<<')'<<endl;
			delete teams[i];

		}
		if(g!=groups-1) cout<<endl;
	}

	system("pause");
	return 0;
}

string toLowerCase(string str)
{
    for (unsigned int i = 0; i < str.length(); ++i)
        if (str[i] >= 'A' && str[i] <= 'Z')
             str[i] += ('a' - 'A');
	return str;
}