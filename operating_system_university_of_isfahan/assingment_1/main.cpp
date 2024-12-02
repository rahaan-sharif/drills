#include <iostream>
using namespace std;

class process
{
private:
    int id;
    int priority;
    int time;

public:
    process *next, *prev;
    process(int idd, int timee, int priorityy)
    {
        id = idd;
        time = timee;
        priority = priorityy;
        next = NULL;
        prev = NULL;
    }
    void make_node(process *&start, int timee, int priorityy)
    {
        if (start == NULL)
        {
            start = new process(0, timee, priorityy);
            return;
        }
        else
        {
            process *tmp = start;
            while (tmp->next != NULL)
                tmp = tmp->next;
            tmp->next = new process(tmp->id + 1, timee, priorityy);
            tmp->next->prev = tmp;
            return;
        }
    }
    void show(process *start)
    {
        cout << "\n****\n";
        cout << "\tshow processes:\n";
        while (start->next != NULL)
        {
            cout << "\tid: " << start->id << "\tpriority: " << start->priority << "\ttime: " << start->time << endl;
            start = start->next;
        }
        cout << "\tid: " << start->id << "\tpriority: " << start->priority << "\ttime: " << start->time << endl;
        cout << "***\n\n";
    }
    int run(int timee)
    {
        if (time >= timee)
        {
            time -= timee;
            return 0;
        }
        else
        {
            timee = time - timee;
            time = 0;
            return timee;
        }
    }
    int give_time()
    {
        return time;
    }
    int give_priority()
    {
        return priority;
    }
    int give_id()
    {
        return id;
    }
    process *give_short_time(process *&start)
    {
        process *tmp_process1 = start;
        process *tmp_process2 = start;
        while (tmp_process1 != NULL)
        {
            if (tmp_process1->time < tmp_process2->time)
                tmp_process2 = tmp_process1;
            tmp_process1 = tmp_process1->next;
        }
        if (tmp_process2->prev != NULL && tmp_process2->next != NULL)
        {
            tmp_process2->prev->next = tmp_process2->next;
            tmp_process2->next->prev = tmp_process2->prev;
        }
        else if (tmp_process2->prev == NULL && tmp_process2->next != NULL)
        {
            start = tmp_process2->next;
            start->prev = NULL;
        }
        else if (tmp_process2->prev != NULL && tmp_process2->next == NULL)
        {
            tmp_process2->prev->next = NULL;
        }
        else if (tmp_process2->prev == NULL && tmp_process2->next == NULL)
        {
            start = NULL;
        }
        return tmp_process2;
    }
    process *give_long_time(process *&start)
    {
        process *tmp_process1 = start;
        process *tmp_process2 = start;
        while (tmp_process1 != NULL)
        {
            if (tmp_process1->time > tmp_process2->time)
                tmp_process2 = tmp_process1;
            tmp_process1 = tmp_process1->next;
        }
        if (tmp_process2->prev != NULL && tmp_process2->next != NULL)
        {
            tmp_process2->prev->next = tmp_process2->next;
            tmp_process2->next->prev = tmp_process2->prev;
        }
        else if (tmp_process2->prev == NULL && tmp_process2->next != NULL)
        {
            start = tmp_process2->next;
            start->prev = NULL;
        }
        else if (tmp_process2->prev != NULL && tmp_process2->next == NULL)
        {
            tmp_process2->prev->next = NULL;
        }
        else if (tmp_process2->prev == NULL && tmp_process2->next == NULL)
        {
            start = NULL;
        }
        return tmp_process2;
    }
    process *give_pure_priority(process *&start)
    {
        process *tmp_process1 = start;
        process *tmp_process2 = start;
        while (tmp_process1 != NULL)
        {
            if (tmp_process1->priority < tmp_process2->priority)
                tmp_process2 = tmp_process1;
            tmp_process1 = tmp_process1->next;
        }
        if (tmp_process2->prev != NULL && tmp_process2->next != NULL)
        {
            tmp_process2->prev->next = tmp_process2->next;
            tmp_process2->next->prev = tmp_process2->prev;
        }
        else if (tmp_process2->prev == NULL && tmp_process2->next != NULL)
        {
            start = tmp_process2->next;
            start->prev = NULL;
        }
        else if (tmp_process2->prev != NULL && tmp_process2->next == NULL)
        {
            tmp_process2->prev->next = NULL;
        }
        else if (tmp_process2->prev == NULL && tmp_process2->next == NULL)
        {
            start = NULL;
        }
        return tmp_process2;
    }
};
class queues
{
private:
    static int watch;
    int id;
    queues *next;
    process *taxes;
    void (*functions)(queues *&start);

public:
    queues(int idd)
    {
        id = idd;
        next = NULL;
        if (id == 1)
            functions = fcfs;
        else if (id == 2)
            functions = rr;
        else if (id == 3)
            functions = sjf;
        else if (id == 4)
            functions = pp;
        else if (id == 5)
            functions = lcfs;
        else if (id == 6)
            functions = ljf;
    }
    void make_node(queues *&start, int idd)
    {
        if (start == NULL)
        {
            start = new queues(idd);
            return;
        }
        else
        {
            queues *tmp = start;
            while (tmp->next != NULL)
                tmp = tmp->next;
            tmp->next = new queues(idd);
            return;
        }
    }
    void show(queues *start)
    {
        cout << "\n\n--------\n";
        cout << "show:\n";
        while (start->next != NULL)
        {
            cout << "id: " << start->id << "\n";
            start = start->next;
        }
        cout << "id: " << start->id << endl;
    }
    queues *give_next()
    {
        return next;
    }
    int get_taxes(queues *&start, process *&start_p)
    {
        if (start_p != NULL)
        {
            start->taxes = start_p;
            return 1;
        }
        else
        {
            cout << "end of program.\n";
            return 0;
        }
    }
    process *give_taxes()
    {
        return taxes;
    }
    int operation(queues *&start)
    {
        cout << endl
             << endl
             << endl
             << endl;
        cout << "operation function: \n";
        start->functions(start);
        int output = 0;
        if (start->taxes != NULL)
            output = 1;
        return output;
    }
    static void fcfs(queues *&start) // first come first service
    {
        cout << "\t** First Come First Service:\n";
        process *tmp_process = start->taxes;
        while (tmp_process != NULL)
        {
            int tmp_time = tmp_process->give_time();
            tmp_process->run(tmp_time);
            watch += tmp_time;
            cout << "\tPID: " << tmp_process->give_id() << "\tpresent time: " << watch << endl;
            tmp_process = tmp_process->next;
        }
        start->taxes = NULL;
        cout << endl
             << endl;
    }
    static void rr(queues *&start) // round robine
    {
        cout << "\t** Round Robine:\n";
        int quantum = 0;
        cout << "\tinsert quantum: ";
        cin >> quantum;
        process *tmp_process = start->taxes;
        while (tmp_process != NULL)
        {
            watch += (quantum - tmp_process->run(quantum));
            cout << "\tPID: " << tmp_process->give_id() << "\tpresent time: " << watch << endl;
            tmp_process = tmp_process->next;
        }
        tmp_process = NULL;
        process *tmp_process2 = start->taxes;
        while (tmp_process2 != NULL)
        {
            int tmp_time = tmp_process2->give_time();
            int tmp_priority = tmp_process2->give_priority();
            if (tmp_time != 0)
                tmp_process->make_node(tmp_process, tmp_time, tmp_priority);
            tmp_process2 = tmp_process2->next;
        }
        start->taxes = tmp_process;
        cout << endl
             << endl;
    }
    static void sjf(queues *&start) // short job first
    {
        cout << "\tShort Job First:\n";
        while (start->taxes != NULL)
        {
            process *tmp_process = start->taxes->give_short_time(start->taxes);
            watch += tmp_process->give_time();
            cout << "\tPID: " << tmp_process->give_id() << "\tpresent time: " << watch << endl;
        }
        cout << endl
             << endl;
    }
    static void pp(queues *&start) // pure priority
    {
        cout << "\t** Pure Priority:\n";
        while (start->taxes != NULL)
        {
            process *tmp_process = start->taxes->give_pure_priority(start->taxes);
            watch += tmp_process->give_time();
            cout << "\tPID: " << tmp_process->give_id() << "\tpriority: " << tmp_process->give_priority();
            cout << "\tpresent time: " << watch << endl;
        }
        cout << endl
             << endl;
    }
    static void lcfs(queues *&start) // last come first service
    {
        cout << "\t** Last Come First Service:\n";
        while (start->taxes->next != NULL)
            start->taxes = start->taxes->next;

        process *tmp_process = start->taxes;
        while (tmp_process != NULL)
        {
            int tmp_time = tmp_process->give_time();
            tmp_process->run(tmp_time);
            watch += tmp_time;
            cout << "\tPID: " << tmp_process->give_id() << "\tpresent time: " << watch << endl;
            tmp_process = tmp_process->prev;
        }
        start->taxes = NULL;
        cout << endl
             << endl;
    }
    static void ljf(queues *&start) // long job first
    {
        cout << "\tLong Job First:\n";
        while (start->taxes != NULL)
        {
            process *tmp_process = start->taxes->give_long_time(start->taxes);
            watch += tmp_process->give_time();
            cout << "\tPID: " << tmp_process->give_id() << "\tpresent time: " << watch << endl;
        }
        cout << endl
             << endl;
    }
};
int queues::watch = 0;

int main(void)
{
    cout << "This program runs multi level feedback queue algorithm.\n";
    process *start_p = NULL;
    cout << "insert number of processes: ";
    int counter_p = 0;
    cin >> counter_p;
    int tmp_time = 0, tmp_prority = 0;
    for (int i = 0; i < counter_p; i++)
    {
        cout << "process: " << i << endl;
        cout << "\tprority: ";
        cin >> tmp_prority;
        cout << "\ttime: ";
        cin >> tmp_time;
        start_p->make_node(start_p, tmp_time, tmp_prority);
    }
    start_p->show(start_p);

    queues *start = NULL;
    cout << endl
         << endl;
    cout << "enter number of queues: ";
    int counter = 0;
    cin >> counter;
    cout << "algorithms:\n";
    cout << "id:\n";
    cout << "1-> first come first service        =    fcfs\n";
    cout << "2-> round robine                    =    rr\n";
    cout << "3-> short job first                 =    sjf\n";
    cout << "4-> pure priority                   =    pp\n";
    cout << "5-> last come first service         =    lcfs\n";
    cout << "6-> long job first                  =    ljf\n\n";

    int tmp_id = 0;
    for (int i = 0; i < counter; i++)
    {
        cout << "\nqueue: " << i << endl;
        cout << "id: ";
        cin >> tmp_id;
        start->make_node(start, tmp_id);
    }
    start->show(start);

    int check1 = 0, check2 = 0;
    check1 = start->get_taxes(start, start_p);
    if (!check1)
    {
        cout << endl
             << endl;
        return 0;
    }
    for (int i = 0; i < counter; i++)
    {
        if (!check1)
        {
            cout << endl
                 << endl;
            return 0;
        }
        check2 = start->operation(start);
        if (!check2)
        {
            cout << endl
                 << endl;
            return 0;
        }
        start_p = start->give_taxes();
        if(i+1!=counter)
            start = start->give_next();
        else
            cout<<"queues ended. maybe some processes are remained.\n";
        check1 = start->get_taxes(start, start_p);
    }

    cout << endl
         << endl;
    return 0;
}