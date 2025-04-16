#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<int> st;
    for(char c :s)
    {
        if(!st.empty() && st.top()==c)
        {
            st.pop();
        }
        else
        {
st.push(c);
            }
        
    }
    return st.empty();
}