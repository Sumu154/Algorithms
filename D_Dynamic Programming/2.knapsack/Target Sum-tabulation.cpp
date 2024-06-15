/*
https://leetcode.com/problems/target-sum/description/

1.define state
      subset_sum(n, target) -> returns in how many ways we can achieve target
                               for n numbers

2.recursive eqn from smaller sub problem
      subset_sum(n, target) = subset_sum(n-1, target + a[n]) +
                              subset_sum(n-1, target - a[n])

3.define base case
      subset_sum(0, target) = 1 if target==0
      else 0

5 3
1 1 1 1 1
output
5

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 102;
const int W = 1e5+5;
int a[N];
int dp[N][W];

int main()
{
    int n, target;
    cin >> n >> target;
    for(int i=1 ; i<=n ; i++){
        cin >> a[i];
    }

    //1.handle base case
    dp[0][0] = 1;
    for(int i=1 ; i<=target ; i++){
        dp[0][i] = 0;
    }

    //2.loop through the state and calculate
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=target ; j++)
        //2.1.calculate the ans from smaller sub problems
        {
            int ans1 = dp[i-1][j-a[i]];
            int ans2 = dp[i-1][j+a[i]];
            int ans = ans1 + ans2;

            dp[i][j] = ans;
        }
    }

    cout << dp[n][target];
}
