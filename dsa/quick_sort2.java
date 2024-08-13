public class quick_sort2 {
    static void quick_sort(int arr[],int start,int end){
        if(start < end){
            int partiti = partition(arr,start,end);
            quick_sort(arr, start, partiti-1);
            quick_sort(arr, partiti+1, end);
        }
    }

    static int partition(int arr[],int start,int end){
        int pivot = arr[end];
        int i = start - 1;
        int temp;
        for(int j=start;j<end;j++){
            if(arr[j] < pivot){
                i++;
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
        temp = arr[i+1];
        arr[i+1] = pivot;
        arr[end] = temp;
        return i+1; 
    }
    public static void main(String args[]){
        int a[] = {7,2,1,3,4,9};
        quick_sort(a,0,a.length-1);
        for(int i: a){
            System.out.print(i + " ");
        }
    }
}
