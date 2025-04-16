#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    // 1. 자기 여벌 있는 사람 처리
    for (int i = 0; i < reserve.size(); ) {
        bool erased = false;
        for (int j = 0; j < lost.size(); j++) {
            if (reserve[i] == lost[j]) {
                reserve.erase(reserve.begin() + i);
                lost.erase(lost.begin() + j);
                erased = true;
                break;
            }
        }
        if (!erased) i++;
    }

    // 2. 빌려주기 (주의: lost는 erase 안 하고 check 배열로 처리)
    vector<bool> isLost(n + 1, false);
    for (int i = 0; i < lost.size(); i++) {
        isLost[lost[i]] = true;
    }

    for (int i = 0; i < reserve.size(); i++) {
        int r = reserve[i];
        if (r > 1 && isLost[r - 1]) {
            isLost[r - 1] = false;
        } else if (r < n && isLost[r + 1]) {
            isLost[r + 1] = false;
        }
    }

    // 3. 최종 정답 계산
    int answer = n;
    for (int i = 1; i <= n; i++) {
        if (isLost[i]) answer--;
    }

    return answer;
}
