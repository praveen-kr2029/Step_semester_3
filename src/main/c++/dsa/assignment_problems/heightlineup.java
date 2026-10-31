public class HeightLineUp {

    // Helper method to print the array in the required format
    public static void printArray(int[] arr) {
        System.out.print("[");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + (i < arr.length - 1 ? ", " : ""));
        }
        System.out.println("]");
    }

    // Method to sort heights and print passes
    public static void lineUp(int[] heights) {
        int n = heights.length;
        for (int i = 0; i < n - 1; i++) {
            boolean swapped = false;
            
            // Sweep from left to right, comparing adjacent elements
            for (int j = 0; j < n - i - 1; j++) {
                if (heights[j] > heights[j + 1]) {
                    // Swap adjacent elements
                    int temp = heights[j];
                    heights[j] = heights[j + 1];
                    heights[j + 1] = temp;
                    swapped = true;
                }
            }
            
            // Print the line after the sweep
            System.out.print("Pass " + (i + 1) + ": ");
            printArray(heights);
            
            // If no swaps were made, the array is already sorted; stop early
            if (!swapped) {
                break;
            }
        }
    }

    public static void main(String[] args) {
        System.out.println("Sample Input 1:");
        int[] heights1 = {4, 2, 5, 1};
        lineUp(heights1);

        System.out.println("\nSample Input 2:");
        int[] heights2 = {1, 3, 2, 4};
        lineUp(heights2);

        System.out.println("\nCustom Input Test:");
        int[] heightsCustom = {5, 3, 1, 4, 2};
        lineUp(heightsCustom);
    }
}