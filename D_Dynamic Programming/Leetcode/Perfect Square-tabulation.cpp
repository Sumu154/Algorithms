/*
https://leetcode.com/problems/perfect-squares/

1.define state:
      Solve(n) ->  least number of perfect square numbers that sum to n

2.recursive eqn from smaller sub problem
      Solve(n) = min(n, 1+Solve(n-i*i))

3.define base case
      Solve(0) = 0

13
output
2

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int dp[N];

int main()
{
    int n;
    cin >> n;

    //1.handle base case
    dp[0] = 0;

    //2.loop through the state and calculate
    for(int i=1 ; i<=n ; i++){
        //2.1.calculate the ans from smaller sub problems
        dp[i] = i;
        for(int j=1 ; j*j<=i ; j++)
        {
            int count = 1+dp[i-j*j];
            dp[i] = min(dp[i], count);
        }
    }
    cout << dp[n];


}
