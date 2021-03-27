/**
*
* Solution to homework assignment 3
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
#include <math.h>                                    //use <math.h>, since I use functions "fabs" and "pow"
using namespace std;

const int SIZE=1000;                                  //define a global constant with the maximum size of the input number N
double matrix[SIZE][SIZE];                            //define a global 2D array, serving as a matrix

bool AreEqual(double first, double second)           //define a bool function that will compare two real numbers (type double) and return respective value if they are equal or not
{
    if(fabs(first-second)<pow(10,-9))                //if their absolute value's difference is lower than 10 to the power of -9, we will still assume that they're equal, because this is a really small difference
    {
        return true;
    }
    else return false;
}

bool IsMagicSquare(int N, double m[][SIZE])               //define the actual function, according to the task, that receives N and a two-dimensional array serving as a matrix, as parameters
{
    double sumMainDiagonal=0, sumSecondDiagonal=0;       //initialize two variables that will serve as sums of the main and the second diagonals respectively
    double arrSumRows[N], arrSumColumns[N];              //and initialize two single dimensional arrays that will contain the sums of each row and each column

    for(int i=0;i<N;i++)                                 //before using them, it's best to give starting values as zeros to all of the containers (because we will add other numbers to them)
    {
        arrSumRows[i]=0; arrSumColumns[i]=0;
    }

    for(int i=0;i<N;i++)                                 //use "i" as index for the rows and "j" as index for the columns
    {
        for(int j=0;j<N;j++)
        {
            arrSumRows[i] += m[i][j];                    //give every sums from every row to its respective array
            arrSumColumns[i] += m[j][i];                 //the same here, but with swapped indexes (because we first increase the row index and after that the column one)
        }
    }

    bool isMagical=true;                                 //create a bool variable that will receive value if the square is magical or not

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {   //if just the sum of one row is not the same as any other OR the sum of one column is different than that of any other
            if( AreEqual(arrSumRows[i],arrSumRows[j])==false || AreEqual(arrSumColumns[i],arrSumColumns[j])==false )
            {
                isMagical=false;           //we can say that the square cannot be magical, thus giving the bool variable "false" value
                break;                     //and end the iterations
            }
        }
    }

    if(not isMagical) return false;       //when the function reaches "return" it does not go any further
                                          //but if it hasn't reached "return", then this means that all sums of each row/column are the same
    for(int i=0;i<N;i++)
    {
        sumMainDiagonal += m[i][i];       //and now we must accumulate the values of all numbers that compose the main diagonal
    }

    for(int i=0, j=N-1; i<N; i++, j--)
    {
        sumSecondDiagonal += m[i][j];     //as well as the second diagonal...
    }
    //and check whether both diagonals' sums are equal to the sums of rows/columns
    if(arrSumRows[0]==arrSumColumns[0] && arrSumRows[0]==sumMainDiagonal && arrSumRows[0]==sumSecondDiagonal) return true;
    else return false;

}

int main()
{
    int N=0;
    cin>>N;                          //the used has to input the size (N) of the square matrix (NxN)

    if(N<=1 || N>=1000)              //if it doesn't belong to [1;1000], the program ends, printing "-1" (indicating illegal input value)
    {
        cout<<-1;
    }

 else                                //if the input N is according to the conditions then we go to the function itself
 {

    bool validInput=true;            //bool variable used to show if our input data (in the matrix itself) is wrong or not

    for(int i=0;i<N;i++)             //go through each row...
    {
        for(int j=0;j<N;j++)         //...and each column of the matrix
        {
            cin>>matrix[i][j];       //input its elements
            if(matrix[i][j]<0 || matrix[i][j]>100)    //and it just one element is input not withing the needed interval
            {
                validInput=false;                     //it's absolutely enough to terminate the checking...
            }
        }
    }

    if(not validInput) cout<<-1;                      //...by printing "-1" and not going further
  else                                                //but if not illegal values have been input then we use our function...
  {
    if(IsMagicSquare(N, matrix)) cout<<"true";        //...that prints whether the matrix is a magic square...
    else cout<<"false";                               //...or not
  }

 }

    return 0;
}
