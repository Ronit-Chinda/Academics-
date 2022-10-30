import java.util.Scanner;
import java.lang.Math;

public class First {
    public static void main(String[] args){
        Scanner input =new Scanner(System.in);
        int n=input.nextInt();
        int counter = (int) (Math.log(n) / Math.log(2));
        int []flag;
        flag = new int[n+1];
        for (int i = 1; i <= n; i++) {  
            flag[i] = 1;
        }
        int temp = 1;
        
        for (int j = 0; j < counter ; j++) {
            for (int i = 1; i <= n; i++) {
                if (temp == 1 && flag[i] == 1) {
                    flag[i] = 0; 
                    temp = 0;
                } else if (flag[i] == 1) {
                    temp = 1;
                } else
                    continue;
            }
        }
        
        int ans = 0;
        
        for (int i = 1; i <= n; i++) {
            if (flag[i] == 1) {
                ans = i;
            }
        }
        
        System.out.println(ans);
        input.close();
    }
}

