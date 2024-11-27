#include <iostream>
#include <string.h>
using namespace std;

class linked_list
{
private:
    int data;
    linked_list* next, *prev;
public:
    linked_list(int value)
    {   
        data=value;
        next=NULL;
        prev=NULL;
    }
    void create_node(linked_list*& start, int value)
    {
        if(start==NULL)
        {   
            start=new linked_list(value);
            return;
        }
        else
        {
            linked_list* tmp=start;
            while(tmp->next!=NULL)
                tmp=tmp->next;
            tmp->next=new linked_list(value);
            tmp->next->prev=tmp;
            return;
        }
    }
    linked_list* rec_rev(linked_list*& start)
    {
        if(start!=NULL && start->next!=NULL)
        {
            linked_list* rtmp=rec_rev(start->next);
            linked_list* tmp=start->next;
            start->next=start->prev;
            start->prev=tmp;
            return rtmp;
        }
        else
        {
            linked_list* tmp=start->next;
            start->next=start->prev;
            start->prev=tmp;
            return start;
        }
    }
    void show(linked_list* start)
    {   
        while(start->next!=NULL)
        {
            cout<<start->data<<" ";
            start=start->next;
        }
        cout<<start->data<<"\n\n";
    }
};

int main(void)
{
    linked_list* start=NULL;
    string ent;
    getline(cin, ent);
    int value=0;
    for(int i=0; i<ent.length(); i++)
    {
        if(ent[i]!=' ' && i!=ent.length()-1)
        {
            value=10*value   +   ent[i]-48;
        }
        else if(ent[i]==' ')
        {
            start->create_node(start, value);
            value= 0;
        }
        else if(i==ent.length()-1)
        {
            value=10*value   +   ent[i]-48;
            start->create_node(start, value);
            break;
        }
    }
    start=start->rec_rev(start);
    start->show(start);

    return 0;
}


/*
مرتبه اجرایی این برنامه
n 
است. چون بکرار ها به ازای یک تا تعداد اعضای 
آرایه انجام می شود.
*/