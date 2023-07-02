#include<bits/stdc++.h>
using namespace std;

int minSwaps(string s)
{
    int n = s.length();
    stack<char> st;
    for(int i=0; i<n; i++)
    {
	if(s[i] == '[')
	    st.push(s[i]);
	else
	{
	    if(!st.empty() && st.top() == '[')
		st.pop();
	    else
		st.push(s[i]);
	}
    }
    int m = st.size();
    int n1 = 0;
    while(!st.empty() && st.top() == '[')
    {
	st.pop();
	n1++;
    }
    return (m/2 + n1%2);
}