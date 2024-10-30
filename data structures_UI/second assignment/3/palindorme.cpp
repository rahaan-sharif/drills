#include <iostream>
#include <string>
#include <climits>
using namespace std;

class linked_list
{
private:
          int value;
          int length;
          linked_list *next, *prev;

public:
          linked_list(int v)
          {
                    value = v;
                    length = -1;
                    next = NULL;
                    prev = NULL;
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
                              linked_list *tmp = start, *tmp1;
                              while (start->next != NULL)
                                        start = start->next;
                              tmp1 = start;
                              start->next = new linked_list(v);
                              start->next->prev = tmp1;
                              start = tmp;
                              start->length++;
                    }
          }

          void show(linked_list *start)
          {
                    linked_list *tmp = start;
                    while (start != NULL)
                    {
                              cout << start->value;
                              if (start->next != NULL)
                                        cout << " ";
                              start = start->next;
                    }
          }

          int get_length()
          {
                    return length;
          }

          int function(linked_list *start)
          {
                    linked_list *tmp2 = start, *end_tmp = start, *tb = start;
                    while (end_tmp->next != NULL)
                              end_tmp = end_tmp->next;
                    int counter = 0, out_pal=counter;

                    linked_list *tc = new linked_list(INT_MIN);

                    tc->next = NULL;
                    tc->prev = end_tmp;
                    end_tmp->next = tc;

                    for (tmp2, tc;; tc = tc->prev)
                    {
                              if(tmp2 == end_tmp)
                              {
                                        if(counter>out_pal)
                                                  out_pal=counter;
                                        counter=0;
                                        break;
                              }
                                        //return counter;
                              else if (tmp2 == tc)
                              {
                                        if (counter != 0)
                                        {
                                                  counter++;
                                                  if(counter>out_pal)
                                                            out_pal=counter;
                                                  counter=0;
                                                  tb=tb->next;
                                                  tmp2=tb;
                                                  tc=end_tmp;
                                                  continue;
                                        }
                                        //          return counter + 1;
                                        tb = tb->next;
                                        tmp2 = tb;
                                        tc = end_tmp->next;
                              }
                              else if (tmp2 == tc->prev)
                              {
                                        if (counter != 0 && tmp2->value == tc->value)
                                        {
                                                  counter+=2;
                                                  if(counter>out_pal)
                                                            out_pal=counter;
                                                  counter=0;
                                                  tb=tb->next;
                                                  tmp2=tb;
                                                  tc=end_tmp;
                                                  continue;
                                        }
                                                  //return counter + 2;
                                        tb = tb->next;
                                        tmp2 = tb;
                                        tc = end_tmp->next;
                                        counter = 0;
                              }

                              if (tmp2->value == tc->value)
                              {
                                        tmp2 = tmp2->next;
                                        counter += 2;
                              }
                              else if (tmp2->value != tc->value)
                              {
                                        tmp2 = tb;
                                        counter = 0;
                              }
                    }

                    return out_pal;
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
          string count;
          getline(cin, count);
          int number = 0;
          for (int i = 0; i < count.length(); i++)
                    number = number * 10 + count[i] - 48;

          linked_list **atl = new linked_list *[number];
          int *tedad = new int[number];

          for (int i = 0; i < number; i++)
                    atl[i] = NULL;

          string tmp;
          for (int i = 0; i < number; i++)
          {
                    getline(cin, tmp);
                    inserting(atl[i]);
                    tedad[i] = atl[i]->function(atl[i]);
          }

          for (int i = 0; i < number; i++)
                    cout << tedad[i];

          return 0;
}
