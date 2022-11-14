import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

class Students implements Serializable {
    public String firstName;
    public String lastName;
    public int rollNo;
    public double cpi;
    public int age;

    Students(String firstName, String lastName, int rollNo, double cpi, int age) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.rollNo = rollNo;
        this.cpi = cpi;
        this.age = age;
    }
}

public class SerializationObj {

    static void serializeObj(Object object, String filename) {

        try {
            FileOutputStream fileOut = new FileOutputStream(filename);
            ObjectOutputStream out = new ObjectOutputStream(fileOut);
            out.writeObject(object);
            out.close();
            fileOut.close();
            System.out.println("Successfully Serialized the Object...");
        } catch (Exception e) {
            System.out.println(e);
            e.printStackTrace();
        }

    }

    @SuppressWarnings("unchecked")
    static ArrayList<Students> deserializeobj(String filename) {

        ArrayList<Students> studentsList = new ArrayList<Students>();
        try {
            FileInputStream fileIn = new FileInputStream(filename);
            ObjectInputStream in = new ObjectInputStream(fileIn);
            studentsList = (ArrayList<Students>) in.readObject();
            in.close();
            fileIn.close();
        } catch (IOException ex) {
            System.out.println(ex);
        } catch (ClassNotFoundException ex) {
            System.out.println(ex);
        }
        return studentsList;
    }

    public static void printwithM(ArrayList<Students> studentsList, char newChar) {
        for (Students user : studentsList) {
            if (user.firstName.charAt(0) == newChar) {
                System.out.println("-----------------------------------------------");
                System.out.println("\tfirstName : " + user.firstName);
                System.out.println("\tlastName : " + user.lastName);
                System.out.println("\trollNo : " + user.rollNo);
                System.out.println("\tCPI : " + user.cpi);
                System.out.println("\tAge : " + user.age);
                System.out.println("-----------------------------------------------");
            }
        }
    }

    public static void printWithAge(ArrayList<Students> studentsList, int age) {
        for (Students user : studentsList) {
            if (user.age < age) {
                System.out.println("-----------------------------------------------");
                System.out.println("\tfirstName : " + user.firstName);
                System.out.println("\tlastName : " + user.lastName);
                System.out.println("\trollNo : " + user.rollNo);
                System.out.println("\tCPI : " + user.cpi);
                System.out.println("\tAge : " + user.age);
                System.out.println("-----------------------------------------------");
            }
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Students student0 = new Students("Ronit", "Chinda", 2101174, 8.39, 19);
        Students student1 = new Students("Manish", "Chug", 2101130, 8.39, 19);
        Students student2 = new Students("Lakshay", "Chachra", 2101190, 8.39, 12);
        Students student3 = new Students("Himanshu", "Ahirwal", 2101084, 8.39, 10);
        Students student4 = new Students("Sahaj", "Gupta", 2101177, 8.39, 20);
        Students student5 = new Students("Harsh", "Bagri", 2101179, 8.39, 18);
        Students student6 = new Students("Mananswita", "Gupta", 2101170, 8.39, 15);
        Students student7 = new Students("Anant", "Sharma", 2101036, 8.39, 17);
        Students student8 = new Students("Satya", "Khushwaha", 2101185, 8.39, 18);
        Students student9 = new Students("Komal", "Jain", 2101102, 8.39, 19);
        ArrayList<Students> objectStudents = new ArrayList<Students>();

        objectStudents.add(student0);
        objectStudents.add(student1);
        objectStudents.add(student2);
        objectStudents.add(student3);
        objectStudents.add(student4);
        objectStudents.add(student5);
        objectStudents.add(student6);
        objectStudents.add(student7);
        objectStudents.add(student8);
        objectStudents.add(student9);

        serializeObj(objectStudents,
                "students.ser");
        ArrayList<Students> studentsList = new ArrayList<Students>();
        studentsList = deserializeobj(
                "students.ser");

        while (true) {
            System.out.println("-----------------------------------------------");
            System.out.println("\t1 - Based On FirstLetter");
            System.out.println("\t2 - Based On Age");
            System.out.println("\t3 - close()");
            System.out.println("-----------------------------------------------");
            System.out.print("Enter Choice : ");
            int choice = input.nextInt();
            input.nextLine();
            if (choice == 1) {
                System.out.print("Enter firstChar : ");
                char newchar = input.next().charAt(0);
                printwithM(studentsList, newchar);
            } else if (choice == 2) {
                System.out.print("Enter Age: ");
                int age = input.nextInt();
                input.nextLine();
                printWithAge(studentsList, age);
            } else if (choice == 3) {
                break;
            } else {
                System.out.println("Invalid Choice!");
            }
        }

        input.close();
    }

}
