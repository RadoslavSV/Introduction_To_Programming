/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Radoslav Velkov
* @idnumber 62528
* @task 4
* @compiler GCC
*
*/



#include <iostream>
using namespace std;

int LengthOfString(char s[])                      //implement a function that counts how many symbols are there in the string
{
    int idx;                                        //define "i" outside of the loop's scope, because we use it outside of that scope in the return statement
    for(idx=0;s[idx]!='\0';idx++);                      //use "i" as an index that will simply increase by one each iteration till the terminating zero is reached
    return idx;
}

int NumberOfAllPossibleSubstrings(char s[])           //function that returns all possible substrings according to the task
{
    if(LengthOfString(s)>=100)                        //string's length must be lower than one hundred
    {
        return -1;
    }

    for(int i=0;i<LengthOfString(s);i++)
    {
        if( (s[i]<'A' || s[i]>'Z') && (s[i]<'a' || s[i]>'z') )     //if a symbol different than a latin letter is encountered...
            return -1;                                             //...the program returns -1 indicating that there is incorrect input data
    }
////////////////////   nothing substantial here below (not working code; not even close to being a working one)/////////////////////////////////
    int counter=0;
    const int MAX_SIZE=100;
    int newS[MAX_SIZE]={};

    for(int i=0;i<LengthOfString(s);i++)
    {
        for(int j=i;j<LengthOfString(s);j++)
        {
            if(i!=j && s[i]==s[j])
            {
                newS[i]++;
                //s[j] = '0';
            }
        }
    }

    for(int i=0;i<LengthOfString(s);i++)
    {
        cout<<newS[i];
    }



//    for(int i=0;i<LengthOfString(s);i++)
//    {
//        cout<<s[i];
//    }

    cout<<endl;
    return counter;               //the only thing I know is that the function should return the so called "counter" variable
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

int main()
{
    const int MAX_SIZE=100;           //use a constant with size equal to the maximum allowed number of input elements
    char userStr[MAX_SIZE];           //define a character sequence

    cin.getline(userStr,MAX_SIZE);    //input that string

    cout<<NumberOfAllPossibleSubstrings(userStr);      //print the returned value of the funtion

    return 0;
}
