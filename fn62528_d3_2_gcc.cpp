/**
*
* Solution to homework assignment 3
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

int LengthOfString(char s[])                      //implement a function that counts how many symbols are there in the string
{
    int idx;                                        //define "idx" outside of the loop's scope, because we use it outside of that scope in the return statement
    for(idx=0;s[idx]!='\0';idx++);                      //use "idx" as an index that will simply increase by one each iteration till the terminating zero is reached
    return idx;
}

void CopyStrings(char result[], const char s[])        //implement a function that copies one string into another (<destination>, <source>)
{                                                      //the first one is the one we're copying into (result (<destination>)), the second is a constant because it does not change its values (<source>)
    int i=0;                                           //define "i" out of for's scope, because we use it at the end, after the loop finishes
    for(i=0;s[i]!='\0';i++)                            //until the constant reaches its terminating zero
    {
        result[i]=s[i];                                //give the result string the value of the respective source string
    }
    result[i]='\0';                                    //we must add the terminating zero at the end

    return;                                            //when the function gets to "return", it ends
}

int PrintResultCharacterSequence(char a[], char b[], char x[])        //define a function that will check if the 3rd input string could be a result of concatenated mixed(or not) 1st and mixed(or not) 2nd
{                                               //use simple names of the strings here: a, b, x. (because we are looking for: a + b = x)
    const int SIZE=150;                         //use a constant because we are not allowed to input more than 150 symbols into a single character sequence

    for(int i=0;i<LengthOfString(a);i++)        //before going to the main task itself, we will exclude every input that is immediately seen as unable to fulfill the conditions
    {
        if(a[i]<'a' || a[i]>'z')                //the first one is when one of the three strings contains an illegal symbol (everything different than a small latin letter is considered "illegal")
            {
                return -1;                      //then the program returns -1 (referring to not valid symbols being input)
            }                                   //this is enough to end the whole process and not continue below
    }

    for(int i=0;i<LengthOfString(b);i++)        //analogically with the second..
    {
        if(b[i]<'a' || b[i]>'z')
            {
                return -1;
            }
    }

    for(int i=0;i<LengthOfString(x);i++)        //and the third strings.
    {
        if(x[i]<'a' || x[i]>'z')
            {
                return -1;
            }
    }

    if(LengthOfString(x)!=LengthOfString(a)+LengthOfString(b))  //now finally, if the first two strings' lengths' sum is not equal to the length of the result string there is no point in continuing below
    {
        return 0;
    }



  else                     ////the main task starts from here below////
    {
        char a1[SIZE],b1[SIZE],x1[SIZE];      //I decided to use different strings for every of the four different cases I'm going to go through below
        char aa[SIZE],bb[SIZE],xx[SIZE];      //all of these are just identical names to the original trio (a, b and x) for easier work and understanding
        char aaa[SIZE],bbb[SIZE],xxx[SIZE];   //the sole reason I need them is because in every different case I change the values of the already used ones
        CopyStrings(a1,a);                  //use our function to copy a into a1, aa and aaa
        CopyStrings(b1,b);                  //analogically - b to b1, bb and bbb
        CopyStrings(x1,x);                  //and x - to x1, xx, xxx
        CopyStrings(aa,a);
        CopyStrings(bb,b);
        CopyStrings(xx,x);
        CopyStrings(aaa,a);
        CopyStrings(bbb,b);
        CopyStrings(xxx,x);

        bool firstCaseEnough=false;        //define one huge bool variable which I am using between the first two and the second two cases
//the task has 4 main cases, which can be separated in 2 subcases
        int yesA=0, yesB=0;                //define counters for the first case; one will count for the first string, the other - for the second
        bool isOne=false;                  //bool variable; used at the end of the first case to determine whether to end or continue
        for(int i=0;i<LengthOfString(a);i++)    //FOR loop to go through the first string (that's why it ends when reaches its length (-1))
        {
            for(int j=0;j<LengthOfString(a);j++)    //second FOR with other index that is used as an index for the result string (from now on "i" will always be used as an index for one of the first two strings, whereas "j" - for the result string)
            {                                       //I intentionally do not use "x", "a" and "b" as indexes, because their names could be confused with the names of the strings
                if(a[i]==x[j])                    //if a symbol from the first string is the same a symbol from the third string
                {
                    yesA++;                   //increase our counter for that particular string
                    x[j] += x[j];             //IMPORTANT STEP: this is something I do to make sure (if there are repetitive symbols) that during every next iteration this already counter symbol in the result string won't be counted again as a counterpart of the same letter
                    break;                    //and end the going through the whole string
                }
            }
        }

        for(int i=0;i<LengthOfString(b);i++)         //the situation here is identical to the one above but for the second input string
        {
            for(int j=LengthOfString(a);j<LengthOfString(x);j++)   //that's why here the result string index begins from where "j" ended in the previous loop and continues until it reaches the end of the third string
            {
                if(b[i]==x[j])          //absolutely the same here...
                {
                    yesB++;
                    x[j] += x[j];
                    break;
                }
            }
        }

        if(yesA==LengthOfString(a) && yesB==LengthOfString(b)) isOne=true;         //and now if these counters (yesA and yesB) have both counted accurately to the length of their respective strings
        if(isOne)                                              //we conclude that the strings fulfill the conditions and..
        {
            return 1;                                         //...return 1 and...
        }                                                     //indicate the end of the whole process.

        else                                                   //but if not, we have to continue checking
        {
            int yesA2=0, yesB2=0;                              //use synonym indicators of the variable as above
            bool isStillOne=false;
            for(int i=0;i<LengthOfString(a1);i++)
            {
                for(int j=LengthOfString(b1);j<LengthOfString(x1);j++)       //here we check if the first input string is positioned latter in the result concatenation
                {
                    if(a1[i]==x1[j])
                    {
                        yesA2++;
                        x1[j] += x1[j];
                        break;
                    }
                }
            }

            for(int i=0;i<LengthOfString(b1);i++)                      //and respectively, check the second string, which here is in the beginning in the result string
            {
                for(int j=0;j<LengthOfString(b1);j++)
                {
                    if(b1[i]==x1[j])
                    {
                        yesB2++;
                        x1[j] += x1[j];
                        break;
                    }
                }
            }

        if(yesA2==LengthOfString(a1) && yesB2==LengthOfString(b1)) isStillOne=true;        //again, if the respective lengths are as they should, we terminate with a true value for the variable
        if(isStillOne)
        {
            firstCaseEnough=true;                                           //and here, the first two main cases conclude and we use our biggest variable to indicate so
            return 1;
        }
    else                                                                    //but if the enough conditions are still not found, the program continues to check
    {
        int yesA=0, yesB=0;                                               //here, the situation is like the previous two cases, but they are mirrored as well
        bool isOne=false;                                                 //the difference is that the inputting of the first two strings is swapped and so are their respective cases
        for(int i=0;i<LengthOfString(aa);i++)
        {
            for(int j=LengthOfString(bb);j<LengthOfString(xx);j++)
            {
                if(aa[i]==xx[j])
                {
                    yesA++;
                    xx[j] += xx[j];
                    break;
                }
            }
        }

        for(int i=0;i<LengthOfString(bb);i++)
        {
            for(int j=0;j<LengthOfString(aa);j++)
            {
                if(bb[i]==xx[j])
                {
                    yesB++;
                    xx[j] += xx[j];
                    break;
                }
            }
        }

        if(yesA==LengthOfString(aa) && yesB==LengthOfString(bb)) isOne=true;
        if(isOne)
        {
            return 1;
        }
        else
        {
            int yesA2=0, yesB2=0;
            bool isStillOne=false;
            for(int i=0;i<LengthOfString(aaa);i++)
            {
                for(int j=LengthOfString(bbb);j<LengthOfString(xxx);j++)
                {
                    if(aaa[i]==xxx[j])
                    {
                        yesA2++;
                        xxx[j] += xxx[j];
                        break;
                    }
                }
            }

            for(int i=0;i<LengthOfString(bbb);i++)
            {
                for(int j=0;j<LengthOfString(bbb);j++)
                {
                    if(bbb[i]==xxx[j])
                    {
                        yesB2++;
                        xxx[j] += xxx[j];
                        break;
                    }
                }
            }

        if(yesA2==LengthOfString(aaa) && yesB2==LengthOfString(bbb)) isStillOne=true;
        if(isStillOne)
        {
            firstCaseEnough=true;
            return 1;
        }
        else                                 //and here, after we've gone through all four cases and if they are still not fulfilling the conditions
        {
            return 0;                        //it can be concluded that the so inputted first and second strings could not result in the third one
                                             //eventually, the function terminates
        }
        }
     }
        }
    }
}


int main()                                                          //in the main function:
{
    const int SIZE=150;                                             //use a constant, because not more than a hundred and fifty symbols could be input into every of the three character sequences
    char first[SIZE],second[SIZE],result[SIZE];                     //define three strings (first and second, which concatenated and mixed(or not) could compose the result one)
    cin>>first>>second>>result;                                     //input all three of them

    cout<<PrintResultCharacterSequence(first,second,result);        //and use our written function with the three strings as its parameters

    return 0;
}
