#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e4+5;

vector<ll> power;

void Solve()
{
    ll x;
    cin >> x;
    bool found = false;
    for(ll i=0 ; i<N ; i++){
        if(power[i]>=x){
            break;
        }

        ll l=0, r=N-1, mid;
        ll need = x-power[i];
        bool ok = false;
        while(l<=r){
            mid = (l+r)/2;
            if(power[mid]==need){
                ok = true;
                break;
            }
            else if(power[mid] > need){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        if(ok){
            found = true;
            break;
        }
    }
    if(found){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main()
{
    for(ll i=1 ; i<=N ; i++){
        power.push_back(pow(i,3ll));
    }

    int t;
    cin >> t;
    while(t--){
        Solve();
    }


}