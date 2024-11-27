#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>

#include <iostream>
#include <cstring>

using namespace std;
using namespace boost::interprocess;

int main(void)
{
    try
    {
        shared_memory_object moshtarak(open_only, "moshtarak", read_only);
        shared_memory_object check(open_only, "check", read_write);

        mapped_region ob1(moshtarak, read_only);
        mapped_region ob2(check, read_write);

        char* client_response =static_cast <char*> (ob2.get_address());

        char *memory = static_cast <char*> (ob1.get_address());
        int length = ob1.get_size();

        cout << "\n\ndatas:\n";
        for (int i = 0; i < length; i++)
            cout << int(memory[i]) << endl;
        cout << endl
             << endl;

        *client_response=1;
    }

    catch (exception &ex)
    {
        cout<<"client exception: "<<ex.what()<<endl;
        return 1;
    }

    return 0;
}
