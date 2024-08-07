class median_two_arrays {
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;
        int arr[] = new int[n1+n2];
        int i=0;
        int j=0;
        int k=0;

        while(i<n1 && j<n2){
            if(nums1[i] <= nums2[j]){
                arr[k++] = nums1[i++];
            }else{
                arr[k++] = nums2[j++];
            }
        }

        while(i<n1){
            arr[k++] = nums1[i++];
        }
        while(j<n2){
            arr[k++] = nums2[j++];
        }
        
        if(k%2 != 0){
            return (double) arr[k/2];
        }else{
            double result = (double) arr[k/2] + arr[(k/2)+1];
            return result;
        }
    }

    public static void main(String Args[]){
        int nums1[] = {1,3};
        int nums2[] = {2};
        System.out.println(findMedianSortedArrays(nums1,nums2));
    }
}