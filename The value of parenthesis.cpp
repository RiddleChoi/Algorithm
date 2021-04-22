#include <iostream>
#include <string>
#include <stack>

using namespace std;

#define IS_PAR(x) (x == '(' || x == ')' || x == '[' || x == ']')

stack<int> st;
string str = "";

int solve(void)
{
    int round = 0,square = 0;
    for(int i = 0; i < (int)str.length(); i++)
    {
        char ch = str[i];
        
        if(!IS_PAR(ch))
            return 0;
        if(ch == '(')
            round++;
        else if(ch == ')')
            round--;
        else if(ch == '[')
            square++;
        else
            square--;
    }
    if(round != 0 || square != 0)
        return 0;
    
    for(int i = 0; i < (int)str.length(); i++)
    {
        int num = 0,top;
        char ch = str[i];
        
        if(ch == '(')
            st.push(-1);
        else if(ch == '[')
            st.push(-2);
        else if(ch == ')')
        {
            while(!st.empty())
            {
                top = st.top();
                st.pop();
                if(top == -2)
                    return 0;
                else if(top != -1)
                    num += top;
                else
                    break;
            }
            if(!num)
                num = 2;
            else
                num *= 2;
            st.push(num);
        }
        else if(ch == ']')
        {
            while(!st.empty())
            {
                top = st.top();
                st.pop();
                if(top == -1)
                    return 0;
                else if(top != -2)
                    num += top;
                else
                    break;
            }
            if(!num)
                num = 3;
            else
                num *= 3;
            st.push(num);
        }
    }
    
    int answer = 0;
    while(!st.empty())
    {
        answer += st.top();
        st.pop();
    }
    
    return answer;
}

int main(void)
{
    cin >> str;
    cout << solve() << '\n';
    return 0;
}
