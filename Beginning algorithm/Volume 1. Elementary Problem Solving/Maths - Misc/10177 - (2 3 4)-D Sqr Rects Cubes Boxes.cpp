#include <string>
#include <iostream>

using namespace std;
int main()
{
	int n;
	while ( cin >> n )
	{
		unsigned long s2 = 0 , s3 = 0 , s4 = 0 , r2 = 0 , r3 = 0 , r4 = 0;
		for ( int i = 1; i <= n; i++ )
		{
			s2 += i * i;
			s3 += i * i * i;
			s4 += i * i * i * i;
		}
		unsigned long all = n * (n  + 1 ) / 2;
		r2 = all * all - s2;
		r3 = all * all * all - s3;
		r4 = all * all * all * all - s4;

		cout << s2 << ' ' << r2 << ' ' << s3 << ' ' << r3 << ' ' << s4 << ' ' << r4 <<endl;
	}

	system ( "pause" );
	return 0;
}
