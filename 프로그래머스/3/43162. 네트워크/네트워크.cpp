#include <string>
#include <vector>

using namespace std;
bool visited[201];
void dfs(int n, vector<vector<int>> computers,int index)
{
    visited[index] =true;
    for(int i =0;i<n;i++)
    {
        if(computers[index][i]==1 && !visited[i])
        {
            dfs(n,computers,i);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i =0;i<n;i++)
    {
            if( !visited[i])
            {
                answer++;
 dfs(n, computers, i);
            }

    }
    return answer;
}