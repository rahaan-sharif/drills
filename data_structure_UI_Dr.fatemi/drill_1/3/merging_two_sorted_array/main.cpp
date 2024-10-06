#include <iostream>
using namespace std;
int main(void)
{
          int a[4]={1,3,5,35};
          int b[5]={2,4,6,10,70};
          int c[9]={0};

          int i=0, j=0, k=0;
          while(i<9)
          {
                    if((a[j]<=b[k] && j<4 && k<5) || (k>=5 && j<4))
                              {
                                        c[i]=a[j];
                                        i++;
                                        j++;
                              }
                    else if((b[k]<a[j] && k<4 && j<4) || (j>=4 && k<5))
                              {
                                        c[i]=b[k];
                                        i++;
                                        k++;
                              }
          }         
          for(int i=0; i<9; i++)
                    cout<<c[i]<<", ";


          return 0;
}
