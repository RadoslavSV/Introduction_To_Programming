/**
*
* Solution to homework assignment 3
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

int LengthOfString(char s[])                      //implement a function that counts how many symbols are there in the string
{
    int idx;                                        //define "idx" outside of the loop's scope, because we use it outside of that scope in the return statement
    for(idx=0;s[idx]!='\0';idx++);                      //use "idx" as an index that will simply increase by one each iteration till the terminating zero is reached
    return idx;
}

void PrintIsCharacterSequenceCorrect(char str[])        //define a function, which will print 1 or 0, according to whether the input char sequence is "correct" according to the conditions
{
        const int SIZE=150;                             //the maximum number of elements in the string must not be higher than 150

        int arr[SIZE], arrSize=0;                       //define an array that will serve as a "counter" of the times every unique element is being input

        for(int i=0;i<LengthOfString(str);i++)                  //the number of elements of the array we need is equal to the length of the input string
        {
            arr[i]=0;                                   //and that's why we give these containers default values of zero
        }

        for(int i=0;i<LengthOfString(str);i++)                  //now use a for loop to input into the array the times every element of the string had been input (as integer numbers)
        {
            bool alrIn=false;
            for(int k=0;k<arrSize;k++)                  //<--- this will start to check after the first iteration is completed
            {
                if(i!=k && str[i]==str[k])              //we need to check for already input symbols (alrIn)
                {
                    alrIn=true;                         //and if a symbol is already in, then we just omit counting again how many times it had been input and the container value remains zero
                    break;
                }
            }

            if(not alrIn) {                             //if not, then we start counting how many times that symbol is found in the string

            for(int j=i;j<LengthOfString(str);j++)
            {
                if(str[i]==str[j])
                {
                    arr[i]++;                           //as I said, every container of the array serves as a counter for their respective symbol
                }
            }
        }
        arrSize++;                                      //of course, we need to count how many containers we are going to use as well

        }

        bool correctWithFirstElOne=false;               //use appropriate bool variable to tell us the final result
        if(arr[0]==1)                                   //firstly, let's check the most unique case where the first symbol is written only once
        {
            for(int i=2;i<arrSize;i++)                  //we can start checking from the third container (second index), because we know the first and the second doesn't have to be compared with itself
            {
                if(arr[1]!=arr[i] && arr[i]!=0)         //the second one has to be equal with every other left (or of course be equal zero; zeros do nothing in this whole checking FROM NOW ON and we just ignore them)
                {
                    correctWithFirstElOne=false;        //if there happens to be just one element with different value (with index bigger than 1)
                    break;                              //we can conclude that out string is not "correct"
                }
                else correctWithFirstElOne=true;        //otherwise it could be..
            }
        }
        bool correctWithFirstElBiggerThanOne=false;     //use appropriate bool variable to tell us the final result
        if(correctWithFirstElOne) cout<<1<<endl;
    else
    {
            if(arr[0]>1 && arr[0]!=arr[1])              //now check the case where the first element is bigger than 1 (that first el has to be different than the next one)
        {
            for(int i=2;i<arrSize;i++)                  //already explained FOR loop above
            {
                if(arr[1]!=arr[i] && arr[i]!=0 && arr[i]!=arr[0]-1)     //the second symbol has to be equal to every other(of course every other could be zero (explained above)), as well as it could be with only 1 less than the first one
                {
                    correctWithFirstElBiggerThanOne=false;              //if these conditions are not fulfilled then we conclude that the string is not "correct"
                    break;
                }
                else correctWithFirstElBiggerThanOne=true;             //otherwise it could be...
            }

            for(int i=2;i<arrSize;i++)                       //one more unique case which we have to go through
            {
                if(arr[0]>arr[i]+1 && arr[i]!=0)             //if the first count of the first symbol is too big (specifically greater than 1 more than the current) (and again of course it could be zero)
                {
                    correctWithFirstElBiggerThanOne=false;   //then the string cannot be "correct"
                    break;
                }

            }
        }

        if(correctWithFirstElBiggerThanOne) cout<<1<<endl;   //use the bool variable to print final result
        else                                                 //if the bool variable is 0, we continue to check
    {
        int commonNumberOfHappening = arr[0];                //use new variable equal to the first symbol (just for better reading)

        bool isCorrect=true;                                 //once again, appropriate bool variable

        for(int i=0;i<arrSize;i++)                           //already known way of going through each element of the array
        {
            if(arr[i]!=commonNumberOfHappening && arr[i]!=0)  //if the checking finds a number different than the so called "common" number (it could be zero as well)
            {
                isCorrect=false;                              //then the string is not "correct"
                break;
            }
        }

        if(isCorrect) cout<<1<<endl;                          //use that variable to check and print
        else                                                  //or not
        {
            int oddCounter=0, cnt=0;                          //now use a variable "oddCounter" which is not exactly a counter but just saves the value of an odd number (different than the "common")
                                                              //and the actual counter is "cnt" which is used to count how many odd numbers are found
            for(int i=0;i<arrSize;i++)
            {
                if(arr[i]!=commonNumberOfHappening && arr[i]!=0)      //if the aforementioned numbers are found
                {
                    oddCounter=arr[i];                              //we give the oddCounter value equal to that particular odd number
                    cnt++;                                          //and count once
                }
            }
            //the final checking
            if(commonNumberOfHappening==2 && oddCounter==1 && cnt==1) cout<<1<<endl;     //cNOH could be 2 only if the odd element is one and is equal to one
            else if(commonNumberOfHappening==oddCounter-1 && cnt==1) cout<<1<<endl;      //cNOH could be with one less than the odd number but there could be just one
            else if(oddCounter==1 && cnt==1) cout<<1<<endl;                              //simply, if the odd element is equal to one and is encountered once, the string is "correct"
            else cout<<0<<endl;                                                     //and here we can conclude that the string is not "correct"
        }
    }
    }

}

int main()
{
    const int SIZE=150;              //use a constant, since the maximum number of input symbols in the array could not be greater than 150
    char s[SIZE];                    //define a character sequence
    cin.getline(s,SIZE);             //input that sequence

    PrintIsCharacterSequenceCorrect(s);       //use already implemented function to print 1 or 0, according to the conditions


    return 0;
}
