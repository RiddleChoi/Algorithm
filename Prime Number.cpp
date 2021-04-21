#include <iostream>

using namespace std;

int primes[10001] = {0,};

int main(int argc,char *argv[])
{
    int M,N;
    primes[2] = 2; primes[3] = 3;
    
    cin >> M >> N;
    for(int i = 4; i < 10001; i++)
    {
        bool check = true;
        for(int j = 2; j < i; j++)
        {
            if(primes[j] && i % j == 0)
            {
                check = false;
                break;
            }
        }
        if(check)
            primes[i] = i;
    }
    
    int m = 987654321;
    int sum = 0;
    for(int i = M; i <= N; i++)
    {
        if(primes[i] && m == 987654321)
            m = primes[i];
        sum += primes[i];
    }
    if(sum == 0)
    {
        cout << -1 << '\n';
        return 0;
    }
    cout << sum << '\n';
    cout << m << '\n';
    return 0;
}
