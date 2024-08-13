public class insertion_sort {
    public static void main(String args[]){
        int a[] = {4,5,2,1,9,3};
        int i,j,temp;
        for(i=1;i<a.length;i++){
            temp = a[i];
            for(j=i-1;j>=0 && a[j] > temp;j--){
                a[j+1] = a[j];
            }
            a[j+1] = temp;
        }

        for(int n: a){
            System.out.print(n + " ");
        }
    }
}
