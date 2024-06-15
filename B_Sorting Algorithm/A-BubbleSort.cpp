#include<bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int> &a)
{
    int n = a.size();
    for(int i=0 ; i<n-1 ; i++){
        for(int j=0 ; j<n-i-1 ; j++){
            if(a[j]>a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
}

int main()
{
    vector<int> a = {5, 7, 3, 8, 10, 34, 1, 0, 7};
    BubbleSort(a);
    for(int i=0 ; i<a.size() ; i++){
        cout << a[i] << " ";
    }
}
