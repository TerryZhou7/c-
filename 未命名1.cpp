#include <stdio.h>
#include <stdlib.h> 
void exchange1(int *,int ,int);
void exchange2(int *,int ,int);
int main()
{
	int t,cntt,m,n,cnt,x,y,z,cnt1,g,cnt2;
	int *a;
	scanf("%d",&t);
	for (cntt =0;cntt <t;cntt ++)
	{
		scanf("%d %d",&n,&m);
		a =(int *)malloc(sizeof(int)*n);
		for (cnt =0;cnt <n;a[cnt] =cnt+1,cnt ++);
		for (cnt =0;cnt <m;cnt ++)
		{
			scanf("%d %d %d",&x,&y,&z);
			for (cnt1 =0;cnt1 <n;cnt1 ++)
			{
				if (a[cnt1] ==y)
				{
					for (cnt2 =0;cnt2 <n;cnt2 ++)
					{
						if (a[cnt2] ==z)
							break;
					}
					break;
				}
			}
			if (x ==1)
				exchange1(a,cnt1,cnt2);
			else 
			{
				if(cnt2 !=n-1)
					exchange1(a,cnt1,cnt2+1);
				else
				{
					g =a[cnt1];
					for (;cnt1 <n;cnt1 ++)
						a[cnt1] =a[cnt1+1];
					a[n-1] =g;
				}
			}
		}
		for (cnt1 =0;cnt1 <n;cnt1 ++)
			printf("%d ",a[cnt1]);
		printf("\n");
		free(a);
	}
	return 0;
}
void exchange1(int *a,int y ,int z)
{
	int cnt,t;
	t =a[y];
	if (y <z)
	{
		for (cnt =y;cnt <z-1;cnt ++)
		a[cnt] =a[cnt+1];
		a[z-1] =t;
	}
	else
	{
		for (cnt =y;cnt >z;cnt --)
		a[cnt] =a[cnt-1];
		a[z] =t;
	}
}
