/*

1.define state
      subset_sum(n, target) -> returns true if it is possible to create a subset
                       from numbers 1 to n from the sum target

2.recursive eqn from smaller sub problem
      subset_sum(n, target) = subset_sum(n-1, target) or
                              subset_sum(n-1, target- nums[n])
                                 if target >= a[n]

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
vector<int> a(N);
int dp[N][M];

bool subset_sum(int n, int target)
{
    //1.handle base case
    if(n == 0){
        if(target == 0){
            return 1;
        }
        return 0;
    }

    //2.if current state is already solved,return the solved result
    if(dp[n][target] != -1){
        return dp[n][target];
    }

    //3.calculate the result from smaller sub problem
    int ans1 = subset_sum(n-1, target);
       //**handle corner case
    if(target < a[n]){
        dp[n][target] = ans1;
        return ans1;
    }
    int ans2 = subset_sum(n-1, target-a[n]);
    int ans = ans1 or ans2;
    
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

    cout << subset_sum(n ,target);
}
