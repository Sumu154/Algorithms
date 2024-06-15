#include<bits/stdc++.h>
using namespace std;

#define ll long long



int main()
{
    int n, pd;
    cin >> n >> pd;
    vector<ll> a(n);
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }

    auto ok = [&](ll m){            //mid nibe..mid time e given product banano possible kina 
        ll total = 0;
        for(int i=0 ; i<n ; i++){
            total += (m/a[i]);
            if(total >= pd){         //mid time e given product banano possible hole 
                return true;
            }
        }
        return false;
    };

    ll l=1, r=1e18;   //minimum time 1 and maximum time 1e18 hote pare(from constraint)
    ll mid, ans;
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