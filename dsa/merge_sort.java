public class merge_sort {
    static void mergesortwork(int arr[],int temp[],int start,int end){
        if(start<end){
            int mid = (start + end)/2;
            mergesortwork(arr,temp,start,mid);
            mergesortwork(arr,temp,mid+1,end);
            merge(arr,temp,start,mid,end);

        }
    }
    static void merge(int arr[],int temp[],int start,int mid,int end){
        int i = start;
        int j = mid + 1;
        int k = start;
        while(i<=mid && j <= end){
            if(arr[i] < arr[j]){
                temp[k++] = arr[i++];
            }else{
                temp[k++] = arr[j++];
            }
        }
        while(i<=mid){
            temp[k++] = arr[i++];
        }
        while(j<=end){
            temp[k++] = arr[j++];
        }
        for(int n=start;n<=end;n++){
            arr[n] = temp[n];
        }
    }

    public static void mergesort(int arr[]){
        int temp[] = new int[arr.length];
        mergesortwork(arr,temp,0,arr.length-1);
    }
    public static void main(String args[]){
        int a[] = {7,2,1,3,4,9};
        mergesort(a);
        for(int i: a){
            System.out.print(i + " ");
        }
    }
}
