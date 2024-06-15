#include<bits/stdc++.h>
using namespace std;

/*
9
11 10 -20 5 -3 -5 8 -13 10
*/

int MaxSum(vector<int> a, int n)
{
    int totalSum=0;
    int total_sum = accumulate(a.begin(), a.end(), 0);

    int maxSum = a[0];
    int currMax = a[0];
    int minSum = a[0];
    int currMin = a[0];
    for(int i=1 ; i<n ; i++){
        currMax += a[i];
        currMax = max(currMax, a[i]);
        maxSum = max(maxSum, currMax);

        currMin += a[i];
        currMin = min(currMin, a[i]);
        minSum = min(minSum, currMin);
    }

    if(minSum==totalSum){
        return maxSum;
    }
    return max(maxSum, totalSum-minSum);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }

    int ans = MaxSum(a, n);
    cout << ans << "\n";
}