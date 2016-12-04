#include <math.h>
#include <iostream>

#define N 1000000

using namespace std;
bool Primes[N / 2] = {false};

long long factor_step(long long num)
{
	if (num % 2 == 0)
	{
		cout << "    2" << endl;
		return num >> 1;
	}
	for (int i = 1; i < N / 2 && i < sqrt(num); i += 1)
	{
		if (i >= sqrt(num))
		{
			break;
		}
		if (!Primes[i] && num % (i * 2 + 1) == 0)
		{
			cout << "    " << i * 2 + 1 << endl;
			return num / (i * 2 + 1);
		}
	}
	cout << "    " << num << endl;
	return num;
}

int main()
{
	long long num = 0;
	
	for (int i = 3; i < N; i += 2)
	{	
		if(Primes[(i - 1) / 2]) continue;

		for (long long j = i; j < N; )
		{
			j += j + j;
			if (j >= N) break;

			Primes[(j - 1) / 2] = true;
		}
	}

	while (cin >> num && num > 0)
	{
		while (true)
		{
			long long temp = factor_step(num);
			if (temp == num || temp == 1) break;
			else num = temp;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

