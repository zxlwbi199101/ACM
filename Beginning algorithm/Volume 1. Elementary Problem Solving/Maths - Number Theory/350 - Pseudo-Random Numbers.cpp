#include <iostream>

using namespace std;

const int MAX = 10000;
int main ()
{
	bool results [ MAX ];
	for ( int group = 1; ; group++ )
	{
		int z , seed , i , m , count = 0;
		cin >> z >> i >> m >> seed;
		if ( z == 0 && i == 0 ) break;

		for ( int p = 0; p < MAX; p++ ) results [ p ] = false;

		for ( ; ; )
		{
			int r = ( z * seed + i ) % m;
			if ( results [ r ] ) break;

			results [ r ] = true;
			seed = r;
			count++;
		}

		cout << "Case " << group << ": " << count << endl;
	}
	system ( "pause" );
	return 0;
}