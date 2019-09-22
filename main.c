#include <stdio.h>
#include <stdint.h>

void bubbleSort(int arr[], int size){
    int isSwapped;
    for(int i=0; i<size-1; i++){
        isSwapped = 0;
        for(int j=0; j<size-1-i; j++){
            if(arr[j] > arr[j+1]){
                if(isSwapped == 0) isSwapped = 1;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(!isSwapped){
            return;
        }
    }
}

void selectionSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        //finding minimum
        int min = arr[i];
        int indexAtMin = i;
        for(int j=i+1; j<size; j++){
            if(min > arr[j]){
                min = arr[j];
                indexAtMin = j;
            }
        }

        //placing the value at correct position
        int temp = arr[i];
        arr[i] = arr[indexAtMin];
        arr[indexAtMin] = temp;
    }
}

void insertionSort(int arr[], int size){
    for(int i=1; i<size; i++){
        int key = arr[i];
        int j;
        for(j=i-1; j>=0; j--){
            if(arr[j] > key){
                arr[j+1] = arr[j];
                continue;
            }
            break;
        }
        arr[j+1] = key;
    }
}

int partitionAlgo(int arr[], int start, int end){
    int index = start;
    for(int i=start+1; i<end; i++){
        if(arr[start] > arr[i]){
            index+=1;
            //swap
            int temp = arr[index];
            arr[index] = arr[i];
            arr[i] = temp;
        }
    }
    //swap
    int temp = arr[index];
    arr[index] = arr[start];
    arr[start] = temp;

    return index;
}

void quickSort(int arr[], int start, int end){
    if(start < end){
        int partitionIndex = partitionAlgo(arr, start, end);
        quickSort(arr, 0, partitionIndex-1);
        quickSort(arr, partitionIndex+1, end);
    }
}


void mergingAlgo(int arr[], int start, int mid, int end){
    int n1 = mid-start+1;
    int n2 = end-mid;
    int arr1[n1+1];
    int arr2[n2+1];

    for(int i=0; i<n1; i++){
        arr1[i] = arr[start + i];
    }

    for(int j=0; j<n2; j++){
        arr2[j] = arr[mid + j + 1];
    }

    arr1[n1] = INT8_MAX;
    arr2[n2] = INT8_MAX;

    int i = 0,j = 0;

    for(int k=start; k<end+1; k++){
        if(arr1[i] <= arr2[j]){
            arr[k] = arr1[i];
            i++;
        }else{
            arr[k] = arr2[j];
            j++;
        }
    }

}

void mergeSort(int arr[], int start, int end){
    if(start < end){
        int mid = start + (end-start)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        mergingAlgo(arr, start, mid, end);
    }
}

int main(){
    int N;
    printf("Enter number of elements for your array\n");
    scanf("%d", &N);

//  Entering Elements for the giver array size
    int arr[N];
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Enter the elements\n");
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }

    int choose;
    printf("Enter 1 for bubble sort, 2 for selection sort, 3 for insertion sort, 4 for quick sort, 5 for merge sort\n");
    scanf("%d", &choose);

    switch(choose){
        case 1: printf("Bubble Sort\n");
            bubbleSort(arr, size);
            break;
        case 2: printf("Selection Sort\n");
            selectionSort(arr, size);
            break;
        case 3: printf("Insertion Sort\n");
            insertionSort(arr, size);
            break;
        case 4: printf("Quick Sort\n");
            quickSort(arr, 0, size);
            break;
        case 5: printf("Merge Sort\n");
            mergeSort(arr, 0, size-1);
            break;
        default: printf("Wrong Selection\nRestart the app\n");
    }

    if(choose>0 && choose <6){
        //Printing Elements
        for(int i=0; i<size; i++){
            if(i == size-1){
                printf("%d", arr[i]);
                break;
            }
            printf("%d, ", arr[i]);
        }
    }

    return 0;
}
