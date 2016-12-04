#include <iostream>
#include <iomanip>

using namespace std;

int gcd ( int a , int b )
{
	if ( a == b ) return a;
	if ( a == 1 || b == 1 ) return 1;

	if ( a < b )
	{
		int temp = a;
		a = b;
		b = temp;
	}
	int mod = a % b;

	if ( mod == 0 ) return b;
	return gcd ( b , mod );
}

int main ()
{
	int step , mod;

	while ( cin >> step >> mod )
	{
		cout << setiosflags ( ios::right ) << setw ( 10 ) << step << setiosflags ( ios::right ) << setw ( 10 ) << mod << "    ";
		if ( gcd ( step , mod ) == 1 )
		{
			cout << "Good Choice";
		}
		else 
		{
			cout << "Bad Choice";
		}
		cout << endl << endl;
	}

	system ( "pause" );
	return 0;
}