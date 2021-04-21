#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a,int b)
{
    if(b == 0)
        return a;
    if(a > b)
        return gcd(b,a%b);
    return gcd(a,b%a);
}

int lcm(int a,int b)
{
    return a*b / gcd(a,b);
}

int main(int argc,char *argv[])
{
    int A,B;
    
    cin >> A >> B;
    cout << gcd(A,B) << '\n';
    cout << lcm(A,B) << '\n';
    return 0;
}
