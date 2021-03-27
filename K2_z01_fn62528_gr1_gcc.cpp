// Radoslav Velkov 62528


#include <iostream>
using namespace std;

int main()
{
    int N=0, M=0;
    bool userInput=true;
    cin>>N>>M;

    int cnt=0;

    while(N<=0 || M<=0)
    {
        cin>>N>>M;
    }

    int secN=N;

    int first=0;
    first=N%10;

    int digits=0;
    int l=0;
    while(secN>0)
    {
        secN /= 10;
        digits++;
    }
    if(M>digits)
        {
            cout<<-10;
            userInput=false;
        }

    if(userInput)
    {

    int n=0;

    while(cnt!=M)
    {
        n = N%10;
        cnt++;
        N /= 10;
    }

    cout<<first-n;

    }


    return 0;
}
