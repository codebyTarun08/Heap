#include <iostream>
using namespace std;

// Function to print an array (generic template)
template <class T>
void Print(T& vec,int n,string s){
    cout<<s<<": ["<<flush;
    for(int i=1;i<n;i++){
        cout<<vec[i]<<flush;
        if(i<n-1){
            cout<<","<<flush;
        }
    }
    cout<<"]"<<endl;
}

void Swap(int A[],int i,int j){
    int temp=A[i];
    A[i]=A[j];
    A[j]=temp;
}

// Function to insert an element into a max heap
void Insert(int A[],int n){
    int temp,i;
    i=n;//Always insert the element at last free space
    temp=A[n]; //Storing the inserted element in temp because for Rearranging
    while(i>1 && temp>A[i/2]){ //jab tak i 1se bada hai aur inserted ele apne parent se bade hai toh
        A[i]=A[i/2];  //agar ele parent se bada hai to parent ko swap karenge
        i=i/2;  //i is decrement by i/2 because it is parent position
    }
    A[i]=temp; //At last we find the suitable position for inserted element so put it on that position
}
//Time Complexity: O(nlogn). For inserting 1 element logn but for n elements nlogn

// Function to create a max heap from an array
void CreateHeap(int A[],int n){ 
   for(int i=2;i<n;i++){    //assume the first element at i=1 is always in a heap so start with 2
       Insert(A,i); 
   }
   Print(A,n,"Heapified A"); //Printing the heap after inserting all element
}

// Function to delete the maximum element from a max heap
int Delete(int A[],int n){    //In heap always root element is deleted
    int i,j,val; 
    val=A[1];   //Step 1:take the root element 
    A[1]=A[n];  //Step 2:Copy the last Element to the root
    A[n]=val;   //
    i=1,j=2*i;  //Make pointer on root and left child
    while(j<n-1){      //repeat the j reaches the last index
        if(A[j]<A[j+1]){ //If left child is smaller than right child
            j=j+1;   //then bring j pn right child
        }
        if(A[i]<A[j]){   //if root is less than than the children
            Swap(A,i,j); //Swap them
            i=j;           //make i on j for next iteration
            j=2*j;      // Update the j on its left child
        }
        else{         //if root is already arrange then break
            break;
        }
    } 
    return val; //return root element
}
//Time Complexity: O(nlogn). For deleting 1 element logn but for n elements nlogn

/*For Heap Sort:
      1.Create Heap for n elements:nlogn
      2.Delete n ele one by one :  nlogn
                              +_____________
                               2nlogn =>O(nlogn)
      */
int main(){
    int A[]={0,10,20,30,25,5,40,35};
    int n=sizeof(A)/sizeof(A[0]);
    // Create a max heap from the array
    CreateHeap(A,n); //Heapified A: [40,25,35,10,5,20,30]
     // Delete elements from the heap (in descending order)
    for(int i=n-1;i>0;i--){
    //   cout<<"deleted element is :"<<Delete(A,n)<<endl;
     Delete(A,i);
    } 
    // Print the resulting array after deletion
    Print(A,n,"Deleted Heap");
    //Resulted array is sorted so this deleting procedure is know as Heap sort.
    return 0;
}
