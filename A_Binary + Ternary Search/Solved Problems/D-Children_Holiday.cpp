#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define Faster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll INF = 1e18;
const ll MOD = 1e9+7;

const int N = 2e5+5;



void Solve()
{
    int n, m;
    cin >> m >> n;
    vector<tuple<int,int,int>> a(n);
    for(int i=0 ; i<n ; i++){
        int t, z, y;
        cin >> t >> z >> y;
        a[i] = make_tuple(t, z, y);
    }

    vector<int> can(n);
    auto ok = [&](int mid){
        vector<int> may(n);
        int ballon = m;
        for(int i=0 ; i<n ; i++){
            tuple<int,int,int> T = a[i];
            int t = get<0>(T);
            int z = get<1>(T);
            int y = get<2>(T);

            int total = (t*z)+y;
            int full = mid/total;
            int rem = mid%total;

            int curr = (full*z) + min(z, rem/t);
            curr = min(ballon, curr);

            ballon -= curr;
            may[i] = curr;
        }

        if(!ballon){
            for(int i=0 ; i<n ; i++){
                can[i] = may[i];
            }
        }

        return !ballon;
    };

    int l=0, r=1e8;
    int mid, ans;
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
    for(int i: can){
        cout << i << " ";
    }cout << "\n";
}

int main()
{
    Faster;
    
    Solve();
    
}