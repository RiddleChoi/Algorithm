#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int H,W;
vector<int> v;

int solve(void)
{
    int answer = 0;
    
    cin >> H >> W;
    for(int i = 0; i < W; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    // Two Pointers
    for(int i = 1; i < W; i++)
    {
        int cur = v[i];
        int left = 0,right = 0,less;
        
        for(int j = i-1; j >= 0; j--)
            if(left < v[j])
                left = v[j];
        for(int j = i+1; j < W; j++)
            if(right < v[j])
                right = v[j];
        
        less = min(left,right);
        if(less-cur > 0)
            answer += less-cur;
    }
    
    return answer;
}

int main(void)
{
    cout << solve() << '\n';
    return 0;
}
