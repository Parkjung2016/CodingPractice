#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

class StudentStat
{
public:
	int index;
	int v;
	int p;
	int s;

public:
	int GetTotalScore()
	{
		return v + p + s;
	}

public:
	static bool compare(StudentStat& a, StudentStat& b)
	{
		return a.GetTotalScore() > b.GetTotalScore();
	}
};
int main()
{
	int n, m;
	cin >> n >> m;

	StudentStat* allStats = new StudentStat[n];
	vector<StudentStat> teamVec;
	StudentStat myStat;
	myStat.index = 0;
	cin >> myStat.v >> myStat.p >> myStat.s;

	teamVec.push_back(myStat);
	for (int i = 0; i < n; i++)
	{
		StudentStat stat;
		cin >> stat.v >> stat.p >> stat.s;
		stat.index = i + 1;
		allStats[i] = stat;
	}

	sort(allStats, allStats + n, StudentStat::compare);
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		StudentStat stat = allStats[i];
		if (stat.GetTotalScore() > myStat.GetTotalScore())
			continue;

		if (teamVec.size() >= m )
			break;

		teamVec.push_back(allStats[i]);
	}
	for (int i = 0; i < teamVec.size(); i++)
	{
		cout << teamVec[i].index << " ";
	}

	delete[] allStats;

}