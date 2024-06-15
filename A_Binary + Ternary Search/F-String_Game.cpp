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
    string t, p;
    cin >> t >> p;
    //cout << t << " " << p;
    int n = t.size();
    int m = p.size();

    vector<int> a(n);
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }


    auto ok = [&](int mid){
        vector<bool> bad(n+1);
        for(int i=0 ; i<mid ; i++){
            bad[a[i]] = 1;      //jei index er char bad ite chacchi shegula 1 kore felbo
        }

        //char gula bad dear pore ar p t er subsequence thake kina check korte hbe
        int j=0;
        for(int i=0 ; i<n ; i++){
            if(t[i]==p[j] and bad[i+1]==0){
                j++;
            }
        }
        return j==m;
    };

    int l=0, r=n;
    int mid, ans;
    while(l<=r){
        mid = (l+r)/2;
        if(ok(mid)){     //p jodi t er subsequence hoy tahole ans save kore right side e khujte thakbo
            ans = mid;   //karon mid er jonno true hole mid er lefte jekono value er jonnoi true hbe
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }

    cout << ans << "\n";
}

int main()
{
    Faster;
    
    Solve();
    
}