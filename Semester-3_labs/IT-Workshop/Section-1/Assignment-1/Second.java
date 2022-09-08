import java.util.Scanner;

public class Second {
    public static void main(String[] args) {
        Scanner input= new Scanner(System.in);
        int max;
        System.out.println("Enter First Number");
        int no1 = input.nextInt();
        max = no1;
        System.out.println("Enter Second Number");
        int no2 = input.nextInt();
        if (max<no2) {
            max = no2;
        }
        System.out.println("Enter Third Number");
        int no3 = input.nextInt();
        if (max<no3) {
            max = no3;
        }
        System.out.println("Enter Fourth Number");
        int no4 = input.nextInt();
        if (max<no4) {
            max = no4;
        }
        System.out.println("Enter Fifth Number");
        int no5 = input.nextInt();
        if (max < no5) {
            max = no5;
        }
        input.close();
        System.out.println(max);
    }
}
