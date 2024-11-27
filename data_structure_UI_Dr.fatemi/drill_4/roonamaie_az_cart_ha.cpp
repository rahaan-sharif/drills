#include <iostream>
//#include <algorithm>
//#include <vector>
using namespace std;

class queue
{
private:
    int data;
    queue* next;
public:
    queue(int d)
    {
        data=d;
        next=NULL;
    }
    void add_node_f(queue*& start, int item)
    {
        queue* t_start=new queue(item);
        t_start->next=start;
        start=t_start;
        return; 
    }
    void make_node(queue*& start, int data)
    {
        if(start==NULL)
        {
            start=new queue(data);
            return;
        }
        else
        {
            queue* tmp=start;
            while (tmp->next!=NULL)
                tmp=tmp->next;
            tmp->next=new queue(data);
            return;
        }
    }
    void show(queue* start)
    {
        
        while(start!=NULL)
        {
            cout<<start->data<<" ";
            start=start->next;
        }
        cout<<endl;
        return;
    }
    int get_node(queue*& start)
    {
        if(start->next==NULL)
        {
            int tmp_i=start->data;
            delete start;
            start=NULL;
            return tmp_i;
        }
        queue* tmp=start;
        while(tmp->next->next!=NULL)
            tmp=tmp->next;
        int tmp_i=tmp->next->data;
        delete tmp->next;
        tmp->next=NULL;
        return tmp_i;
    }

    void req_alg(queue*& start, int item)
    {
        if(start==NULL)
        {
            start->make_node(start, item);
            return;
        }
        else
        {
            int tmp=start->get_node(start);
            start->add_node_f(start, tmp);
            start->add_node_f(start, item);
            return;
        }



    }

};

int factoriel(int n)
{
    if(n==0)
    {
        return 1;
    }
    else if(n==1)
    {
        return 1;
    }
    else
    {
        return n*factoriel(n-1);
    }
}

int main(void)
{
    queue* start1=NULL;
    int counter=0;
    cin>>counter;
    int* arr1=new int[counter];
    for(int i=0; i<counter; i++)
        cin>>arr1[i];
    for(int i=0; i<counter; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr1[i]<arr1[j])
            {
                int tmp=arr1[i];
                arr1[i]=arr1[j];
                arr1[j]=tmp;
            }
        }
    }

    for(int i=counter-1; i>=0; i--)
    {
        start1->req_alg(start1, arr1[i]);
    }
    start1->show(start1);



    return 0;
}