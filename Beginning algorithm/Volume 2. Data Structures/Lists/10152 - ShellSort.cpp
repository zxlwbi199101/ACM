#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
	int count;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		int num;
		cin >> num;

		vector<string> oriOrder;
		vector<string> tarOrder;
		int wrongCount = 0;
		int currentTar = num - 1;
		
		cin.get();
		string turtle;
		for (int j = 0; j < num; j++)
		{
			getline(cin, turtle);
			oriOrder.push_back(turtle);
		}
		for (int j = 0; j < num; j++)
		{
			getline(cin, turtle);
			tarOrder.push_back(turtle);
		}
		for (int j = num - 1; j >= 0; j--)
		{
			if (tarOrder[currentTar] == oriOrder[j])
			{
				currentTar--;
			}
			else
			{
				wrongCount++;
			}
		}

		for (int j = wrongCount - 1; j >= 0; j--)
		{
			cout << tarOrder[j] << endl;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

