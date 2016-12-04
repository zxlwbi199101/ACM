#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;

int main ()
{
	int n, k, m;
	bool list[20];
	while (cin >> n >> k >> m && n != 0)
	{
		memset (list, true, sizeof(bool) * 20);
		for (int a = 0, b = n - 1, remain = n; remain > 0; )
		{
			for (int counter1 = list[a], counter2 = list[b]; counter1 < k || counter2 < m; )
			{
				if (counter1 < k && ++a >= n) a = 0;
				if (counter2 < m && --b < 0) b = n - 1;
				if (list[a] && counter1 < k) counter1++;
				if (list[b] && counter2 < m) counter2++;
			}
			
			list[a] = list[b] = false;
			cout << setiosflags (ios::right) << setw (3) << (a + 1);
			remain--;

			if (a != b)
			{
				cout << setiosflags (ios::right) << setw (3) << (b + 1);
				remain--;
			}

			if (remain != 0) cout << ",";
		}
		cout << endl;
	}

	system ("pause");
	return 0;
}
