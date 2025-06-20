#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int inputBase;
	scanf("%d",&inputBase);
	int outputBase;
	scanf("%d",&outputBase);
	
	if (n<=0 || inputBase<2 || outputBase>10 || outputBase<2 )
	{
		printf("INVALID INPUT");
		return 0;
	}

	int nCopy=n;
	int dCount=0;
	int decimalSum=0;
	
	while (nCopy != 0)
	{
		dCount=dCount+1;
		int k=1;
		if (nCopy%10>=inputBase)
		{
			printf("INVALID INPUT");
			return 0;
		}
		for (int i=0;i<dCount-1;i++)
		{
			k=k*inputBase;
		}
		decimalSum=decimalSum+((nCopy%10)*k)
		nCopy=nCopy/10;
	}
	
	int pow=1;
	int sum=0;
	while (decimalSum!=0)
	{
		sum=sum+((decimalSum%outputBase)*pow);
		pow=pow*10;
		decimalSum=decimalSum/2;
	}
	
	printf("%d",sum);
	
	
	/*
	while (nCopy != 0)
	{
		dCount=dCount+1;
		Pow=Pow*10;
		if (nCopy%10>=inputBase)
		{
			printf("INVALID INPUT");
			return 0;
		}
		nCopy=nCopy/10;
	}
	
	Pow=Pow/10;
	int SumtoDecimal=0;
	while (dCount!=0)
	{
		int k=n/Pow;
		n=n%Pow;
		Pow=Pow/10;
		int nBase=1;
		for (int i=0;i<dCount-1;i++)
		{
			nBase=nBase*inputBase;
		}
		SumtoDecimal=SumtoDecimal+(k*nBase)

		dCount=dCount-1;
		
		
	}*/
	
	

}