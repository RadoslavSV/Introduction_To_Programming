/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Radoslav Velkov
* @idnumber 62528
* @task 5
* @compiler GCC
*
*/



#include<iostream>
#include<fstream>
using namespace std;

int LengthOfString(char s[])                      //implement a function that counts how many symbols are there in the string
{
    int idx;                                      //define "idx" outside of the loop's scope, because we use it outside of that scope in the return statement
    for(idx=0;s[idx]!='\0';idx++);                //use "idx" as an index that will simply increase by one each iteration till the terminating zero is reached
    return idx;
}

int main()
{
    const int MAX_SIZE=10000;                     //use a constant integer whose value is a lot higher than the maximum number of symbols one line is allowed to contain (I think 10 000 is big enough)
    char str[MAX_SIZE];                           //define a character sequence
    ifstream inFile;                              //input stream class to operate on files - "inFile" in order to read from a file
    inFile.open("message.txt", ios::in);          //open a .txt file named "message.txt"
    if(!inFile)                                   //check if the file does not open
    {
        cout<<-2<<endl;
    }

    bool needToContinue=true;                     //use a bool variable if there is any need to continue reading the document
    while(inFile.getline(str,MAX_SIZE,'\n'))      //read each line until the maximum size OR a new line is reached
    {
        for(int i=0;i<min(LengthOfString(str),150);i++)    //go through each string on each row
        {//the maximum size of array that is allowed is 150, so the loop ends once the index has reached either the length of the string(if it's lower than 150) or the maximum itself (150; this means the string is longer and we ignore any odd symbols)
            if( (str[i]<'A' || str[i]>'Z') && (str[i]<'a' || str[i]>'z') )       //if incorrect data is read (anything different from a lowercase/uppercase latin letter)
                {
                    needToContinue=false;                                        //there is no need to go on below and end the process with printing -2
                    cout<<-1;
                    break;
                }
        }
    if(needToContinue)                                   //anyway, if no illegal symbols are found:
    {
        char smallest=str[0];                            //define a character variable initially being the very first symbol of the string
                                                         //use it to find the searched letter (smallest to not be input as well as bigger that the smallest input)
        for(int i=0;i<min(LengthOfString(str),150);i++)           //go through the whole string..
        {
            if(smallest>str[i]) smallest=str[i];         //..in order to find the smallest element (according to the ASCII table)
        }
        smallest++;                                      //increase it by one (the task inquires so)

        int iterations=0;                                //define a variable that will count iterations

        while(iterations<=150)
        {//we want to make sure the for loop here iterates at least 150 times (since there cannot be more than 150 equal symbols)
            for(int i=0;i<min(LengthOfString(str),150);i++)
            {
                if(smallest==str[i]) smallest++;         //and if neighbour letters keeps being encountered again and again, we make sure it goes through all of them
            }
            iterations++;                                //iterations increase
        }

        if(smallest>'Z' && smallest <'a')                //here is the case where that searched symbol is in the gap between 'Z' and 'a' (91 and 96 in ASCII)
            smallest = 'a';                              //and we just give it the value of 'a' (and everything may continue normally)

        iterations=0;
        while(iterations<=150)                           //now after that small check, we repeat the same thing again just to make sure everything's fine
        {
            for(int i=0;i<min(LengthOfString(str),150);i++)
            {
                if(smallest==str[i]) smallest++;
            }
            iterations++;
        }

        if(smallest>'z') smallest='.';                  //and here, finally, is the case where that searched letter has greater ASCII value than the biggest allowed symbol
                                                        //we print a dot ('.')
        cout<<smallest;
    }
    }

    inFile.close();                                     //in the end, close the file that was once opened

    return 0;
}
