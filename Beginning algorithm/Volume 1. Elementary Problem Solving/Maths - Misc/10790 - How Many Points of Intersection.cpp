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
	�����¸���m,n����
	�ĸ�����һ������
	��������ȡ������ȡ����(m(m-1))/2
	������(n(n-1))/2

	��ʽ�Ƶ��ɹ�
*/