#include<bits/stdc++.h>
using namespace std;

void CountSort(vector<int> &a, int exp)
{
    int n = a.size();
    vector<int> count(10);

    for(int i=0 ; i<n ; i++){
        count[(a[i]/exp)%10]++;
    }
    for(int i=1 ; i<10 ; i++){
        count[i] += count[i-1];
    }

    vector<int> ans(n);
    for(int i=n-1 ; i>=0 ; i--){
        ans[--count[(a[i]/exp)%10]] = a[i];
    }
    swap(a, ans);
}

void RadixSort(vector<int> &a)
{
    int n = a.size();
    int max = *max_element(a.begin(), a.end());

    for(int exp=1 ; max/exp>0 ; exp*=10){
        CountSort(a, exp);
    }
    
}

int main()
{
    vector<int> a = {5, 7, 3, 8, 10, 34, 1, 0, 7};
    RadixSort(a);
    for(int i=0 ; i<a.size() ; i++){
        cout << a[i] << " ";
    }   
}