#include <string>
#include <iostream>
#include <sstream>

using namespace std;
int main()
{
	int k , n;

	for ( string nums ; cin >> k ; )
	{
		cin.get();
		getline ( cin , nums );

		istringstream iss ( nums );
		int last = 0;
		bool IsStart = false;

		cout << "q(x):";
		for ( int i , count = 0; iss >> i; count++ )
		{
			if ( IsStart ) cout << ' ' << last;
			else IsStart = true;

			last = i + k * last;
		}
		if ( nums.find ( ' ' ) == nums.npos ) cout << " 0";
		cout << endl << "r = " << last << endl << endl;
	}
	system ( "pause" );
	return 0;
}