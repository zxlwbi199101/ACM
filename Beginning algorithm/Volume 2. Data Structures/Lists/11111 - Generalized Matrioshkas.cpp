#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

class Matrioshkas
{
public:
	long Capacity;
	long Content;
	Matrioshkas (long c)
	{
		Content = 0;
		Capacity = c;		
	}
	bool Add (long c)
	{
		Content += c;
		return Content < Capacity;
	}
};

int main()
{
	string line;
	while (getline(cin, line))
	{
		stringstream stream;
		stream << line;

		stack<Matrioshkas> stk;
		long temp;
		bool wrong = false;
		while (stream >> temp)
		{
			if (temp < 0) stk.push(Matrioshkas(-temp));
			else if (stk.size() > 0 && stk.top().Capacity == temp)
			{
				stk.pop();
				if (stk.size() > 0)
				{
					if (!stk.top().Add(temp))
					{
						wrong = true;
						break;
					}
				}
			}
			else
			{
				wrong = true;
				break;
			}
		}
		if (wrong || stk.size() != 0) cout << ":-( Try again." << endl;
		else cout << ":-) Matrioshka!" << endl;
	}
	return 0;
}