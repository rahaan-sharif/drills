#include <iostream>
using namespace std;

class TREE
{
private:
    int data;
    int left_childs, right_childs;
    TREE* left, *right;
public:
    TREE(int data_in)
    {
        data=data_in;
        left_childs=0;
        right_childs=0;
        left=NULL;
        right=NULL;
    }

    //This algorithm tries to make level order compliting of the tree
    //but not exactly what we learned in DAta Structures;
    //It tries to make balance between left and right leaves of the root
    //and each node. Every node can have just one more node in left leaves than right one.
    int make_tree(TREE*& start, int data_in)
    {
        if(start==NULL)
        {
            cout<<"data_in: "<<data_in<<endl;
            start=new TREE(data_in);
            return 1;
        }
        else
        {
            if(start->left_childs==0)
            {
                int tmp_int= start->left->make_tree(start->left, data_in);
                start->left_childs +=tmp_int;
                return tmp_int;
            }
            else if(start->right_childs==0)
            {
                int tmp_int=start->right->make_tree(start->right, data_in);
                start->right_childs += tmp_int;
                return tmp_int;
            }

            else
            {
                if(start->left_childs==start->right_childs)
                {
                    int tmp_int=start->left->make_tree(start->left, data_in);
                    start->left_childs+=tmp_int;
                    return tmp_int;
                }
                else
                {
                    int tmp_int=start->right->make_tree(start->right, data_in);
                    start->right_childs+=tmp_int;
                }
            }
        }
    }

    void show_tree(TREE* start)
    {
        if(start==NULL)
        {
            return;
        }
        else
        {
            start->left->show_tree(start->left);
            cout<<start->data<<", ";
            start->right->show_tree(start->right);
        }
    }
};

int main(void)
{
    int arr[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    TREE* start=NULL;
    for(int i=0; i<10; i++)
    {
        start->make_tree(start, arr[i]);
    }

    start->show_tree(start);




    return 0;
}
