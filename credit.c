#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //prompt user for card number
    long n;
    do
    {
        n = get_long("Number: ");
    }
    while (n < 0);
    //Luhn's algorithm + track digits for card identification
    int count = 0;
    int sum = 0;
    int x;
    int amex;
    int master;
    while(n)
    {
        x = n%10;
        if (count%2==0)
        {
            sum += x;
        }
        else if (x < 5)
        {
            sum += x*2;
        }
        else
        {
            sum += ((x*2)%10) + 1;
        }
        count +=1;
        //2nd to last digit if amex
        if (count==14)
        {
            amex = x;
        }
        //2nd to last digit if mastercard
        if (count==15)
        {
            master = x;
        }
        n /= 10;
        //printf("count: %i, digit:%i, sum: %i\n",count,x,sum);
    }
    //does not satisfy Luhn's algorithm
    if (sum%10!=0)
    {
        printf("INVALID\n");
    }
    //amex cards have 15 digits and start w 34 or 37
    else if (count==15 && x==3 && (amex==4 || amex==7))
    {
        printf("AMEX\n");
    }
    //visa cards have 13 or 16 digits and start w 4
    else if ((count==13 || count==16) && x==4)
    {
        printf("VISA\n");
    }
    //mastercard cards have 16 digits and start w 51-55
    else if (count==16 && x==5 && master>0 && master<6)
    {
        printf("MASTERCARD\n");
    }
    //satisfies Luhn's algorithm, but doesn't fall into a known card category
    else
    {
        printf("INVALID\n");
        //printf("count: %i, x: %i\n",count,x);
    }
}
