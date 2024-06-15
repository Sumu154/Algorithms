/*
calculate the nth fibonacci number
fib(n) = fib(n-1)+fib(n-2)

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int dp[N];  //for memorization


int main()
{
    int n;
    cin >> n;

    //1.handle base case
    dp[1] = 1;
    dp[2] = 1;

    //2.loop through the state and calculate
    for(int i=3 ; i<=n ; i++){
        //2.1.calculate the ans from smaller sub problems
        dp[i] = dp[i-1]+dp[i-2];
    }

    cout << dp[n];
}
