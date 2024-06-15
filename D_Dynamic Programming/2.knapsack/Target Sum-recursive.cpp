/*
https://leetcode.com/problems/target-sum/description/

1.define state
      target_sum(n, target) -> returns in how many ways we can achieve target
                               for n numbers

2.recursive eqn from smaller sub problem
      target_sum(n, target) = target_sum(n-1, target + a[n]) +
                              target_sum(n-1, target - a[n])

3.define base case
      target_sum(0, target) = 1 if target==0
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

int target_sum(int n, int target)
{
    //1.handle base case
    if(n == 0)
    {
        if(target == 0)
            return 1;
        return 0;
    }

    //2.if current state is already solved,return the solved result
    if(dp[n][target] != -1)
        return dp[n][target];

    //3.calculate the result from smaller sub problem
    int ans1 = target_sum(n-1, target-a[n]);
    int ans2 = target_sum(n-1, target+a[n]);
    int ans = ans1+ans2;

    dp[n][target] = ans;
    return ans;

}

int main()
{
    int n, target;
    cin >> n >> target;
    for(int i=1 ; i<=n ; i++){
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << target_sum(n, target);
}
