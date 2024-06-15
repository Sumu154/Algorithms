/*

1.define state
      fun(n, m) -> min cost of path from 0,0 to n-1,m-1

2.recursive eqn from smaller sub problem
      fun(n, m) = min(fun(n-1, m) + a[n][m] +
                      fun(n, m-1) + a[m][n]
                     )

3.define base case
      fun(0, 0) = a[0][0];

3 3
1 3 1
1 5 1
4 2 1
output
7

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 101;
int dp[N][N];
int grid[N][N];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++)
        {
            cin >> grid[i][j];
        }
    }

    // base case
    dp[0][0] = grid[0][0];

    //2.loop through the state and calculate
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
        //2.1.calculate the ans from smaller sub problems
        {
            if(i==0 && j==0)
                continue;

            int ans1=9999, ans2=9999;
            if(i>0)
                ans1 = dp[i-1][j] + grid[i][j];

            if(j>0)
                ans2 = dp[i][j-1] + grid[i][j];

            int ans = min(ans1, ans2);
            dp[i][j] = ans;
        }
    }

    cout << dp[n-1][m-1];
}


