#include<vector>
#include<queue>
using namespace std;

int dx[]= {-1,1,0,0};
int dy[]= {0,0,-1,1};
int dist[101][101];
bool visited[101][101];
int xSize;
 int ySize;
void bfs(const vector<vector<int> >& maps)
{
    queue<pair<int,int>> q;
    q.emplace(0,0);
    visited[0][0]=true;
    dist[0][0]=1;
    
     xSize= maps[0].size();
     ySize= maps.size();
    while(!q.empty())
    {
        pair<int,int> pair =q.front();
        q.pop();
        int y= pair.first;
        int x= pair.second;

        for(int i =0;i <4;i++)
        {
            int ny= y +dy[i];
            int nx= x +dx[i];

            if(nx>=0 && ny >= 0 && nx< xSize&& ny<ySize&& maps[ny][nx]==1 && !visited[ny][nx])
            {
                visited[ny][nx]= true;
                dist[ny][nx]= dist[y][x]+1;
                q.emplace(ny,nx);
            }
        }
    }
}
int solution(vector<vector<int> > maps)
{

    bfs(maps);
    if(dist[ySize-1][xSize-1]==0)return -1;
    return dist[ySize-1][xSize-1];
}