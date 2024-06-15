#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const ll INF = 1e18;
const ll MOD = 1e9+7;

const int N = 2e4+5;
int dp[N];

int Solve(int n)
{
    if(n<=2){
        return n;
    }

    if(dp[n] != -1){
        return dp[n];
    }
    int ans1 = Solve(n-1);
    int ans2 = (n-1)*Solve(n-2);
    int ans = ans1+ans2;
    
    dp[n]= ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << Solve(n) << "\n";
}