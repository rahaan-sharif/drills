//Hi Dr.Kiani.
//in this program, I simulate semaphors
//to solve readers and writers program.

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

class th_id
{
public:
    int data;
    th_id *next;

    th_id(int data_in)
    {
        data = data_in;
        next = NULL;
    }
    void make_new(th_id *&start, int data_in)
    {
        if (start == NULL)
        {
            start = new th_id(data_in);
            return;
        }
        else
        {
            th_id *tmp_ti = start;
            while (tmp_ti->next != NULL)
                tmp_ti = tmp_ti->next;
            tmp_ti->next = new th_id(data_in);
            return;
        }
    }
    int get_first(th_id *&start)
    {
        th_id *tmp = start;
        start = start->next;
        return tmp->data;
    }
};

class semaphor
{
private:
    mutex mtx;
    int data;
    int is_free;
    th_id* th_id_list;

public:
    semaphor()
    {
        data = -1;
        is_free = 1;
        th_id_list=NULL;
    }
    void write_function(int thread_id, int data_in)
    {
        th_id_list->make_new(th_id_list, thread_id);
        while (is_free == 0 || th_id_list->data != thread_id)
            ;
        is_free = 0;
        th_id_list->get_first(th_id_list);
        cout << "\n**** start writing ****\n";
        data = data_in;
        cout << "#### end writing ####\n\n";
        is_free = 1;
        return;
    }
    int read_function(int thread_id)
    {
        th_id_list->make_new(th_id_list, thread_id);
        while (is_free == 0 || th_id_list->data != thread_id)
            ;
        is_free = 0;
        th_id_list->get_first(th_id_list);
        int tmp_int = data;
        is_free = 1;
        return tmp_int;
    }
};

void print_nums(int thread_id, semaphor &s_ob)
{
    for (int i = 0; i < 5; i++)
    {
        int data=s_ob.read_function(thread_id);
        cout << "thread_id: " << thread_id << "\tdata: " << data << endl;
        this_thread::sleep_for(chrono::milliseconds(100*(34353>>i)%40));
    }
}
void write_num(int thread_id, semaphor &s_ob)
{
    for(int i=0; i<5; i++)
    {
        s_ob.write_function(thread_id, 10*i);
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int main(void)
{
    semaphor s_ob;
    cout << "running amir's code\n";
    thread **pt1 = new thread *[4];
    for (int i = 0; i < 3; i++)
    {
        pt1[i] = new thread(print_nums, i, ref(s_ob));
    }
    pt1[3]=new thread(write_num, 3, ref(s_ob));

    for (int i = 0; i < 3; i++)
    {
        pt1[i]->join();
    }
    pt1[3]->join();

    return 0;
}