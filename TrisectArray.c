//Solving TA problem using sum array and PnC
#include <stdio.h>
long long sum[1000009],arr[1000009],ind[3][1000009];
int main()
{
	long long i,j,k,h,n,count1=0,count2=0,count=0,total,compare;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
			if(i)
				sum[i]=sum[i-1]+arr[i];
			else
				sum[0]=arr[0];
           // printf("%lld ",sum[i]);
		}
	total=sum[n-1];
	compare=total/3;
	//printf("\n%lld\n",total);
	h=0;
	for(i=0;i<n-2;i++)
	{
		if(sum[i]==compare)
			{
				ind[0][h]=i;;
				count1++;
				h++;
			}
		//if(sum[i]==2*compare)
		//	index[i]=2;
	}
	/*for(i=0;i<h;i++)
		printf("%lld ",ind[0][i]);
	printf("\n");*/

	k=0;
	for(i=0;i<n-1;i++)
	{
		if(sum[i]==2*compare)
		{
			ind[1][k]=i;
			count2++;
			k++;
		}
	}
	/*for(i=0;i<k;i++)
		printf("%lld ",ind[1][i]);
	printf("\n");*/

	/*for(i=0;i<h;i++)
		for(j=0;j<k;j++)
			if(ind[0][i]<ind[1][j])
				count++;
				*/
	j=0;
	for(i=0;i<h;i++)
	{
		if(ind[0][i]<ind[1][j])
			{
				count=count=count+k-j;
				continue;
			}

		while(ind[0][i]>=ind[1][j])
		{
			j++;
			if (j>=k)
			{
				break;
			}
			if(ind[0][i]<ind[1][j])
			{
				count=count+k-j;
				break;
			}
		}
		if (j>=k)
			{
				break;
			}
	}

	printf("%lld\n",count);
	return 0;
}
