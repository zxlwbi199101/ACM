#include <string>
#include <iostream>

using namespace std;
int main()
{
	unsigned long p ,q;
	int group = 1;
	for ( ; ; group++)
	{
		cin >> p >> q;
		if ( p == 0 ) break;
		if ( p == 1 || q == 1 )
		{
			cout << "Case " << group << ": 0" << endl;
			continue;
		}

		cout << "Case " << group << ": " << ( p - 1 ) * ( q - 1 ) * p * q / 4 << endl;
	}

	system ( "pause" );
	return 0;
}
/*
	设上下各有m,n各点
	四个顶点一个交点
	上面任意取两个的取法是(m(m-1))/2
	下面是(n(n-1))/2

	公式推导成功
*/