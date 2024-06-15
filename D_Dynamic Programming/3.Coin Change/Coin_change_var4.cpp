/*

1.define state
      Coin_change(n, target) -> number of ways to make sum=target from coin 1 to n
                                wihtout crossing limit

2.recursive eqn from smaller sub problem
      Coin_change(n, target) = Coin_change(n, target)+
                               Coin_change(n-1, target-coin[n])+
                               Coin_change(n-1, target-2*coin[n])+
                               ..................................
                               Coin_change(n-1, target-limit[n]*coin[n])
3.define base case
      coin_change(0, 0) = 1

2
3 5
1 2 5 3 2 1
4 20
1 2 3 4 8 4 2 1


output
Case 1: 3
Case 2: 9

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 60;
const int M = 100;
int dp[N][M];
int coin[N];
int limit[N];

int MOD = 1e9+7;

int Coin_change(int n, int target)
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
    int ans = Coin_change(n-1, target);
    for(int i=1 ; i*coin[n]<=target and i<=limit[n] ; i++) {
        int res = Coin_change(n-1, target-i*coin[n]);
        ans = ans + res;
    }

    dp[n][target] = ans;
    return ans;


}

int main()
{
    int t;
    cin >> t;
    for(int i=1 ; i<=t ; i++){
        int n, target;
        cin >> n >> target;
        for(int j=1 ; j<=n ; j++){
            cin >> coin[j];
        }
        for(int j=1 ; j<=n ; j++){
            cin >> limit[j];
        }

        memset(dp, -1, sizeof(dp));

        cout << "Case " << i << ": " << Coin_change(n, target) << "\n";
    }
}

