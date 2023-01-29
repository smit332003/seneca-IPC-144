/*
*****************************************************************************
						  Workshop - #8 (P1)
Full Name  :Smitkumar Kalpeshkumar Patel
Student ID#:157308214
Email      :spatel556
Section    :NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS


// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h" 

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* Num) {
	int n;
	do {
		scanf("%d", &n);
		if (n <= 0)
			printf("ERROR: Enter a positive value: ");
	} while (n <= 0);
	
	if (Num != NULL)
			*Num = n;

	return n;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* Num) {
	double n;
	do {
		scanf("%lf", &n);
		if (n <= 0)
			printf("ERROR: Enter a positive value: ");
	} while (n <= 0);

	if (Num != NULL)
		*Num = n;

	return n;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int Num){
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", Num);
	printf("NOTE: A 'serving' is %dg\n",SERVING);
	return;
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int n){
	struct CatFoodInfo FOOD;
	printf("\nCat Food Product #%d\n",n+1);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&FOOD.SKUnumber);
	printf("PRICE         : $");
	getDoublePositive(&FOOD.productPRZ);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&FOOD.productWGHT);
	printf("CALORIES/SERV.: ");
	getIntPositive(&FOOD.productCAL);
	return FOOD;
}


// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int SKUnumber, double *productPRZ, int productCAL, double *productWGHT){
printf("%07d %10.2lf %10.1lf %8d\n", SKUnumber, *productPRZ, *productWGHT, productCAL);
	return;
}

// 7. Logic entry point
void start() {
	struct CatFoodInfo FOOD[_NUM_PRODUCTS] = { {0} };
	int num_products = 3, i;
	openingMessage(num_products);
	for(i=0;i<num_products;i++){
		FOOD[i] = getCatFoodInfo(i);
	}
	displayCatFoodHeader();

	for(i=0; i<num_products; i++){
    	displayCatFoodData(FOOD[i].SKUnumber, &FOOD[i].productPRZ, FOOD[i].productCAL, &FOOD[i].productWGHT);
	}
	return;
}