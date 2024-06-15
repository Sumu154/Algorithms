#include<bits/stdc++.h>
using namespace std;

void BucketSort(vector<int> &a)
{
    int n = a.size();
    vector<vector<int>> b(n, vector<int> ());

    for(int i=0 ; i<n ; i++){
        int bi = n*a[i];
        b[bi].push_back(a[i]);
    }

    for(int i=0 ; i<n ; i++){
        sort(b[i].begin(), b[i].end());
    }

    int idx = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<b[i].size() ; j++){
            a[idx++] = b[i][j];
        }
    }

}

int main()
{
    vector<int> a = {5, 7, 3, 8, 10, 34, 1, 0, 7};
    BucketSort(a);
    for(int i=0 ; i<a.size() ; i++){
        cout << a[i] << " ";
    } 
}