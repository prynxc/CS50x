#include <stdio.h>
#include <cs50.h>

bool checksum(long cardNo);
int cardLen(long cardNo);
int cardStart(long cardNo, int cLen);

int main(void)
{
    long cardNo;

    do
    {
        cardNo = get_long("Card Number: ");
    }
    while (cardNo < 0);

    int cLen = cardLen(cardNo); // The length of the card num.

    if (checksum(cardNo) == true && (cardLen(cardNo) == 13 || cardLen(cardNo) == 15 || cardLen(cardNo) == 16))
    {
        int cStart = cardStart(cardNo, cLen);

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



bool checksum(long cardNo) // Luhn's Algorithm
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

int cardLen(long cardNo) // Gets the length of the he card number
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