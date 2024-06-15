#include<bits/stdc++.h>
using namespace std;

void SelectionSort(vector<int> &a)
{
    int n = a.size();
    for(int i=0 ; i<n-1 ; i++){
        int min = i;
        for(int j=i+1 ; j<n ; j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        if(min!=i){
            swap(a[min], a[i]);
        }
    }
}

int main()
{
    vector<int> a = {5, 7, 3, 8, 10, 34, 1, 0, 7};
    SelectionSort(a);
    for(int i=0 ; i<a.size() ; i++){
        cout << a[i] << " ";
    }
}