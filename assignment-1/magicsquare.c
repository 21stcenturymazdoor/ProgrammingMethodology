#include<stdio.h>

/*function to validate a magic square*/
int validMagic(int size,int a[size][size])
{
	int magicsum=size*(size*size+1)/2;
	
	/*validating rows then columns, then diagonals*/

	for (int i=0;i < size;i++)
	{
		int sum1=0,sum2=0,diag=0;
		
		for (int j=0;j<size;j++)
		{
			sum1=sum1+a[i][j]; //rows
			sum2=sum2+a[j][i]; //columns
			 
			if (i==j) //main diagonal
			{
				diag=diag+a[i][i];
			}
			
		}
		
		int diag2=0;
		/*other diagonals*/
		for ( int k=0;k<size;k++)
		{
			for (int l=size-1;l>=0;l--)
			{
				diag2=diag2+a[k][l];
			}
		}
		if (sum1!=magicsum || sum2!=magicsum || diag!=magicsum || diag2!=magicsum)
		{
			return 0;
		}
	}
	
	return 1;
	
}


/*function to generate magic square by staircase method*/
void magicSquareStaircase(int n)
{
	
	
	
	int mtx[n][n];
	
	/*initializing all elements of the array with 0*/
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			mtx[i][j]=0;
		}
	}
	
	/* Set initial position for 1 */
    	int i = n / 2;
   	int j = n - 1;
  	/*Filling of  the elements in magic square*/
 	for (int num = 1; num <= n * n;) 
 	{
     		if (i == -1 && j == n) 
      		{
          		  j = n - 2;
        		  i = 0;
    		}
    		else 
 	        {
          	  /*Wrap around when elements clash*/
         		if (j == n)
          	      		j = 0;
         		if (i < 0)
                		i = n - 1;
       		}
        	if (mtx[i][j] != 0) 
      		{
         		   j -= 2;
   		           i++;
        		   continue;
    		}
    		  else
    		  	mtx[i][j] = num++;
        	j++;
      		i--;
      		
      	}
	
	
	int valid=validMagic(n,mtx);
	
	if (valid==1)
	{
		printf("This program generates a valid magic square\n");
	}
	else
	{
		printf("INVALID MAGIC SQUARE");
	}
	
	/*printing the magic square after validating*/
	printf("Magic square for n=%d\n\n",n);
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			printf(" %4d ",mtx[i][j]);
		}
		printf("\n");
	}
	
	
}



/*start of main function*/
int main()
{
	int size;
	printf("ENTER THE ODD NUMBER OF WHICH YOU WANT TO FIND THE MAGIC SQUARE :");
	scanf("%d", &size);
	
	
	/*cheking if size is positive and odd*/
	if ( size <= 0 || size % 2 == 0 )
	{
		printf("INVALID INPUT\n");
		return 0;
	}
	
	
	magicSquareStaircase(size);
	
	return 0; /*program ended successfully*/
	
}/*end of main function*/
