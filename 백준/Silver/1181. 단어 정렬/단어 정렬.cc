#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool compare(string str1, string str2)
{
	if (str1.length() == str2.length())
		return str1 < str2;
	return str1.length() < str2.length();

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	vector<string> strVec;
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		strVec.push_back(str);
	}
	sort(strVec.begin(), strVec.end(), compare);
	strVec.erase(unique(strVec.begin(), strVec.end()), strVec.end());
	for (int i = 0; i < strVec.size(); i++)
	{
		cout << strVec[i] << endl;
	}
}