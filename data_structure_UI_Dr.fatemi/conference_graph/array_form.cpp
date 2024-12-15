#include <iostream>
using namespace std;

class ll_adt
{
private:
    int x, y;

public:
    ll_adt *next, *prev;
    ll_adt(int x_in, int y_in)
    {
        x = x_in;
        y = y_in;
        next = NULL;
        prev = NULL;
    }
    void add_node(ll_adt *&start, int x_in, int y_in)
    {
        if (start == NULL)
        {
            start = new ll_adt(x_in, y_in);
            return;
        }
        else
        {
            ll_adt *tmp_node = start;
            while (tmp_node->next != NULL)
            {
                tmp_node = tmp_node->next;
            }
            tmp_node->next = new ll_adt(x_in, y_in);
            tmp_node->next->prev = tmp_node;
            return;
        }
    }
    int search(ll_adt *start, int x_in, int y_in)
    {

        if (start->x == x_in && start->y == y_in)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void show(ll_adt *start)
    {
        while (start != NULL)
        {
            cout << start->x << "  " << start->y << endl;
            start = start->next;
        }
    }
};

class hash_table
{
private:
    ll_adt **hash_array;
    int array_size;

public:
    hash_table(int size_in)
    {
        array_size = size_in;
        hash_array = new ll_adt *[size_in];
        for(int i=0; i<size_in; i++)
            hash_array[i]=NULL;
    }
    void set_edge(int x, int y)
    {
        int k = 10 * x + y;
        k = k % array_size;
        if (hash_array[k] == NULL)
        {
            hash_array[k] = new ll_adt(x, y);
            return;
        }
        else
        {
            ll_adt *tmp_node = hash_array[k];
            while (tmp_node->next != NULL)
            {
                tmp_node = tmp_node->next;
            }
            tmp_node->next = new ll_adt(x, y);
            return;
        }
    }
    int search(int x, int y)
    {
        int k = 10 * x + y;
        k = k % array_size;
        ll_adt *tmp_node = hash_array[k];
        while (tmp_node != NULL)
        {
            if (tmp_node->search(tmp_node, x, y))
                return 1;
            tmp_node = tmp_node->next;
        }
        return 0;
    }
    void delete_edge(int x, int y)
    {
        int k = 10 * x + y;
        k = k % array_size;
        ll_adt *tmp_node = hash_array[k];
        while (tmp_node != NULL)
        {
            if (tmp_node->search(tmp_node, x, y))
            {
                if (tmp_node->prev == NULL && tmp_node->next == NULL)
                {
                    hash_array[k] = NULL;
                    delete tmp_node;
                }
                else if (tmp_node->prev == NULL)
                {
                    hash_array[k] = hash_array[k]->next;
                    hash_array[k]->prev = NULL;
                    delete tmp_node;
                }
                else if (tmp_node->next == NULL)
                {
                    tmp_node->prev->next = NULL;
                    delete tmp_node;
                }
                else
                {
                    tmp_node->prev->next = tmp_node->next;
                    tmp_node->next->prev = tmp_node->prev;
                    delete tmp_node;
                }
            }
            tmp_node = tmp_node->next;
        }
    }
};

class graph_node
{
private:
    int used;
    int *heads, *next, *data;
    int m, n;
    int last_edged_node;

public:
    graph_node(int n_in, int m_in) // n: vertices           m: edges
    {
        heads = new int[n + 1];
        next = new int[m + 1];
        data = new int[m + 1];
        m = m_in;
        n = n_in;
        used = 0;
        heads[1] = 1;
    }

    // edges should be given by order of source vertix.
    void add_edge(int x, int y)
    {
        if (y == -1)
        {
            heads[x + 1] = heads[x];
            return;
        }
        else
        {
            used++;
            heads[x + 1] = used + 1;
            data[used] = y;
            if (used - 1 >= heads[x])
                next[used - 1] = used;
            next[used] = -1;
            last_edged_node = x;
            return;
        }
    }
    void show(int x) // x is index of a vertix.
    {
        if (x > last_edged_node)
            return;
        for (int i = heads[x]; i < heads[x + 1]; i++)
            cout << data[i] << " * ";
        cout << endl;
    }
    void  set_edge_hash(hash_table &hash_object) // x is index of a vertix.
    {
        for (int j = 0; j <= last_edged_node; j++)
        {
            for (int i = heads[j]; i < heads[j + 1]; i++)
            {
                hash_object.set_edge(j, data[i]);
            }
        }
    }
};



int main(void)
{

    graph_node object(6, 5);
    object.add_edge(1, -1);

    object.add_edge(2, 5);
    object.add_edge(3, 1);

    object.add_edge(3, 2);
    object.add_edge(3, 4);
    object.add_edge(4, -1);
    object.add_edge(5, -1);
    object.add_edge(6, 5);

    for (int i = 1; i < 7; i++)
    {
        cout << "node: " << i << "\t->\t";
        object.show(i);
    }

    hash_table hash_object(5);
    object.set_edge_hash(hash_object);

    cout<<"testing hashing:\n";
    cout<<hash_object.search(3, 1)<<endl;;

    return 0;
}
