#include <iostream>
using namespace std;

void show(long long int* arr,long long int start, long long int end)
{
    for(long long int i=start; i<end; i++)
        cout<<arr[i]<<", ";
    cout<<endl<<endl;
}

void quick_sort(long long int*& arr, long long int start, long long int end)//, long long int*& counter)
{
    if(start+1>=end)
    {
        return;
    }
    else
    {

        long long int mid=(start+end)/2;
        long long int mid_value=arr[mid];

        long long int* lower=new long long int[end-start];
        long long int l_p=0;

        long long int* upper=new long long int[end-start];
        long long int u_p=0;

        for(long long int i=start; i<end; i++)
        {
            if(i!=mid)
            {
                if(arr[i]<=mid_value)
                {
                    lower[l_p++]=arr[i];
                }
                else
                {
                    upper[u_p++]=arr[i];
                }
            }
        }

        for(long long int i=0; i<l_p; i++)
        {
            if(arr[start+i]!=lower[i])
            {
                arr[start+i]=lower[i];
            }
        }

        if(arr[start+l_p]!=mid_value)
        {
            arr[start+l_p]=mid_value;
            mid=start+l_p;
        }

        for(long long int i=0; i<u_p; i++)
        {
            if(arr[i+start+l_p+1]!=upper[i])
            {
                arr[i+start+l_p+1]=upper[i];
            }
        }

        quick_sort(arr, start, mid);
        quick_sort(arr, mid+1, end);

        delete []upper;
        delete []lower;
    }
}

int main(void)
{
    int length=0;
    cout<<"enter length: ";
    cin>>length;

    long long int* arr=new long long int[length];
    long long int* const_arr=new long long int[length];
    for(long long int i=0; i<length; i++)
    {
        cout<<"enter element "<<i<<": ";
        cin>>arr[i];
        const_arr[i]=arr[i];
    }
    quick_sort(arr, 0, length);

    cout<<"\nsorted array:\t";
    show(arr, 0, length);

    cout<<endl<<endl;
    return 0;
}
