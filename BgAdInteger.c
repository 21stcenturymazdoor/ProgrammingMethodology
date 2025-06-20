#include<stdio.h>

int Countstring1(char string[])          //counting function for first strings with index like counting
{
    int i=0, count=0;

    while ( string[i] != ' ' )           //counting until we get space so that we only count until first string number
    {
        count++;
        i++;
    }

    return count;

}

int Countstring2(char string[])            //counting until we ger null in strings
{
    int i=0, count=0;

    while ( string[i] != '\0' )
    {
        count++;
        i++;
    }

    count = count - (Countstring1(string)+1);       //calculating total digits in string2
    return count-1;

}

void String_Int(char string[])              //changing strings to integer
{   
    int total = (Countstring1(string)+Countstring2(string));

    while ( total != Countstring1(string) )
    {
        string[total] = string[total] - 48;
        total--; 
    }

    total=total-1;

    while ( total >= 0 )
    {
        string[total] = string[total] - 48;
        total--;
    }
    
   
}



int main()
{
    char string[100];
    fgets( string, 100, stdin );           //using fgets function to read all strings at one time

    for ( int i = 0; i < Countstring1(string); i++)     //validating the input for first group of string
    {
        if ( string[i] >= '0' && string[i] <= '9')
        {
            continue;
        }
        else
        {
            printf("INVALID INPUT");
            return 0;
        }
    }
    for ( int i = Countstring1(string) + 1; i <= Countstring2(string) + Countstring1(string); i++ )   //validating input for second group of strings
    {
        if ( string[i] >= '0' && string[i] <= '9')
        {
            continue;
        }
        else
        {
            printf("INVALID INPUT");
            return 0;
        }
    }

    int CountIndex1 = Countstring1(string) -1, CountIndex2 = Countstring2(string) + Countstring1(string), max, min, maxforindex;

    if ( Countstring1(string) > Countstring2(string) )  //finding in which group of strings the digits are maximum
    {
        max = Countstring1(string) -1;
        maxforindex =  Countstring1(string) -1;
        min = Countstring2(string) -1;
        
    }
    else
    {
        max = Countstring2(string) -1;
        maxforindex =  Countstring1(string) + Countstring2(string);
        min = Countstring1(string) -1;
    }

    String_Int(string);
    int ansstring[min], sum, caree = 0;

    int diff = max -min, mincopy = min;

    while ( min >= 0 )
    {
        sum = string[CountIndex1] + string[CountIndex2] + caree;   // using simple addition method
        ansstring[min] = sum%10;
        caree = sum / 10;
        CountIndex1--;
        CountIndex2--;
        maxforindex--;
        max--;
        min--;
    }

    while ( max >= 0 )
    {
        sum = string[maxforindex] + caree;         //getting the left out digits
        string[max] = sum%10;
        caree = sum / 10;
        maxforindex--;
        max--;
    }

   int Int_String[100], firstdigit;     //inputing a new array which will have ans integers
    
    if ( caree != 0)
    {
        firstdigit = 0;
    }
    else{
        firstdigit = 1;
    }

    Int_String[0]=caree;

    for ( int i = 0 ; i < diff ; i++ )                 //copying the ans to the Int_String array
    {
       Int_String[i + 1] = string[i];
    }

    for ( int i = 0 ; i <= mincopy ; i++)
    {
        Int_String[diff + 1 + i] = ansstring[i];
    }

    int rep = firstdigit + mincopy + diff+1;

    for ( int i = firstdigit; i<rep; i++)       //converting ans from integer to character
    {
         switch(Int_String[i])
         {
            case 0:Int_String[i]='0';
                   break;
                   
            case 1:Int_String[i]='1';
                   break;

            case 2:Int_String[i]='2';
                   break;

            case 3:Int_String[i]='3';
                   break;

            case 4:Int_String[i]='4';
                   break;

            case 5:Int_String[i]='5';
                   break;

            case 6:Int_String[i]='6';
                   break;

            case 7:Int_String[i]='7';
                   break;

            case 8:Int_String[i]='8';
                   break;

            default:Int_String[i]='9';
                 
         }
    }


    for ( int i = firstdigit; i<rep; i++)   //printing the character ans
    {
        printf("%c", Int_String[i]);
    }

}

