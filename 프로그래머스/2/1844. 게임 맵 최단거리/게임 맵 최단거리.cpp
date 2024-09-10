#include<vector>
#include <queue>
using namespace std;

int visited[101][101];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int a[101][101];

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    int answer = -1;

    queue<pair<int, int>> q; 
    q.push({0,0});
    visited[0][0] = 1;
    a[0][0] = 1;
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if( nx < 0 || ny < 0 || nx >=n || ny >=m ) {
                continue;
            }

            if(maps[nx][ny] == 1 && visited[nx][ny] == 0) {

                int dsum = a[cx][cy] + 1;

                if (a[nx][ny] == 0 || a[nx][ny] > dsum) {
                    a[nx][ny] = dsum;
                    q.push({nx,ny});
                    visited[nx][ny] = 1;
                } 
            }
        }
    }

    if (a[n-1][m-1] !=0) return a[n-1][m-1];
    return answer;
}