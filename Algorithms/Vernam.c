#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char msg[100], key[100], encMsg[100], decMsg[100];
int msgLen;
void decrypt();
void encrypt()
{
    int i;
    printf("Enter the plaintext:");
    scanf("%s", msg);
    printf("Enter the key (The length of the key must be equal to length of the message):");
    scanf("%s", key);
    msgLen = strlen(msg);
    if (strlen(key) != msgLen)
    {
        printf("Invalid Key. The lengths of Message and Key are not equal.");
        exit(0);
    }
    for (i = 0; i < msgLen; i++)
    {
        msg[i] = toupper(msg[i]);
        key[i] = toupper(key[i]);
        encMsg[i] = ((msg[i] + key[i]) % 26) + 'A';
    }
    printf("\nThe encrypted text is:%s", encMsg);
}
void decrypt()
{
    int i;
    printf("Enter the ciphertext:");
    scanf("%s", msg);
    printf("Enter the key (The length of the key must be equal to length of the cipher):");
    scanf("%s", key);
    msgLen = strlen(msg);
    if (strlen(key) != msgLen)
    {
        printf("Invalid Key. The lengths of Cipher and Key are not equal.");
        exit(0);
    }
    for (i = 0; i < msgLen; i++)
    {
        msg[i] = toupper(msg[i]);
        key[i] = toupper(key[i]);
        decMsg[i] = ((msg[i] - key[i] + 26) % 26) + 'A';
    }
    printf("\nThe decrypted text is:%s", decMsg);
}
int main()
{
    int choice;
    printf("1. Encryption\n2. Decryption\n3. Exit\nEnter your choice:");
    scanf("%d", &choice);
    if (choice == 1)
    {
        encrypt();
    }
    else if (choice == 2)
    {
        decrypt();
    }
    else if (choice == 3)
    {
        printf("Program is exiting");
        exit(0);
    }
    else
    {
        printf("invalid Choice!");
        exit(0);
    }
    return 0;
}