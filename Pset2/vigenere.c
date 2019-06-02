#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Shift function declaration
int shift(char c);

int main(int argc, string argv[])
{
    // Assign to a string variable the command-line argument which is the key
    string keyPhrase = argv[1];  
    // Check to see only one command-line argument is entered
    if (argc != 2) 
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    else
    {
        // Iterate over number of arguments
        for (int i = 1; i < argc; i++) 
        {
            // Iterate on every element of second argument
            for (int j = 0, n = strlen(argv[i]); j < n; j++) 
            {
                // Check if all characters in key are alphabetical, continue to encypher if all true
                if (isalpha(argv[i][j])) 
                {
                    continue;
                }
                else
                {
                    // Exit loop and return failure code if character in key is not alphabetical
                    printf("Usage: ./vigenere keyword\n"); 
                    return 1;
                }   
            }
        }
        // Ask user to enter the text to be encrypted
        string plaintext = get_string("plaintext: "); 
        // Print out ciphertext
        printf("ciphertext: "); 
        // Counter for each time an alphabetical character is used in plaintext
        int alphaCounter = 0; 
        
        for (int i = 0, n = strlen(plaintext); i < n; i++) // Iterate over length of plaintext
        {
            // Index of keyPhrase based on the number of alphabetical chars encrypted, modulo over length of keyPhrase to ensure wrap around when len Plaintext > len keyPhrase
            int keyCounter = alphaCounter % strlen(keyPhrase); 
            // Calls shift function based on the char in keyPhrase to get the correct shift value 
            int key = shift(keyPhrase[keyCounter]); 
            
            if (isupper(plaintext[i]))
            {
                printf("%c", (((plaintext[i] + key) - 'A') % 26) + 'A');
                alphaCounter ++; // Increment by 1 when uppercase character is encrypted
            }
            else if (islower(plaintext[i]))
            {
                printf("%c", (((plaintext[i] + key) - 'a') % 26) + 'a');
                alphaCounter ++; // Increment by 1 when lowercase character is encrypted
            }
            else
            {
                // Print char without any shift if it's non-alphabetical e.g. punctuation, numbers, spaces 
                printf("%c", plaintext[i]); 
            }
        }
        printf("\n");
        return 0;
    }
}

// Function to convert key character to shift value to be used in encrypting plaintext character
int shift(char c)
{
    if (isupper(c))
    {
        int k = c - 'A';
        return k; // Returns shift value for uppercase character
    }
    else if (islower(c))
    {
        int k = c - 'a';
        return k; // Returns shift value for lowercase character
    }
    else
    {
        return 0;
    }
    
}
