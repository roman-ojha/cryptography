//MONOALPHABATIC CIPHER
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
            char pt[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
            char ct[26]={'Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K','J','I','H','G','F','E','D','C','B','A'};
            char p[50]={'\0'},c[50]={'\0'},r[50]={'\0'};
            int i,j;
            printf("\n enter the plain text:");
            scanf("%s",p);
            //converting plain text into cipher text (encryption)
            for(i=0;i<strlen(p);i++)
            {
                p[i] = toupper(p[i]);
                        for(j=0;j<26;j++)
                        {
                        if(pt[j]==p[i])
                        {
                                    c[i]=ct[j];
                        }
                        }
            }
            printf("\n cipher text is: %s",c);

            //converting cipher text into plain text (decryption)
            for(i=0;i<strlen(c);i++)
            {
                        for(j=0;j<26;j++)
                        {
                        if(ct[j]==c[i])
                        {
                                    r[i]=pt[j];
                        }
                        }
            }
            printf("\n \n plain text is: %s",r);
            return 0;
}