package main.c++.class_problems;

public import java.util.Arrays;

public class MergeSortedArrays {

    public static void main(String[] args) {

        int[] arr1 = {1,3,5}; //3 length
        int[] arr2 = {2, 4, 6}; //3 length

        System.out.println(Arrays.toString(mergeSortedArrays(arr1, arr2)));
    }

    private static int[] mergeSortedArrays(int[] arr1, int[] arr2) {

         int[]  result = new int[arr1.length + arr2.length];  //{0,0,0,0,0,0}

         int i = 0;
         int j = 0;
         int k = 0;

         while(i < arr1.length && j < arr2.length){   //arr1 = {1,3,5}   arr2 = {2, 4, 6}
             if(arr1[i] < arr2[j]){
                 result[k++] = arr1[i++];
             } else {
                 result[k++] = arr2[j++];
             }
         }

         while(i < arr1.length){
             result[k++] = arr1[i++];
         }

         while(j < arr2.length){
             result[k++] = arr2[j++];
         }
        return result;
    }
}
 {
    
}
