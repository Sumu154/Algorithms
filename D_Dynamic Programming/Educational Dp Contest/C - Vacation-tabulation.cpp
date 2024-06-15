/*
1.define state:
       fun(n, x) -> maximum happiness till day n
                    if we pick task x on day n

2.recursive eqn from smaller sub problem
     fun(n, x) = max(fun(n-1, y)+happiness[n][x]    where x!=y

3.define base case
     fun(1, x) = happiness(1, x)

3
10 40 70
20 50 80
30 60 90


output
210     <=70+50+90

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int h[N][4];
int dp[N][4];

int main()
{
    int n;
    cin >> n;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=3 ; j++)
        {
            cin >> h[i][j];
        }
    }

    //1.handle base case
    for(int x=1 ; x<=3 ; x++){
        dp[1][x] = h[1][x];
    }

    //2.loop through the state and calculate
    for(int i=1 ; i<=n ; i++){
        for(int x=1 ; x<=3 ; x++){
            //2.1.calculate the ans from smaller sub problems

            int max_profit = 0;
            for(int j=1 ; j<=3 ; j++)
            {
                if(j != x)
                {
                    int candidate_profit = dp[i-1][j] + h[i][x];
                    max_profit = max(max_profit, candidate_profit);
                }
            }
            dp[i][x] = max_profit;
        }
    }

    int ans = max({dp[n][1], dp[n][2], dp[n][3]});
    cout << ans;

}


