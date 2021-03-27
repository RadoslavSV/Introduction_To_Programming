/**
*
* Solution to homework assignment 2
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
int main()
{
    int N=0, cnt=0;             //initialize a "counter" variable which will be used to count how many palindrome subarrays are there
    const int SIZE=1000;        //the maximum count of input numbers is 1000, and that's why I use a constant as a size for my array
    int arN[SIZE];              //arN stands for arabic numerals
    cin>>N;

    while(N<3 || N>1000)        //check to see whether N is between 3 and 1000
    {
        cin>>N;
    }

    for(int i=0;i<N;i++)        //input the first N numbers of our array; the other 1000-N containers will remain usused
    {
        cin>>arN[i];
    }


    for(int i=1;i<N;i++)        //start with a for loop and go through the whole array
    {
        if(arN[i-1]==arN[i+1])  //we watch every single element and if its two neighbour numbers are equal, then we have our first palindrome and count +1
        {
            cnt++;
            for(int m=2;m<=i;m++)       //then, we have to see if this palindrome is even bigger and start checking the equality between its neighbour numbers
            {
                if(arN[i-m]==arN[i+m]) cnt++;    //if they are equal, we expand the current palindrome and add another +1 to the total
                else break;                      //if they are not, we stop revising that particular palindrome and go on...
            }
        }
        if(arN[i]==arN[i+1])         //the other type of palindrome is the one where two neighbour numbers are equal (but just 2 numbers are not enough according to the conditions)
        {                            //and because of that we start checking their neighbour elements, if they are equal
            for(int n=1,k=2;n<=i;n++,k++)        //I use other names of variables as indexes(n,k), which will start from the closest to the two said numbers and increase with 1 each time
            {
                if(arN[i-n]==arN[i+k]) cnt++;    //the same way - if the two closest numbers by both sides to the first numbers are equal, we now have a new palindrome (4-digited) and cnt++
                else break;                      //again - it's important to terminate the loop if a pair of elements are not equal to one another
            }
        }
    }                                        //the whole process goes on until we have gone through the whole array

    if(cnt==0) cout<<-1;                  //no subarrays fulfilling the condition
    else cout<<cnt;                       //print the final sum of these palindrome subarrays with at least 3 digits

    return 0;
    }
