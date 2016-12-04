#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Dimention
{
public:
	int d1;
	int d2;

	Dimention (int a, int b)
	{
		d1 = a;
		d2 = b;
	}
	Dimention Multi (Dimention second, int & sum)
	{
		if (d2 != second.d1)
			return Dimention(-1, -1);

		sum += d1 * d2 * second.d2;
		return Dimention(d1, second.d2);
	}
};

int main()
{
	int count;
	cin >> count;

	int s1[26], s2[26];
	while (count--)
	{
		char matrix;
		cin >> matrix;
		cin >> s1[matrix - 'A'] >> s2[matrix - 'A'];
	}

	string exp;
	while (cin >> exp)
	{
		if (exp[0] != '(')
		{
			cout << "0" << endl;
			continue;
		}

		stack<Dimention> stk;
		bool wrong = false;
		int sum = 0;
		for (int i = 0; i<exp.size(); i++)
		{
			if (exp[i] == ')')
			{
				Dimention second = stk.top();
				stk.pop();
				Dimention first = stk.top();
				stk.pop();
				
				Dimention result = first.Multi(second, sum);
				if (result.d1 < 0)
				{
					wrong = true;
					break;
				}
				stk.push(result);
			}
			else if (exp[i] != '(')
			{
				stk.push(Dimention(s1[exp[i] - 'A'], s2[exp[i] - 'A']));
			}
		}

		if (wrong)
		{
			cout << "error" << endl;
		}
		else
		{
			cout << sum << endl;
		}
		
	}
	return 0;
}