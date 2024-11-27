#include <iostream>
#include <string.h>
using namespace std;

class queue
{
private:
    string data;
    queue *next;
    queue *prev;

public:
    queue(char *item)
    {
        data = item;
        next = NULL;
        prev = NULL;
    }
    void add_node_last(queue *&start, char *item)
    {
        if (start == NULL)
        {
            start = new queue(item);
            start->prev=start;
            return;
        }
        else
        {
            queue *tmp = start;
            while (tmp->next != NULL)
                tmp = tmp->next;
            tmp->next = new queue(item);
            tmp->next->prev = tmp;
            start->prev=tmp->next;
            return;
        }
    }
    void show(queue *start)
    {
        if (start == NULL)
            return;
        else
        {
            cout << start->data;
            start = start->next;
            if (start == NULL)
                return;
            while (start->next != NULL)
            {
                cout << start->data << "/";
                start = start->next;
            }
            cout << start->data;
            cout << endl;
        }
    }
    void go_back(queue*& start)
    {
        if(start==NULL)
            return;
        else if(start->next==NULL)
        {
            start->data="/";
            return;
        }

        queue* tmp=start->prev;
        tmp->prev->next=NULL;
        start->prev=tmp->prev;
        delete tmp;
    }
    void req_alg(queue *&start)
    {
        queue *tmp = start;
        if (tmp->next == NULL)
            return;
        else if (tmp->data == "/")
            if (tmp->next->data == "..")
            {
                if (tmp->next->next != NULL)
                {
                    tmp->next->next->prev = tmp;
                }
                tmp->next = tmp->next->next;
            }
        tmp = tmp->next;
        while (tmp != NULL)
        {
            if (tmp->data == "..")
            {
                queue *tmp2 = tmp->prev->prev;
                tmp2->next = tmp->next;
                if (tmp->next != NULL)
                    tmp->next->prev = tmp2;
                delete tmp;
                tmp = tmp2;
            }
            else if (tmp->data == ".")
            {
                queue *tmp2 = tmp->prev;
                tmp2->next = tmp->next;
                if (tmp->next != NULL)
                    tmp->next->prev = tmp2;
                delete tmp;
            }

            tmp = tmp->next;
        }
    }
};

int main(void)
{
    queue *start1 = NULL;
    char ch[3000], tmp_ch[3000];
    cin >> ch;
    tmp_ch[0] = '/';
    tmp_ch[1] = 0;
    start1->add_node_last(start1, tmp_ch);

    int counter = 0;

    // inserting items to queue:
    for (int i = 0; i <= strlen(ch); i++)
    {
        if (ch[i] == '/' || i == strlen(ch))
        {
            if (counter != 0)
            {
                for (int j = counter; j > 0; j--)
                    tmp_ch[counter - j] = ch[i - j];
                tmp_ch[counter] = 0;

                if (!strcmp(tmp_ch, ".."))
                {
                    start1->go_back(start1);
                    counter=0;
                }
                else if (strcmp(tmp_ch, "."))   //they shouldn't be equal.
                {

                    start1->add_node_last(start1, tmp_ch);
                    counter = 0;
                    
                }
                else if(!strcmp(tmp_ch, "."))
                {
                    counter=0;
                }
            }
        }
        else if (ch[i] == '/')
        {
            counter = 0;
        }
        else if (ch[i] != '/')
        {
            counter++;
        }
    }

   // start1->req_alg(start1);
    start1->show(start1);

    return 0;
}