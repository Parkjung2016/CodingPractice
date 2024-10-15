#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int fn(int startNum, int nextNum, int idx)
{
	if (idx >= n) return startNum;
	else return fn(nextNum, startNum + nextNum, idx + 1);
}
int main() {
	cin >> n;
	cout << fn(0, 1, 0);

	return 0;
}
