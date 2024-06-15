/*

1.define state
      Coin_change(n, target) -> minimum number of coins to make sum=target from coin 
                                1 to n

2.recursive eqn from smaller sub problem
      Coin_change(n, target) = min(Coin_change(n, target) +
                                   Coin_change(n, target-coin[n])+1
                                  )
3.define base case
      coin_change(0, 0) = 0
      coin_change:\Academic LAB\Algo Lab\Lab 13\210041154_task2.cpp e:\Academic LAB\Algo Lab\Lab 13\210041154_task1.cppe(0, !=0) = INF

3 11
1 2 5

output -> 3(5+5+1)

*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 100;
const int M = 1e5;
int coin[N];
int dp[N][M];


int Coin_change(int n, int target) 
{
    //1.handle base case
    if(n==0){
        if(target==0){
            return 0;
        }
        return INF;
    }

    //2.if current state is already solved,return the solved result
    if(dp[n][target] != -1){
        return dp[n][target];
    }
    
    //3.calculate the result from smaller sub problem
    int ans1 = Coin_change(n-1, target);  //+0
    if(target < coin[n]){
        dp[n][target] = ans1;
        return ans1;
    }
    int ans2 = Coin_change(n, target-coin[n])+1;
    int ans = min(ans1, ans2);

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

    int res = Coin_change(n, target);
    if(res >= INF){
        cout << -1 << "\n"; 
    } 
    else{
        cout << res << "\n"; 
    }

}
