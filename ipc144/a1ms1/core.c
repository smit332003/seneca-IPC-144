/*
*****************************************************************************
                        Assignment 1 - Milestone 1
Full Name  : Smitkumar K Patel
Student ID#: 157308214
Email      : spatel556@myseneca.ca
Section    : NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include <stdio.h>
#include "core.h"


void clearInputBuffer(void)
{
    while (getchar() != '\n')
    {
        ;
    }
}

void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

int inputInt() {
    char numberLength;
    int numValue;
    do {
        scanf("%d%c", &numValue, &numberLength);
        if (numberLength != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");

        }
    } while (numberLength != '\n');
    return numValue;
}



int inputIntPositive() {
    int numValue;
    do {
        numValue = inputInt();
        if (numValue <= 0) {
            printf("ERROR! Value must be > 0: ");
        }
    } while (numValue <= 0);
    return numValue;
}




int  inputIntRange(int minimumValue, int maximumValue) {
    int Value;
    do {
        Value = inputInt();
        if (Value < minimumValue || Value > maximumValue) {
            printf("ERROR! Value must be between -3 and 11 inclusive: ");
        }
    } while (Value < minimumValue || Value > maximumValue);
    return Value;
}


void clearInputBuffer();
char inputCharOption(const char* validCharacters) {
    char valueChar;
    int i = 0;

    for (i = 0; validCharacters[i] != '\0'; i++) {
        scanf("%c", &valueChar);
        if (valueChar == validCharacters[i]) {
            break;
        }
        else {
            printf("ERROR: Character must be one of [%s]: ", validCharacters);
            clearInputBuffer();
        }
    }
    return valueChar;
}
void clearInputBuffer();
void inputCString(char* Cstring, int minimumLength, int maximumLength) {
    int i;
    clearInputBuffer();
    do {
        scanf("%[^\n]s", Cstring);
        for (i = 0; Cstring[i] != '\0'; i++);
        if ((i != minimumLength || i != maximumLength) && (minimumLength == maximumLength)) {
            printf("ERROR: String length must be exactly %d chars: ", minimumLength);
            clearInputBuffer();
        }
        else if (i < minimumLength || i > maximumLength) {
            if (i > maximumLength) {
                printf("ERROR: String length must be no more than %d chars: ", maximumLength);
                clearInputBuffer();
            }
            else
            {
                printf("ERROR: String length must be between %d and %d chars: ", minimumLength, maximumLength);
                clearInputBuffer();
            }
        }
        else if (i == maximumLength || i == minimumLength) {
            i = 0;
            break;
        }
    } while (i > minimumLength || i < maximumLength);
}

void clearInputBuffer();
void displayFormattedPhone(const char* phoneNumber) {
    int i = 0, count = 0;

    if (phoneNumber == NULL) {
        printf("(___)___-____");
    }

    else {
        for (i = 0; phoneNumber[i] != '\0'; i++) {
            if (phoneNumber[i] >= '0' && phoneNumber[i] <= '9') {
                count++;
            }
        }

        if (i != 10 || i != count) {
            printf("(___)___-____");
        }
        else if (i == 10) {
            printf("(%c%c%c)%c%c%c-%c%c%c%c", phoneNumber[0], phoneNumber[1],
                phoneNumber[2], phoneNumber[3], phoneNumber[4], phoneNumber[5], phoneNumber[6],
                phoneNumber[7], phoneNumber[8], phoneNumber[9]);
        }
    }
}