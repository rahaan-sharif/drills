#include <iostream>
#include <string>
using namespace std;

class numbers
{
private:
          int length;
          int* arr;
public:
         numbers(int* a, int l)
          {
                    length=l;
                    arr=new int[l];
                    for(int i=0; i<l; i++)
                              arr[i]=a[i];
          }
          numbers()
          {
                    string ent_str;
                    cin>>ent_str;
                    int counter=0;
                    for(int i=0; ent_str[i]!=0; i++, counter++);
                    length=counter;
                    arr=new int[length];
                    for(int i=0; i<length; i++)
                              arr[i]=ent_str[i]-48;
          }
          ~numbers()
          {
                    delete []arr;
          }
          numbers operator*(numbers& ob)
          {
                    int* tmp_arr=new int[(length+ob.length)*ob.length];
	          for (int i=0; i<((length+ob.length)*ob.length); i++)
		          tmp_arr[i]=0;


                    int counter=0;
	          for(int j=ob.length-1; j>-1; j--)         
	          {
		          for(int i=length-1; i>-1; i--)               
			          tmp_arr[(j*(length+ob.length))+(i+ob.length)-counter]+=arr[i]*ob.arr[j];

	                    counter++;
	          }
	          int* resault=new int[length+ob.length];
          	for(int i=0; i<length+ob.length; i++)
	                    resault[i]=0;
	    
	    
	          for(int i=length+ob.length-1; i>-1; i--)
	                    for(int j=0; j<ob.length; j++)
	                    {
                                        resault[i]+=tmp_arr[(j*(length+ob.length))+i];
                                        if(resault[i]>9)
                                        {
                                                  resault[i-1]+=resault[i]/10;
                                                  resault[i]%=10;
                                        }
	                    }
                    return numbers(resault, length+ob.length);
                    
	  
          }
          void show()
          {
                    int i=0;
                    while(1)
                    {
                              if(arr[i]==0)
                                        i++;
                              else
                                        break;
                    }
                    for(i; i<length; i++)
                              cout<<arr[i];
          }

};

int main(void)
{
          numbers ob1,ob2;
          numbers ob3=ob1*ob2;
          ob3.show();

          return 0;
}
