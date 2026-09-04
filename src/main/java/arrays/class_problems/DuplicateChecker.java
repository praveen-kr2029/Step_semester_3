package main.c++.class_problems;

public public class DuplicateChecker {

    public static void main(String[] args) {

        int[] nums = {1, 2, 3, 1};
        boolean result = findDup(nums);
        System.out.println(result);
    }

    private static boolean findDup(int[] nums) {   //{1,2,3,1}

        for(int i = 0; i<nums.length; i++){

            for(int j = i; j < nums.length; j++){
                if(nums[i] == nums[j]){
                    return true;
                }

            }
        }

        return false;
    }


}
 {
    
}
