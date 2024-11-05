#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int len1, len2;
	string str1;
	string str2;
	string ret;
	cin >> str1 >> str2;
	len1 = str1.size();
	len2 = str2.size();
	int row = str1.size(), col = str2.size();
	vector<vector<int>>dp(row + 1, vector<int>(col + 1));
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] += dp[i - 1][j - 1] + 1;
			}
			else
				dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]);
		}
	}


	int i = len1;
	int j = len2;
	while (i >= 1 && j >= 1) {
		if (dp[i][j] > dp[i - 1][j] && dp[i - 1][j] == dp[i][j - 1] && dp[i][j - 1] == dp[i - 1][j - 1]) {
			ret += str2[j - 1];
			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1] && dp[i - 1][j] == dp[i][j]) {
			i--;
		}
		else if (dp[i - 1][j] < dp[i][j - 1] && dp[i][j - 1] == dp[i][j]) {
			j--;
		}
		else {
			j--;
		}
	}

	reverse(ret.begin(), ret.end());

	if (dp[len1][len2] != 0)
		cout << dp[len1][len2] << "\n" << ret;
	else
		cout << "0";
}