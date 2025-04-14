#include<vector>
#include<queue>
using namespace std;

bool visited[101][101];
int dist[101][101];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void bfs(const vector<vector<int> >& maps)
{
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0]=true;
    dist[0][0]=1;
    while(!q.empty())
    {
        pair<int,int> pair= q.front();
        q.pop();
        
        int y= pair.first;
        int x= pair.second;
        for(int i =0; i<4;i++)
        {
            int nx=  x+ dx[i];
            int ny=  y+ dy[i];
            if(nx>=0 && ny>=0 && ny< maps.size() && 
               nx < maps[0].size() && maps[ny][nx]==1 && !visited[ny][nx]){
                visited[ny][nx]=true;
                dist[ny][nx]= dist[y][x]+1;
                q.push({ny,nx});
            }
        }
    }
}

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    
    bfs(maps);
    int dis = dist[maps.size()-1][maps[0].size()-1];
    if(dis!=0)
        answer= dis;
    return answer;
}