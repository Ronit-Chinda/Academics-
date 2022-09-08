import java.util.Scanner;

public class Sixth {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the String");
        String str = input.nextLine();
        int count = 1;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == ' ') {
                count++;
            }
        }
        input.close();
        System.out.println("The string is");
        System.out.println(str);
        System.out.println("The total number of words in the sentence is " + count);

    }
}