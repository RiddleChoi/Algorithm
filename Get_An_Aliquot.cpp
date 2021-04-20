#include <iostream>

using namespace std;

int main(int argc,char *argv[])
{
    int N,K;
    
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
    {
        if(N % i == 0)
        {
            K--;
            if(!K)
            {
                cout << i << '\n';
                return 0;
            }
        }
    }
    cout << 0 << '\n';
    return 0;
}
