/*
*****************************************************************************
                          Workshop - #8 (P2)
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
#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User-Defined Libraries

#include "w8p2.h"



int getIntPositive(int* positive_int) {
    int numcheck;
    do
    {
        scanf("%d", &numcheck);
        if (numcheck <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
    } while (numcheck <= 0);
    if (positive_int != NULL)
        *positive_int = numcheck;
    return numcheck;
}



double getDoublePositive(double* positive_double) {
    double num_check;
    do
    {
        scanf("%lf", &num_check);
        if (num_check <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }

    } while (num_check <= 0);
    if (positive_double != NULL)
        *positive_double = num_check;
    return num_check;

}


void openingMessage(const int num_product) {
    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", num_product);
    printf("NOTE: A 'serving' is %dg\n", perservingingrams);
}



struct CatFoodInfo getCatFoodInfo(const int seq_num) {
    struct CatFoodInfo Product = { 0 };
    printf("\nCat Food Product #%d\n", seq_num + 1);
    printf("--------------------\n");
    printf("SKU           : ");
    getIntPositive(&Product.SKUnumber);
    printf("PRICE         : $");
    getDoublePositive(&Product.productPRZ);
    printf("WEIGHT (LBS)  : ");
    getDoublePositive(&Product.productWGHT);
    printf("CALORIES/SERV.: ");
    getIntPositive(&Product.productCAL);

    return Product;
}


void displayCatFoodHeader(void)
{
    printf("\n");
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}


void displayCatFoodData(const int SKUnumber, const double productPRZ, const int caloriesofproduct, const double productWGHT) {
    printf("%07d %10.2lf %10.1lf %8d\n", SKUnumber, productPRZ, productWGHT, caloriesofproduct);
}


double convertLbsKg(const double* lbs, double* kg) {
    double i;
    i = *lbs / converttolbsfromkgs;
    if (kg != NULL)
    {
        *kg = i;
    }
    return(i);
}



int convertLbsG(const double* lbs, int* g) {
    int j;
    j = convertLbsKg(lbs, 0) * 1000;
    if (g != NULL)
    {
        *g = j;
    }
    return(j);
}


void convertLbs(const double* lbsCovert, double* kg, int* g) {
    convertLbsKg(lbsCovert, kg);
    convertLbsG(lbsCovert, g);
}



double calculateServings(const int volume, const int sum, double* result) {
    double i;
    i = (double)sum / (double)volume;
    if (result != NULL)
    {
        *result = i;
    }
    return(i);
}


double calculateCostPerServing(const double* rate, const double* result, double* costResult) {
    double cost = 0;
    cost = *rate / *result;
    if (costResult != NULL)
    {
        *costResult = cost;
    }
    return(cost);
}


double calculateCostPerCal(const double* productPRZ, const double* calories, double* costCalories) {
    double cost = 0;
    cost = *productPRZ / *calories;
    if (costCalories != NULL)
    {
        *costCalories = cost;
    }
    return(cost);
}



struct ReportData calculateReportData(const struct CatFoodInfo getDetailCatFood)
{
    struct ReportData reportInfo;
    double cal;

    reportInfo.productskunumber = getDetailCatFood.SKUnumber;
    reportInfo.pricepro = getDetailCatFood.productPRZ;
    reportInfo.weightlb = getDetailCatFood.productWGHT;
    reportInfo.caloriesofproduct = getDetailCatFood.productCAL;
    reportInfo.inkgs = convertLbsKg(&getDetailCatFood.productWGHT, &reportInfo.inkgs);
    reportInfo.wghtgrams = convertLbsG(&getDetailCatFood.productWGHT, &reportInfo.wghtgrams);
    reportInfo.totalserves = calculateServings(perservingingrams, reportInfo.wghtgrams, &reportInfo.totalserves);
    cal = reportInfo.caloriesofproduct * reportInfo.totalserves;
    reportInfo.costserves = calculateCostPerServing(&reportInfo.pricepro, &reportInfo.totalserves, &reportInfo.costserves);
    reportInfo.costpercalperserve = calculateCostPerCal(&reportInfo.pricepro, &cal, &reportInfo.costpercalperserve);

    return(reportInfo);
};


void displayReportHeader(void)
{
    printf("\n");
    printf("Analysis Report (Note: Serving = %dg)\n", perservingingrams);
    printf("---------------\n");
    printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
    printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}


void displayReportData(const struct ReportData reportInfo, const int cheap) {
    printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", reportInfo.productskunumber, reportInfo.pricepro, reportInfo.weightlb, reportInfo.inkgs,
        reportInfo.wghtgrams, reportInfo.caloriesofproduct, reportInfo.totalserves, reportInfo.costserves, reportInfo.costpercalperserve);
}


void displayFinalAnalysis(const struct CatFoodInfo cheaper_product) {
    printf("\n");
    printf("Final Analysis\n");
    printf("--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%07d Price: $%.2lf\n\n", cheaper_product.SKUnumber, cheaper_product.productPRZ);
    printf("Happy shopping!");
}


void start(void)
{
    struct CatFoodInfo catFoodDetail[productmaximum];
    {
        int i = 0, cheapProduct = 0;
        openingMessage(productmaximum);
        for (i = 0; i < productmaximum; i++)
        {
            catFoodDetail[i] = getCatFoodInfo(i);
        }

        displayCatFoodHeader();
        for (i = 0; i < productmaximum; i++)
        {
            displayCatFoodData(catFoodDetail[i].SKUnumber, catFoodDetail[i].productPRZ, catFoodDetail[i].productCAL, catFoodDetail[i].productWGHT);
        }

        struct ReportData reportArray[productmaximum];
        displayReportHeader();
        for (i = 0; i < productmaximum; i++)
        {
            reportArray[i] = calculateReportData(catFoodDetail[i]);
            if (reportArray[i].costpercalperserve < reportArray[i - 1].costpercalperserve)
            {
                cheapProduct = i;
            }
        }
        int j;
        for (j = 0; j < productmaximum; j++)
        {
            struct ReportData x = { 0 };
            x = reportArray[j];
            displayReportData(x, cheapProduct);
            if (cheapProduct == j)
            {
                printf(" ***");
            }
            printf("\n");

        }
        printf("\n");
        displayFinalAnalysis(catFoodDetail[cheapProduct]);
    }
}