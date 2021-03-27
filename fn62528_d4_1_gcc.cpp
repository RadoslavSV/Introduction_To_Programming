/**
*
* Solution to homework assignment 4
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




#include<iostream>
using namespace std;

//Just to be clear: ZERO is not a Natural number.

void CopyArrays(int arr1[], int arr2[], int M)         //write a function that copies one array into another one
{
    for(int i=0; i<M; i++)
    {
        arr2[i]=arr1[i];
    }
}

void InputArray(int arr[], int M)                      //write a function that inputs an array
{
    for(int i=0; i<M; i++)
    {
        cin>>arr[i];
    }
}

int MostRecurringNumber(int arr[], int M)         //write a function that returns the most recurring number in an array
{
    int biggestN=arr[0];                   //initialize a variable that will receive the value of the biggest number in the array
    for(int i=1;i<M;i++)
    {
        if(biggestN<arr[i]) biggestN=arr[i];
    }
    const int histSIZE=biggestN;  //use a constant that will serve as the size of a histogram (it has to be the biggest possible number whose repetitions will be counted)
    int hist[histSIZE];           //initialize a histogram array that will count how many times each numbers recurs in the array
    for(int i=0;i<histSIZE;i++)
    {
        hist[i]=0;         //first, make every number equal to zero (as per default)
    }
    for(int i=0;i<M;i++)
    {
        hist[arr[i]-1]++;     //and now add one to the count of every number that has been encountered in the input array
    }
    int biggest=hist[0];   //create a variable that will eventually receive the biggest input value, initially equal to the very first container of the histogram array
    int idx=0;               //and an index (the index of that "biggest" number)
    for(int i=0;i<histSIZE;i++)
    {
        if(biggest<hist[i])
        {
            biggest=hist[i];
            idx=i;
        }
    }
    return idx+1;
    //at the end, return that index but increased with one (because the indexes in an array start from zero, but we cannot have 0 as input value (the lowest is 1) and that's why 0 counts the times number one is encountered and so on...)
}

int CountOfNumbersDifferentThanTheMostRecurringOne(int arr[], int M)       //and now write a function that will return the count of how many numbers, not equal to the most recurring one, are found
{
    int mostRecurring=MostRecurringNumber(arr, M);      //use the aforeimplemented function to give value of our new variable
    int cnt=0;  //counter variable
    for(int i=0;i<M;i++)
    {
        if(arr[i]!=mostRecurring) cnt++;      //simply, when a number in the array is not the most recurring one, "cnt" increases
    }
    if (arr[M-1]>mostRecurring) return cnt-1;  //if the very last number is bigger than the most occurring, it does not hinder the process, so the counter could be decreased once (once because of that last number)
    else return cnt;
}

bool WrongArrayInputData(int arr[], int M)            //write a function that check if the array is correct
{
    bool wrongInputData=false;
    for(int i=0; i<M; i++)
    {
        if(arr[i]<=0) wrongInputData=true;             //simply, if any element is lower than or equal to zero (thus not a Natural number)...
    }
    return wrongInputData;                            //...it's enough to conclude that the input data is incorrect
}

bool CouldTheArrayBecomeIncreasing(int arr[], int M, int N)
{//write the wanted function that will return a true/false value according to whether a certain array could become increasing by changing exactly N numbers in it (optimal changes)
    int originalArray[M];         //define a second array which will be exactly the same as the input one (used because I change the values of the array, while going through it and then want to go through the first one for a second time)
    int thirdArray[M];
    CopyArrays(arr, originalArray, M);      //use our aforeimplemented function to copy the first into the second array
    CopyArrays(arr, thirdArray, M);

    int leftToRightBiggerFound=0;        //initialize two variables - the first will count the first case
    int rightToLeftBiggerFound=0;        //whereas the second - the second looked case

    for(int i=0; i<M-1; i++)             //go through the array beginning from the very first element and going forward
    {
        if(arr[i] > arr[i+1])            //if a number, bigger than its successor, is encountered:
        {
            arr[i+1] = arr[i];           //then give its successor the value of that current number (because that's the minimum this number can be in order to have an increasing array (they could be equal and the array could still be increasing))
            leftToRightBiggerFound++;    //and add one to the counter variable
        }
    }

    for(int i=M-1; i>0; i--)             //identical here, but the going through the array happens backwards, starting from the last number
    {
        if(originalArray[i] < originalArray[i-1])    //and, of course, if its predecessor is bigger, we do the same thing
        {
            originalArray[i-1] = originalArray[i];
            rightToLeftBiggerFound++;
        }
    }

    int neededActions=0;                 //use another variable
    neededActions = min(min(leftToRightBiggerFound,rightToLeftBiggerFound),CountOfNumbersDifferentThanTheMostRecurringOne(thirdArray,M));
    //it will be the lowest of the two counters (these two counters represent both possible cases of checking) and the third case where it takes less changes if we just make all numbers equal

    if(neededActions <= N) return true;  //if N is enough, according to the value of the needed actions, return true
    else return false;

}

int main()
{
    int N=0, M=0;
    cin>>N>>M;

    if(M<=0 || N<=0 ) cout<<-1;             //N and M have to be Natural numbers
    else
    {
        int userArray[M];                   //now we define the array
        InputArray(userArray,M);            //input its M elements

        if(WrongArrayInputData(userArray,M)) cout<<-1;      //now check the input data of the array, since it has to be in the set of Natural numbers as well
        else
        {
            cout<<CouldTheArrayBecomeIncreasing(userArray,M,N);    //and eventually here, after all checks have been made, we use the implemented function
        }
    }

    return 0;
}
