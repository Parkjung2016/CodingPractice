#include <iostream>
#include <string>
using namespace std;
int main()
{
	int height;

	int r;
	string p;

	cin >> height;
	for (int i = 0; i < height; i++)
	{
		cin >> r >> p;
		for (int c = 0; c < p.length(); c++)
		{

			for (int j = 0; j < r; j++)
			{
				cout << p[c];
			}
		}
		cout << endl;
	}
}
