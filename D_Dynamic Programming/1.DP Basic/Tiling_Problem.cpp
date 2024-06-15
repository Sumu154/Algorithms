#include<bits/stdc++.h>
using namespace std;


const int N = 2e5+5;
int dp[N];


int tilingWays(int n)
{
    //1.handle base case
    if(n <= 2){
        return n;
    }

    //2.if current state is already solved,return the solved result
    if(dp[n] != -1){
        return dp[n];
    }

    //3.calculate the result from smaller sub problem
    int ans = tilingWays(n-1)+tilingWays(n-2);
    dp[n] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));
    cout << tilingWays(n) << "\n";
}