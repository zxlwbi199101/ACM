#include <iostream>
#include <iomanip>

using namespace std;

const int COUNT = 10000;

int main()
{
	int results [ COUNT ];
	results [ 0 ] = results [ 1 ] = 1;

	int last = 1;
	for ( int i = 2; i <= COUNT; i++ )
	{
		last *= i;
		while ( last % 10 == 0 ) last /= 10;
		last %= ( 10 * COUNT );

		results [ i ] = last % 10;
	}
	
	for ( int number; cin >> number; )
	{
		cout << setiosflags ( ios::right ) << setw ( 5 ) << number << " -> ";
		cout << results [ number ] << endl;
	}

	system ( "pause" );
	return 0;
}
