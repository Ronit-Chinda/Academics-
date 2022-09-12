import java.util.ArrayList;
import java.util.Scanner;

public class Task1 {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        ArrayList<String> arr = new ArrayList<String>();

        int i = 0;
        while (true) {
            System.out.println("\t -------------------");
            System.out.println("\t|1 - addString()    |");
            System.out.println("\t|2 - removeString() |");
            System.out.println("\t|3 - isEmpty()      |");
            System.out.println("\t|4 - modifyString() |");
            System.out.println("\t|5 - printall()     |");
            System.out.println("\t|6 - Exit()         |");
            System.out.println("\t -------------------");

            System.out.println("Enter your choice");
            int choice = input.nextInt();

            if (choice == 1) {
                System.out.println("Enter string to add : ");
                input.nextLine();
                String str = input.nextLine();
                arr.add(str);
                i++;
            } else if (choice == 2) {
                System.out.print("Enter string to remove : ");
                input.nextLine();
                String str = input.nextLine();
                arr.remove(str);
                i--;
            } else if (choice == 3) {
                if (i == 0) {
                    System.out.println("ArrayList is empty!");
                } else {
                    System.out.println("ArrayList is not empty!");
                }
            } else if (choice == 4) {
                System.out.println("Enter index to edit string");
                int index = input.nextInt();
                input.nextLine();
                String str = input.nextLine();
                arr.set(index, str);

            } else if (choice == 5) {

                for (int j = 0; j < i; j++) {
                    System.out.print(arr.get(j) + " ");
                }
                System.out.println();

            } else if (choice == 6) {
                break;
            } else {
                System.out.println("Invalid Choice!");
            }
        }

        input.close();
    }
}
