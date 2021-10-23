#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(int a,int b)
{
    return (a<b);
}

int get(vector<int> &a,vector<int> &b,vector<int> &d,int m,int n,int o)
{
    int c[m+1][n+1][o+1];

    
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            {
                for(int l=0;l<=o;l++)
                {
                     if(i==0||j==0||l==0)
                     {
                        c[i][j][l]=0;
                     }
                      else if(a[i-1]==b[j-1]&&b[j-1]==d[l-1])
                     {
                        c[i][j][l]=c[i-1][j-1][l-1]+1;
                      
                     }
                     else
                     {
                        int k=c[i][j-1][l];
                        int p=c[i-1][j][l];
                        int q=c[i][j][l-1];
                        c[i][j][l] = max({k,p,q},comp);
                     }
                }
                
            }
        }
    }
    return c[m][n][o];
    
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

  size_t o;
  std::cin >> o;
  vector<int> d(o);
  for (size_t i = 0; i < o; i++) {
    std::cin >> d[i];
  }

  std::cout << get(a, b,d,n,m,o) << std::endl;
}