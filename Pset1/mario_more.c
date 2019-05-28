#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int height;
    int row;
    int hashes;
    int spaces;
    int gap;
    
    do
    {
        height = get_int("Height: ");
    }       
    while (height < 1 || height > 8);  
    
    for (row = 1; row <= height; row++)
    {      
        for (spaces = height - row; spaces > 0; spaces--)
        {
            printf(" ");
        }
        for (hashes = 1; hashes <= row; hashes++)
        {
            printf("#");
        }
        
        printf("  "); //prints double spaces between pyramid
        
        for (hashes = 1; hashes <= row; hashes++)
        {
            printf("#");
        }
        printf("\n");
    }
}
