#include<stdio.h>
//Function to swap two elements by indices
void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

//partition function  using the first element as the pivot
int partition(int arr[],int low,int high){
    int pivot=arr[low]; // pivot is the first element
    int left=low+1;
    int right=high;

    while(1){
        //move the left pointer to the right until an element greater than pivot is found
        while(left<=right && arr[left]<=pivot){
            left++;
        }

        //move the right pointer to the left until an element less than pivot is found
        while(right>=left && arr[right]>=pivot){
            right--;
        }
        //if the left pointer has crossed th right pointer , break out pf the loop
        if(left>right){
            break;
        }

        //swap the elements at the left and right indices
        swap(arr,left,right);
    }
    //place the pivot in its correct position
    swap(arr,low,right);

    return right; // return the position of the pivot
}

// quickSort function 
void quickSort(int arr[],int low,int high){
    if(low<high){
        // partition the array and get the pivot index
        int pivotIndex=partition(arr,low,high);

        //recursively sort the sub-arrays
        quickSort(arr,low,pivotIndex-1);
        quickSort(arr,pivotIndex+1,high);
    }
}

//function to print teh array
void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[]={10,7,8,9,1,5};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr,n);

    quickSort(arr,0,n-1);

    printf("Sorted array: ");
    printArray(arr,n);

    return 0;
}