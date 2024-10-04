#include <iostream>
#include <fstream>
#define length 18
using namespace std;

class data_class
{
private:
          int faravani;
          double faravani_nesbi;
          double faravani_tajamoi, faravani_tajamoi_nesbi;
          static int counter;
          static int day;
public:
          data_class(){}
          data_class(int a): faravani(a) {counter+=a;}
          void show()
          {
                    cout<<day++<<"\t"<<faravani<<"\t\t"<<faravani_nesbi;
                    cout<<"\t"<<faravani_tajamoi<<"\t\t\t";
                    cout<<faravani_tajamoi_nesbi<<endl;
          }
          void calculate_faravani_nesbi()
          {
                    faravani_nesbi=double(faravani)/double(counter);
          }
          void calculate(data_class *ptc)
          {
                    ptc->faravani_tajamoi=ptc->faravani;
                    ptc->faravani_tajamoi_nesbi=ptc->faravani_nesbi;
                    for(ptc; ptc!=this; ptc++)
                    {
                              (ptc+1)->faravani_tajamoi=(ptc+1)->faravani + ptc->faravani_tajamoi;
                              (ptc+1)->faravani_tajamoi_nesbi=(ptc+1)->faravani_nesbi + ptc->faravani_tajamoi_nesbi;
                    }
          }

};
int data_class::counter=0;
int data_class::day=1;

int main(void)
{
          ifstream file("data.txt");
          data_class ptd[length];
          int s=0;
          for(int i=0; i<length; i++)
          {
                    file>>s;
                    ptd[i]=data_class(s);
          }
         

          for(int i=0; i<length; i++)
                    ptd[i].calculate_faravani_nesbi();
          ptd[17].calculate(ptd);

          cout<<"data\tfaravani\tfaravani_nesbi\t";
          cout<<"faravani_tajamoi\t";
          cout<<"faravani_tajamoi_nesbi"<<endl;

          for(int i=0; i<length; i++)
                    ptd[i].show();


          file.close();


          return 0;
}
