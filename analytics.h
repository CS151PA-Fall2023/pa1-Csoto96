/**
 * @file   <analytics.h>
 * @author Chris Soto
 * @brief  header file for pa 1
 * @date   08/28/2023
 *
 */
#ifndef ANALYTICS_H
#define ANALYTICS_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
struct GradEmploymentData
{
    int demographicsTotal;     // The estimated total of people awarded degrees in this major during 2005
    string educationMajor;     // The name of the major for these graduated students
    float meanSalary;          // The average (mean) recorded salary reported for employed people with this degree
    float medianSalary;        // The median recorded salary reported for employed people with this degree
    int demographicsAsian;     // The estimated number of people identifying as Asian that were awarded degrees in this major
    int demographicsMinority;  // The estimated number of people identifying as minority 
                               // (e.g., Black, African American, Native American) that were awarded degrees in this major
    int demographicsWhite;     // The estimated number of people identifying as White that were awarded degrees in this major
    int demographicsFemales;   // The estimate number of women awarded degrees in this major
    int demographicsMales;     // The estimate number of men awarded degrees in this major
    int educationBachelor;     // The estimated number of bachelor degrees awarded in this for major
    int educationDoctorate;    // The estimated number of doctoral degrees awarded in this for major
    int educationMasters;      // The estimated number of Masters awarded in this for major
};
//Function protos
void openInputFile(ifstream &File, string name);
void readFileToVector(ifstream &File, vector<GradEmploymentData> &v);
void displayVector(vector<GradEmploymentData> &v);
void displayMenu();
void menuChoice(int input,vector<GradEmploymentData> &v);
void sortMeanHigh(vector<GradEmploymentData> &v);
void sortMeanLow(vector<GradEmploymentData> &v);
void sortMedHigh(vector<GradEmploymentData> &v);
void sortMedLow(vector<GradEmploymentData> &v);
void sortAsianHigh(vector<GradEmploymentData> &v);
void sortAsianLow(vector<GradEmploymentData> &v);
void sortMinHigh(vector<GradEmploymentData> &v);
void sortMinLow(vector<GradEmploymentData> &v);
void sortMaleHigh(vector<GradEmploymentData> &v);
void sortFemaleHigh(vector<GradEmploymentData> &v);
void selectedMajor(vector<GradEmploymentData> &v);
int binarySearch(vector<GradEmploymentData> &v, string name);
#endif // ANALYTICS_H