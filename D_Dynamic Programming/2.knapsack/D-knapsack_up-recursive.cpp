/*
https://atcoder.jp/contests/dp/tasks/dp_d

1.define state
     knapsack(n, cap) -> max profit considering object 1 to n and capacity cap

2.recursive eqn from smaller sub problem
     knapsack(n, cap) = max(knapsack(n-1, cap-wt[n]),
                            knapsack(n-1, cap)
                           )
3.define base case
    knapsack(0, x) = 0


time complexity -> O(cap*n)
space complexity -> O(cap*n)

3 8
3 30
4 50
5 60

output: 90

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 102;
const int W = 1e5;
ll dp[N][W];   //[n][cap]
int wt[N];
int val[N];

ll knapsack(int n, int cap)
{
    //1.handle base case
    if(n == 0){
        return 0;
    }

    //2.if current state is already solved,return the solved result
    if(dp[n][cap] != -1){
        return dp[n][cap];
    }

    //3.calculate the result from smaller sub problem
    //**handle corner case
    if(cap <  wt[n]){
        ll ans = knapsack(n-1, cap);
        dp[n][cap] = ans;
        return ans;
    }

    ll ans1 = knapsack(n-1, cap-wt[n]) + val[n];   //yes case
    ll ans2 = knapsack(n-1, cap);             //no case
    ll ans = max(ans1, ans2);

    dp[n][cap] = ans;
    return ans;
}

int main()
{
    int n, cap;
    cin >> n >> cap;
    for(int i=1 ; i<=n ; i++){
        cin >> wt[i] >> val[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << knapsack(n, cap);
}
