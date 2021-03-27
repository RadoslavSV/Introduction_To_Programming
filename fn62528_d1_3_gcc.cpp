/**
*
* Solution to homework assignment 1
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
    int a=0,b=0,c=0;
    int x1,x2,X,y2,y1;                      // declare the five numbers, which we will use to form the palindrome
                                            // x1=y1 - the first and the last; x2=y2 - the second and the penultimate; X - the middle
    cin>>a>>b>>c;

    if( a==0 && b==0 && c==0)                // check for the only case where we will print only one zero and that's if all three are 0s
    {
        cout<<0;
    }
    else

    if( a==b && b==c && a==c )                // firstly we check the most unique cases where the three input numbers are equal
    {
        cout<<a<<b<<c;
    }
    else

    if( a==0 && b==0 )                        // secondly we check to see if two of the three numbers are 0
    {
        cout<<c<<a<<b<<c;
    }
    else

    if( b==0 && c==0 )
    {
        cout<<a<<b<<c<<a;
    }
    else

    if( a==0 && c==0 )
    {
        cout<<b<<a<<c<<b;
    }
    else

    if( a==0 )                                       // then we check the other three rare cases where one of the input numbers is 0
    {                                                // (the palindrome cannot start with a 0)
        if(b>c) { cout<<c<<a<<b<<a<<c; }
        else if(b<c) { cout<<b<<a<<c<<a<<b; }
        else { cout<<b<<a<<c; }
    }
    else

    if( b==0 )
    {
        if(a>c) { cout<<c<<b<<a<<b<<c; }
        else if(a<c) { cout<<a<<b<<c<<b<<a; }
        else { cout<<a<<b<<c; }
    }
    else

    if( c==0 )
    {
        if(a>b) { cout<<b<<c<<a<<c<<b; }
        else if(a<b) { cout<<a<<c<<b<<c<<a; }
        else { cout<<a<<c<<b; }
    }

    else

    if ( a==b && a!=c && b!=c )                 // now we will see if two of the numbers are the same and the third is different
    {
        cout<<a<<c<<b;
    }
    else

    if ( b==c && b!=a && c!=a )
    {
        cout<<b<<a<<c;
    }
    else

    if ( a==c && a!=b && c!=b )
    {
        cout<<a<<b<<c;
    }
    else

{


    if(a>=b && a>=c && b>=c)                 // to choose the second (x2) and the penultimate (y2) numbers I create this complex of
    {                                       // six different IF operators through which the program will check every possible option of the
        x2=b;                               // greatness of the three input numbers; !we are looking for the middle-sized of the three!
        y2=b;
    }

    if(a>=b && a>=c && c>=b)
    {
        x2=c;
        y2=c;
    }

    if(b>=a && b>=c && a>=c)
    {
        x2=a;
        y2=a;
    }

    if(b>=a && b>=c && c>=a)
    {
        x2=c;
        y2=c;
    }

    if(c>=a && c>=b && a>=b)
    {
        x2=a;
        y2=a;
    }

    if(c>=a && c>=b && b>=a)
    {
        x2=b;
        y2=b;
    }

    x1=min(a,min(b,c));                 // the first, the last, and the middle numbers are easy to be chosen
    y1=x1;                              // the first = the last and they should have the lowest value of the three
    X=max(a,max(b,c));                  // the middle one is the one with the greatest value

    cout<<x1<<x2<<X<<y2<<y1;


}

    return 0;
}
