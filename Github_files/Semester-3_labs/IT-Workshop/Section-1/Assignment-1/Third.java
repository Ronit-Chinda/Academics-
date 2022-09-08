import java.util.Scanner;

public class Third {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        for (int i = 1; i <= 5; i++) {
            System.out.println("Enter details for student " + i);
            System.out.println("Enter marks for first subject");
            int subject1 = input.nextInt();
            System.out.println("Enter marks for first subject");
            int subject2 = input.nextInt();
            System.out.println("Enter marks for first subject");
            int subject3 = input.nextInt();
            input.close();
            int avg = (subject1 + subject2 + subject3) / 3;
            if (avg > 60) {
                System.out.println("Good");
            }
            else if (avg < 60 && avg > 30) {
                System.out.println("Ok");
            }
            else {
                System.out.println("Poor");
            }
        }
    }
}
