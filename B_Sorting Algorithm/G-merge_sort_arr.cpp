#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int l,int mid,int r)
{
    int n1= mid-l+1;
    int n2= r-mid;

    int b[n1];
    int c[n2];

    for(int i=0 ; i<n1 ; i++){
        b[i]= a[l+i];
    }
    for(int i=0 ; i<n2 ; i++){
        c[i]= a[mid+1+i];
    }

    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(b[i] < c[j])
        {
            a[k]= b[i];
            k++;i++;
        }
        else
        {
            a[k]= c[j];
            k++;j++;
        }
    }
    while(i<n1)
    {
        a[k]= b[i];
        k++;i++;
    }
    while(j<n2)
    {
        a[k]= c[j];
        k++;j++;
    }
}

void merge_sort(int a[],int l,int r)
{
    if(l<r)             //l=r means ar ekta element ace baki
    {
        int mid= (l+r)/2;
        merge_sort(a,l,mid);
        merge_sort(a,mid+1,r);

        merge(a,l,mid,r);
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
    merge_sort(a,l,r);
    for(int i=0 ; i<n ; i++){
        cout << a[i] << " ";
    }
}
