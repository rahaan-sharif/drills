#include <iostream>
using namespace std;

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
            cout << data[i] << "  ";
        cout << endl;
    }
};

int main(void)
{
    graph_node object(4, 4);
    object.add_edge(1, -1);

    object.add_edge(2, 5);
    object.add_edge(3, 1);

    object.add_edge(3, 2);
    object.add_edge(3, 4);
    object.add_edge(4, -1);
    object.add_edge(5, -1);
    object.add_edge(6, 5);

    object.show(2);

    return 0;
}
