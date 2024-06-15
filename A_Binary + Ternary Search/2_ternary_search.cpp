#include<bits/stdc++.h>
using namespace std;

#define ll long long


int ternarySearch(vector<int> a, int k, int l, int h)
{
    if(l<=h){
        int mid1 = l+(h-l)/3;
        int mid2 = h-(h-l)/3;

        if(a[mid1]==k){
            return mid1;
        }
        if(a[mid2]==k){
            return mid2;
        }

        if(k < a[mid1]){
            return ternarySearch(a, k, l, mid1-1);
        }
        else if(k>a[mid2]){
            return ternarySearch(a, k, mid2+1, h);
        }
        else{
            return ternarySearch(a, k, mid1+1, mid2-1);
        }
    }
    return -1;
}

int main()
{
    vector<int> a = {6, 4, 7 ,8, 2, 0, 4, 10, 34,};
    int idx = ternarySearch(a, 10, 0, 8);
    cout << idx << "\n";
}