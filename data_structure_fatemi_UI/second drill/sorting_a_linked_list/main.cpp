//in this program, we get some digits,
//then print them serted in output.

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
                              cout << start->value << " ";
                              start = start->next;
                    }
          }
          void sort(linked_list *&start)
          {
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
          int get_length()
          {
                    return length;
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

          linked_list *tmp = start;
          start->sort(start);

          start->show(start);

          return 0;
}
