/**
*
* Solution to homework assignment 2
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
#include <vector>                        //library <vector> needed to use vectors
using namespace std;
int main()
{
    int N=0;
    cin>>N;

    while(N<3 || N>100)                  //input check: the program needs to know the number of unique elements that are going to be input
    {
        cin>>N;                          //until the user inputs a numbers between 3 and 100, they will have to input again
    }

    int number=0;                        //need numbers that belong to [-2147483648, 2147483647] so type "int" is appropriate
    vector <int> everyElement;           //initialize a vector (a dynamic array), because that way we can delete (erase) repetitive numbers from all numbers
    for(int i=0;i<N;i++)                 //use a for loop for user's input
    {
        cin>>number;                     //start inputting every element; one by one
        everyElement.push_back(number);


        for(int k=i;k>0;k--)             //use a variable "k" that starts from the current "i" and decreases with one each iteration
        {
            int j=i-k;                   //we subtract that variable from the index we are currently using (i) and give that value to a new variable "j"
            if(i!=j && everyElement[i]==everyElement[j])   //the indexes have to be unequal, because otherwise we will be comparing one number with itself
            {                                              //AND if it happens that any two elements from all elements are equal
                everyElement.erase(everyElement.begin()+j);//we delete that element (since it's repetitive/already input)
                i--;                                       //and we have to decrease the index once, so it returns to the same one we just checked
            }                                              //because that index now contains a new value
        }

    }

    const int SIZE=100;                                    //no more than one hundred UNIQUE elements are allowed so that's why we use a constant
    int uniqueElementsArr[SIZE];                           //create an array to store each unique value

    for(int i=0;i<N;i++)                                   //with this loop, we now give every single number's value of the vector to the new static array
    {
        uniqueElementsArr[i]=everyElement[i];
    }

    int counter=0;                                //create a counter variable that will simply count and be printed as the final result

    for(int i=0;i<N;i++)                          //now I use three nested FOR loops to go through every single possible combination of three numbers of that array
    {
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<N;k++)
            {
                if(i!=j && j!=k && k!=i && i<j && j<k && k>i && uniqueElementsArr[i]+uniqueElementsArr[j]+uniqueElementsArr[k]==0)
                { //to find the combination we're looking for: all three indexes have to be unequal AND their respective elements must have their accumulated values equal to zero
                    counter++; //and then we add 1 to the counter
                }
            }
        }
    }

    cout<<counter;

    return 0;
}
