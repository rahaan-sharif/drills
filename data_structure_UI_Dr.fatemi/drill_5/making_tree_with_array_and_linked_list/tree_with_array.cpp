#include <iostream>
#include <math.h>
using namespace std;

class node
{
private:
    int value;
    int index;

public:
    node(){}
    node(int v, int i) : value(v), index(i)
    {}

    void add_node(node*& start, int v, int i)
    {
        start=new node(v, index);
    }
    void show(node* start)
    {
        cout<<start->value<<endl;
    }
};

class tree
{
private:
    node** array;
    int level_count;
    int total_count;
    int loc;
public:
    tree(int l)
    {
        loc=0;
        level_count=l;
        total_count=pow(2, level_count);
        array=new node*[total_count];
    }
    void make_node(int value)
    {
        array[++loc]=new node(value, loc);
    }
    void inorder_show(int index=1)
    {
        if(index >= total_count)
            return;
        inorder_show(index*2);
        array[index]->show(array[index]);
        inorder_show(index*2 + 1);
    }
};

int main(void)
{
    //4 is number of levels.
    tree ar_tr(4);
    for(int i=1; i<pow(2, 4); i++)
    {
        ar_tr.make_node(i);
    }
    ar_tr.inorder_show();

    return 0;
}