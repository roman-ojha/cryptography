#include<stdio.h>


int modInverse(int a, int m)
{
    int x;
	for (int x = 1; x < m; x++)
		if (((a % m) * (x % m)) % m == 1)
			return x;
}

int main()
{
	int a,m,minv,adInv;
	
	printf("Enter the number and the modulo:");
	scanf("%d%d",&a,&m);
	minv = modInverse(a,m);
	adInv = m - a;
	printf("\nAdditive inverse of %d mod %d = %d",a,m,adInv);
	// Function call
	printf("\nMultiplicative inverse of %d mod %d = %d",a,m,minv);
	return 0;
}
