#include <stdio.h> 
int main () 

{ 

    char text [100]; 

    int shift; 

    printf ("Enter plaintext: "); 

    gets(text); 

    printf ("Enter shift: "); 

    scanf ("%d", &shift); 

    for (int i = 0; text[i] != '\0'; i++) 

    { 

        if (text[i] >= 'a' && text[i] <= 'z') 

            text[i] = (text[i] - 'a' + shift) % 26 + 'a'; 

        else if (text[i] >= 'A' && text[i] <= 'Z') 

            text[i] = (text[i] - 'A' + shift) % 26 + 'A'; 

    } 

    printf ("Cipher text: %s", text); 

    return 0; 

}
int main() 

{ 

    char text[100]; 

    int shift; 

    printf ("Enter ciphertext: "); 

    gets(text); 

    printf ("Enter shift: "); 

    scanf("%d", &shift); 

    int len = strlen(text); 

    for (int i = 0; i < len; i++) 

    { 

        if (text[i] >= 'a' && text[i] <= 'z') 

        { 

            text[i] = ((text[i] - 'a' - shift + 26) % 26) + 'a'; 

        } 

        else if (text[i] >= 'A' && text[i] <= 'Z') 

        { 

            text[i] = ((text[i] - 'A' - shift + 26) % 26) + 'A'; 

        } 

    } 

    printf ("Plaintext: %s", text); 

    return 0; 

} 