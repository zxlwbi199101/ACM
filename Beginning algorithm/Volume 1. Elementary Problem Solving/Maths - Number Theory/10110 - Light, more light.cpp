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
	bulbs = 3 ʱ 1 3 => �� ��
	bulbs = 4 ʱ 1 2 4 => �� �� ��
	�����bulbsΪ��ȫƽ������ʱ�� Ϊ����
*/