#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define Faster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



void Solve()
{
    ll n, k;
    cin >> n >> k;

    auto ok = [&](ll mid){
        return mid-(mid/n) >= k;
    };

    ll l=1, r=2e9;
    ll mid, ans=0;
    while(l<=r){
        mid = (l+r)/2;
        if(ok(mid)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << ans << "\n";
}

int main()
{
    Faster;
    int t;
    cin >> t;
    while(t--){
        Solve();
    }
}