/********************************************************
*   This is a simple C program that allows you to       *
*   determine whether a given credit card number        *
*   is a Visa, American Express, or MasterCard.         *
*********************************************************/


#include <stdio.h>
#include <cs50.h>


bool checksum(long cardNo); // Initialise checksum (Luhn's algo) to valide creditcard num
int cardLen(long cardNo); // Initialises function to find length of credit card num
int cardStart(long cardNo, int cLen); // Initialises function to get the starting digit(s) of the credit card using the length


int main(void)
{

    long cardNo;

    do
    {
        cardNo = get_long("Card Number: "); // Ask the user for their credit card number
    }
    while (cardNo < 0); // Makes sure the user does not input a negative number

    int cLen = cardLen(cardNo); // Length of credit card number

    // Checks if the card passes the checksum (Luhn's algo) and whether it is one of 13,15 or 16 digits long
    if (checksum(cardNo) && (cLen == 13 || cLen == 15 || cLen == 16)) 
    {
        int cStart = cardStart(cardNo, cLen); // Credit card number's the starting digit(s)

        if (cLen == 13 && cStart == 4)
        {
            printf("VISA\n");
        }
        else if (cLen == 15 && (cStart == 34 || cStart == 37))
        {
            printf("AMEX\n");
        }
        else if (cLen == 16 && cStart == 4)
        {
            printf("VISA\n");
        }
        else if (cLen == 16 && (cStart >= 51 && cStart <= 55))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}



bool checksum(long cardNo) 
/***********************************************************************************************************************************************
*   Luhn's Algorithm to check if it is a valid credit card number:      																	   *
*   1.Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.          *
*   2.Add the sum to the sum of the digits that weren’t multiplied by 2.         															   *
*	3.If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!				   *
************************************************************************************************************************************************/

{
    int odd = 0;
    int even = 0;
    int check;

    while (cardNo > 0)
    {
        odd += cardNo % 10;
        cardNo /= 10;
        even += ((cardNo % 10) * 2) % 10 + ((cardNo % 10) * 2) / 10;
        cardNo /= 10;
    }

    check = odd + even;

    if (check % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int cardLen(long cardNo) // Gets the length of the card number
{
    int len = 0;

    while (cardNo > 0)
    {
        cardNo /= 10;
        len ++;
    }

    return len;
}

int cardStart(long cardNo, int cLen) // Finds the starting digit(s) of the card num, dependent on the length of the card (cLen).
{
    if (cLen == 13) // VISA are 13 digits long and start with 4 (need first digit)
    {
        for (int i = 0; i < (cLen - 1); i++) // cLen - 1 = 12 
        {
            cardNo /= 10;
        }
    }
    else if (cLen == 15) // AMEX are 15 digits long and start with 34 or 37 (need first two digits)
    {
        for (int i = 0; i < (cLen - 2); i++) // cLen - 2 = 13
        {
            cardNo /= 10;
        }
    }
    else if (cLen == 16) // MASTERCARD and VISA are 16 digits
    {
        for (int i = 0; i < (cLen - 2); i++) 
        {
            cardNo /= 10;
        }

        if (cardNo >= 51 && cardNo <= 55) // MASTERCARD starts with 51 to 55
        {
            return cardNo;
        }
        else if ((cardNo /= 10) == 4) // VISA starts with 4
        {
            return cardNo;
        }

    }

    return cardNo;
}
