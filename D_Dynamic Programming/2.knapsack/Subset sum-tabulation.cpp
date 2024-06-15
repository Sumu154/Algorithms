/*

1.define state
      subset_sum(n, target) -> returns true if it is possible to create a subset
                       from numbers 1 to n and from the sum target

2.recursive eqn from smaller sub problem
      subset_sum(n, target) = subset_sum(n-1, target) or
                              subset_sum(n-1, target- nums[n])

3.define base case
      subset_sum(0, target) = 1 if target==0
      else 0

6 9
3 34 4 12 5 2

output
1


*/

#include<bits/stdc++.h>
using namespace std;

const int N = 101;
const int M = 1e5+5;
int a[N];
int dp[N][M];

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
            int ans1 = dp[i-1][j];
            if(j < a[i])
                dp[i][j] = ans1;

            else
            {
                int ans2 = dp[i-1][j- a[i]];
                int ans = ans1 or ans2;

                dp[i][j] = ans;
            }

        }
    }

    cout << dp[n][target];
}

