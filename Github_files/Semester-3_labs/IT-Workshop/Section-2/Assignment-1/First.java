import java.util.Scanner;

public class First {
    public static void main(String[] args) {
        // First part
        Scanner input = new Scanner(System.in);

        System.out.println("Enter First Number");
        int no1 = input.nextInt();
        System.out.println("Enter Second Number");
        int no2 = input.nextInt();
        input.close();
        int sum = no1 + no2;

        System.out.println("The sum is :" + sum);

        // Second Part

        System.out.println("Enter First Number");
        int no1 = input.nextInt();
        System.out.println("Enter Second Number");
        int no2 = input.nextInt();
        int sub = no1 - no2;

        System.out.println("The Ans is :" + sub);

        // Third part
        System.out.println("Enter First Number");
        int no1 = input.nextInt();
        System.out.println("Enter Second Number");
        int no2 = input.nextInt();
        int sum = no1 + no2, sub = no1 - no2;
        System.out.println("The addition of " + no1 + " and " + no2 + " is " + sum + " and when " + no1
                + " is subtracted from " + no2 + ",the result is " + sub);

    }
}
