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

int UniquePath(int n, int m)
{
    //1.handle base case
    if(n==0 and m==0){
        return 1;
    }

    //2.if current state is already solved,return the solved result
    if(dp[n][m] != -1){
        return dp[n][m];
    }
        
    //3.calculate the result from smaller sub problem
    int ans = 0;
    if(n>0){
        ans += UniquePath(n-1, m);
    }
    if(m>0){
        ans += UniquePath(n, m-1);
    }
        
    dp[n][m] = ans;
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    memset(dp, -1, sizeof(dp));

    cout << UniquePath(n-1, m-1);
}

