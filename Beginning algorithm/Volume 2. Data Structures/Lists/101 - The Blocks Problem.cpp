#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Pile
{
public:
	void MoveOnto (vector<int> value, int v)
	{
		vector<int>::iterator itr = findValue (v);
		for (vector<int>::iterator temp = itr + 1; temp != container.end(); temp++)
		{
			(*piles)[*temp].container.push_back (*temp);
		}
		container.erase (itr + 1, container.end());
		container.insert (itr + 1, value.begin(), value.end());
		
	}
	void MoveOver (vector<int> value)
	{
		for (int i = 0; i < value.size(); i++)
		{
			container.push_back (value[i]);
		}
	}
	vector<int> GetPile (int v)
	{
		vector<int> pile;
		vector<int>::iterator itr = findValue (v);
		for (vector<int>::iterator temp = itr ; temp != container.end(); temp++)
		{
			pile.push_back (*temp);
		}
		container.erase (itr, container.end());
		return pile;
	}
	vector<int> GetSingle (int v)
	{
		vector<int> pile;
		vector<int>::iterator itr = findValue (v);
		for (vector<int>::iterator temp = itr + 1; temp != container.end(); temp++)
		{
			(*piles)[*temp].container.push_back (*temp);
		}
		pile.push_back (*itr);
		container.erase (itr, container.end());

		return pile;
	}
	bool exists (int v)
	{
		return (findValue (v) != container.end());
	}	
	void Print ()
	{
		for (int i = 0; i < container.size(); i++)
		{
			cout << " " << container[i];
		}
	}
	Pile (int v, vector<Pile> * ps)
	{
		container.push_back (v);
		piles = ps;
	}
	vector<int> container;

private:
	vector<Pile> * piles;
	vector<int>::iterator findValue (int v)
	{
		return find (container.begin(), container.end(), v);
	}
};

int main ()
{
	int num;
	cin >> num;
	vector<Pile> piles;

	for (int i = 0; i < num; i++)
	{
		piles.push_back (Pile (i, & piles));
	}

	string cmd1, cmd2;
	int n1, n2, finder1 = -1, finder2 = -1;
	vector<int> toMove;
	while (cin >> cmd1 && cmd1 != "quit")
	{
		cin >> n1 >> cmd2 >> n2;
		for (int i = 0; i < num; i++)
		{
			if (piles[i].exists (n1)) finder1 = i;
			if (piles[i].exists (n2)) finder2 = i;
		}
		if (finder1 == -1 || finder2 == -1 || finder1 == finder2) continue;

		if (cmd1 == "move") toMove = piles[finder1].GetSingle (n1);
		if (cmd1 == "pile") toMove = piles[finder1].GetPile (n1);

		if (cmd2 == "onto") piles[finder2].MoveOnto (toMove, n2);
		if (cmd2 == "over") piles[finder2].MoveOver (toMove);

	}

	for (int i = 0; i < num; i++)
	{
		cout << i << ":";
		piles[i].Print();
		cout << endl;
	}

	system ("pause");
	return 0;
}