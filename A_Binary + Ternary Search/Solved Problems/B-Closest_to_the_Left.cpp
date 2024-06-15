#include<bits/stdc++.h>
using namespace std;

/*
6 4
1 3 4 4 4 8

*/

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    while(q--){
        int x;
        cin >> x;
        
        int l=0, r=n-1;
        int ans = -1;          //*****
        while(l<=r){
            int mid = (l+r)/2;
            if(a[mid] <= x){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }

        cout << ans+1 << "\n";
    }


}
