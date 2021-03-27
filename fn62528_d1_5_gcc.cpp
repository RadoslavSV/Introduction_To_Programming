/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Radoslav Velkov
* @idnumber 62528
* @task 5
* @compiler GCC
*
*/


#include <iostream>
using namespace std;

int main()
{
    double N,Num; int digitCounter=0;
    cin>>N;

    while (N<2 || N>1000000000)        // input check
    {
        cin>>N;
    }

    Num=1/N;                           // declare variable Num and give it the value of (1/N)


    for( ;Num!=0; )                    // create a FOR loop with the condition that Num has to be different than 0 (i.e. a decimal)
    {
        Num=Num*10;                    // shift the decimal separator to the right once
        digitCounter++;                // the counter increases with one each iteration the loop does
        int integerNum=Num;            // define an integer variable which receives the value of the current number
        Num -= integerNum;             // subtract that integer from the decimal number
    }

    if(digitCounter>=49)               // check to see if Num is a repeating decimal
    {
        cout<<"NO";
    }
    else

        cout<<digitCounter;

    return 0;
}
