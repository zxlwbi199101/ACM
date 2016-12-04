#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double PI = acos(-1.0);
	int count;
	cin >> count;

	double height, width, radiu, sum;
	for ( ; count > 0 && cin >> width >> height; count--)
	{
		sum = 0;
		width /= 2.0;
		double tan_alpha = height / width;
		double tan_half_alpha = tan(atan(tan_alpha) / 2);		

		for (; ;)
		{
			radiu = tan_half_alpha * width;
			if (radiu < 0.000001) break;

			sum += 2 * PI * radiu;
			height -= radiu * 2;
			width = height / tan_alpha;
		}
		cout << setw(13) << setprecision(6) << setiosflags(ios::fixed) << sum << endl;

		if (count != 1) cout << endl;
	}
	system("pause");
	return 0;
}