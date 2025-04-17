#include <string>
#include <vector>
#include <queue>

using namespace std;
int answer = 0;
bool visited[201];
void bfs(int start,const vector<vector<int>>& computers){
    queue<int> q;
    q.push(start);
    visited[start]=true;
    while(!q.empty())
    {
        int index= q.front();
        q.pop();

        for(int i =0;i<computers.size();i++)
        {
            if( computers[index][i]==1 &&!visited[i]) {
                q.push(i);
                visited[i]=true;
            }
        }


    }
}
int solution(int n, vector<vector<int>> computers) {

    for(int i =0;i<n;i++)
    {
        if(!visited[i])
        {
            bfs(i,computers);
            answer++;
        }
    }
    return answer;
}