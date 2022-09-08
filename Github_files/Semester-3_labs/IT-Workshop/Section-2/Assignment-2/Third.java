import java.util.Scanner;

public class Third {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.println("Enter the size of array");
        int n = input.nextInt(),count=0;
        int[] arr = new int[n];
        int[] placement = new int[n];
        System.out.println("Enter the elements");
        for (int i = 0; i < arr.length; i++) {
            arr[i] = input.nextInt();
        }
        input.close();
        placement[0] = 0;
        for (int i = 1; i < placement.length; i++) {
            count = 0;
            for (int j = 0; j < i; j++) {
                if (arr[j] > arr[i]) {
                    count++;
                }
            }
            placement[i] = count;
        }
        for (int i = 0; i < placement.length; i++) {
            System.out.print(placement[i] + " ");
        }
        System.out.println();
        input.close();
        
    }
}
