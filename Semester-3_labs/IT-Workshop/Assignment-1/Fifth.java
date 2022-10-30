import java.util.Scanner;

public class Fifth {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the number");
        
        int number = input.nextInt(), sum = 0;
        input.close();
        while (number != 0) {
            int x = number % 10;
            sum += x;
            number = number / 10;
        }
        System.out.println("The Sum of digit is : " + sum);
    }
}
