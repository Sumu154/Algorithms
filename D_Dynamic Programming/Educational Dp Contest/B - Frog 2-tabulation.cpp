/*
1.define state:
     stone(n) -> cost of reaching n-th stone from 1st one

2.recursive eqn from smaller sub problem
     stone(i) = for(i=1 to k
                min (stone(i-1) + abs(h[i]-h[i-1]))

3.define base case
     stone(1) = 0

i <=== i-1, i-2, i-k
i<k hote pare na

5 3
10 30 40 50 20

output
30

*/

#include<bits/stdc++.h>
using namespace std;

const int INF = 2e9;

const int N = 1e5+5;
int h[N];
int dp[N];
int n, k;


int main()
{
    cin >> n >> k;
    for(int i=1 ; i<=n ; i++){
        cin >> h[i];
    }

    //1.handle base case
    dp[1] = 0;

    //2.loop through the state and calculate
    for(int i=2 ; i<=n ; i++){
        dp[i] = INF;

        //2.1.calculate the ans from smaller sub problems
        for(int j=1 ; j<=k ; j++){
            //**handle corner case
            if(i-j <= 0){
                break;
            }

            int candidate_ans = dp[i-j] + abs(h[i]-h[i-j]);
            dp[i] = min(candidate_ans, dp[i] );
        }
    }

    cout << dp[n] << "\n";
}
