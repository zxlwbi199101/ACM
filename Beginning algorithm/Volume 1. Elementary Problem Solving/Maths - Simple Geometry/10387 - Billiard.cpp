#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double a, b, s, m, n;
	while (cin >> a >> b >> s >> m >> n && (a != 0 && b != 0 && s != 0 && m != 0 && n != 0))
	{
		double A = atan((b * n) / (a * m)) * 180 / acos(-1.0);
		cout << setprecision(2) << setiosflags(ios::fixed) << A << " " << sqrt(a * m * a * m  + b * n * b * n) / s << endl;
	}

	system("pause");
	return 0;
}