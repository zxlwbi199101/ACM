#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	string times;
	while (cin >> times && times != "0:00")
	{
		int commo = times.find_first_of(":");
		int hour, minutes;

		stringstream(times.substr(0, commo)) >> hour;
		stringstream(times.substr(commo + 1, 2)) >> minutes;

		double minus = abs(30.0 * hour + minutes / 2.0 - 6.0 * minutes);
		if (minus > 180) minus = 360 - minus;
		cout << setprecision(3) << setiosflags(ios::fixed | ios::showpoint) << minus << endl;
	}

	system("pause");
	return 0;
}