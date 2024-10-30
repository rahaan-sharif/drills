#include <iostream>
using namespace std;

class cll
{
private:
          int data;
          cll* next;
public:
          cll(int d)
          {
                    data=d;
                    next=NULL;
          }
          void make_list(cll*& start, int d)
          {
                    if(start==NULL)
                    {
                              start=new cll(d);
                              start->next=start;
                              return;
                    }
                    else
                    {
                              cll* tmp=start;
                              while(tmp->next!=start)
                                        tmp=tmp->next;
                              tmp->next=new cll(d);
                              tmp->next->next=start;
                              return;
                    }
          }
          void join(cll*& start1, cll*& start2)
          {
                    cll* tmp1=start1;
                    while(tmp1->next!=start1)
                              tmp1=tmp1->next;
                    
                    cll* tmp2=start2;
                    while(tmp2->next!=start2)
                              tmp2=tmp2->next;
                    
                    tmp1->next=start2;
                    tmp2->next=start1;
          }
          void show(cll* start)
          {
                    cll* tmp=start;
                    while(tmp->next!=start)
                    {
                              cout<<tmp->data<<", ";
                              tmp=tmp->next;
                    }
                    cout<<tmp->data<<endl;
                    return;
          }

};

int main(void)
{
          cll* start1=NULL, *start2=NULL;
          start1->make_list(start1, 1);
          start1->make_list(start1, 2);
          start1->make_list(start1, 3);
          start1->make_list(start1, 4);

          start2->make_list(start2, 11);
          start2->make_list(start2, 12);
          start2->make_list(start2, 13);
          start2->make_list(start2, 14);

          start1->join(start1, start2);

          cout<<"header is start1: ";
          start1->show(start1);
          cout<<"\nheader is start2: ";
          start2->show(start2);
          


          return 0;
}
