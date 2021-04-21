#include <iostream>

using namespace std;

int dp[1024] = {0,};

int main(int argc,char *argv[])
{
    int A,B;
    int cur = 1;
    int cnt = 1;
    
    cin >> A >> B;
    for(int i = 1; i < 1024; i++)
    {
        cnt--;
        dp[i] = dp[i-1]+cur;
        if(!cnt)
        {
            cur++;
            cnt = cur;
        }
    }
    
    cout << dp[B]-dp[A-1] << '\n';
    return 0;
}
