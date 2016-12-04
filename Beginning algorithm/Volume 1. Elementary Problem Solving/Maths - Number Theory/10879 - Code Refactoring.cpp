#include <iostream>

using namespace std;

int main()
{
	int count = 0,
		k = 0,
		index = 0;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		cin >> k;
		cout << "Case #" << i + 1 << ": " << k;
		index = 0;

		for (int j = 2; j < sqrt(k); j++)
		{
			if (k % j == 0)
			{
				cout << " = " << j << " * " << k / j;
				if (++index == 2) break;
			}
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

