#include <iostream>
using namespace std;

int rec_func(int value)
{
    if (value == 0)
    {
        return 0;
    }
    else
    {
        int tmp = rec_func(value - 1);
        if (tmp % 10 == 0)
        {
            cout << tmp + 1 << endl;
            return tmp + 1;
        }
        else
        {
            tmp++;

            int tmp2 = 0;
            int j = 1;
            for (j = 1; tmp / j != 0; j *= 10)
            {
                tmp2 = (tmp % (j * 10)) / j;
                if (tmp2 / 2 > 0)
                {
                    tmp = ((tmp / (j * 10)) + tmp2 / 2) *j* 10 + (tmp2 % 2) + (tmp % (j));
                }
            }

            cout << tmp << endl;
            return tmp;
        }
    }
}

int main(void)
{
    int ent=0;
    cin>>ent;
    rec_func(ent);

    return 0;
}