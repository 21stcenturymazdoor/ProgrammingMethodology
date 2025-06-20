#include<stdio.h>

/*program to count digits, space, vowels, symbols,alphabets*/

/*function to count vowels in the st*/
int countVowel(char str[])
{
	int i=0, vowelCounter=0;
	while (str[i++]!='\0')
	{
		if (str[i]=='a'|| str[i]=='e' || str[i]=='i' ||  str[i]=='o' ||  str[i]=='u' ||  str[i]=='A' ||  str[i]=='E' ||  str[i]=='I' ||  str[i]=='O' ||  str[i]=='U')
   		{
        		++vowelCounter;
    		}
    	}
    	
    	return vowelCounter;

}

int main()
{


	char st[100];
	fgets(st,100,stdin);
	/*taking input from user*/
   
   
	int Cdig=0,Calp=0,Csym=-1,Cspa=0;
   
	int vowel=countVowel(st);
   
   
   	/*loop to count digits, alphabets,space, symbols*/
	int i=0;
	while (st[i]!='\0')
	{
	   	if ( st[i]>='0' && st[i]<='9' )
	   	    Cdig++;
	   	else if (( st[i]>='A' && st[i]<='Z') || ( st[i]>='a' && st[i]<='z' ))
	   	    Calp++;
	   	else if ( st[i]==' ')
	   	    Cspa++;
	   	else 
	   	    Csym++;
	   	    
		i=i+1;
	}
  
  
	printf("#digits=%d, #wspace=%d, #vowels=%d, #alphabets=%d, #symbol=%d", Cdig, Cspa, vowel, Calp, Csym);
   
   
	return 0;/*program ended successfully*/
   
}/*main function ends*/
