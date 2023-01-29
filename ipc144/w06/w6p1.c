/*
*****************************************************************************
                          Workshop - #6 (P1)
Full Name  : Smitkumar Kalpeshkumar Patel
Student ID#: 157308214
Email      : spatel556@myseneca.ca
Section    : NCC
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#define variable 10
#include <stdio.h>

int main(void)
{
    const double virb1 = 500.00, virb2 = 400000.00, a = 100.00;
    double virb3;
    int virb4 = 0, i;
    double virb5[variable] = { 0 }, virb6 = 0;
    int virb7[variable] = { 0 };
    char virb8[variable] = { 0 };


    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");

    do
    {
        printf("\nEnter your monthly NET income: $");
        scanf("%lf", &virb3);
        if (virb3 < virb1)
        {
            printf("ERROR: You must have a consistent monthly income of at least $%5.2lf\n", virb1);
        }
        else if (virb3 > virb2)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%8.2lf\n", virb2);
        }
    } while (virb3 < virb1 || virb3 > virb2);

    do
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &virb4);
        if (virb4 <= 0 || virb4 > variable)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }

    } while (virb4 <= 0 || virb4 > variable);
    printf("\n");


    i = 0;
    while (i < virb4)
    {
        printf("Item-%d Details:\n", i + 1);
        do
        {
            printf("   Item cost: $");
            scanf("%lf", &virb5[i]);
            if (virb5[i] < a)
                printf("      ERROR: Cost must be at least $%5.2lf\n", a);

        } while (virb5[i] < a);
        virb6 += virb5[i];

        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &virb7[i]);
            if (!(virb7[i] >= 1 && virb7[i] <= 3))
                printf("      ERROR: Value must be between 1 and 3\n");
        } while (!(virb7[i] >= 1 && virb7[i] <= 3));

        do
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &virb8[i]);
            if (!(virb8[i] == 'y' || virb8[i] == 'n'))
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
        } while (!(virb8[i] == 'y' || virb8[i] == 'n'));
        printf("\n");
        i++;
    };

    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    
    for (i = 0; i < virb4; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i+1, virb7[i], virb8[i], virb5[i]);
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", virb6);

    printf("Best of luck in all your future endeavours!\n");

    return 0;
}