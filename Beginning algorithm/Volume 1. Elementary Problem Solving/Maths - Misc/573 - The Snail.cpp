#include <iostream>
#include <string>

using namespace std;

int main()
{
	int h , u , d , f;
	while ( 1 )
	{
		cin >> h >> u >> d >> f;
		if( h == 0 ) break;

		double speed = u * 1.0;
		double climbed = 0;
		int days = 1;
		for ( ; ; days++ )
		{
			climbed += speed;
			if ( climbed > h )
			{
				cout << "success on day " << days << endl;
				break;
			}
			climbed -= d;
			if ( climbed < 0 )
			{
				cout << "failure on day " << days << endl;
				break;
			}

			double sub = (f / 100.0) * u;
			if ( speed - sub < 0 ) speed = 0;
			else speed -= sub;
		}
	}

	system ( "pause" );
	return 0;
}