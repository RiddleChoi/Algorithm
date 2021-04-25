#include <iostream>
#include <vector>

using namespace std;

int N,K;
vector<int> multitab;
vector<int> schedule;

int solve(void)
{
    int answer = 0;
    
    cin >> N >> K;
    for(int i = 0; i < K; i++)
    {
        int order;
        cin >> order;
        multitab.push_back(0);
        schedule.push_back(order);
    }
    
    for(int i = 0; i < K; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(multitab[j] == 0)
            {
                multitab[j] = schedule[i];
                break;
            }
            else
            {
                int idx;
                
                if(multitab[j] == schedule[i])
                    break;
                if(j != N-1)
                    continue;
                
                int change,temp = -1;
                for(int k = 0; k < N; k++)
                {
                    int diff = 0;
                    for(int l = i+1; l < K && multitab[k] != schedule[l]; l++)
                        diff++;
                    if(diff > temp)
                    {
                        temp = diff;
                        change = k;
                    }
                }
                multitab[change] = schedule[i];
                answer++;
            }
        }
    }
    
    return answer;
}

int main(int argc,char *argv[])
{
    cout << solve() << '\n';
    return 0;
}
