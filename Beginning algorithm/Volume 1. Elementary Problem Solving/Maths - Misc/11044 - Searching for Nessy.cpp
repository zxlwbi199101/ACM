#include <string>
#include <iostream>

using namespace std;
int main()
{
	int p ,q;
	int group;
	for ( cin >> group ; group > 0 ; group--)
	{
		cin >> p >> q;
		int x = ( p - 2 ) / 3 , y = ( q - 2 ) / 3;

		if ( ( p - 2 ) % 3 != 0 ) x++;
		if ( ( q - 2 ) % 3 != 0 ) y++;

		cout << x * y <<endl;
	}
	system ( "pause" );
	return 0;
}