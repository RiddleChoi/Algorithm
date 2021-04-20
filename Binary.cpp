#include <string>
#include <iostream>

using namespace std;

int main(int argc,char *argv[])
{
    int TC;
    
    cin >> TC;
    while(TC--)
    {
        int N;
        string str = "";

        cin >> N;
        while(N != 0)
        {
            str += to_string(N % 2);
            N /= 2;
        }
        //cout << "str : " << str << '\n';
        for(int i = 0; i < str.length(); i++)
            if(str[i] == '1')
                cout << i << " ";
        cout << '\n';
    }
    
    return 0;
}
