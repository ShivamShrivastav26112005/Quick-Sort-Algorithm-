// #include<iostream>
// using namespace std;
// int partition(int arr[], int si,int ei)
// {
//     // 1st kaam 
//     int pivotElement=arr[si];
//     int count=0;
//     for(int i=si+1;i<=ei;i++)
//     {
//         if(arr[i]<=pivotElement)
//         count++;
//     }
//     int pivotidx=count+si;
//     swap(arr[si],arr[pivotidx]);// hm index ke gariye ele. ko swap kara diye 

//     // 2nd kaam
//     int i=si; 
//     int j=ei;
//     while(i<pivotidx && j>pivotidx)
//     {
//         if(arr[i]<=pivotElement) i++;
//         if(arr[j]>pivotElement) j++;
//         else if (arr[i]>pivotElement && arr[j]<=pivotElement)
//         {
//             swap(arr[i],arr[j]);
//             i++;
//             j--;
//         }
//     }
//     return pivotidx;
// }
// void quicksort(int arr[], int si,int ei)
// {
//     //si=starting idx,ei=ending idx,pi=pivot idx
//     if(si>=ei) return; // base case
//     int pi=partition(arr,si,ei);// to find pivot ele, we find pi.

//     quicksort(arr,si,pi-1); //pi=pivot index
//     quicksort(arr,pi+1,ei);

// }
// int main()
// {
//     int arr[]={5,1,7,4,9,6,8,2,3};
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


// // Practice -: Quick Sort

#include<iostream>
using namespace std;
int partition(int arr[], int si, int ei)
{
    // partition se pta chal gya pivotidx and ele also. 

   // int pivotElement=arr[si]; // pivotele ko array ka 1st ele maan liye
   // use - randomized pivot point worst case se bachne ke liye-:
   int pivotElement=arr[(si+ei)/2];
   int count=0; // pivotele se small ele kitne h-becoz hm esse pivotidx find kar skte h
   //for(int i=si+1;i<=ei; i++)
     for(int i=si;i<=ei; i++)
    {
      if(i==(si+ei)/2) continue;
      if(arr[i]<=pivotElement)
      count++;
    }
   int pivotidx=count+si;

 //  swap(arr[si],arr[pivotidx]); 

  swap(arr[(si+ei)/2],arr[pivotidx]);


// pivot ele ke left me small ele and right me large ele place ho jayega 
   int i=si;
   int j=ei;

   while(i<pivotidx && j>pivotidx)
   {
    if(arr[i]<=pivotElement) i++;
    if(arr[j]>pivotElement) j--;
    else if(arr[i]>pivotElement && arr[j]<=pivotElement)
    {
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
   }
   return pivotidx;
}
void quicksort(int arr[], int si, int ei) // recursion
{
   // base case necessary  
   while(si>=ei) return ;
   int pi=partition(arr,si,ei);
   

 // pi=pivotidx,si=starting idx,ei=ending idx
 // recursion 
   quicksort(arr,si,pi-1); 
   quicksort(arr,pi+1,ei);
   
}
int main()
{
    int arr[]={4,3,2,5,1,7,4,98,5,65,4,453,-9,6,6,0,5};
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

// 5 3 7 6 9 1 8 2 4 3 
// 1 2 3 3 4 5 6 7 8 9 


// practice -: Quick Sort

// #include<iostream>
// using namespace std;
// int partition(int arr[], int si, int ei)
// {
//   int pivotele=arr[si];
//   int count=0;
//   for(int i=si+1; i<=ei; i++)
//   {
//     if(arr[i]<pivotele)
//     count++;
//   }
//   int pivotidx=count+si;
//   swap(arr[si], arr[pivotidx]); // becoz 1st ele ko uske actual postion per lane ke liye

//   // we place small ele left and large ele right from the pivotele

//   int i=si;
//   int j=ei;
//   while(i<pivotidx && j>pivotidx)
//   {
//     if(arr[i]<pivotele) i++;
//     if(arr[j]>pivotele) j--;
//     else if(arr[i]>pivotele && arr[j]<pivotele)
//     {
//       swap(arr[i], arr[j]);
//       i++;
//       j--; 
//     }
//   }
//   return pivotidx;
// }
// void quicksort(int arr[], int si, int ei)
// {
//   // base case
//   if(si>=ei) return ;
//   int pi=partition(arr,si,ei); // 1st ele(pivot) ka actual pi(pivotidx) 
//   //find karenge using partition
// // pi= pivotidx 
// // recursion - fun calling itself
// // 1st Q.S-left side ele and 2nd Q.S- right side ele from the pivotele.
//   quicksort(arr,si,pi-1);
//   quicksort(arr,pi+1,ei);
// }
// int main()
// {
//   int arr[]={5,1,8,2,7,6,3,4};
//   int n=sizeof(arr)/sizeof(arr[0]);
//   for(int i=0; i<n; i++)
//   {
//     cout<<arr[i]<<" ";
//   }
//   cout<<endl;

//   quicksort(arr,0,n-1);
//   for(int i=0; i<n; i++)
//   {
//     cout<<arr[i]<<" ";
//   }
// }





// // Ques.1-> Write a program to find kth smallest ele in an array using quick sort.

// // algorithm use- quick select.
// // array given = {5,1,8,2,7,6,3,4}  k=5 means 5th smallest ele = 5
// #include<iostream>
// using namespace std;
// int partition(int arr[], int si, int ei, int k)
// {
//   int pivotele=arr[si];
//   int count=0;
//   for(int i=si+1; i<=ei; i++)
//   {
//     if(arr[i]<pivotele)
//     count++;
//   }
//   int pivotidx=count+si;
//   swap(arr[si], arr[pivotidx]); 

//   int i=si;
//   int j=ei;
//   while(i<pivotidx && j>pivotidx)
//   {
//     if(arr[i]<pivotele) i++;
//     if(arr[j]>pivotele) j--;
//     else if(arr[i]>pivotele && arr[j]<pivotele)
//     {
//       swap(arr[i], arr[j]);
//       i++;
//       j--; 
//     }
//   }
//   return pivotidx;
// }
// int kthsmallest(int arr[], int si, int ei,int k)
// {
//   int pi=partition(arr,si,ei,5); 
//   if(pi+1==k) return arr[pi];
//   else if (pi < k) return kthsmallest(arr,pi+1,ei,k);
//   else return kthsmallest(arr,si, pi-1, k);


// }
// int main()
// {
//   int arr[]={5,1,8,6,3,4};
//   int n=sizeof(arr)/sizeof(arr[0]);
//   for(int i=0; i<n; i++)
//   {
//     cout<<arr[i]<<" ";
//   }
//   cout<<endl;

//   int k=2;
//   cout<<kthsmallest(arr,0,n-1,k);
// }
