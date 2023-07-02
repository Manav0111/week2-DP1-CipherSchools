#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        

        stack<char> resp;
        for (char c : s)
        {
           if (c == '(' || c == '[' ||c == '{' )
           {
               resp.push(c);
            }
               else
               {    
                   if (resp.empty()) return false;
                   if(c==')' && (resp.top()!='(') ) return false;
                   if(c=='}' && (resp.top()!='{') ) return false;
                   if(c==']' && (resp.top()!='[') ) return false;
                   resp.pop();
               }
        }

        return resp.empty();
    }
};