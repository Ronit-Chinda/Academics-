import java.util.Scanner;

public class Second {
    static int check_palindrome(int n) {
        int k = n;
        int rev = 0;
        while (k != 0) {
            int rem = k % 10;
            rev = rev * 10 + rem;
            k = k / 10;
        }
        if (rev == n) {
            return 1;
        } 
            return 0;
        
    }

    static void print(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] +" ");
        }
        System.out.println();
    }

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.println("Enter the size of array");
        int n = input.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter the elements");
        for (int i = 0; i < arr.length; i++) {
            arr[i] = input.nextInt();
        }
        
        for (int i = 0; i < arr.length; i++) {
            
            while (check_palindrome(arr[i]) == 0) {
                arr[i] += 1; 
            }
 
        }
        
        print(arr);
        
        input.close();

    }
}
