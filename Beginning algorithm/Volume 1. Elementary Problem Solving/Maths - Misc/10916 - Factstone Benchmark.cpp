#include <string>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int main()
{
	vector < int > maxs;

	double current = 0;
	double LOG2 = log ( 2.0 );
	for ( double i = 1; ; i++ )
	{
		current += log ( i ) / LOG2;
		for ( int j = 0; j < 21; j++ )
		{
			if ( maxs.size() <= j )
			{
				if ( current > pow ( 2.0 , j + 2 ) ) maxs.push_back ( i - 1 );
				break;
			}
		}
		if ( current > pow ( 2.0 , 23 ) ) break;
	}

	for ( int year = 0; cin >> year && year != 0; )
	{
		year = ( year - 1960 ) / 10;
		cout << maxs [ year ] << endl;
	}

	system ( "pause" );
	return 0;
}
