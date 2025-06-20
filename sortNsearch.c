#include<stdio.h>

/*function for insertion sort*/
int insertSort(int size, int a[])
{
	int j;
	
	for (int i=1;i<size;i++)
	{
		j=i;
		
		while (j>0)
		{
			if (a[j-1] > a[j])
			{
				int temp=a[j-1];
				a[j-1]=a[j];
				a[j]=temp;
				--j;
			}
		}
	}
	
	
	for (int i=0;i<size;i++)
	{
		printf("%d ",a[i]);
	}
	
}

/*function for binary search*/

int binarySearch(int size, int a[], int ele)
{
	int left=0,right=size-1;
	
	while (left <= right)
	{
		int mid=(left+right)/2;
		
		if (a[mid]==ele)
			return 1;
		else if (a[mid] < ele )
			left=mid+1;
		else
			right=mid-1;
	}
	
	return 0;
}

int main()
{
	
	int n;
	scanf("%d",&n);
	
	if ( n <=0 )
	{
		printf("INVALID INPUT");
		return 0;
	}
	
	int a[n];  /*input elements in list*/
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	int e;
	scanf("%d",&e); /*input element you want to find*/
	
	insertSort(n,a); /*function call for insertion sort*/
	

	
	int bin=binarySearch(n,a,e); /*function call for binary search*/
	printf("%d",bin);
	
	return 0; /*program ended successfully*/
	
	
} /*end of main function*/

