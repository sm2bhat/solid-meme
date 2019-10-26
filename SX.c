//Solved storming X question using perimeter of figure and of rectangle

#include<stdio.h>
#include<math.h>
int main()
{
	long long int n,x[100050],y[100050],ans,i,j,rect=0,peri=0;
	long long int minx=5000000,miny=5000000,maxx=-5000000,maxy=-5000000;
	//long long int A[5]={5000000,-5000000},B[5]={-5000000,-5000000},C[5]={-5000000,5000000},D[5]={5000000,5000000};
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&x[i],&y[i]);
		if(i)
			peri=peri+fabs(x[i]-x[i-1])+fabs(y[i]-y[i-1]);

		/*if(x[i]<A[0] && y[i]>A[1])
		{
			A[0]=x[i];
			A[1]=y[i];
		}

		else if(x[i]>B[0] && y[i]>B[1])
		{
			B[0]=x[i];
			B[1]=y[i];
		}

		else if(x[i]>C[0] && y[i]<C[1])
		{
			C[0]=x[i];
			C[1]=y[i];
		}

		else if(x[i]<D[0] && y[i]<D[1])
		{
			D[0]=x[i];
			D[1]=y[i];
		}*/
		if(x[i]>maxx)
			maxx=x[i];
		else if(x[i]<minx)
			minx=x[i];

		if(y[i]>maxy)
			maxy=y[i];
		else if(y[i]<miny)
			miny=y[i];

	}
	peri=peri+fabs(x[0]-x[n-1])+fabs(y[0]-y[n-1]);
	//printf("\n%lld  %lld | %lld  %lld\n",maxx,minx,maxy,miny);
	rect=2*(fabs(maxx-minx) + fabs(maxy-miny));
	//printf("\n%lld    %lld\n",rect,peri);
	ans=fabs(peri-rect);
	printf("%lld\n",ans);

}
