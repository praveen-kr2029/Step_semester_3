package main.c++.class_problems;

public import java.util.Arrays;

public class TwoSum {

    public static void main(String[] args) {
        int[] nums = {2, 7, 11, 15};  //length = 4

        int target = 99;

        int[] result = findSum(nums,target);

        System.out.println(Arrays.toString(result));
    }

    private static int[] findSum(int[] nums, int target) {    //{2,7,11,5}
        for(int i = 0; i < nums.length; i++){

            for(int j = i + 1; j < nums.length; j++){

                if(nums[i] + nums[j] == target){   //i = 2, j = 7 = 9

                    return new int[]{i,j};
                }
            }
        }

        return new int[]{};
    }


}

 {
    
}
