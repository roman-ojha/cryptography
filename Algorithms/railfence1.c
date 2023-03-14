#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char msg[100]={'\0'};
int key;
void encrypt(){
    int msgLen = strlen(msg), i, j, k = -1, row = 0, col = 0;
    char railMatrix[key][msgLen];
 
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            railMatrix[i][j] = '\n';
 
    for(i = 0; i < msgLen; ++i){
        railMatrix[row][col++] = msg[i];
 
        if(row == 0 || row == key-1)
            k= k * (-1);
 
        row = row + k;
    }
 
    printf("\nEncrypted Message: ");
 
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            if(railMatrix[i][j] != '\n')
                printf("%c", railMatrix[i][j]);
}
 
void decrypt(){
    int msgLen = strlen(msg), i, j, k = -1, row = 0, col = 0, m = 0;
    char railMatrix[key][msgLen];
 
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            railMatrix[i][j] = '\n';
 
    for(i = 0; i < msgLen; ++i){
        railMatrix[row][col++] = '*';
 
        if(row == 0 || row == key-1)
            k= k * (-1);
 
        row = row + k;
    }
 
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            if(railMatrix[i][j] == '*')
                railMatrix[i][j] = msg[m++];
 
    row = col = 0;
    k = -1;
 
    printf("\nDecrypted Message: ");
 
    for(i = 0; i < msgLen; ++i){
        printf("%c", railMatrix[row][col++]);
 
        if(row == 0 || row == key-1)
            k= k * (-1);
 
        row = row + k;
    }
}
int main(){
    int choice;
    printf("1. Encryption\n2. Decryption\n3. Exit\nEnter your choice:");
    scanf("%d",&choice);
    if(choice==1){
        printf("Enter the plaintext:");
        scanf("%s",msg);
        printf("Enter the key (No. of fence):");
        scanf("%d",&key);
        encrypt();
    }
    else if(choice==2){
        printf("Enter the ciphertext:");
        scanf("%s",msg);
        printf("Enter the key (No. of fence):");
        scanf("%d",&key);
        decrypt();
    }
    else if(choice==3){
        printf("Program is exiting");
        exit(0);
    }
    else{
        printf("invalid Choice!");
        exit(0);
    }
    return 0;
}