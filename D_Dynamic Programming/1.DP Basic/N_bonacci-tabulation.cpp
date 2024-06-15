/*
1.define state
      fib(n,k) -> kth number of n-bonacci

2.recursive equation from smaller sub problem
      fib(n,k) = fib(k-1)+fib(k-2)....+fib(k-n)

3.define base case
      fib(1) = 1
      ..........
      ..........
      fib(n) = 1

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int dp[N];

int main()
{
    int n, k;
    cin >> n >> k;

    //1.handle base case
    for(int i=1 ; i<=n ; i++){
        dp[i] = 1;
    }

    //2.loop through the state and calculate
    for(int i=n+1 ; i<=k ; i++){
        //2.1.calculate the ans from smaller sub problems
        for(int j=1 ; j<=n ; j++)
        {
            dp[i] += dp[i-j];
        }
    }

    cout << dp[k];
}
