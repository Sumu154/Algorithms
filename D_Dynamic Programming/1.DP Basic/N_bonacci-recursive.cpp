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

int fib(int n, int k)
{
    //1.define base case
    if(k <= n)
        return 1;

    //2.if current state is already solved,return the solved result
    if(dp[k] != -1)
        return dp[k];

    //3.calculate the result from smaller sub problem
    int ans = 0;
    for (int i=k-n ; i<k ; i++) {
        ans += fib(n, i);
    }
    dp[k] = ans;
    return ans;

}

int main()
{
    int n,k;
    cin >> n >> k;

    for(int i=1 ; i<=k ; i++){
        dp[i] = -1;
    }

    cout << fib(n,k);
}
