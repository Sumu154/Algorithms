#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int r)  //pivot ke right positione boshanor kaj kore
{
    int pivot= a[r];
    int i= l-1;

    for(int j=l ; j<r ; j++){
        if(a[j] < pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}

void quick_sort(int a[], int l, int r)
{
    if(l<r)
    {
        int pivot_pos= partition(a,l,r); //pivoter right position ta return kore partition function jeta i+1
        quick_sort(a,l,pivot_pos-1);     //pivoter ager elementgulak right positione boshay
        quick_sort(a,pivot_pos+1,r);     //poer gulak
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n+1];
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }

    int l=0,r= n-1;
    quick_sort(a,l,r);
    for(int i=0 ; i<n ; i++){
        cout << a[i] << " ";
    }
}
