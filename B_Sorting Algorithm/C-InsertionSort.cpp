#include<bits/stdc++.h>
using namespace std;

void InsertionSort(vector<int> &a)
{
    int n = a.size();
    for(int i=1 ; i<n ; i++){
        int curr = a[i];
        int j = i-1;
        while(a[j]>curr and j>=0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = curr;
    }
}

int main()
{
    vector<int> a = {5, 7, 3, 8, 10, 34, 1, 0, 7};
    InsertionSort(a);
    for(int i=0 ; i<a.size() ; i++){
        cout << a[i] << " ";
    }
}