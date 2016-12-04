#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int Culculate ( int length );

int main()
{
	int groups;
	cin >> groups;
	for ( ; groups > 0 ; groups-- )
	{
		int start , end;
		cin >> start >> end;

		int sub = end - start;
		cout << Culculate ( sub ) << endl;
	}

	system ( "pause" );
	return 0;
}

int Culculate ( int sub )
{
	if ( sub <= 3 ) return sub;

	int b = ( int ) sqrt ( sub * 1.0 );
	int product = b * b;

	if ( sub == product ) return ( b << 1 ) - 1;

	int steps = ( b << 1 ) - 1;
	int left = sub - product;
	for ( ; left != 0 ; b-- )
	{
		steps += left / b;
		left = left % b;
		if ( left == 1 ) return steps + 1;
	}
	return steps;
}