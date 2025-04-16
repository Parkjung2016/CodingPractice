#include <string>
#include <vector>
#include <bitset>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = n+1;
    
bitset<256> nBit(n);
    int cnt=0;
    for(int i =0;i<256;i++)
    {
        if(nBit[i]==1)
            cnt++;
    }
    
while(true)
{
    bitset<256> aBit(answer);
    int cnt2=0;
    for(int i =0;i<256;i++)
    {
        if(aBit[i]==1)
            cnt2++;
    }
    
    if(cnt2==cnt)
    {
        break;
    }
    
    answer++;
}
    return answer;
}