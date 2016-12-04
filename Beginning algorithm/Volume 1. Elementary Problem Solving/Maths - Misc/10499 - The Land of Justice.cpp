#include <iostream>
#include <string>

using namespace std;
int main()
{
	long part;
	while ( cin >> part )
	{
		if ( part < 0 ) break;
		if ( part <= 1 )
		{
			cout << "0%" << endl;
			continue;
		}
		cout << ( long ) ( part * 25 ) << "%" << endl;
	}

	system ( "pause" );
	return 0;
}