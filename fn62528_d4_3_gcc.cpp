/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Radoslav Velkov
* @idnumber 62528
* @task 3
* @compiler GCC
*
*/




#include <iostream>
using namespace std;

void ConvertToIrreducibleFraction(int &numerator, int &denominator)         //write a function that will convert any fraction into an irreducible one
{                                                                           //by receiving numerator and denominator as parameters
    for(int divisor=2;divisor<100000000;divisor++)                          //use a "divisor" variable that will begin at 2 (since there's no point in dividing by one and cannot divide by zero)
    {                                                                       //and will go on until it reaches 10 to the power of 8, because that should be enough
        while(numerator%divisor==0 && denominator%divisor==0)               //use the condition that while both the numerator and the denominator are exactly divisible by the same number, we divide them by that particular number
        {
            numerator /= divisor;
            denominator /= divisor;
        }
    }
}

void PrintArray(int arr[], int N)      //write a function that prints an array with N elements in it
{
    for(int i=0;i<N;i++)
    {
        cout<<arr[i]<<" ";             //print the numbers with an interval between each of them
    }
    cout<<endl;
}

void ReturnCalculatedNumeratorAndDenominator(int a, int b, char s, int c, int d)
{//write the wanted function according to the task with parameters respectively - numerator and denominator of the first fraction, then the arithmetic op and then the second fraction's parts
    int resultN=0, resultD=0; //define variables that will serve as "result" variables for their respective part of the fraction
    int arr[2];               //define an integer array with only two elements in it - the first one is for the numerator, the second one - for the denominator

    switch(s)                 //use "switch" operator, with four different cases for the four allowed arithmetic operations (+,-,*,/)
    {
    case '+':

        if(b==d)              //if the input denominators are equal
        {
            resultN=a+c;      //we just sum both numerators
            resultD=b;        //and leave the denominator the same
        }
        else                  //if they're not equal
        {
            resultN=a*d+c*b;  //then I decided not to use the GCD method, ...
            resultD=b*d;      //...so just expand both fractions until they both have the same denominator equal to the product of the two input denominators
        }

        ConvertToIrreducibleFraction(resultN, resultD);   //use our implemented function

        arr[0]=resultN;     //the first container of the array receives the value of the calculated numerator
        arr[1]=resultD;     //the second (and last) container is given the value of the calculated denominator

        PrintArray(arr,2);  //print the result numerator and denominator

        break;              // use break in order not to fall into the other cases

    case '-':               //absolutely identical situation here with the subtraction case

        if(b==d)
        {
            resultN=a-c;
            resultD=b;
        }
        else
        {
            resultN=a*d-c*b;
            resultD=b*d;
        }

        ConvertToIrreducibleFraction(resultN, resultD);

        arr[0]=resultN;
        arr[1]=resultD;

        PrintArray(arr,2);

        break;

    case '*':         //now it the operation is multiplication

        resultN=a*c;  //just multiply the numerators with each other
        resultD=b*d;  //...as well as the denominators

        ConvertToIrreducibleFraction(resultN, resultD);   //and again use the simplification function at them

        arr[0]=resultN;
        arr[1]=resultD;

        PrintArray(arr,2);

        break;

    case '/':        //identical with the multiplication method; actually, just swap the numerator and the denominator of the second fraction and execute multiplication

        if(c==0) cout<<-1;  //when the operation is division, the input numerator of the second fraction cannot be zero (because division is basically multiplication by the reciprocal)
        else   //but if the input numerator of the second fraction is anything different than zero, go on as usual
        {
            resultN=a*d;
            resultD=b*c;

            ConvertToIrreducibleFraction(resultN, resultD);

            arr[0]=resultN;
            arr[1]=resultD;

            PrintArray(arr,2);
        }

        break;
    }
}

int main()                                                   //in the main function:
{
    int numerator1=0, denominator1=0, numerator2=0, denominator2=0;     //declare and initialize all five needed variables that will be input by the user
    char arithmeticOperation=0;
    cin>>numerator1>>denominator1>>arithmeticOperation>>numerator2>>denominator2;

    if ( (numerator1<-100000000 || numerator1>100000000)        //use one big IF operator checking every possible illegal data input and printing -1 if found
         || (denominator1<-100000000 || denominator1>100000000 || denominator1==0)        //(denominators cannot be zeros, and if the wanted operation is division, then zero cannot be input as a numerator of the second fraction, as well)
         || (numerator2<-100000000 || numerator2>100000000)
         || (denominator2<-100000000 || denominator2>100000000 || denominator2==0)
         || (arithmeticOperation!='+' && arithmeticOperation!='-' && arithmeticOperation!='*' && arithmeticOperation!='/') )
    {
        cout<<-1;
    }
    else       //if not illegal input data is found:
    {
        ReturnCalculatedNumeratorAndDenominator(numerator1, denominator1, arithmeticOperation, numerator2, denominator2);   //use the implemented function
    }



    return 0;
}
