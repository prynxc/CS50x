#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Checks that the user inputs exactly one command-line argument as the key
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    else 
    {
        // Iterates over the key
        for (int i = 1; i < argc; i++)

        {
            // Iterates over the individual elements of the key/argument and checks if it they are digits
            for (int j = 0, n = strlen(argv[i]); j < n; j++)
            {
                if (isdigit(argv[i][j]))
                {
                    continue;
                }
                // Break loop when element is not a digit
                else
                    
                {
                    printf("Usage: ./caesar key\n");
                    return 1;
                }
            }
        }
        
        // Converts the key into an int, key is stored in the 1st element of argv
        int key = atoi(argv[1]);

        // Asks user for the text they would like to be enciphered
        string plaintext = get_string("plaintext: ");
        
        // Prints out the enciphered text using the command-line argument/key
        printf("ciphertext: ");

        // Iterates over each character in the plain text 
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        { 
            // Checks if char is lowercase  
            if (islower(plaintext[i]))
                // Prints char shifted by key, keeping lowercase
            {
                printf("%c", (((plaintext[i] + key) - 97) % 26) + 97);
            }
            // Checks if char is uppercase
            else if (isupper(plaintext[i]))
            {
                // Prints char shifted by key, keeping uppercase
                printf("%c", (((plaintext[i] + key) - 65) % 26) + 65);  
            }
            // Otherwise print char without changing
            else
            {
                printf("%c", plaintext[i]);
            }
            
        }
    }
    printf("\n");
    return 0;
}
