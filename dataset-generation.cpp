#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
    int numberOfInput,lengthOfSlice,i,k=0,x=456783,n,f=1,c=0;
    ofstream fout;
    fout.open("output.txt");

    cout<<"Number of Input : ";
    cin>>numberOfInput;

    cout<<"length of Slice : ";
    cin>>lengthOfSlice;

    srand(time(0));
    for(i=1;i<=numberOfInput;i++)
    {
        if(k==0)
        {
            x = x + 5;
            n = x + (rand()%5);
            fout<<n<<" ";
            c = 1;
        }
        else
        {
            c++;
            if(f%4==2)
            {
                x = x - 5;
                n = x - (rand()%5);
            }

            else
            {
                if(c==1)
                {
                    x = x + 5;
                    n = x + (rand()%5);
                }
                else
                {
                    x = x - 5;
                    n = x - (rand()%5);
                }
            }

            fout<<n<<" ";
        }
        if(i%lengthOfSlice==0)
        {
            f++;
            if(f%4!=1)
                k = 1;
            else
                k = 0;
            c = 0;
        }
    }

    return 0;
}
