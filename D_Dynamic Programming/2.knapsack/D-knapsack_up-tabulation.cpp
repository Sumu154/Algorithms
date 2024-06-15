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

output: 100 in place of 90

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 102;
const int W = 1e5;
long long dp[N][W];
int wt[N];
int val[N];

int main()
{
    int n, cap;
    cin >> n >> cap;
    for(int i=1 ; i<=n ; i++){
        cin >> wt[i] >> val[i];
    }

    //1.handle base case
    for(int i=0 ; i<=cap ; i++){
        dp[0][i] = 0;
    }

    //2.loop through the state and calculate
    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j<=cap ; j++)
        //2.1.calculate the ans from smaller sub problems
        {
            if(j < wt[i])
            {
                int ans = dp[i-1][j];
                dp[i][j] = ans;
            }
            else
            {
                int ans1 = dp[i-1][j-wt[i]] + val[i];
                int ans2 = dp[i][j-wt[i]] + val[i];
                int ans3 = dp[i-1][j];
                int ans = max({ans1, ans2, ans3});

                dp[i][j] = ans;
            }
        }
    }

    cout << dp[n][cap];
}
