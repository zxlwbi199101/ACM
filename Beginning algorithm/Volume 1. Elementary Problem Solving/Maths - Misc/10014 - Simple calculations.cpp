#include <string>
#include <iostream>
#include<iomanip>

using namespace std;
int main()
{
	int group;
	cin >> group;

	double c_array [3000];
	for ( int n; group > 0; group-- )
	{
		double a0;
		double amax;

		cin >> n >> a0 >> amax;
		for ( int i = 0; i < n; i++ )
		{
			cin >> c_array [i];
		}

		double Csum = 0;
		for ( int i = n; i > 0; i-- )
		{
			Csum += 2 * i * c_array [ n - i ];
		}
		double result = ( n * a0 + amax - Csum ) / ( n + 1 );
		cout << setiosflags ( ios::fixed ) << setprecision ( 2 ) << result <<endl; 
		if ( group != 1 ) cout << endl;
	}
	system ( "pause" );
	return 0;
}

/*
	根据公式：
	2 * A1 = A0 + A2 - 2 * C1;
	2 * A2 = A1 + A3 - 2 * C2;
	......
	2 * An = An-1 + An+1 - 2 * Cn;
--------------------------------
 +	A1 + An   = A0 + An+1 - 2 * ( C1 + ... + Cn )
	A1 + An-1 = A0 + An   - 2 * ( C1 + ... + Cn-1 )
	......
	A1 + A2   = A0 + A3   - 2 * ( C1 + C2 )
	A1 + A1   = A0 + A2   - 2 * C1;
-----------------------------------------------------
 +  ( n + 1 ) * A1 = n * A0 + An+1 - ( 2 * n * C1 ) - ( 2 * ( n - 1 ） * C2 ) - ... - ( 2 * Cn )
	
	结束
*/