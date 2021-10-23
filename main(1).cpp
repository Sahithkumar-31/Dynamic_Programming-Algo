#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
int comp(int a, int b)
{
    return (a<b);
}
int op(string s1, string s2, int m, int n)
{
    int arr[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i == 0)
            {
                arr[i][j] = j;
                //cout<<arr[i][j]<<" 1 "<<endl;
            }
            
            else if(j == 0)
            {
                arr[i][j] = i;
            }
            else if(s1[i-1] == s2[j-1])
            {
                arr[i][j] = arr[i-1][j-1];
            }
            else
            {
                arr[i][j] = 1+ min({arr[i][j-1],arr[i-1][j],arr[i-1][j-1]},comp);
                //cout<<arr[i][j]<<" 2 "<<endl;
            }
        }
    }
    
    return arr[m][n];
}

    
    
int main(){
    string s1 ;
    cin>>s1;
    string s2;
    cin>>s2;
    
    int m = s1.length();
    int n = s2.length();
 //   cout<<"length of m and n "<<m<<" "<<n<<endl;
    
    cout<<(op(s1,s2,m,n));
    
    }
