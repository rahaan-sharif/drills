#include <iostream>
using namespace std;

class tree
{
private:
    int data;
public:
    tree* left, *right;
    tree(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
    void add_root(tree*& start, int d)
    {
        start=new tree(d);
    }
    void add_right(tree*& start, int d)
    {   
        start->right->add_root(start->right, d);
    }
    void add_left(tree*& start, int d)
    { 
        start->left->add_root(start->left, d);
    }
    void show(tree*& start)
    {
        if(start==NULL)
            return;
        start->left->show(start->left);
        cout<<start->data<<", ";
        start->right->show(start->right);
    }
    int heighth(tree* start)
    {
        if(start==NULL)
            return -1;
        else
        {
            int a=start->left->heighth(start->left);
            int b=start->right->heighth(start->right);
            if(a>=b)
                return a+1;
            else
                return b+1;
        }
    }

};

int main(void)
{
    tree* start=NULL;
    start->add_root(start, 0);
    start->add_left(start, 1);
    start->add_right(start, 2);
    start->right->add_right(start->right, 3);
    start->show(start);
    cout<<endl;
    cout<<start->heighth(start);





    return 0;

}