#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int count;
	cin >> count;
	cin.get();

	while (count--)
	{
		string p;
		getline(cin, p);
		if (p == "")
		{
			cout << "Yes" << endl;
			continue;
		}

		stack<char> st;
		bool isWrong = false;
		for (int i = 0; i < p.size(); i++)
		{
			if (p[i] == '(' || p[i] == '[')
			{
				st.push(p[i]);
			}
			else
			{
				if ((p[i] == ']' && (st.size() == 0 || st.top() != '[')) ||
					(p[i] == ')' && (st.size() == 0 || st.top() != '(')))
				{
					isWrong = true;
					break;
				}
				st.pop();
			}
		}
		if (!isWrong && st.size() == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}