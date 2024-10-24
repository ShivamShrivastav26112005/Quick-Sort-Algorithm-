// #include<iostream>
// using namespace std;
// int partition(int arr[], int si, int ei)
// {
//     int pivotele=arr[si];
//     int count=0;
//     for(int i=si+1; i<=ei; i++)
//     {
//         if(arr[i]<=pivotele)
//         count++;
//     }
//     int pivotidx=si+count;
//     swap(arr[si], arr[pivotidx]);

//     int i=si;
//     int j=ei;

//     while(i<pivotidx && j>pivotidx)
//     {
//         if(arr[i]<=pivotele) i++;
//         if(arr[j]>pivotele) j--;
//         else if(arr[i]>pivotele && arr[j]<=pivotele)
//         {
//             swap(arr[i],arr[j]);
//             i++;
//             j--;
//         }
//     }
//     return pivotidx;
// }
// void quicksort(int arr[],int si, int ei)
// {
//     if(si>=ei) return ;
//     int pi=partition(arr,si,ei);

//     quicksort(arr,si,pi-1);
//     quicksort(arr,pi+1,ei);

// }
// int main()
// {
//     int arr[]={4,3,2,5,1,7,4,98,5,65,4,453,-9,6,6,0,5};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     for(int i=0; i<n; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;

//     quicksort(arr,0,n-1);

//     for(int i=0; i<n; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
// }


// quick sort - > is based on divide and conquer algorithm 

#include<iostream>
using namespace std;
int partition(int arr[], int si, int ei)
{
    int pivotele=arr[si];
    int count=0;
    for(int i=si+1; i<=ei; i++)
    {
        if(arr[i]<=pivotele)
        count++;
    }
    int pivotidx=si+count;
    swap(arr[si],arr[pivotidx]);

    int i=si;
    int j=ei;

    while(i<pivotidx && j>pivotidx)
    {
        if(arr[i]<=pivotele) i++;
        if(arr[j]>pivotele) j--;
        else if (arr[i]>pivotele && arr[j]<pivotele)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivotidx;
}
void quicksort(int arr[], int si, int ei)
{
    if(si>=ei) return ;

    int pi=partition(arr,si, ei);

    quicksort(arr,si,pi-1);
    quicksort(arr,pi+1,ei);
}
int main()
{
    int arr[]={4,3,5,2,6,1,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    quicksort(arr,0,n-1);

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

}
























