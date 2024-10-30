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
          void breaking(cll*& start1, cll*& start2)
          {
                    cll* tmp1=start1;
                    int length=1;
                    while(tmp1->next!=start1)
                    {
                              length++;
                              tmp1=tmp1->next;
                    }

                    cll* tmp2=start1;
                    int i=1;
                    while(i<length/2)
                    {
                              tmp2=tmp2->next;
                              i++;
                    }

                    start2=tmp2->next;
                    tmp2->next=start1;

                    cll* tmp3=start2;
                    while(tmp3->next!=start1)
                    {
                              tmp3=tmp3->next;
                    }
                    tmp3->next=start2;

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
          start1->make_list(start1, 5);
          start1->make_list(start1, 6);
          
          start1->breaking(start1, start2);

          start1->show(start1);
          start2->show(start2);

          return 0;
}
