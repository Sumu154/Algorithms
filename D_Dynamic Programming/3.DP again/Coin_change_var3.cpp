/*
Coin Change Variation 1
       can use a coin more than once, how many ways we make target
       //subset_sum problem er moto


1.define state
      Coin_change(n, target) -> returns true if it is possible to create a subset
                       from numbers 1 to n from the sum target

2.recursive eqn from smaller sub problem
      Coin_change(n, target) = Coin_change(n-1, target) +
                               Coin_change(n-1, target- nums[n])
                                 if target >= a[n]

3.define base case
      Coin_change(0, target) = 1 if target==0
      else 0

6 9
3 34 4 12 5 2

output
2  

3+4+2 = 9
5+4 = 9

*/


#include<bits/stdc++.h>
using namespace std;

const int N = 100;
const int M = 1e5;
int coin[N];
int dp[N][M];


int Coin_change(int n, int target)
{
    //1.handle base case
    if(n==0){
        if(target==0){
            return 1;
        }
        return 0;
    }

    //2.if current state is already solved,return the solved result
    if(dp[n][target] != -1){
        return dp[n][target];
    }

    //3.calculate the result from smaller sub problem
    int ans = Coin_change(n-1, target);
    for(int i=1 ; i*coin[n]<=target ; i++){
        int res = Coin_change(n-1, target-i*coin[n]);
        ans = ans+res;
    }

    dp[n][target] = ans;
    return ans;
    
}


int main()
{
    int n, target;
    cin >> n >> target;
    for(int i=1 ; i<=n ; i++){
        cin >> coin[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << Coin_change(n, target);
}