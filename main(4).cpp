#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int get(vector<int> &a,vector<int> &b,int m,int n)
{
    int c[m+1][n+1];

    
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
            {
                c[i][j]=0;
            }
            else if(a[i-1]==b[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
               
            }
            else
            {
                int k=c[i][j-1];
                int p=c[i-1][j];
               
                c[i][j] = max(k,p);
                
            }
        }
    }
    return c[m][n];
    
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << get(a, b,n,m) << std::endl;
}