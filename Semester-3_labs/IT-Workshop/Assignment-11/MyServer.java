import java.net.*;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.*;

class MyServer {

    public static String FileInfo(Scanner file, String path) {
        ArrayList<String> words = new ArrayList<>();
        int wordCount = 0;
        int numberOfLines = 0;
        while (file.hasNextLine()) {
            String[] line = file.nextLine().split(" ");
            for (String word : line) {
                words.add(word);
            }
            wordCount = wordCount + words.size();
            numberOfLines++;
        }

        return ("\t Word Count : " + Integer.toString(wordCount) + "\n" + "\t Line Count : "
                + Integer.toString(numberOfLines) + "\n" + "\t Absolute path : " + path);
    }

    public static void main(String args[]) throws Exception {
        try {

            ServerSocket ss = new ServerSocket(3333);
            Socket s = ss.accept();
            System.out.println("Client Connected...");
            DataInputStream in = new DataInputStream(s.getInputStream());
            DataOutputStream out = new DataOutputStream(s.getOutputStream());
            String[] flist = (new File(".")).list();

            String str;
            str = (String) in.readUTF();
            if (str.equals("-1")) {
                out.writeUTF("Successfully Aborted!");
            } else {
                try {
                    File newfile = new File(str);
                    String absolute = newfile.getAbsolutePath();
                    Scanner file = new Scanner(newfile);
                    System.out.println("File Found...");
                    out.writeUTF(FileInfo(file, absolute));

                }

                catch (FileNotFoundException e) {
                    System.out.println("File Not Found...");
                    out.writeUTF("-1");
                    String[] files = new String[3];
                    int i = 0;
                    for (String name : flist) {
                        System.out.println(name);
                        if ((new File(name)).isFile()) {
                            if (name.substring(0, 2).equals(str.substring(0, 2))) {
                                files[i] = name;
                                i++;
                            }
                        }
                    }
                    out.writeUTF(files[0] + " " + files[1] + " " + files[2]);
                    String choice = (String) in.readUTF();

                    if (choice.equals("-1")) {
                        out.writeUTF("Successfully Aborted!");
                    } else {
                        for (String string : files) {
                            if (choice.equals(string)) {
                                File newfile = new File(string);
                                String absolute = newfile.getAbsolutePath();
                                Scanner secondFileScanner = new Scanner(newfile);
                                out.writeUTF(FileInfo(secondFileScanner, absolute));
                                secondFileScanner.close();
                                break;
                            }
                        }
                    }

                }

            }

            in.close();
            s.close();
            ss.close();
        } catch (Exception e) {
            System.out.println(e);
            e.printStackTrace();
        }
    }

}
