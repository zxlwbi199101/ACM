#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Card
{
public:
	Card (string v)
	{
		rank = v[0];
		suit = v[1];
	}
	char rank;
	char suit;
	bool operator== (Card c)
	{
		return c.rank == rank || c.suit == suit;
	}
};

void InterateFront (vector<stack<Card> > & lists, int index)
{
	for (int j = index; j < lists.size(); j++)
	{
		int finder = -1;
		for (int i = j; i >= 0; i--)
		{
			if (i >= 3 && lists[i - 3].top() == lists[i].top())
			{
				i -= 2;
				finder = i - 1;
				continue;
			}
			if (i >= 1 && lists[i - 1].top() == lists[i].top())
			{
				finder = i - 1;
				continue;
			}
			break;
		}

		if (finder != -1)
		{
			lists[finder].push (lists[j].top());
			lists[j].pop();

			if (lists[j].empty())
			{
				lists.erase (lists.begin() + j);
			}

			j = finder - 1;
		}
	}
}

int main ()
{
	string value;
	vector<stack<Card> > lists;
	for (int i = 0; cin >> value && value != "#"; i++)
	{
		stack<Card> s;
		s.push (Card (value));
		lists.push_back(s);

		InterateFront (lists, lists.size() - 1);

		if (i == 51)
		{
			i = -1;
			cout << lists.size() << " pile" << (lists.size() > 1 ? "s" : "") << " remaining:";
			for (int j = 0; j < lists.size(); j++)
			{
				cout << " " << lists[j].size();				
			}
			cout << endl;

			lists.clear();
		}
	}

	system ("pause");
	return 0;
}

