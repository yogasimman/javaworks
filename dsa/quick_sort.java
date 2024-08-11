

public class quick_sort {

        static  int partition(int arr[],int low,int high){
            int pivot = arr[high];
            int i = low - 1;
            for(int j=low;j<high;j++){
                if(arr[j] < pivot){
                    i++;
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            int temp = arr[i+1];
            arr[i+1] = arr[high];
            arr[high] = temp;
            return i + 1;
        }
        static void quicksort(int arr[],int low,int high){
            if(low<high){
                int pi = partition(arr,low,high);
                printarray(arr);
                quicksort(arr,low,pi -1);
                quicksort(arr,pi + 1,high);
            }
        }
        static void printarray(int arr[]){
            System.out.print("\n[ ");
            for(int i : arr){
                System.out.print(i + " ");
            }
            System.out.println("]");
        }

        public static void main(String[] args){
            int arr[] = {7,2,1,8,9,3,5,4};
            quicksort(arr,0,arr.length-1);
            printarray(arr);
    }
}
