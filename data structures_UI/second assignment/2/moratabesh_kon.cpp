#include <iostream>
#include <string>
using namespace std;

class linked_list
{
private:
          int value;
          int length;
          linked_list *next;

public:
          linked_list(int v)
          {
                    value = v;
                    length = -1;
                    next = NULL;
          }
          void make_node(linked_list *&start, int v)
          {
                    if (start == NULL)
                    {
                              start = new linked_list(v);
                              start->length = 1;
                              return;
                    }
                    else
                    {
                              linked_list *tmp = start;
                              while (start->next != NULL)
                                        start = start->next;
                              start->next = new linked_list(v);
                              start = tmp;
                              start->length++;
                    }
          }
          void show(linked_list *start)
          {
                    while (start != NULL)
                    {
                              cout << start->value;
                              if(start->next!=NULL)
                                        cout<<" ";
                              start = start->next;
                    }
          }
          int get_length()
          {
                    return length;
          }
          void sort(linked_list *&start)
          {
                    if(start==NULL || start->length==1)
                              return;
                    int slength = start->length;
                    for (int k = 0; k < slength; k++)
                    {
                              if (start->value > start->next->value)
                              {
                                        linked_list *tmp = start;
                                        start = start->next;
                                        tmp->next = start->next;
                                        start->next = tmp;
                              }

                              linked_list *store_place = start;
                              while (start->next->next != NULL)
                              {
                                        if (start->next->value > start->next->next->value)
                                        {
                                                  linked_list *tmp = start->next;
                                                  linked_list *tmp2 = start->next->next;
                                                  tmp->next = tmp2->next;
                                                  tmp2->next = tmp;
                                                  start->next = tmp2;
                                        }
                                        start = start->next;
                              }
                              start = store_place;
                    }
          }  
          void insert_sort(linked_list*& start1, linked_list*& start2)
          {
                    if(start2==NULL)
                              return;
                    if(start1==NULL)
                    {
                              start1=start2;
                              return;
                    }
                    int check=1;
                    while(check==1)
                    {
                              if(start2!=NULL && start2->value <= start1->value)
                              {
                                        linked_list* tmp=start2;
                                        start2=start2->next;
                                        tmp->next=start1;
                                        start1=tmp;
                              }
                              else
                                        check=0;
                    }
                    linked_list* tmp1=start1;
                    while(tmp1->next!=NULL && start2!=NULL)
                    {
                              if(start2->value <= tmp1->next->value)
                              {
                                        linked_list* tmp=start2;
                                        start2=start2->next;
                                        tmp->next=tmp1->next;
                                        tmp1->next=tmp;
                              }
                              tmp1=tmp1->next;
                    }
                    if(start2!=NULL)
                              tmp1->next=start2;
          }
};

int main(void)
{
          linked_list *start = NULL;

          string l;
          getline(cin, l);
          int value=0;
          for (int i = 0; i < l.length(); i++)
          {
                    if(l[0]=='\n')
                              break;
                    if (l[i]!=' ' && i!=l.length()-1)
                              value=value*10+l[i]-48;

                    else if(i==l.length()-1)
                    {
                              value=value*10 + l[i]-48;
                              start->make_node(start, value);
                              value=0;
                    }
                    else if(l[i]==' ')
                    {
                              start->make_node(start, value);
                              value=0;
                    }
          }

          linked_list *start2=NULL;
          getline(cin, l);
          for (int i = 0; i < l.length(); i++)
          {
                    if(l[0]=='\n')
                              break;
                    if (l[i]!=' ' && i!=l.length()-1)
                              value=value*10+l[i]-48;

                    else if(i==l.length()-1)
                    {
                              value=value*10 + l[i]-48;
                              start->make_node(start2, value);
                              value=0;
                    }
                    else if(l[i]==' ')
                    {
                              start->make_node(start2, value);
                              value=0;
                    }
          }
          //start->sort(start);
          start2->sort(start2);
          start->insert_sort(start, start2);
          start->show(start);
          cout<<" ";

          




          return 0;
}
