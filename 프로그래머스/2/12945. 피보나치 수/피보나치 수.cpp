#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAX 100001
long long dp[MAX];
int solution(int n) {
    
    dp[0]=0;
    dp[1]=1;
    
    for(long long i =2;i<=n;i++)
    {
        dp[i] = (dp[i-1]+dp[i-2])%1234567;
    }
    int answer =dp[n] ;
    
    
    
    return answer;
}