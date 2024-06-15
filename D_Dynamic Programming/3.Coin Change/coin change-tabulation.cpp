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

        //1.handle base case
        dp[0][0] = 1;

         //2.loop through the state and calculate
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=target ; j++){
               //2.1.calculate the ans from smaller sub problems
                dp[i][j] = dp[i-1][j];
                for(int k=1 ; k<=limit[i] ; k++)
                {
                    if(j < k*coin[i])
                        break;

                    int value = dp[i-1][j - k*coin[i]];
                    dp[i][j] = (dp[i][j] + value)%MOD;
                }
            }
        }

        cout << "Case " << i << ": " << dp[n][target] << "\n";

    }

}


