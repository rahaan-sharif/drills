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
        shared_memory_object:: remove("moshtarak");
        shared_memory_object:: remove("check");

        shared_memory_object moshtarak(create_only, "moshtarak", read_write);
        shared_memory_object check(create_only, "check", read_write);

        moshtarak.truncate(20);
        check.truncate(1);

        mapped_region ob1(moshtarak, read_write);
        mapped_region ob2(check, read_write);


        char* client_response =static_cast <char*> (ob2.get_address());
        *client_response=0;
        
        char* memory = static_cast <char*> (ob1.get_address());
        int length = ob1.get_size();

        for(int i=0; i<length; i++)
            memory[i]=i;

        cout<<"server is wating for clinet to be done...\n";
        cout<<"client response: "<<int(*client_response)<<endl;
        while(!*client_response);
        cout<<"client response: "<<int(*client_response)<<endl;
        cout<<"client is done. end of this program\n\n";
    }


    catch(exception& ex)
    {
        shared_memory_object:: remove("moshtarak");
        shared_memory_object:: remove("check");
        cout<<"server exception: "<<ex.what()<<endl;
        return 1;
    }
    shared_memory_object:: remove("moshtarak");
    shared_memory_object:: remove("check");
    return 0;
}
