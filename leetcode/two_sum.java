import java.util.HashMap;

public class two_sum {
    public int[] twoSum(int[] nums, int target) {
        int arr[] = new int[2];
        int partial;
        for(int i=0;i<(nums.length-1);i++){
            partial = nums[i];
            for(int j=i+1;j<nums.length;j++){
                if(partial + nums[j] == target){
                    arr[0] = i;
                    arr[1] = j;
                }
            }
        }
        return arr;
    }
    public int[] twoSumEffective(int[] nums, int target) {
        HashMap<Integer,Integer>  hash= new HashMap<Integer,Integer>();
        int arr[] = new int[2];
        int compliment;
        for(int i=0;i<nums.length;i++){
            hash.put(nums[i],i);
        }

        for(int i=0;i<nums.length;i++){
            compliment = target - nums[i];
            if(hash.get(compliment) != null && hash.get(compliment) != i){
                arr[0] = i;
                arr[1] = hash.get(compliment);
            }
        }
        return arr;
    }
}
