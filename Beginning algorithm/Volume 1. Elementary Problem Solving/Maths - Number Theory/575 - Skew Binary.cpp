#include <string>
#include <iostream>

using namespace std;
int main()
{
	string skew;
	while ( cin >> skew && skew != "0" )
	{
		int result = 0;
		for ( int i = 0; i < skew.size(); i++ )
		{
			result += ( skew [ i ] - '0' ) * ( ( 2 << ( skew.size() - i - 1 ) ) - 1 );
		}
		cout << result << endl;
	}

	system ( "pause" );
	return 0;
}
