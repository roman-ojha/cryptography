#include<stdio.h>
 
int gcd_euclid(int a, int b)
{
    int x,y;
    
    if(a>b){
        x = a;
        y = b;
    }
    else{
        x = b;
        y = a;
    }
   
    if (y == 0) 
    {
        return x;
    } 
    else 
    {
        return gcd_euclid(y, (x % y));
    }
}
 
int main()
{
    int num1, num2, gcd;
    printf("\nEnter two numbers to find gcd using Euclidean algorithm: ");
    scanf("%d%d", &num1, &num2);
    gcd = gcd_euclid(num1, num2);
 
    printf("The GCD of %d and %d is %d\n", num1, num2, gcd);
    return 0;
}