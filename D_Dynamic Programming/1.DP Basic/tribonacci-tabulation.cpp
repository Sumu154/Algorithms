/*
1.define state
      fib(n)

2.recursive equation from smaller sub problem
      fib(n) = fib(n-1)+fib(n-2)+fib(n-3)

3.define base case
      fib(1) = 1;
      fib(2) = 1;
      fib(3) = 1

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int dp[N];

int main()
{
    int n;
    cin >> n;

    //1.handle base case
    for(int i=1 ; i<=3 ; i++){
        dp[i] = 1;
    }

    //2.loop through the state and calculate
    for(int i=4 ; i<=n ; i++){
        //2.1.calculate the ans from smaller sub problems
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }

    cout << dp[n];
}
