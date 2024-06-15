#include<bits/stdc++.h>
using namespace std;

#define ll long long

/*
problem link -> https://codeforces.com/problemset/problem/1201/C
*/
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    auto ok = [&](ll mid){
        ll count = 0;
        for(int i=n/2 ; i<n ; i++){
            if(a[i]<mid){
                count += mid-a[i];
            }
        }
        return count<=k;
    };

    ll l=1, r=2e9;
    ll mid, ans = 0;
    while(l<=r){
        mid = (l+r)/2;
        if(ok(mid)){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }

    cout << ans << "\n";
}