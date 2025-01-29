#include<iostream>
using namespace std;

int have_empty(int* a, int length=3)
{
    for(int i=0; i<length; i++)
    {
        if(a[i]==-1)
            return i;
    }
    return -1;
}

class optimal
{
private:
    int *data;
    int length;  
    int frame_num;
public:
    optimal(int *data_in, int length_in, int frame_num_in)
    {
        data=new int[length_in];
        length=length_in;
        frame_num=frame_num_in;
        for(int i=0; i<length_in; i++)
            data[i]=data_in[i];
    }
    void operation()
    {
        int* tmp=new int[frame_num];
        for(int i=0; i<frame_num; i++)
            tmp[i]=-1;

        cout<<"time\t\t";
        for(int i=0; i<frame_num; i++)
            cout<<"frame"<<i+1<<"\t";
        cout<<endl;
        for(int i=0; i<length; i++)
        {
            if(have_empty(tmp, frame_num)>-1)
            {
                tmp[have_empty(tmp, frame_num)]=data[i];
            }
            else if(location(tmp, i)!=-1)
            {
                tmp[location(tmp, i)]=data[i];
            }
            
            cout<<i<<"->\t\t";
            for(int i=0; i<frame_num; i++)
            {
                cout<<tmp[i]<<"\t";
            }
            cout<<endl;
        }


    }
    int location(int* tmp, int i)
    {
        int counter=0;
        int* tmp_tmp=new int[frame_num];
        for(int j=0; j<frame_num; j++)
            tmp_tmp[j]=tmp[j];

        for(int j=0; j<frame_num; j++)
        {
            if(tmp[j]==data[i])
                return -1;
        }

        for(int j=i; j<length; j++)
        {
            for(int k=0; k<frame_num; k++)
            {
                if(tmp_tmp[k]==data[j])
                {
                    counter++;
                    tmp_tmp[k]=-1;
                    break;
                }
            }
            if(counter==(frame_num-1))
                break;
        }
        for(int k=0; k<frame_num; k++)
        {
            if(tmp_tmp[k]!=-1)
            {
                return k;
            }
        }
        return -1;
    }
};

int main(void)
{
    cout<<"optimal policy:\n"<<endl;
    int a[20]={7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    optimal ob(a, 20, 3);
    ob.operation();

    return 0;
}