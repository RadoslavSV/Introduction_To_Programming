/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Radoslav Velkov
* @idnumber 62528
* @task 2
* @compiler GCC
*
*/


#include <iostream>
using namespace std;
                                      // just to be clear - the program will return "-1" in the console, if the input data is less than
int main()                            // two different numbers
{
    int a=1;                          // initialize a counter initially equal to one, so that we can set the condition of while to be "a>0"
    int penultimate=0,ultimate=0;     // initialize ultimate (largest/greatest) and penultimate (second to largest) numbers, both initially
                                      // equal to zero

    while (a>0)
    {
        cin>>a;                             // input number greater than zero

        if(a>ultimate)                    // in the case where the input number (a) is bigger than the last ultimate:
        {
            penultimate=ultimate;         // from the second iteration till the last, the penultimate will receive the value of the ultimate;
            ultimate=a;                   // the ultimate gets the value of the input(a);(the first input automatically becomes the largest)
        }
        else
        if(a>penultimate && a<ultimate)     // but when the input number isn't larger than the last ultimate, but is larger than the last penultimate:
        {
            penultimate=a;                  // the penultimate gets its value
        }

    }

    if(penultimate==0)                           // check to see if there is enough input data to print the second to largest number
    {                                            // if there isn't then simply print "-1"
        cout<<-1;
    }
    else

    cout<<penultimate;

    return 0;
}
