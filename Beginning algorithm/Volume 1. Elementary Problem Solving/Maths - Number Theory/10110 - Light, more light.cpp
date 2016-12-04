#include <string>
#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	for ( long bulbs; cin >> bulbs && bulbs != 0; )
	{
		double nums = sqrt ( bulbs * 1.0 );
		if ( nums - ( int ) nums == 0 )
		{
			cout << "yes" << endl;
		}
		else cout << "no" << endl;
	}

	system ( "pause" );
	return 0;
}
/*
	bulbs = 3 时 1 3 => 开 关
	bulbs = 4 时 1 2 4 => 开 关 开
	因此在bulbs为完全平方数的时候 为开着
*/