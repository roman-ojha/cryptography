/*  this program calculates the Key for two persons  using the Diffie Hellman Key exchange algorithm */ 
#include<stdio.h>
long int power(int a,int b,int mod)
 {
  long long int t;
  if(b==1)
  return a;
  t=power(a,b/2,mod);
  if(b%2==0)
   return (t*t)%mod;
  else
   return (((t*t)%mod)*a)%mod;
 }
 long long int calculateKey(int a,int x,int n)
 {
  return power(a,x,n);
 }
 int main()
 {
  int n,r,x,a,y,b;
  long int s1,s2;  
// prime number n and its primitive root r is common for both the parties 
  printf("Enter the prime number n and and its primitive root g : "); 
  scanf("%d%d",&n,&r);    
// first person will choose the x  
  printf("Enter the value of secret key for the first party : ");
  scanf("%d",&x);  
  a=power(r,x,n);//compute the public key for the first party
  printf("The public key for the first party = %d\n",a);

// second person will choose the y
  printf("Enter the value of secret key for the second party : ");
  scanf("%d",&y);  
  b=power(r,y,n);//compute the public key for the second party
  printf("The public key for the second party = %d\n",b);
  s1 = power(b,x,n);
  s2 = power(a,y,n);
  printf("Session key for the first person is = %ld\n",s1);
  printf("Session key for the second person is = %ld\n",s2);
  return 0;
 }