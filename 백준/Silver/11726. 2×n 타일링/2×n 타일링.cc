#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	for (int i = 2; i < n; i++)
	{
		vec.push_back((vec[i - 1] + vec[i - 2]) % 10007);
	}
	cout << vec[n-1];

	return 0;
}
