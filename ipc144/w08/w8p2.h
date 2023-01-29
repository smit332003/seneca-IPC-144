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
// ----------------------------------------------------------------------------
#include <stdio.h>
#define productmaximum 3
#define perservingingrams 64 
#define converttolbsfromkgs 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
	int SKUnumber, productCAL;
	double productPRZ, productWGHT;
};
struct ReportData
{
	int productskunumber;
	double pricepro;
	int caloriesofproduct;
	double weightlb;
	double inkgs;
	int wghtgrams;
	double totalserves;
	double costserves;
	double costpercalperserve;
};



int getIntPositive(int* positive_int);


double getDoublePositive(double* positive_double);


void openingMessage(const int num_product);


struct CatFoodInfo getCatFoodInfo(const int seq_num);


void displayCatFoodHeader(void);



void displayCatFoodData(const int SKUnumber, const double productPRZ, const int productCAL, const double productWGHT);






double convertLbsKg(const double* LB, double* LG);


int convertLbsG(const double* LBS, int* G);


void convertLbs(const double* LBS, double* weightKGg, int* grams);


double calculateServings(const int volume, const int sum, double* total_servings);


double calculateCostPerServing(const double* price, const double* total_servings, double* cost_per_serving);


double calculateCostPerCal(const double* price, const double* productCAL, double* cost_per_cal_per_serving);


struct ReportData calculateReportData(const struct CatFoodInfo Info);


void displayReportHeader(void);


void displayReportData(const struct ReportData report, const int a);


void displayFinalAnalysis(const struct CatFoodInfo cheaper_Item);


void start(void);