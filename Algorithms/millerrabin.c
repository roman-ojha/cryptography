// Determining whether a number is a prime or not

# include<stdio.h>
#include<stdlib.h>
# include<math.h>

// Function for modular exponentiation. It returns (x^y) % p
int power(int x, unsigned int y, int p){
    int res = 1;
    
    // Update x if it is more than or equal to p
    x = x % p; 
    
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y % 2 ==1)
            res = (res*x) % p;
 
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

// This function is called for all k trials.
int millerRabinTest(int d, int n){
    
    // Pick a random number in [2,n-2]
    // n > 4, because of the corner cases
    int a = 2 + rand() % (n - 4);
 
    // Computing a^d % n
    int x = power(a, d, n);
 
    if (x == 1  || x == n-1)
       return 1;
 
    // Keep squaring x till:
    // (i)  (x^2) % n is not 1
    // (ii) (x^2) % n is not n-1
    while (d != n-1){
        x = (x * x) % n;
        d *= 2;
 
        if (x == 1)      return 0;
        if (x == n-1)    return 1;
    }
 
    // Return composite
    return 0;
}

// Function for Primality test
int isPrime(int n, int k){
    
    // Corner Cases
    if (n<=3)
        return n>1;
    else if (n==4)
        return 0;
    
    // Finding r such that n = 2^d * r + 1, (r > 0)
    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    
    // Iterating k times
    for (int i = 0; i < k; i++)
         if (!millerRabinTest(d, n))
              return 0;
              
    return 1;
}

int main(){
    int k = 10,x;
    printf("Enter the number:");
    scanf("%d",&x);
    isPrime(x,k)?printf("%d is probably a prime number",x):printf("%d is a composite number",x);
}