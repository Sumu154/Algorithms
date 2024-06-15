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

    //1.handle base case
    dp[1][1] = 1;

    //2.loop through the state and calculate
    for(int i=1 ; i<=n ; i++){
       for(int j=1 ; j<=m ; j++)
       //2.1.calculate the ans from smaller sub problems
       {
           if(i==1 and j==1)
               continue;

           int ans = 0;
           if(i>1 and grid[i][j]=='.')
               ans += dp[i-1][j]%mod;

           if(j>1 and grid[i][j]=='.')
               ans += dp[i][j-1]%mod;

          dp[i][j] = ans%mod;
       }
    }

    cout << dp[n][m];

}
