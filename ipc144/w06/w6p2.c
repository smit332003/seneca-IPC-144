/*
*****************************************************************************
                          Workshop - #6 (P2)
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
#define v12 10
#include <stdio.h>

int main(void)
{
    const double a = 100.00, v1 = 500.00, v2 = 400000.00;
    double v3;
    int v4 = 0, i, v5, year, month, v6;
    double v7[v12] = { 0 }, v8 = 0, v9 = 0, d;
    int v10[v12] = { 0 };
    char v11[v12] = { 0 };

    
    
        printf("+--------------------------+\n");
        printf("+   Wish List Forecaster   |\n");
        printf("+--------------------------+\n");

        do
        {
            printf("\nEnter your monthly NET income: $");
            scanf("%lf", &v3);
            if (v3 < v1)
            {
                printf("ERROR: You must have a consistent monthly income of at least $%5.2lf\n", v1);
            }
            else if (v3 > v2)
            {
                printf("ERROR: Liar! I'll believe you if you enter a value no more than $%8.2lf\n", v2);
            }
        } while (v3 < v1 || v3 > v2);

        do
        {
            printf("\nHow many wish list items do you want to forecast?: ");
            scanf("%d", &v4);
            if (v4 <= 0 || v4 > v12)
            {
                printf("ERROR: List is restricted to between 1 and 10 items.\n");
            }

        } while (v4 <= 0 || v4 > v12);
        printf("\n");


        i = 0;
        while (i < v4)
        {
            printf("Item-%d Details:\n", i + 1);
            do
            {
                printf("   Item cost: $");
                scanf("%lf", &v7[i]);
                if (v7[i] < a)
                    printf("      ERROR: Cost must be at least $%5.2lf\n", a);

            } while (v7[i] < a);
            v8 += v7[i];

            do
            {
                printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
                scanf("%d", &v10[i]);
                if (!(v10[i] >= 1 && v10[i] <= 3))
                    printf("      ERROR: Value must be between 1 and 3\n");
            } while (!(v10[i] >= 1 && v10[i] <= 3));

            do
            {
                printf("   Does this item have financing options? [y/n]: ");
                scanf(" %c", &v11[i]);
                if (!(v11[i] == 'y' || v11[i] == 'n'))
                    printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            } while (!(v11[i] == 'y' || v11[i] == 'n'));
            printf("\n");
            i++;
        };

        printf("Item Priority Financed        Cost\n");
        printf("---- -------- -------- -----------\n");

        for (i = 0; i < v4; i++)
        {
            printf("%3d  %5d    %5c    %11.2lf\n", i + 1, v10[i], v11[i], v7[i]);
        }

        printf("---- -------- -------- -----------\n");
        printf("                      $%11.2lf\n", v8);


        
        do
        
        {
            printf("\nHow do you want to forecast your wish list?\n");
            printf(" 1. All items (no filter)\n");
            printf(" 2. By priority\n");
            printf(" 0. Quit/Exit\n");
            printf("Selection: ");
            scanf("%d", &v5);
            
            if (!(v5 == 0 || v5 == 1 || v5 == 2))
            {
                printf("\nERROR: Invalid menu selection.\n");
            }
            else
                
                
                    if(v5 == 1)
                    {
                        printf("\n====================================================\n");
                        printf("Filter:   All items\n");
                        printf("Amount:   $%1.2lf\n", v8);

                        d = (v8 / v3); 
                        year = (v8 / v3) / 12; 
                        if (d - (int)d > 0.0)
                        {
                            month = (int)d % 12;
                            month++;

                        }
                        else 
                            month = (int)d % 12;

                        printf("Forecast: %d years, %d months\n", year, month);

                        for (i = 0; i < v4; i++)
                        {
                                    if (v11[i] == 'y')
                                    {
                                        printf("NOTE: Financing options are available on some items.\n");
                                        printf("      You can likely reduce the estimated months.\n");
                                        printf("====================================================\n");
                                        i = v4;
                                    }
                        }
                            
                        

                    }

                    if(v5 == 2)
                    {
                        printf("\nWhat priority do you want to filter by? [1-3]: ");
                        scanf("%d",&v6);
                        printf("\n====================================================\n");
                        printf("Filter:   by priority (%d)\n", v6);
                        v9 = 0;
                        for (i = 0; i < v4; i++)
                        {
                            if (v6 == v10[i])
                            {
                                v9 += v7[i];
                            }
                        }
                        printf("Amount:   $%1.2lf\n", v9);

                        d = (v9 / v3);
                        year = (v9 / v3) / 12;
                        if (d - (int)d > 0.0)
                        {
                            month = (int)d % 12;
                            month++;

                        }
                        else
                            month = (int)d % 12;

                        printf("Forecast: %d years, %d months\n", year, month);

                        for (i = 0; i < v4; i++)
                        {
                            if (v6 == v10[i])
                            {
                                if (v11[i] == 'y')
                                {
                                    printf("NOTE: Financing options are available on some items.\n");
                                    printf("      You can likely reduce the estimated months.\n");
                                    
                                    i = v4;
                                }
                            }
                        }
                        printf("====================================================\n");
                    }
                
        } while (v5 != 0);
        
        printf("\nBest of luck in all your future endeavours!\n");

        return 0;
    }