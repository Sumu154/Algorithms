#include<bits/stdc++.h>
using namespace std;

void CountSort(vector<int> &a)
{
    int n = a.size();
    int max = *max_element(a.begin(), a.end());
    vector<int> count(max+1);

    for(int i=0 ; i<n ; i++){
        count[a[i]]++;
    }
    for(int i=1 ; i<=max ; i++){
        count[i] += count[i-1];
    }

    vector<int> ans(n);
    for(int i=n-1 ; i>=0 ; i--){
        ans[--count[a[i]]] = a[i];
    }
    swap(a, ans);

}

int main()
{
    vector<int> a = {5, 7, 3, 8, 10, 34, 1, 0, 7};
    CountSort(a);
    for(int i=0 ; i<a.size() ; i++){
        cout << a[i] << " ";
    }   
}

