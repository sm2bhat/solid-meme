//Solving MRT question using binary search + merge sort
#include <stdio.h>
long long int s;
void merge(long long int a[1000000],long long int p,long long int q,long long int r);

void mergeSort(long long int a[1000000],long long int p,long long int r)
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


void merge(long long  int a[1000000],long long int p,long long int q,long long int r)
{
    long long int b[s],i, j, k;
    k = 0;
    i = p;
    j = q + 1;
    while(i <= q && j <= r)
    {
        if(a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
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
	long long int array[100050],difference[100050];
	long long int w,i,j,t,ans,count;
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lld%lld",&w,&s);
		for(j=0;j<s;j++)
		{
			scanf("%lld",&array[j]);
			if(j)
				difference[j]=array[j]-array[j-1]-1;
			else
				difference[0]=0;
		}

		//for(j=0;j<s;j++)
			//printf("%lld ",difference[j]);
		//printf("\n");

		mergeSort(difference,0,s-1);

		//for(j=0;j<s;j++)
			//printf("%lld ",difference[j]);
		//printf("\n");

        ans=difference[s-w+1];
        printf("%lld\n",ans);
	}
	return 0;
}
