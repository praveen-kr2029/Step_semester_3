public import java.util.Scanner;

public class PalindromeNum {
    public static void main(String[] args) {

        int num = 2002;

        int temp = num;  //temp = 121

        int rev = 0;

        while(num>0){
            int last = num % 10;      // 123 % 10 = 3 -> last = 3  || 12%10 = 2 -> last = 2  || 1%10 = 1-> last = 1
            num = num/10;             // 123 / 10 = 12 -> num = 12 || 12 / 10 = 1 -> num = 1 || 1/10 = 0 -> num = 0
            rev = (rev * 10 ) + last; // 3 -> rev = 3              || (3*10) + 2 -> rev = 32 || rev = (32*10)+1 = 321
        }

        if(rev == temp){  //321 == 123
            System.out.println("The number is a palindrome number");
        }
        else{
            System.out.println("The number is not a palindrome number");
        }

    }
}


 {
    
}
