/*
https://atcoder.jp/contests/dp/tasks/dp_h

1.define state
      fun(n, m) -> number of unique path from 0,0 to n-1,m-1

2.recursive eqn from smaller sub problem
      fun(n, m) = fun(n-1, m) + fun(n, m-1)

3.define base case
      fun(0, 0) = 1;

3 4
...#
.#..
....

output
3

*/

#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

const int N = 1005;
char grid[N][N];
int dp[N][N];

int UniquePath(int n, int m)
{
     //1.handle base case
     if(n==1 and m==1)
        return 1;

    //2.if current state is already solved,return the solved result
    if(dp[n][m] != -1)
        return dp[n][m];

    //3.calculate the result from smaller sub problem
    int ans = 0;
    if(n>1 and grid[n][m]=='.')
        ans += UniquePath(n-1, m)%mod;

    if(m>1 and grid[n][m]=='.')
        ans += UniquePath(n, m-1)%mod;

    dp[n][m] = ans%mod;
    return ans%mod;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << UniquePath(n, m);

}
