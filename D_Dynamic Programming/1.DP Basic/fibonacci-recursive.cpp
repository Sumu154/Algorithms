/*
calculate the nth fibonacci number
fib(n) = fib(n-1)+fib(n-2)

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 100;
int dp[N];  //for memorization

ll fib(int n)
{
    //1.handle base case
    if(n <= 2)
        return 1;

    //2.if current state is already solved,return the solved result
    if(dp[n] != -1)
        return dp[n];

    //3.calculate the result from smaller sub problem
    ll ans = fib(n-1)+fib(n-2);
    dp[n] = ans;
    return ans;

}

int main()
{
    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));
    cout << fib(n);
}
