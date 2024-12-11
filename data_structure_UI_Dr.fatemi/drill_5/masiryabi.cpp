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

class stack
{
private:
    int data;
    stack *prev;

public:
    stack(int dd)
    {
        data = dd;
        prev = NULL;
    }
    void make_nod(stack *&start, int dd)
    {
        if (start == NULL)
        {
            start = new stack(dd);
            return;
        }
        else
        {
            stack *tmp = NULL;
            tmp = new stack(dd);
            tmp->prev = start;
            start = tmp;
        }
    }
    void show(stack *start)
    {
        while (start != NULL)
        {
            cout << start->data << " ";
            start = start->prev;
        }
        cout << endl;
    }
};

class tree
{
private:
    int data;

public:
    tree *left, *right, *parent;
    tree(int d, tree *p)
    {
        data = d;
        parent = p;
        left = NULL;
        right = NULL;
    }
    void add_root(tree *&start, tree *p, int d)
    {
        start = new tree(d, p);
    }
    void add_right(tree *&start, tree *p, int d)
    {
        start->right->add_root(start->right, p, d);
    }
    void add_left(tree *&start, tree *p, int d)
    {
        start->left->add_root(start->left, p, d);
    }
    void show(tree *&start)
    {
        if (start == NULL)
            return;
        start->left->show(start->left);
        cout << start->data << ", ";
        start->right->show(start->right);
    }
    int heighth(tree *start)
    {
        if (start == NULL)
            return -1;
        else
        {
            int a = start->left->heighth(start->left);
            int b = start->right->heighth(start->right);
            if (a >= b)
                return a + 1;
            else
                return b + 1;
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
    void chosen_route(tree *start, int sum)
    {
        sum=sum-start->data;
        if (sum < 0)
            return;
        else if (sum == 0)
        {
            if (start->right == NULL && start->left == NULL)
            {
                tree *tmp_tree = start;
                stack *tmp_stack = NULL;
                while (tmp_tree != NULL)
                {
                    tmp_stack->make_nod(tmp_stack, tmp_tree->data);
                    tmp_tree = tmp_tree->parent;
                }
                tmp_stack->show(tmp_stack);
                return;
            }
        }
        else
        {
            if (start->left != NULL)
                start->left->chosen_route(start->left, sum);
            if (start->right != NULL)
                start->right->chosen_route(start->right, sum);
        }
    }
};

int main(void)
{
    int counter = 0;
    cin >> counter;
    int *preorder = new int[counter];
    int *inorder = new int[counter];

    for (int i = 0; i < counter; i++)
        cin >> preorder[i];
    for (int i = 0; i < counter; i++)
        cin >> inorder[i];

    int length = 0;
    cin >> length;

    tree *start = NULL, *null = NULL;
    start->make_tree_p_i(start, null, preorder, counter, inorder, counter);
    start->chosen_route(start, length);

    return 0;
}