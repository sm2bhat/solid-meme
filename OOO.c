#include<stdio.h>
long long int n,count=0;

void merge(long long int a[100050],long long int p,long long int q,long long int r);

void mergeSort(long long int a[100050],long long int p,long long int r)
{
    long long int q;
    if(p < r)
    {
        q = (p + r) / 2;
        mergeSort(a, p, q);
        mergeSort(a, q+1, r);
        merge(a, p, q, r);
    }
}


void merge(long long int a[100050],long long int p,long long int q,long long int r)
{
    long long int b[n],i, j, k;
    k = 0;
    i = p;
    j = q + 1;
    while(i <= q && j <= r)
    {
        if(a[i] <= a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
            //count=count+q-i+1;
        }
    }

    while(i <= q)
    {
        b[k++] = a[i++];
    }

    while(j <= r)
    {
        b[k++] = a[j++];
    }

    for(i=r; i >= p; i--)
    {
        a[i] = b[--k];
    }
}

int main()
{
    long long int t,array[100050],i,j;
    scanf("%lld",&t);
    for(i=0;i<t;i++)
    {
        scanf("%lld",&n);
        for(j=0;j<n;j++)
            scanf("%lld",&array[j]);
        mergeSort(array,0,n-1);
        j=0;
        while(j<n)
        {
            if(array[j]!=array[j+1])
            {
                printf("%lld\n",array[j]);
                break;
            }
            j=j+3;
        }
    }
    return 0;
    //ghfhj
}
