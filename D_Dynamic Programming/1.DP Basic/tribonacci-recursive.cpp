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

int fib(int n)
{
    //1.define base case
    if(n <= 3)
        return 1;

    //2.if current state is already solved,return the solved result
    if(dp[n] != -1)
        return dp[n];

    //3.calculate the result from smaller sub problem
    int ans = fib(n-1)+fib(n-2)+fib(n-3);
    dp[n] = ans;
    return ans;

}

int main()
{
    int n;
    cin >> n;

    for(int i=1 ; i<=n ; i++){
        dp[i] = -1;
    }

    cout << fib(n);
}
