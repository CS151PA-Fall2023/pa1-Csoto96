#include "analytics.h"
/**
 * @brief opens file
 * 
 * @param File 
 * @param name 
 */
void openInputFile(ifstream &File, string name)
{
    File.open(name);
    //error block
    if(!File)
    {
        cout << "Error opening file!" << endl;
        exit(1);
    }
}
/**
 * @brief reads file and copies info to struct Grad EmploymentData and then placing into vector
 * 
 * @param File 
 * @param v 
 */
void readFileToVector(ifstream &File, vector<GradEmploymentData> &v)
{
    string skip;
    char delim = ',';
    char altDelim = '"';
    getline(File, skip);
    while(File.peek()!= EOF)
    {
            GradEmploymentData newMajor;
            File>>newMajor.demographicsTotal;
            getline(File,skip,delim);
            if(File.peek() == '"')
            {
            getline(File,skip,altDelim);
            getline(File, newMajor.educationMajor, altDelim);
            getline(File,skip,delim); 
            }
            else
            {
                getline(File, newMajor.educationMajor, delim);  
            }  
            File>>newMajor.meanSalary;
            getline(File,skip,delim);
            File>>newMajor.medianSalary;
            getline(File,skip,delim);
            File>>newMajor.demographicsAsian;
            getline(File,skip,delim);
            File>>newMajor.demographicsMinority;
            getline(File,skip,delim);
            File>>newMajor.demographicsWhite;
            getline(File,skip,delim);
            File>>newMajor.demographicsFemales;
            getline(File,skip,delim);
            File>>newMajor.demographicsMales;
            getline(File,skip,delim);
            File>>newMajor.educationBachelor;
            getline(File,skip,delim);
            File>>newMajor.educationDoctorate;
            getline(File,skip,delim);
            File>>newMajor.educationMasters;
            File.get();         
            v.push_back(newMajor);    
        
    }
}
/**
 * @brief displays vector mainly used for debugging
 * 
 * @param v 
 */
 void displayVector(vector<GradEmploymentData> &v)
 {
    for(int i = 0; i < (int)v.size(); i++)
    {
        cout << v[i].demographicsTotal << " " << v[i].educationMajor << " " <<v[i].meanSalary << " " 
        <<v[i].medianSalary << " " <<v[i].demographicsAsian << " " <<v[i].demographicsMinority << " " <<v[i].demographicsWhite
        << " " <<v[i].demographicsFemales << " " <<v[i].demographicsMales << " " <<v[i].educationBachelor << " " <<v[i].educationDoctorate
        << " " <<v[i].educationMasters<< " " << endl;
    }
 }
/**
 * @brief displays menu to operator
 * 
 */
 void displayMenu()
 {
    cout << "2015 National Survey of Recent College Graduate" << endl;
    cout << "1. Top 10 Majors with the Highest Mean Salary" << endl;
    cout << "2. Top 10 Majors with the Lowest Mean Salary" << endl;
    cout << "3. Top 10 Majors with the Highest Median Salary" << endl;
    cout << "4. Top 10 Majors with the Lowest Median Salary" << endl;
    cout << "5. What are the Top 5 Majors with the Highest Number of Asians" << endl;
    cout << "6. What are the Top 5 Majors with the Lowest Number of Asians" << endl;
    cout << "7. What are the Top 5 Majors with the Highest Number of Minorities" << endl;
    cout << "8. What are the Top 5 Majors with the Lowest Number of Minorities" << endl;
    cout << "9. What are the Top 10 Majors with the Highest Number of Males" << endl;
    cout << "10. What are the Top 10 Majors with the Highest Number of Females" << endl;
    cout << "11. Display Information for a Specific Major" << endl;
    cout << "12. Exit" << endl;
 }
/**
 * @brief takes choice from user and matches to operation in switch menu
 * 
 * @param input 
 * @param v 
 */
 void menuChoice(int input, vector<GradEmploymentData> &v)
 {
    switch(input)
    {
        case 1: sortMeanHigh(v);
                break;
        case 2: sortMeanLow(v);
                break;
        case 3: sortMedHigh(v);
                break;
        case 4: sortMedLow(v);
                break;
        case 5: sortAsianHigh(v);
                break;
        case 6: sortAsianLow(v);
                break;
        case 7: sortMinHigh(v);
                break;
        case 8: sortMinLow(v);
                break;
        case 9: sortMaleHigh(v);
                break;
        case 10: sortFemaleHigh(v);
                 break;
        case 11: selectedMajor(v);
                 break;
        default: cout << "menu choice is invalid" << endl;
    }
 }
/**
 * @brief sorts the vector by highest mean salary
 * 
 * @param v 
 */
 void sortMeanHigh(vector<GradEmploymentData> &v)
 {
    int size = v.size()-1;
    for (int maxElement = size; maxElement > 0; maxElement--)
    {
       for (int i = 0; i < maxElement; i++)
       {
          if (v[i].meanSalary < v[i + 1].meanSalary)
             swap(v[i], v[i + 1]);
       }
    }
    cout << "Education Major                    Mean Salary" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << v[i].educationMajor << " " << setw(36-v[i].educationMajor.length()) << "$  " << v[i].meanSalary << endl;
    }
    cout << "Press enter to continue...";
    cin.ignore();
    cin.get();
    displayMenu();
 }
/**
 * @brief sorts vector by lowest mean salary
 * 
 * @param v 
 */
 void sortMeanLow(vector<GradEmploymentData> &v)
 {
    int size = v.size()-1;
    for (int maxElement = size; maxElement > 0; maxElement--)
    {
       for (int i = 0; i < maxElement; i++)
       {
          if (v[i].meanSalary > v[i + 1].meanSalary)
             swap(v[i], v[i + 1]);
       }
    }
    cout << "Education Major                    Mean Salary" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << v[i].educationMajor << " " << setw(36-v[i].educationMajor.length()) << "$  " << v[i].meanSalary << endl;
    }
    cout << "Press enter to continue...";
    cin.ignore();
    cin.get();
    displayMenu();
 }
/**
 * @brief sorts vector by highest median salary
 * 
 * @param v 
 */
 void sortMedHigh(vector<GradEmploymentData> &v)
 {
    int size = v.size()-1;
    for (int maxElement = size; maxElement > 0; maxElement--)
    {
       for (int i = 0; i < maxElement; i++)
       {
          if (v[i].medianSalary < v[i + 1].medianSalary)
             swap(v[i], v[i + 1]);
       }
    }
    cout << "Education Major                    Median Salary" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << v[i].educationMajor << " " << setw(36-v[i].educationMajor.length()) << "$  " << v[i].medianSalary << endl;
    }
    cout << "Press enter to continue...";
    cin.ignore();
    cin.get();
    displayMenu();
 }
/**
 * @brief sorts by lowest median salary
 * 
 * @param v 
 */
 void sortMedLow(vector<GradEmploymentData> &v)
 {
    int size = v.size()-1;
    for (int maxElement = size; maxElement > 0; maxElement--)
    {
       for (int i = 0; i < maxElement; i++)
       {
          if (v[i].medianSalary > v[i + 1].medianSalary)
             swap(v[i], v[i + 1]);
       }
    }
    cout << "Education Major                    Median Salary" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << v[i].educationMajor << " " << setw(36-v[i].educationMajor.length()) << "$  " << v[i].medianSalary << endl;
    }
    cout << "Press enter to continue...";
    cin.ignore();
    cin.get();
    displayMenu();
 }
/**
 * @brief sorts by highest asian count
 * 
 * @param v 
 */
 void sortAsianHigh(vector<GradEmploymentData> &v)
 {
    int size = v.size()-1;
    for (int maxElement = size; maxElement > 0; maxElement--)
    {
       for (int i = 0; i < maxElement; i++)
       {
          if (v[i].demographicsAsian < v[i + 1].demographicsAsian)
             swap(v[i], v[i + 1]);
       }
    }
    cout << "Education Major                Number of Asians" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << v[i].educationMajor << " " << setw(36-v[i].educationMajor.length()) << v[i].demographicsAsian << endl;
    }
    cout << "Press enter to continue...";
    cin.ignore();
    cin.get();
    displayMenu();
 }
/**
 * @brief sorts by lowest asian count
 * 
 * @param v 
 */
 void sortAsianLow(vector<GradEmploymentData> &v)
 {
    int size = v.size()-1;
    for (int maxElement = size; maxElement > 0; maxElement--)
    {
       for (int i = 0; i < maxElement; i++)
       {
          if (v[i].demographicsAsian > v[i + 1].demographicsAsian)
             swap(v[i], v[i + 1]);
       }
    }
    cout << "Education Major                Number of Asians" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << v[i].educationMajor << " " << setw(36-v[i].educationMajor.length()) << v[i].demographicsAsian << endl;
    }
    cout << "Press enter to continue...";
    cin.ignore();
    cin.get();
    displayMenu();
 }
/**
 * @brief sorts by highest minority count
 * 
 * @param v 
 */
 void sortMinHigh(vector<GradEmploymentData> &v)
 {
    int size = v.size()-1;
    for (int maxElement = size; maxElement > 0; maxElement--)
    {
       for (int i = 0; i < maxElement; i++)
       {
          if (v[i].demographicsMinority < v[i + 1].demographicsMinority)
             swap(v[i], v[i + 1]);
       }
    }
    cout << "Education Major                    Number of Minorities" << endl;
    cout << "--------------------------------------------------------" << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << v[i].educationMajor << " " << setw(40-v[i].educationMajor.length()) << v[i].demographicsMinority << endl;
    }
    cout << "Press enter to continue...";
    cin.ignore();
    cin.get();
    displayMenu();
 }
/**
 * @brief sorts by lowest minority count
 * 
 * @param v 
 */
 void sortMinLow(vector<GradEmploymentData> &v)
 {
    int size = v.size()-1;
    for (int maxElement = size; maxElement > 0; maxElement--)
    {
       for (int i = 0; i < maxElement; i++)
       {
          if (v[i].demographicsMinority > v[i + 1].demographicsMinority)
             swap(v[i], v[i + 1]);
       }
    }
    cout << "Education Major                    Number of Minorities" << endl;
    cout << "--------------------------------------------------------" << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << v[i].educationMajor << " " << setw(40-v[i].educationMajor.length()) << v[i].demographicsMinority << endl;
    }
    cout << "Press enter to continue...";
    cin.ignore();
    cin.get();
    displayMenu();
 }
/**
 * @brief sorts by highest male count
 * 
 * @param v 
 */
 void sortMaleHigh(vector<GradEmploymentData> &v)
 {
    int size = v.size()-1;
    for (int maxElement = size; maxElement > 0; maxElement--)
    {
       for (int i = 0; i < maxElement; i++)
       {
          if (v[i].demographicsMales < v[i + 1].demographicsMales)
             swap(v[i], v[i + 1]);
       }
    }
    cout << "Education Major                   Number of Males" << endl;
    cout << "---------------------------------------------------" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << v[i].educationMajor << " " << setw(40-v[i].educationMajor.length()) << v[i].demographicsMales << endl;
    }
    cout << "Press enter to continue...";
    cin.ignore();
    cin.get();
    displayMenu();
 }
/**
 * @brief sorts by highest female count
 * 
 * @param v 
 */
 void sortFemaleHigh(vector<GradEmploymentData> &v)
 {
    int size = v.size()-1;
    for (int maxElement = size; maxElement > 0; maxElement--)
    {
       for (int i = 0; i < maxElement; i++)
       {
          if (v[i].demographicsFemales < v[i + 1].demographicsFemales)
             swap(v[i], v[i + 1]);
       }
    }
    cout << "Education Major                   Number of Females" << endl;
    cout << "---------------------------------------------------" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << v[i].educationMajor << " " << setw(40-v[i].educationMajor.length()) << v[i].demographicsFemales << endl;
    }
    cout << "Press enter to continue...";
    cin.ignore();
    cin.get();
    displayMenu();
 }
/**
 * @brief insertion sort then displays major info from users input
 * 
 * @param v 
 */
 void selectedMajor(vector<GradEmploymentData> &v)
 {
    string major;
    for (int startScan = 1; startScan < (int)v.size(); ++startScan)
    {
        GradEmploymentData key = v[startScan];
        int index = startScan - 1;
        while (index >= 0 && v[index].educationMajor > key.educationMajor)
        {
            v[index+1] = v[index];
            --index;
        }
        v[index+1] = key;
    }
    cout << "Enter Major: ";
    cin.ignore();
    getline(cin,major);
    int choice = binarySearch(v,major);
    cout << "Education Major" << endl;
    cout << "---------------" << endl;
    cout << v[choice].educationMajor << endl;
    cout << "DemographicsTotal|Mean Salary|Median Salary" << endl;
    cout << "-------------------------------------------" << endl;
    cout << setw(18) << left << v[choice].demographicsTotal << setw(12)
         << v[choice].meanSalary 
         << v[choice].medianSalary << endl
         << "Asian  |Minority|White" << endl
         << "----------------------" << endl 
         << setw(8) << v[choice].demographicsAsian << setw(9) 
         << v[choice].demographicsMinority 
         << v[choice].demographicsWhite<< endl
         << "Females |Males" << endl
         << "--------------" << endl 
         << setw(9) << v[choice].demographicsFemales 
         << v[choice].demographicsMales<< endl
         << "Bachelor|Doctorate|Masters" << endl
         << "--------------------------" << endl
         << setw(9) << v[choice].educationBachelor << setw(10) 
         << v[choice].educationDoctorate
         << v[choice].educationMasters << endl;
    cout << "Press enter to continue...";
    cin.get();
    displayMenu();
    

 }
/**
 * @brief searches vector using binary search and returns index of vector from user input
 * 
 * @param v 
 * @param name 
 * @return int 
 */
int binarySearch(vector<GradEmploymentData> &v, string name)
{
    int first = 0, // First array element
    last = v.size() - 1, // Last array element
    middle, // Midpoint of search
    position = -1; // Position of search value
    bool found = false; // Flag
    while (!found && first <= last)
        {   
            middle = (first + last) / 2; // Calculate midpoint
            if (v[middle].educationMajor == name) // If value is found at mid
                {
                    found = true;
                    position = middle;
                }
        else if (v[middle].educationMajor > name) // If value is in lower half
            {
                last = middle - 1;
            }
        else
            {
                first = middle + 1; // If value is in upper half
            }
        }
    return position;
}

 /**
  * @brief used by bubble sort function
  * 
  * @param a 
  * @param b 
  */
  void swap(int &a, int &b)
 {
   int temp = a;
    a = b;
    b = temp;
 }
