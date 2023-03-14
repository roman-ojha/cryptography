#include <stdio.h>
 
int extended_euclid(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    int p, q;
    int gcd = extended_euclid(b % a, a, &p, &q);
 
    *x = q - (b/a) * p;
    *y = p;
 
    return gcd;
}
 
int main()
{
    int a,b,x,y,gcd;

    printf("Enter the two numbers:");
    scanf("%d%d",&a,&b);
    gcd = extended_euclid(a,b,&x,&y);
    printf("The GCD of %d and %d = %d \n",a,b,gcd);
    printf("x = %d, y = %d", x, y);
 
    return 0;
}