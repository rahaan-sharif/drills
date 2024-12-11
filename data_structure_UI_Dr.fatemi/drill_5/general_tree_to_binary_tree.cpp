#include <iostream>
using namespace std;

class gnode_values
{
public:
    int data;
    int children_number;
};

class general_tree
{
private:
    int data;
    int children_num;

public:
    general_tree **children;
    general_tree()
    {
    }
    general_tree(int data_in, int children_num_in)
    {
        data = data_in;
        children_num = children_num_in;
        children = new general_tree *[children_num];
    }
    void make_node(general_tree *&start, gnode_values gv)
    {
        start=new general_tree(gv.data, gv.children_number);
    }
    int get_data(general_tree* start)
    {
        return start->data;
    }
    int get_children_num(general_tree* start)
    {
        return start->children_num;
    }
};

class binary_tree
{
private:
    int data;
    binary_tree* left, *right;
public:
    binary_tree(int data_in)
    {
        data=data_in;
        left=NULL;
        right=NULL;
    }
    void make_bt(general_tree* start1, binary_tree*& start2)
    {
        if(start1==NULL)
            return;
        else if(start2==NULL)
        {
            start2=new binary_tree(start1->get_data(start1));
            start2->left=new binary_tree(start1->children[0]->get_data(start1->children[0]));
        }

        binary_tree* tmp_bt=start2->left;
        for(int i=1; i<start1->get_children_num(start1); i++)
        {
            if(start1->children[i]==NULL)
                break;
            cout<<"start1: "<<start1->children[i]->get_data(start1->children[i])<<endl;
            tmp_bt->right=new binary_tree(start1->children[i]->get_data(start1->children[i]));
            tmp_bt=tmp_bt->right;
        }
        tmp_bt=start2->left;
        int tmp_int=0;
        while(tmp_bt!=NULL)
        {
            tmp_bt->make_bt(start1->children[tmp_int++], tmp_bt);
            tmp_bt=tmp_bt->right;
        }

    }
    void inorder_show(binary_tree* start)
    {
        if(start==NULL)
            return;
        start->left->inorder_show(start->left);
        cout<<start->data<<" ";
        start->right->inorder_show(start->right);

    }
};

int main(void)
{
    general_tree *start1 = NULL;
    gnode_values ob;

    ob.children_number = 3;
    ob.data = 1;
    start1->make_node(start1, ob);

    ob.data=2;
    start1->children[0]->make_node(start1->children[0], ob);

    ob.data=3;
    start1->children[1]->make_node(start1->children[1], ob);

    ob.data=4;
    start1->children[2]->make_node(start1->children[2], ob);

    ob.data=5;
    start1->children[0]->children[0]->make_node(start1->children[0]->children[0], ob);

    ob.data=6;
    start1->children[0]->children[1]->make_node(start1->children[0]->children[1], ob);

    ob.data=7;
    start1->children[0]->children[2]->make_node(start1->children[0]->children[2], ob);

    ob.data=8;
    start1->children[1]->children[0]->make_node(start1->children[1]->children[0], ob);

    ob.data=9;
    start1->children[1]->children[1]->make_node(start1->children[1]->children[1], ob);

    ob.data=10;
    start1->children[1]->children[2]->make_node(start1->children[1]->children[2], ob);

    ob.data=11;
    start1->children[2]->children[0]->make_node(start1->children[2]->children[0], ob);

    ob.data=12;
    start1->children[2]->children[1]->make_node(start1->children[2]->children[1], ob);

    ob.data=13;
    start1->children[2]->children[2]->make_node(start1->children[2]->children[2], ob);


    binary_tree* start2=NULL;
    start2->make_bt(start1, start2);
    start2->inorder_show(start2);







    return 0;
}