#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 50;
int T, M, N, K;
int field[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y) {
    visited[x][y] = true;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
            if (field[nx][ny] == 1 && !visited[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    cin >> T;
    
    while (T--) {
        cin >> M >> N >> K;
        
        // 초기화
        memset(field, 0, sizeof(field));
        memset(visited, false, sizeof(visited));
        
        // 배추 위치 입력
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            field[x][y] = 1;
        }
        
        int worm_count = 0;
        
        // 모든 위치에 대해 DFS 탐색
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (field[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j);
                    worm_count++;
                }
            }
        }
        
        cout << worm_count << endl;
    }
    
    return 0;
}
