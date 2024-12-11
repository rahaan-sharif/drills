#include <iostream>
#include <limits.h>
#include <math.h>
using namespace std;

class tree
{
private:
    int data;
    int manitoring;
    int married = 0;
    tree *parent, *right, *left;

public:
    tree(int dd)
    {
        data = dd;
        parent = NULL;
        right = NULL;
        left = NULL;
        manitoring = 0;
        married = 0;
    }
    void make_node(tree *&start, int *&ent_arr, int limit, int if_first = 0)
    {
        static int location = 0;
        if (if_first)
        {
            location = 0;
        }
        if (location > limit || start->data==-1)
            return;
        if (start->married == 1)
        {
            if (start->right->data != -1 && start->left->data != -1)
            {
                start->left->make_node(start->left, ent_arr, limit);
                start->right->make_node(start->right, ent_arr, limit);
            }
            else if (start->left->data == -1)
                start->right->make_node(start->right, ent_arr, limit);
            else if (start->right->data == -1)
                start->left->make_node(start->left, ent_arr, limit);
            else
                return;
        }
        else if (start->married == 0)
        {
            start->left = new tree(ent_arr[location++]);
            start->left->parent = start;
            start->right = new tree(ent_arr[location++]);
            start->right->parent = start;
            start->married = 1;
        }
    }
    void make_tree(tree *&start, int *&ent_arr, int length_ent)
    {

        int *a = NULL, *b = NULL, *c = NULL;
        a = new int(length_ent + 1);
        b = new int(length_ent + 1);
        c = new int(length_ent + 1);
        a[0] = b[0] = c[0] = b[1]=0;
        a[1]=c[1]=1;
        int location = 1;
        int check_arr_length=0;

        for (int i = 2; location < length_ent; i++)
        {
            check_arr_length=i;
            c[i ] = 2*a[i-1];
            int tmp_int = 0;
            for (int j = location; j < location + c[i]; j++)
            {
                if (ent_arr[j] == -1)
                    tmp_int += 1;
            }
            location += c[i];
            b[i ] = tmp_int;
            a[i ] = c[i ] - b[i];
        }

        start = new tree(ent_arr[0]);
        int limit = c[1];
        ent_arr++;
        for (int i = 2; i <= check_arr_length; i++)
        {

            limit = c[i];
            start->make_node(start, ent_arr, limit, 1);
            ent_arr += c[i];
        }
    }
    void inorder_show(tree *start)
    {
        if (start == NULL)
            return;
        start->left->inorder_show(start->left);
        cout << start->data << "   ";
        start->right->inorder_show(start->right);
    }
    void manitor_set(tree*& start, int if_begin=0, int start_manitoring=-1)
    {
        if(if_begin)
        {

            start->manitoring=start_manitoring;

            start->left->manitor_set(start->left);
            start->right->manitor_set(start->right);
        }
        else
        {

            if(start->parent->manitoring==0)
                start->manitoring=1;
            else 
                start->manitoring=0;


            if(start->left!=NULL)
                start->left->manitor_set(start->left);


            if(start->right!=NULL)
                start->right->manitor_set(start->right);
        }

    }
    int manitor_count(tree*& start, int is_begin=0)
    {
        static int counter=0;
        if(is_begin)
            counter=0;
        if(start==NULL)
            return INT_MIN;
        start->left->manitor_count(start->left);
        if(start->manitoring==1 && start->data!=-1)
            counter++;
        start->right->manitor_count(start->right);
        return counter;
        
    }
    int min_manitoring(tree*& start)
    {
        start->manitor_set(start, 1, 0);
        int a=start->manitor_count(start, 1);

        start->reset_manitoring(start);

        start->manitor_set(start, 1, 1);
        int b=start->manitor_count(start, 1);
        

        if(a<b)
            return a;
        else 
            return b;
    }
    void reset_manitoring(tree*& start)
    {
        if(start==NULL)
            return;
        start->left->reset_manitoring(start->left);
        start->manitoring=0;
        start->right->reset_manitoring(start->right);
    }
};

int main(void)
{
    tree *start_tree = NULL;
    int counter_zero=0, counter_all=0;
    cin>>counter_zero;
    int *ent_arr=new int[(counter_zero*2)];
    for(int i=0; i<counter_zero; i++)
        {cin>>ent_arr[i];
         if(ent_arr[i]!=0)
            counter_zero++;
         counter_all++;
         
        }
    start_tree->make_tree(start_tree, ent_arr, counter_all);

    cout<<start_tree->min_manitoring(start_tree);

    return 0;
}