import java.util.Scanner;

public class Seventh {
    public static void main(String[] args) {
        System.out.println("Set of integer = [1,2,3,4,5]");
        Scanner input = new Scanner(System.in);
        int number = input.nextInt();
        input.close();
        switch (number) {
            case 1:
                System.out.println("Entered number is 1");
                break;
            case 2:
                System.out.println("Entered number is 2");
                break;
            case 3:
                System.out.println("Entered number is 3");
                break;
            case 4:
                System.out.println("Entered number is 4");
                break;
            case 5:
                System.out.println("Entered number is 5");
                break;
            default:
                System.out.println("Entered number is " + number + " and it doesnot belong to the set!");
                break;
        }
    }
}
