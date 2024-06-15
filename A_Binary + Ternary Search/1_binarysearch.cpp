#include<bits/stdc++.h>
using namespace std;

int isFound(vector<int> a, int k)
{
    int n = a.size();
    int l=0, r= n-1;

    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid]==k){
            return mid+1;
        }
        else if(a[mid] > k){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return -1;
}

int main()
{
    int n,k;
    cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    cin >> k;
    int pos = isFound(a, k);
    if(pos==-1){
        cout << "NO\n";
    }
    else{
        cout << "YES" << " " << pos << "\n";
    }


}
