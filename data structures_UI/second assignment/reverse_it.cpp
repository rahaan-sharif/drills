#include <iostream>
#include <string>
#include <climits>
using namespace std;

class linked_list
{
private:
          int value;
          int id;
          int length;
          linked_list *next, *prev;

public:
          linked_list(int v, int i)
          {
                    value = v;
                    id = i;
                    length = -1;
                    next = NULL;
                    prev = NULL;
          }

          void make_node(linked_list *&start, int v)
          {
                    if (start == NULL)
                    {
                              start = new linked_list(v, 1);
                              start->length = 1;
                              return;
                    }
                    else
                    {
                              linked_list *tmp = start, *tmp1;
                              while (start->next != NULL)
                                        start = start->next;
                              tmp1 = start;
                              tmp->length += 1;
                              start->next = new linked_list(v, tmp->length);
                              start->next->prev = start;
                              start = tmp;
                    }
          }

          void show(linked_list *start)
          {
                    while (start != NULL)
                    {
                              cout << start->value <<" ";
                              start=start->next;
                    }
          }

          int get_length()
          {
                    return length;
          }

          void reverse(linked_list*& start, int id_l, int id_h)
          {
                    linked_list* tmp=start, *tmp_end=NULL, *tmp_start=NULL;
                    while(tmp->id!=id_h)
                              tmp=tmp->next;
                    tmp_end=tmp->next;

                    linked_list* r_l=NULL;
                    linked_list* tmp1=tmp;
                    while(tmp1->id!=id_l)
                    {
                              r_l->make_node(r_l, tmp1->value);
                              tmp1=tmp1->prev;
                    }
                    r_l->make_node(r_l,tmp1->value);
                    tmp_start=tmp1->prev;

                    tmp_start->next=r_l;
                    while(r_l->next!=NULL)
                              r_l=r_l->next;
                    r_l->next=tmp_end;


                    
                    
          }
};

void inserting(linked_list *&start)
{
          string l;
          getline(cin, l);
          int value = 0;
          for (int i = 0; i < l.length(); i++)
          {
                    if (l[0] == '\n')
                              break;
                    if (l[i] != ' ' && i != l.length() - 1)
                              value = value * 10 + l[i] - 48;

                    else if (i == l.length() - 1)
                    {
                              value = value * 10 + l[i] - 48;
                              start->make_node(start, value);
                              value = 0;
                    }
                    else if (l[i] == ' ')
                    {
                              start->make_node(start, value);
                              value = 0;
                    }
          }
}

int main(void)
{
          linked_list *atl = NULL;
          inserting(atl);
          cout<<"****"<<endl;
          int l=0, h=0;
          cout<<"l: ";
          cin>>l;
          cout<<"h: ";
          cin>>h;
          atl->reverse(atl, l, h);


          atl->show(atl);
          cout << endl;

          return 0;
}
