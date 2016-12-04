#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	double x1, y1, x2, y2;
	double cx, cy;
	while (cin >> x1 >> y1 >> x2 >> y2)
	{
		if (x1 == x2 && y1 == y2)
		{
			cout << "Impossible." << endl;
			continue;
		}

		cx = (x1 + x2) / 2;
		cy = (y1 + y2) / 2;

		x1 -= cx;
		y1 -= cy;

		cout << setprecision(10) << setiosflags(ios::fixed | ios::showpoint) 
			<< cx + y1 << " " << cy - x1 << " " << cx - y1 << " " << cy + x1 << endl;
	}

	system("pause");
	return 0;
}

