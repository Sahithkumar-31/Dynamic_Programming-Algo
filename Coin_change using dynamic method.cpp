#include <iostream>
#include <climits>
using namespace std;
long long minn(long long coins[],long long value)
{
    long long table[value+1];
    table[0]=0;
    for(int i=1;i<=value;i++)
    {
        table[i]=INT_MAX;
    }
    
    for(int i=1;i<=value;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(coins[j]<=i)
            {
                int res1=table[i-coins[j]];
                if(res1!=INT_MAX && res1<table[i])
                table[i]=res1+1;
            }
        }
    }
    return table[value];
}
int main()
{
    long long n;
    cin>>n;
    long long coins[3]={1,3,4};
    
   std::cout << minn(coins,n) << std::endl; 
    

    return 0;
}
