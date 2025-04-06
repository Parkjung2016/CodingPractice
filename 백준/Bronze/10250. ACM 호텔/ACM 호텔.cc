#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define  MAX 101

string rooms[MAX][MAX];
int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int h, w, n;
		cin >> h >> w >> n;

		int floor = (n - 1) % h + 1;
		int room = (n - 1) / h + 1;

		cout << floor;
		if (room < 10) cout << "0";
		cout << room << "\n";

	}
}