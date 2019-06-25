#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declare variables for height, row, spaces and hashes
    int height; // Consider this the number of columns
    int row; // The number of rows equals the input for height i.e. there are as many rows as there are height/columns
    int spaces;
    int hashes; // The number of hashes is equal to the given row and column i.e. for row two there are 2 hashes, for row 3 there are 3 hashes and so on
    
    // Prompt user for height between 1 and 8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8); // Check input is between 1 and 8
    
    for (row = 1; row <= height; row++) // For every row starting at 1
    {
        for (spaces = (height - row); spaces > 0; spaces--) // the number of spaces decreases as the rows increase
        {
            printf(" ");
        }
        
        for (hashes = 1; hashes <= row; hashes++) // the number of hashes is equal to the given row e.g. 5 hashes for row 5
        {
            printf("#");
        }
        printf("\n");    
    }
}

