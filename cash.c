#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float a;
    do
    {
        a = get_float("Change owed: ");
    }
    while (a < 0);
    //dollars to cents - store as int to avoid float imprecision
    int b = round(a*100);
    //counter
    int c =0;
    while (b >= 25)
    {
        b -= 25;
        c += 1;
    }
    while (b >= 10)
    {
        b -= 10;
        c += 1;
    }
    while (b >= 5)
    {
        b -= 5;
        c += 1;
    }
    while (b >= 1)
    {
        b -= 1;
        c += 1;
    }
    printf("%i\n",c);
}