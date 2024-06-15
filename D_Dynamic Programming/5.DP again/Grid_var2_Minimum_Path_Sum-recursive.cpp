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

int MinPathSum(int n, int m)
{
    //1.handle base case
    if(n==0 and m==0){
        return grid[0][0];
    }

    //2.if current state is already solved,return the solved result
    if(dp[n][m] != -1){
        return dp[n][m];
    }

    //3.calculate the result from smaller sub problem
    int ans1 = 9999, ans2 = 9999;
    if(n > 0){
        ans1 = MinPathSum(n-1, m) + grid[n][m];
    }
    if(m > 0){
        ans2 = MinPathSum(n, m-1) + grid[n][m];
    }
    int ans = min(ans1, ans2);

    dp[n][m] = ans;
    return ans;
}

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

    memset(dp, -1, sizeof(dp));

    cout << MinPathSum(n-1, m-1) << "\n";
}
