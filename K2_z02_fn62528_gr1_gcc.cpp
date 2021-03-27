// Radoslav Velkov 62528


#include <iostream>
using namespace std;

void InputArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}

int AverageOfTwoNumbers(int i, int j)
{
    return (i+j)/2;
}

int main()
{
    int N=0;
    cin>>N;

    while(N<0 || N>20)
    {
        cin>>N;
    }

    int arr[N];

    InputArray(arr,N);

    int idx=0;

    for(int i=N-2; i>0; i--)
    {
        if( arr[i] > AverageOfTwoNumbers(arr[i-1],arr[i+1]) )
        {
            idx=i;
            break;
        }
    }

    if(idx==0 || idx==N-1)
        cout<<-1;
    else cout<<idx;

    //did not have enough time to figure out where to use recursion...

    return 0;
}
