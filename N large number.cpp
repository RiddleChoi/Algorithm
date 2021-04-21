#include <vector>
#include <memory.h>
#include <iostream>

using namespace std;

int TC;
int arr[10];
int sorted[10];

void merge(int left,int right)
{
    int l,r,idx,mid = (left+right)/2;
    
    idx = left;
    l = left;
    r = mid+1;
    while(l < mid+1 && r <= right)
    {
        if(arr[l] > arr[r])
            sorted[idx++] = arr[l++];
        else
            sorted[idx++] = arr[r++];
    }
    while(l < mid+1)
        sorted[idx++] = arr[l++];
    while(r <= right)
        sorted[idx++] = arr[r++];
    for(int i = left; i <= right; i++)
        arr[i] = sorted[i];
}

void merge_sort(int left,int right)
{
    if(left < right)
    {
        int mid = (left+right)/2;
        merge_sort(left,mid);
        merge_sort(mid+1,right);
        merge(left,right);
    }
}

int main(int argc,char *argv[])
{
    vector<int> result;
    
    cin >> TC;
    while(TC--)
    {
        memset((int *)arr,0,sizeof(arr));
        memset((int *)sorted,0,sizeof(sorted));
        
        for(int i = 0; i < 10; i++)
            cin >> arr[i];
        
        merge_sort(0,9);
        result.push_back(arr[2]);
    }
    
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << '\n';
    return 0;
}
