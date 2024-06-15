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

int main()
{
    cin >> s >> t;

    n = s.size();
    m = t.size();


    //1.handle base case
    for(int i=0 ; i<=n ; i++){
        dp[i][m] = 0;
    }
    for(int j=0 ; j<=m ; j++){
        dp[n][j] = 0;
    }

    //2.loop through the state and calculate
    for(int i=n-1 ; i>=0 ; i--){
        for(int j=m-1 ; j>=0 ; j--)
        //2.1.calculate the ans from smaller sub problems
        {
            if(s[i] == t[j])
                dp[i][j] = 1 + dp[i+1][j+1];
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
    }

    cout << dp[0][0];
}

