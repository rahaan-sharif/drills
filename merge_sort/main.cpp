#include <iostream>
using namespace std;
using l_type=long long int;

void merge(l_type*& arr, l_type start, l_type mid, l_type end)
{
    l_type p_1=start, p_2=mid, i=0;
    l_type* tmp_arr=new l_type[end-start];
    while(p_1!=mid && p_2!=end)
    {
        if(arr[p_1]<=arr[p_2])
        {
            tmp_arr[i++]=arr[p_1++];
        }
        else
        {
            tmp_arr[i++]=arr[p_2++];
        }
    }
    while(i<(end-start))
    {
        if(p_1<mid)
        {
            tmp_arr[i++]=arr[p_1++];
        }
        else if(p_2<end)
        {
            tmp_arr[i++]=arr[p_2++];
        }
    }

    for(l_type j=0; j<(end-start); j++)
    {
        arr[j+start]=tmp_arr[j];
    }
    cout<<endl;
}

void merge_sort(l_type*& arr, l_type start, l_type end)
{

    if(start>=end || end-start==1)
    {
        return;
    }
    else
    {
        l_type mid=(start+end)/2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid, end);
        merge(arr, start, mid, end);
    }
}


int main(void)
{
    l_type length=-1;
    cout<<"enter length: ";
    cin>>length;
    l_type* arr= new l_type[length];

    for(l_type i=0; i<length; i++)
    {
        cout<<"enter item "<<i<<": ";
        cin>>arr[i];
    }

    cout<<endl<<endl<<"inserted array: ";
    for(l_type i=0; i<length; i++)
    {
        cout<<arr[i]<<", ";
    }

    merge_sort(arr, 0, length);

    cout<<endl<<endl<<"sorted array: ";
    for(l_type i=0; i<length; i++)
    {
        cout<<arr[i]<<", ";
    }

    cout<<endl<<endl;
    return 0;
}
