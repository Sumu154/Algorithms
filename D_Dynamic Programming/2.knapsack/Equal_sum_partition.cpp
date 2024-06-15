/*

problem link -> https://leetcode.com/problems/partition-equal-subset-sum/description/

1.define state
      subset_sum(n, target) -> returns true if it is possible to create a subset
                       from numbers 1 to n from the sum target

                       where target = total/2

2.recursive eqn from smaller sub problem
      subset_sum(n, target) = subset_sum(n-1, target) or
                              subset_sum(n-1, target- nums[n])
                                 if target >= a[n]

3.define base case
      subset_sum(0, target) = 1 if target==0
      else 0

4
1 2 3 4

output
YES

5
1 2 3 4 5

output
NO

*/



#include<bits/stdc++.h>
using namespace std;

const int N = 101;
const int M = 1e5+5;
vector<int> a(N);
int dp[N][M];

bool subset_sum(int n, int target)
{
    if(n==0){
        if(target==0){
            return true;
        }
        return false;
    }


    if(dp[n][target] != -1){
        return dp[n][target];
    }

    int ans1 = subset_sum(n-1, target);
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
    int n;
    cin >> n;
    for(int i=1 ; i<=n ; i++){
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));

    int total = accumulate(a.begin(), a.end(), 0);
    if(total%2 != 0){
        cout << "NO\n";
    }
    else{
        int target = total/2;
        if(subset_sum(n ,target)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}