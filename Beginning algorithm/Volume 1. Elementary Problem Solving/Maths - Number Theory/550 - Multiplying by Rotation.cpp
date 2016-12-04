#include <iostream>

using namespace std;

int main()
{
	int b , m , n;
	while ( cin >> b >> m >> n )
	{
		int result = m * n;
		int count = 1;

		while ( result != m )
		{
			result = result % b * n + result / b;
			count++;
		}
		cout << count << endl;
	}

	system ( "pause" );
	return 0;
}
