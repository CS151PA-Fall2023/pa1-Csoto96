/**
 * @file main.cpp
 * @author Chris Soto
 * @brief 
 * @version 0.1
 * @date 2023-08-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "analytics.h"

using namespace std;

int main()
{
    ifstream gradFile;
    vector<GradEmploymentData> gradData;
    openInputFile(gradFile,"graduates2015.csv");
    readFileToVector(gradFile,gradData);
    gradFile.close();
    displayVector(gradData);
    int input;
    displayMenu();
    while(1)
    {
        cout << "Select a Menu: ";
        do
        {
            cin >> input; 
            if(input > 12 || input < 1)
            {
                cout << "invalid input, please enter 1-12" << endl;
            }
        } while (input > 12 || input < 1);
        if(input == 12)
        {
            break;
        }
        else
        {
            menuChoice(input, gradData);
        }
        
    }
    
    return 0;
}
