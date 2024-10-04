#include <iostream>
using namespace std;

// Function to print an array (generic template)
template <class T>
void Print(T& vec,int n,string s){
    cout<<s<<": ["<<flush;
    for(int i=0;i<n;i++){
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

int Delete(int A[],int n){
    int i,j,val;
    val=A[0];
    A[0]=A[n];
    A[n]=val;
    i=0;
    j=2*i+1;
    while(j<n-1){
        if(A[j]<A[j+1]){
            j++;
        }
        if(A[i]<A[j]){
            Swap(A,i,j);
            i=j;
            j=2*j+1;
        }
        else{
            break;
        }
    }
  return val;
}
void Heapify(int A[],int n){
    /* No of Leaf Element=(n+1)/2*
    , index of last leaf element's Parent=(n/2)-1 */

    //In heapify (faster method to insert the element)
    //the Array is scanned from right to left
    //The elements are rearranged from root towards leaf means everytime we check for the chidren of node.
    for(int i=(n/2)-1;i>=0;i--){
        int j=2*i+1;
        while(j<n-1){
             if(A[j]<A[j+1]){
            j++;
        }
        if(A[i]<A[j]){
            Swap(A,i,j);
            i=j;
            j=2*j+1;
        }
        else{
            break;
        }
      }
    }
}

int main(){
    int Heap[]={5,10,30,20,35,40,15};
    int n=sizeof(Heap)/sizeof(Heap[0]);
    Print(Heap,n,"Before Heapify");
    Heapify(Heap,n);
    Print(Heap,n,"Heapify");
}
