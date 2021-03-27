/**
*
* Solution to homework assignment 1
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

int main()
{
    long long N=0;
    int m,n,p;

    cin>>N;

    while(N<1 || N>1000000000)           // check whether the input number N is less than one and bigger than 1 000 000 000
    {
        cin>>N;
    }

    int x=N,y=N,z=N;                    // initialize x, y and z equal to N so that we are sure N+N+N will be big enough for the comparison in the FOR loops next

    for(m=1;m<=N;m++)                   // make three FOR loops - one for each number (m, n, p) to make all possible ordered trios of numbers
    {
        for(n=1;n<=N;n++)
        {
            for(p=1;p<=N;p++)
            {
                    if(m*n*p==N && m!=n && n!=p && p!=m)              // we need only those triplets which multiplication equals N
                    {                                                 // and all three numbers must be different (not equal to one another)
                        if(m+n+p<x+y+z) { x=m; y=n; z=p; }            // if their sum is lower than the sum of x, y and z we give their
                    }                                                 // values to x, y and z and then the loop and the checks continue
            }
        }
    }

    if (x==N && y==N && z==N) cout<<-1;                       // check if the input number (N) has no three different divisors and print "-1"
    else

    cout<<x<<" "<<y<<" "<<z<<" "<<endl;

    return 0;
}

