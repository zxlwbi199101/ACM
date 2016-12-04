#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#define eps 1e-8
using namespace std;

class Point
{
public:
	char Name;
	double X;
	double Y;
};

double Area (Point a, Point b, Point c)
{
	return fabs(0.5 * ((c.Y - a.Y) * (b.X - a.X) - (b.Y - a.Y) * (c.X - a.X)));
}

bool IsInPolygon(Point p, Point a, Point b, Point c)
{
	return fabs(Area(p, a, b) + Area(p, a, c) + Area(p, b, c) - Area(a, b, c)) < eps;
}

int main()
{
	int count;
	vector<Point> points;
	int record1, record2, record3;

	while (cin >> count && count > 0)
	{
		double max = 0;
		points.clear();
		for (int i = 0; i < count; i++)
		{
			Point p;
			cin >> p.Name >> p.X >> p.Y;
			points.push_back(p);
		}

		for (int i = 0; i < count - 2; i++)
		{
			for (int j = i + 1; j < count - 1; j++)
			{
				for (int k = j + 1; k < count; k++)
				{
					bool validate = true;
					for (int s = 0; s < count; s++)
					{
						if (s == i || s == j || s == k) continue;
						if (IsInPolygon(points[s], points[i], points[j], points[k]))
						{						   
							validate = false;	   
							break;
						}
					}
					if (!validate) continue;
					
					double value = Area(points[i], points[j], points[k]);
					
					if (value > max)
					{
						max = value;
						record1 = i;
						record2 = j;
						record3 = k;
					}
				}
			}
		}
		cout << points[record1].Name << points[record2].Name << points[record3].Name << endl;
	}

	system("pause");
	return 0;
}




