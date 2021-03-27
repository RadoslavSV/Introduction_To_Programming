/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Radoslav Velkov
* @idnumber 62528
* @task 1
* @compiler GCC
*
*/


#include <iostream>
using namespace std;
int main()
{
    int N, X, M;
    int gift = 30;                  // initialize a "gift" initially equal to 30 (since that's the sum he receives on his first even B-Day)
    int sumOdd=0, sumEven=0;        // initialize two different variables for sums - one for the even and the other-for odd
    cin>>N>>X>>M;                   // input the Birthday we will check (N); the price of the computer (X); the money he makes on odd B-Day

    for(int i=2;i<=N;i=i+2)                   // create one FOR loop for his even birthdays where the sum will increase due to the
    {                                         // received gift (and will decrease with 5);
        sumEven = sumEven + gift - 5;
        gift = gift + 30;                     // the "gift" will increase with 30 on his own every time he is being used
    }

    for(int j=1;j<=N;j=j+2)                   // and create a second FOR loop for his odd birthdays in which the sum will increase with the
    {                                         // input M
        sumOdd += M;
    }

    int finalSum = sumOdd + sumEven;          // then we accumulate both sums to get the final sum

    if (finalSum >= X)                        // check whether the "final" sum is enough to buy the computer (X) and calculate the
    {                                         // remaining money
        cout<<"yes"<<endl;
        cout<< finalSum - X;
    }
    else
    if (finalSum < X)                         // if the sum is not enough then we calculate the money he needs more to buy the computer (X)
    {
        cout<<"no"<<endl;
        cout<< X - finalSum;
    }

    return 0;
}
