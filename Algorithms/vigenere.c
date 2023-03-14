#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

//encryption
void encrypt(char msg[100],char newKey[100],int msgLen){
    int i;
    char encryptedMsg[100]={'\0'};
    for(i = 0; i < msgLen; ++i){
        msg[i] = toupper(msg[i]);
        encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A';
    }
    printf("\nOriginal Message: %s", msg);
    printf("\nEncrypted Message: %s", encryptedMsg);
}
 
 
//decryption
void decrypt(char msg[100],char newKey[100], int msgLen){
    int i;
    char decryptedMsg[100]={'\0'};
    for(i = 0; i < msgLen; ++i){
        msg[i] = toupper(msg[i]);
        decryptedMsg[i] = (((msg[i] - newKey[i]) + 26) % 26) + 'A';
    }
    printf("\nEncrypted Message: %s", msg);
    printf("\nDecrypted Message: %s", decryptedMsg);
}    
int main(){
    char msg[100] = {'\0'},key[25] = {'\0'},newKey[100]={'\0'};
    int msgLen, keyLen, i, j, choice;
    printf("1 Encryption\n2 Decryption\n3 Exit \nEnter your choice:");
    scanf("%d",&choice);
    printf("Enter the key:");
    scanf("%s",key);
    printf("Enter the text:");
    scanf("%s",msg);
    msgLen = strlen(msg);
    keyLen = strlen(key);

    //generating new key
    for(i = 0, j = 0; i < msgLen; ++i, ++j){
        if(j == keyLen)
            j = 0;
 
        newKey[i] = toupper(key[j]);
    }
    printf("\nKey: %s", key);
    printf("\nNew Generated Key: %s", newKey);
    if(choice==1){
        encrypt(msg,newKey,msgLen);
    }
    else if(choice==2){
        decrypt(msg,newKey,msgLen);
    }
    else if(choice==3){
        printf("Program is exiting.");
        exit(0);
    }
    else{
        printf("Invalid choice.");
        exit(0);
    }
    return 0;
}