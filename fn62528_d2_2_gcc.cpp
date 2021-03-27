/**
*
* Solution to homework assignment 2
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



#include<iostream>
using namespace std;
int main()
{
    int N=0;
    const int SIZE=365;         //initialize constant "SIZE" with value equal to the maximum number of numbers that can be input
    double act[SIZE];           //initialize an array ("act" shortened for actions)
    cin>>N;

    while(N<3 || N>365)         //check to see if N belong to [3;365]
    {
        cin>>N;
    }

    for(int i=0;i<N;i++)        //input every number in the first N containers of the array
    {
        cin>>act[i];
    }

    double min=act[0];          //initialize a real variable (type double), which will be used to find the first smallest action to buy, initially equal to the first value of the array
    int indexMin=0;             //we want to use its index as well
    double profit=0;               //and the "profit" variable will be used to count the current amount of money (we subtract the bought actions from it and add the sold ones to it)

    for(int i=1;i<N;i++)        //use for loop to start the first going through the array, which stop when one value is bigger than the next one
    {                           //(when we find an action that is more expensive than the one from the next day, we stop the first counting)

        if(act[i]<min)          //meanwhile, we are looking for the smallest of these actions
        {
            min=act[i];
            indexMin=i;
        }
        if(act[i]>act[i+1])     //here, when a cheaper action appears in the next day, the for loop terminates
        break;
    }
    profit -= min;                 //we have bought our first action, so we subtract it from the whole sum (profit)
    int indexSold=0;            //initialize a new index-following variable, which begins with the index of the first sold action

    for(int j=indexMin;j<N;j++) //now, we continue through the array, this time starting from the sold action
    {                           //we are looking for the most expensive price of our action, in order to make the biggest possible profit
        if(act[j]>act[j+1])     //immediately, when we find one that costs more than the following-day-one, we sell it
        {
            profit += act[j];      //that's why we now add the price of the actions to our general sum
            indexSold=j;        //and, of course, remember the index of the sold one, because we will start from its place forward now
            break;
        }
    }

    if(indexSold==N-1) cout<<profit;  //check if the index has reached the maximum input numbers: if it has - we end the program and print the profit
    else                              //but if it hasn't - the whole process continues
{
    while(indexSold!=N-1)          //create a while loop, which will serve as a check, if we have reached the end of the array
    {
        double secondMin=act[indexSold];   //now, everything is similar and repetitive from above
        int indexBought=0;
        for(int l=indexSold+1;l<N;l++)
        {
            if(act[l]<secondMin)           //search for the lowest, till reaching a bigger than its successor
            {
                secondMin=act[l];
                indexBought=l;
            }
            if(act[l]>act[l+1])
            break;
        }

        profit -= secondMin;                   //buy it (which means subtract from the total)
        indexSold = indexBought;

        for(int k=indexSold;k<N;k++)
        {
            if(act[k]>act[k+1])             //and now find the greatest and sell it for that price (add to the total profit)
            {
                profit += act[k];
                indexSold=k;
                break;
            }
        }
    }

    cout<<profit;
}
    return 0;
}
