#include<bits/stdc++.h>
using namespace std;

/*

8
-2 -2 4 -1 -2 1 5 -3

output -> 7

*/


int maxCrossSum(vector<int> a, int l, int mid, int r)
{
    int sum=0;
    int leftSum = INT_MIN;
    for(int i=mid ; i>=l ; i--){
        sum += a[i];
        leftSum = max(leftSum, sum);
    }

    sum = 0;
    int rightSum = INT_MIN;
    for(int i=mid ; i<=r ; i++){
        sum += a[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum+rightSum-a[mid];
}

int maxSubarraySum(vector<int> a, int l, int r)
{
    if(l>r){
        return INT_MIN;
    }
    if(l==r){
        return a[l];
    }

    int mid = (l+r)/2;

    int leftSum = maxSubarraySum(a, l, mid-1);
    int rightSum = maxSubarraySum(a, mid+1, r);
    int crossSum = maxCrossSum(a, l, mid, r);

    return max({leftSum, rightSum, crossSum});
}


int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }

    cout << maxSubarraySum(a, 0, n-1);
}


