/*

1.define state
      LCS(i, j) = length of longest common subsequence between
                  strings s[1...i][1...j]

2.recursive eqn from smaller sub problem
      LCS(i, j) = 1 + LCS(i-1, j-1) if(s[i] == t[j])
                  max(LCS(i-1, m), LCS(n, j-1)) if(s[i] != t[i])

3.define base case
      LCS(i, m) = 0
      LCS(n, j) = 0


sumaiya
saif

output
1


*/

#include<bits/stdc++.h>
using namespace std;

const int N = 101;
int dp[N][N];
string s, t;
int n, m;
int ans;

int LCS(int n, int m)
{
    //1.handle base case
    if(n==0 or m==0){
        return 0;
    }

    //2.if current state is already solved,return the solved result
    if(dp[n][m] != -1){
        return dp[n][m];
    }

    LCS(n-1, m);
    LCS(n, m-1);

    //3.calculate the result from smaller sub problem
    if(s[n-1] == t[m-1]){
        dp[n][m] =  LCS(n-1,m-1) + 1;
        ans = max(ans, dp[n][m]);
        return dp[n][m];
    } 
    dp[n][m] = 0;
    return dp[n][m];
}

int main()
{
    cin >> s >> t;

    n = s.size();
    m = t.size();

    memset(dp, -1, sizeof(dp));

    LCS(n,m);
    cout << ans << "\n";
}
