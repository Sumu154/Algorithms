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

int Solve(int n)
{
    //1.handle base case
    if(n <= 0)
        return 0;

    //2.if current state is already solved,return the solved result
    if(dp[n] != -1)
        return dp[n];

    //3.calculate the result from smaller sub problem
    int ans = n;
    for(int i=1 ; i*i<=n ; i++){
        int count = 1 + Solve(n-i*i);
        ans = min(ans, count);
    }

    dp[n] = ans;
    return ans;

}

int main()
{
    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));

    cout << Solve(n);
}
