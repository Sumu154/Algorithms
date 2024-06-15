#include<bits/stdc++.h>
using namespace std;

/*
6 4
1 3 4 4 4 8

*/

int isFound(vector<int> a, int k)
{
    int n = a.size();
    int l=0, h= n-1;

    int ind = -1;
    while(l<=h){
        int mid = (l+h)/2;
        if(a[mid]==k){
            ind = mid+1;
            h = mid-1;
            //l = mid+1;    // jodi last occurance bolto tahole
        }
        else if(a[mid] > k){
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return ind;
}

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    int pos = isFound(a, k);
    if(pos==-1){
        cout << "NO\n";
    }
    else{
        cout << "YES" << " " << pos << "\n";
    }


}
