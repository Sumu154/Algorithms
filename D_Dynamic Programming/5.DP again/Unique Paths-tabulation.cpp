/*

1.define state
      fun(n, m) -> number of unique path from 0,0 to n-1,m-1

2.recursive eqn from smaller sub problem
      fun(n, m) = fun(n-1, m) + fun(n, m-1)

3.define base case
      fun(0, 0) = 1;

3 7
output
28


*/

#include<bits/stdc++.h>
using namespace std;

const int N = 101;
int dp[N][N];

int main()
{
    int n, m;
    cin >> n >> m;

    //1.handle base case
    dp[0][0] = 1;

    //2.loop through the state and calculate
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++)
        //2.1.calculate the ans from smaller sub problems
        {
            if(i==0 and j==0)
                continue;

            int ans = 0;
            if(i > 0)
                ans += dp[i-1][j];
            if(j > 0)
                ans += dp[i][j-1];

            dp[i][j] = ans;
        }
    }

    cout << dp[n-1][m-1];

}
