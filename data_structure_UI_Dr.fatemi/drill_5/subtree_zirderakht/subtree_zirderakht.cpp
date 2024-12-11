#include <iostream>
using namespace std;

void sort_arr(int *&arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (arr[i] < arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

class tree
{
private:
    int data;

public:
    tree *left, *right, *par;
    tree(tree *p, int d)
    {
        data = d;
        par = p;
        left = NULL;
        right = NULL;
    }
    void add_root(tree *&start, tree *p, int d)
    {
        start = new tree(p, d);
    }
    void inorder_show(tree *start)
    {
        if (start == NULL)
            return;
        start->left->inorder_show(start->left);
        cout << start->data << "  ";
        start->right->inorder_show(start->right);
    }
    static int is_subtree(tree *start1, tree *start2)
    {
        if (start1 == NULL || start2 == NULL)
            return 0;
        else if (start1->data == start2->data)
            return is_equal(start1, start2);
        else
        {
            int a = is_subtree(start1->left, start2);
            int b = is_subtree(start1->right, start2);
            return max(a, b);
        }
    }
    static int is_equal(tree *start1, tree *start2)
    {
        if (start1 == NULL && start2 == NULL)
            return 1;
        else if (start1 == NULL || start2 == NULL)
            return 0;

        if (start1->data != start2->data)
            return 0;
        else
        {
            int a = is_equal(start1->left, start2->left);
            int b = is_equal(start1->right, start2->right);
            return min(a, b);
        }
    }
    void make_tree_p_i(tree *&start, tree *&par,
                       int *preorder, int n_preorder,
                       int *inorder, int n_inorder)
    {
        if (n_preorder == 0 && n_inorder == 0)
        {
            start = NULL;
            return;
        }
        int root_location_in = 0;
        for (int i = 0; i < n_inorder; i++)
        {
            if (preorder[0] == inorder[i])
            {
                int *tmp_arr_in = new int[i];
                int *tmp_arr_pre = new int[i];
                for (int j = 0; j < i; j++)
                {
                    tmp_arr_in[j] = inorder[j];
                    tmp_arr_pre[j] = preorder[j + 1];
                }
                sort_arr(tmp_arr_in, i);
                sort_arr(tmp_arr_pre, i);

                int flag = 0;
                for (int j = 0; j < i; j++)
                {
                    if (tmp_arr_in[j] != tmp_arr_pre[j])
                    {
                        flag = 1;
                        continue;
                    }
                }
                if (flag)
                    continue;
                root_location_in = i;
                break;
            }
        }

        start->add_root(start, par, preorder[0]);

        int left_preorder_length = root_location_in;
        int right_preorder_length = n_preorder - root_location_in - 1;
        int left_inorder_length = root_location_in;
        int right_inorder_length = n_inorder - root_location_in - 1;

        // left leave:
        make_tree_p_i(start->left, start,
                      preorder + 1, left_preorder_length,
                      inorder, left_inorder_length);
        // right leave:
        make_tree_p_i(start->right, start,
                      preorder + root_location_in + 1, right_preorder_length,
                      inorder + root_location_in + 1, right_inorder_length);
    }
};

int main(void)
{
    tree *start1 = NULL, *start2 = NULL, *null=NULL;

    cout << "start1\n";
    int counter = 0;
    cout << "enter counter: ";
    cin >> counter;
    int *preorder = new int[counter];
    int *inorder = new int[counter];

    cout << "enter preorder traversal:\n";
    for (int i = 0; i < counter; i++)
        cin >> preorder[i];
    cout << "\nenter inorder traversal: \n";
    for (int i = 0; i < counter; i++)
        cin >> inorder[i];

    
    start1->make_tree_p_i(start1, null, preorder, counter, inorder, counter);
    start1->inorder_show(start1);
    cout<<endl<<endl;

    null=NULL;
    cout << "start2\n";
    counter = 0;
    cout << "enter counter: ";
    cin >> counter;
    delete []preorder;
    delete []inorder;
    preorder = new int[counter];
    inorder = new int[counter];

    cout << "enter preorder traversal:\n";
    for (int i = 0; i < counter; i++)
        cin >> preorder[i];
    cout << "\nenter inorder traversal: \n";
    for (int i = 0; i < counter; i++)
        cin >> inorder[i];

    
    start1->make_tree_p_i(start2, null, preorder, counter, inorder, counter);
    start1->inorder_show(start2);
    cout<<endl<<endl;


    cout << "is start2 a subtree of start1:  ";
    if (tree::is_subtree(start1, start2))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}