#include<stdio.h>
#include<string.h>

int main(int argc, char **argv)
{
    FILE *file = NULL;                     //initailizing pointer file to NULL 
    
    if ( argc < 2 )                        //validating file input 
    {
    	printf("ERROR FILE NAME IS MISSING\n");
    	return 0;
    }
    else if ( argc > 2 )
    {
    	printf("ERROR ONLY ONE FILE IS REQUIRED\n");
    	return 0;
    }
    
    file = fopen(argv[1], "r");          //opening file into file pointer
    
    if ( file == NULL )  			//validating file opening
    {	
    	printf("ERROR READING THE FILE\n");
    	return 0;
    }
    
    int n;
    fscanf(file, "%d", &n);     	//scaning no of ques from file
    
    if ( n <= 0 )			//validating ques no
    {
    	printf("ERROR INVALID QUESTIONS NUMBER\n");
    	fclose(file);
    	return 0;
    }
    
    
    char Ques[n][100];
    char Ans[n][7];
    char UserAns[n][7];
    char valid1[5]={'T','r','u','e'};			//creating the checking file
    char valid2[5]={'F','a','l','s','e'};
    int score=0,wrong[n],l=0;
    fgetc(file);
    
    for (int i=0; i<n; i++ )
    {
    	fgets(Ques[i], 100, file);			//scanning ques from file
    	Ques[i][strlen(Ques[i])-1]='\0';
    	
    	fgets(Ans[i], 7, file);
    	Ans[i][strlen(Ans[i])-1]='\0';	
    }
    
    for (int i=0; i<n; i++ )
    {	
    	printf("Q%d %s\n", i+1, Ques[i]);
    	printf("Enter 'True' or 'False' : ");
    	fgets(UserAns[i], 7, stdin);
    	
    	printf("\n");
    	
    	
    	if ( UserAns[i][1]==Ans[i][1] && UserAns[i][2]==Ans[i][2] && UserAns[i][3]==Ans[i][3] )
    	{
    		score++;
    	}
    	else 
    	{
    		wrong[l]=i;
    		l++;
    	}
    	
    }
    
    if (l==0)
    {
    	printf("ALL ANSWERS ARE CORRECT\n\n");
    }
    else
    {
    	printf("WRONG ANSWERS : %d\n\n",l);
    	
    	for (int i=0;i<l;i++)
    	{
    		printf("Q%d %s\n",wrong[i+1] , Ques[wrong[i]]);
    		printf("CORRECT ANSWER : %s\n\n",Ans[wrong[i]]);
    	}
    }
    
   
    
    printf("YOUR SCORE IS %d OUT OF %d\n",score,n);
    
    fclose(file);
    return 0;
    
    
}
