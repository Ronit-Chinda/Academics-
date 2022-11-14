import java.net.*;
import java.util.Scanner;
import java.io.*;

class MyClient {
    public static void main(String args[]) throws Exception {
        Scanner input = new Scanner(System.in);
        Socket s = new Socket("localhost", 3333);
        System.out.println("Successfully connected to the server!");
        DataInputStream in = new DataInputStream(s.getInputStream());
        DataOutputStream out = new DataOutputStream(s.getOutputStream());
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str2;
        System.out.print("Enter fileName() or -1 to abort : ");
        String str = br.readLine();
        out.writeUTF(str);
        out.flush();

        str2 = (String) in.readUTF();
        if (str2.equals("-1")) {
            System.out.println("File not found!");
            System.out.println("Similar Files : " + in.readUTF());
            System.out.print("Enter fileName() or -1 to abort : ");
            String choice = input.nextLine();
            out.writeUTF(choice);
            System.out.println(in.readUTF());

        } else {
            System.out.println(str2);
        }

        in.close();
        out.close();
        s.close();
        input.close();
    }
}