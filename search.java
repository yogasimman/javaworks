public class search{
    public static void main(String[] args){

        int nums[] = {5,7,9,11,13};
        int target = 11;

        int result = linearSearch(nums, target);
        result = binarySearch(nums,target);
        System.out.println("Element found at Index:" + result);
    }

    public static int linearSearch(int[] nums,int target){
        for(int i=0;i<nums.length;i++){
            if(nums[i] == target){
                return i;
            }
        }
        return -1;
    }

    public static int binarySearch(int[] nums,int target){
        int s = 0; int l = nums.length;
        int mid = 0;
        while(s<=l){
            mid = (s+l) /2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                l = mid -1;
            }else{
                s = mid + 1;
            }
        }
        return -1;
    }
}