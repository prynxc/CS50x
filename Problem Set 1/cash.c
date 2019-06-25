#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Declare variables
    float changeOwed; // The amount of change the user is owed
    int coinCount; // The number of coins returned to user as change
    int changeCents; // converting the amount of change owed to cents e.g. $1 = 100cents 
    
    // Prompt user to input the amount of change owed
    do
    {
        changeOwed = get_float("Change owed: ");
    }
    while (changeOwed < 0.00); // Continue to prompt if change owed is less than 0
    
    changeCents = round(changeOwed * 100); // Converts the input into cents

    coinCount = 0; // Initialises the number of coins returned as change at 0
    
    // While loops which checks the largest coin possible to return in change. Increases the coinCount when returned
    while (changeCents >= 25) 
    {
        changeCents -= 25;
        coinCount += 1;
    }
    while (changeCents >= 10)
    {
        changeCents -= 10;
        coinCount += 1;
    }
    while (changeCents >= 5)
    {
        changeCents -= 5;
        coinCount += 1;
    }
    while (changeCents >= 1)
    {
        changeCents -= 1;
        coinCount += 1;
    }
    printf("%i\n", coinCount); // Prints the final count of coins returned in change
}
