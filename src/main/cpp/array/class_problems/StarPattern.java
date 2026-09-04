import java.util.Scanner;

public class StarPattern {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the number of rows you want: ");

        int rows = sc.nextInt();  //rows = 5


        for (int i = 1; i <= rows; i++) {   //outer for loop -> no of rows

            for (int j = 1; j <= i; j++) {  // printing number of stars
                System.out.print("*");
            }

            System.out.println();
        }

        sc.close();
    }
}

