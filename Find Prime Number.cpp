#include <vector>
#include <iostream>

using namespace std;

int primes[1024] = {0,};

int main(int argc,char *argv[])
{
    int N;
    vector<int> num;
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        num.push_back(tmp);
    }
    primes[2] = 2; primes[3] = 3;
    for(int i = 4; i < 1024; i++)
    {
        bool check = true;
        for(int j = 2; j < i; j++)
            if(i % j == 0)
            {
                check = false;
                break;
            }
        if(check)
            primes[i] = i;
    }
    
    int cnt = 0;
    for(int i = 0; i < num.size(); i++)
        if(primes[num[i]])
            cnt++;
    cout << cnt << '\n';
    return 0;
}
