/***********************************************
 * Title:   Program_1_2400.cpp
 * Author:  Kevin Ulrich
 * Date:    Sept. 8, 2023
 * Purpose: Implements different algorithms 
 *      for finding the GCD of two numbers
************************************************/
#include <iostream>
using namespace std;

void extendedEuclidsAlgorithm(int, int);
void consecutiveIntAlgorithm(int, int);
void middleSchoolAlgorithm(int, int);
int smallestPrimeFactor(int num);

int main()
{
    int num1, num2;

    //Input from user
    cout << "num1:    ";
    cin >> num1;

    cout << "num2:    ";
    cin >> num2;

    //Function calls
    extendedEuclidsAlgorithm(num1, num2);
    consecutiveIntAlgorithm(num1, num2);
    middleSchoolAlgorithm(num1, num2);

    return 0;
}

/*
    Function:   extendedEuclidsAlgorithm()
    Purpose:    Finds the greatest common denomintator of the
                2 numbers passed to the function
*/
void extendedEuclidsAlgorithm(int num1, int num2)
{
    int hold, div_result;       //hold is used as placeholder and div_result holds each iterations' 
    int holdNum1 = num1;        //Used for remembering the input for use in output
    int holdNum2 = num2;
    num1 = abs(num1);       //Finds the absolute value of the corresponding variable
    num2 = abs(num2);       //handles special cases where inputs are negative
    int x = 1;                  //Variables for keeping track of coefficients
    int x1 = 0;
    int y = 0;
    int y1 = 1;

    cout << "\nExtended Euclid's Alogorithm:      ";

    // handles special case where both inputs are 0
    if((num1 == 0) && (num2 == 0)) {
        cout << "gcd is undefined" << endl;
        return;
    }

    while(num2){
        //calculating quotient and remainder
        div_result = num1 / num2;

        // updating values for finding gcd
        hold = num1;
        num1 = num2;
        num2 = hold % num2;

        // updating coeffiecients
        hold = x;
        x = x1;
        x1 = hold - div_result * x1;

        hold = y;
        y = y1;
        y1 = hold - div_result * y1;
    }
    
    // Adjust coefficients based on the signs of the original numbers
    if (holdNum1 < 0) {
        x = -x;
    }
    if (holdNum2 < 0) {
        y = -y;
    }

    //Iterate in formatting
    cout << "gcd(num1, num2) = (x)num1 + (y)num2" << endl;
    cout << "\t\t\t\t   " << num1 << " = (" << x << ")" << holdNum1 << " + (" << y << ")" << holdNum2 << endl;

}


/*
    Function:   consecutiveIntAlgorithm()
    Purpose:    Finds the greatest common denomintator of the
                2 numbers passed to the function
*/
void consecutiveIntAlgorithm(int num1, int num2)
{
    int holdNum1 = num1;    //Holds the value of the corresponding variable for outputting
    int holdNum2 = num2;

    num1 = abs(num1);       //Finds the absolute value of the corresponding variable
    num2 = abs(num2);

    int minNum = min(num1, num2);   //finds the smaller number
    int maxNum = max(num1, num2);   //finds the larger number

    cout << "\nConsecutive Integer Alogrithm:     ";


    // handles special case for both inputs being 0
    if((num1 == 0) && (num2 == 0)) {
        cout << "gcd is undefined" << endl;
        return;
    }

    
    // handles special case where one of the inputs is 0
    if(minNum == 0) {
        cout << "gcd(" << holdNum1 << ", " << holdNum2 << ") = " << maxNum << endl;
        return;
    }


    //Iterate through the algorithm
    while((num1 % minNum != 0) || (num2 % minNum != 0)){
        // reduces minNum until it is a common divisor
        while(num2 % minNum){
            minNum--;
        }

        while(num1 % minNum){
            minNum--;
        }
    }

    //Output in correct format
    cout << "gcd(" << holdNum1 << ", " << holdNum2 << ") = " << minNum << endl;
    
}


/*
    Function:   middleSchoolAlgorithm()
    Purpose:    Finds the greatest common denomintator of the
                2 numbers passed to the function
*/
void middleSchoolAlgorithm(int num1, int num2) {
    int gcd = 1;
    int holdNum1 = num1;    //Holds the value of the corresponding variable for outputting
    int holdNum2 = num2;

    num1 = abs(num1);       //Finds the absolute value of the corresponding variable
    num2 = abs(num2);

    cout << "\nMiddle School Alogrithm:     ";
   
    if((num1 == 0) && (num2 == 0)) {  // handles special case for both inputs being 0
        cout << "gcd is undefined" << endl;
        return;
    } else if((num1 == 0) || (num2 ==0)) {   // handles special case where one of the inputs is 0
        cout << "gcd(" << holdNum1 << ", " << holdNum2 << ") = " << max(num1, num2) << endl;
        return;
    }

    while ((num1 > 1) && (num2 > 1)) {
        // Finding the smallest prime factors of each input
        int factor1 = smallestPrimeFactor(num1);
        int factor2 = smallestPrimeFactor(num2);

        if (factor1 == factor2) {   //common prime factor is found

            gcd *= factor1; //consecutively multiplies the common factor into the gcd

            // reducing the numbers by the common prime factor
            num1 /= factor1;
            num2 /= factor1;

        } else if (factor1 < factor2) { // Reduces num1 so that it can find the next smallest prime factor
            num1 /= factor1;
        } else {    // Reduces num2 so that it can find the next smallest prime factor
            num2 /= factor2;
        }
    }

    cout << "gcd(" << holdNum1 << ", " << holdNum2 << ") = " << gcd << endl;
}

/*
    Function:   smallestPrimeFactors()
    Purpose:    finds the smallest prime factor of the number sent to this function
*/
int smallestPrimeFactor(int num) {
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) { //checks to see if i is a prime factor of num if not increase i and try again
            return i;
        }
    }
    return num;
};