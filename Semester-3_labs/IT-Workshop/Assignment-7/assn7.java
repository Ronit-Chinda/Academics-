import java.util.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;

abstract class User {

    protected String name;
    protected Date dateOfBirth;
    protected String userId;

    public void setDetails() throws ParseException {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter Name : ");
        String name = input.nextLine();

        System.out.print("Enter DateOfBirth (dd/MM/yyyy) : ");
        String date = input.nextLine();
        SimpleDateFormat formatter1 = new SimpleDateFormat("dd/MM/yyyy");
        Date dateOfBirth = formatter1.parse(date);

        this.name = name;
        this.dateOfBirth = dateOfBirth;

    }

    public void showDetails(int birthYear) throws ParseException {
        if (this.dateOfBirth.getYear() + 1900 == birthYear) {
            System.out.println("\tName : " + name);
            System.out.println("\tBirth-Year : " + dateOfBirth);
            System.out.println("\tUser-Id : " + userId);
        }
    }
}

final class Student extends User {
    private int rollno;
    private int semester;
    private float cpi;
    
    Student() {

    }

    final public Boolean checkrollno(int rollno) {
        if (this.rollno == rollno) {
            return true;
        }
        return false;
    }

    final public Boolean checkuserId(String userId) {
        if (this.userId.equals(userId)) {
            return true;
        }
        return false;
    }

    final public int getrollno() {
        return this.rollno;
    }

    Student(String name, Date dateOfBirth, String userId, int rollno, int semester, float cpi) {
        this.name = name;
        this.dateOfBirth = dateOfBirth;
        this.userId = userId;
        this.rollno = rollno;
        this.semester = semester;
        this.cpi = cpi;
    }

    final public String getuserId() {
        return this.userId;
    }

    final public void setDetails(Student arr[]) throws ParseException {

        Scanner input = new Scanner(System.in);
        super.setDetails();

        Boolean flag = false, flag2 = false;

        System.out.print("Enter User-Id : ");
        String userId = input.nextLine();

        while (true) {

            for (int i = 0; i < arr.length; i++) {
                if (arr[i] == null) {
                    break;
                }
                if (arr[i].getuserId() != null) {
                    if (arr[i].getuserId().equals(userId)) {
                        System.out.println("User-Id already exist!");
                        flag2 = true;
                    }
                }
            }

            if (flag2 == false) {
                this.userId = userId;
                break;
            }

            System.out.print("Enter User-Id : ");
            userId = input.nextLine();
            flag2 = false;
        }

        System.out.print("Enter Roll-No : ");
        int rollno = input.nextInt();
        input.nextLine();

        while (true) {

            for (int i = 0; i < arr.length; i++) {
                if (arr[i] == null) {
                    continue;
                }

                if (arr[i].getrollno() == rollno) {
                    System.out.println("Rollno already exist!");
                    flag = true;
                }
            }

            if (flag == false) {
                this.rollno = rollno;
                break;
            }

            System.out.print("Enter Roll-No : ");
            rollno = input.nextInt();
            input.nextLine();
            flag = false;
        }

        System.out.print("Enter Semester : ");
        int semester = input.nextInt();
        input.nextLine();

        System.out.print("Enter CPI : ");
        float cpi = input.nextFloat();
        input.nextLine();

        this.semester = semester;
        this.cpi = cpi;

    }

    final public void showDetails(int birthYear) throws ParseException {
        if (this.dateOfBirth.getYear() + 1900 == birthYear) {
            System.out.println("--------------------------------------------------------------");
            super.showDetails((this.dateOfBirth.getYear() + 1900));
            System.out.println("\tRoll-No : " + rollno);
            System.out.println("\tSemester : " + semester);
            System.out.println("\tCPI : " + cpi);
            System.out.println("--------------------------------------------------------------");
        }

    }

    final public void detailsforuserId(String userId) throws ParseException {
        if (this.userId.equals(userId)) {
            System.out.println("--------------------------------------------------------------");
            super.showDetails((this.dateOfBirth.getYear() + 1900));
            System.out.println("\tRoll-No : " + rollno);
            System.out.println("\tSemester : " + semester);
            System.out.println("\tCPI : " + cpi);
            System.out.println("--------------------------------------------------------------");
        }
    }

    final public void detailsforRollno(int rollno) throws ParseException {
        if (this.rollno == rollno) {
            System.out.println("--------------------------------------------------------------");
            super.showDetails((this.dateOfBirth.getYear() + 1900));
            System.out.println("\tRoll-No : " + rollno);
            System.out.println("\tSemester : " + semester);
            System.out.println("\tCPI : " + cpi);
            System.out.println("--------------------------------------------------------------");
        }
    }
}

final class Faculty extends User {
    private String employeeId;
    private String departmentName;
    private int noOfPublications;

    Faculty() {

    }

    Faculty(String name, Date dateOfBirth, String userId, String employeeId, String departmentName,
            int noOfPublications) {
        this.name = name;
        this.dateOfBirth = dateOfBirth;
        this.userId = userId;
        this.employeeId = employeeId;
        this.departmentName = departmentName;
        this.noOfPublications = noOfPublications;
    }

    final public String getemployeeId() {
        return this.employeeId;
    }

    final public Boolean checkemployeeId(String employeeId) {
        if (this.employeeId.equals(employeeId)) {
            return true;
        }
        return false;
    }

    final public Boolean checkuserId(String userId) {
        if (this.userId.equals(userId)) {
            return true;
        }
        return false;
    }

    final public void setDetails(Faculty arr[]) throws ParseException {
        Scanner input = new Scanner(System.in);
        super.setDetails();
        Boolean flag = false, flag2 = false;

        System.out.print("Enter User-Id : ");
        String userId = input.nextLine();

        while (true) {

            for (int i = 0; i < arr.length; i++) {
                if (arr[i] == null) {
                    break;
                }
                if (arr[i].getuserId() != null) {
                    if (arr[i].getuserId().equals(userId)) {
                        System.out.println("User-Id already exist!");
                        flag2 = true;
                    }
                }
            }

            if (flag2 == false) {
                this.userId = userId;
                break;
            }

            System.out.print("Enter User-Id : ");
            userId = input.nextLine();
            flag2 = false;
        }

        System.out.print("Enter Employee-Id : ");
        String employeeId = input.nextLine();

        while (true) {

            for (int i = 0; i < arr.length; i++) {
                if (arr[i] == null) {
                    break;
                }
                if (arr[i].getemployeeId() != null) {
                    if (arr[i].getemployeeId().equals(employeeId)) {
                        System.out.println("Employee-Id already exist!");
                        flag = true;
                    }
                }
            }

            if (flag == false) {
                this.userId = userId;
                break;
            }

            System.out.print("Enter Employee-Id : ");
            employeeId = input.nextLine();
            flag = false;
        }

        System.out.print("Enter DepartmentName : ");
        String departmentName = input.nextLine();

        System.out.print("Enter NoOfPublications : ");
        int noOfPublications = input.nextInt();
        input.nextLine();

        this.employeeId = employeeId;
        this.departmentName = departmentName;
        this.noOfPublications = noOfPublications;

    }

    final public void showDetails(int birthYear) throws ParseException {
        if (this.dateOfBirth.getYear() + 1900 == birthYear) {
            System.out.println("--------------------------------------------------------------");
            super.showDetails((this.dateOfBirth.getYear() + 1900));
            System.out.println("\tEmployee-ID : " + employeeId);
            System.out.println("\tDepartmentName : " + departmentName);
            System.out.println("\tNoOfPublications  : " + noOfPublications);
            System.out.println("--------------------------------------------------------------");

        }

    }

    final public void detailsforuserId(String userId) throws ParseException {
        if (this.userId.equals(userId)) {
            System.out.println("--------------------------------------------------------------");
            super.showDetails((this.dateOfBirth.getYear() + 1900));
            System.out.println("\tEmployeeID : " + employeeId);
            System.out.println("\tDepartmentName : " + departmentName);
            System.out.println("\tNoOfPublications  : " + noOfPublications);
            System.out.println("--------------------------------------------------------------");
        }
    }

    final public void detailsforemployeeId(String employeeId) throws ParseException {
        if (this.userId.equals(employeeId)) {
            System.out.println("--------------------------------------------------------------");
            super.showDetails((this.dateOfBirth.getYear() + 1900));
            System.out.println("\tEmployeeID : " + employeeId);
            System.out.println("\tDepartmentName : " + departmentName);
            System.out.println("\tNoOfPublications  : " + noOfPublications);
            System.out.println("--------------------------------------------------------------");
        }
    }

    final public String getuserId() {
        return this.userId;
    }

    final public void checkDepartment(Faculty f1, Faculty f2) {
        if (f1.departmentName.equals(f2.departmentName)) {
            System.out.println("Same department!");
        } else {
            System.out.println("Different department!");
        }
    }
}

final class Staff extends User {
    private String employeeId;
    private String sectionName;
    private String designation;

    Staff() {

    }

    Staff(String name, Date dateOfBirth, String userId, String employeeId, String sectionName, String designation) {
        this.name = name;
        this.userId = userId;
        this.dateOfBirth = dateOfBirth;
        this.employeeId = employeeId;
        this.sectionName = sectionName;
        this.designation = designation;
    }

    final public String getuserId() {
        return this.userId;
    }

    final public String getemployeeId() {
        return this.employeeId;
    }

    final public Boolean checkemployeeId(String employeeId) {
        if (this.employeeId.equals(employeeId)) {
            return true;
        }
        return false;
    }

    final public Boolean checkuserId(String userId) {
        if (this.userId.equals(userId)) {
            return true;
        }
        return false;
    }

    final public void setDetails(Staff arr[]) throws ParseException {
        Scanner input = new Scanner(System.in);
        super.setDetails();

        Boolean flag = false, flag2 = false;

        System.out.print("Enter User-Id : ");
        String userId = input.nextLine();

        while (true) {

            for (int i = 0; i < arr.length; i++) {
                if (arr[i] == null) {
                    break;
                }
                if (arr[i].getuserId() != null) {
                    if (arr[i].getuserId().equals(userId)) {
                        System.out.println("User-Id already exist!");
                        flag2 = true;
                    }
                }
            }

            if (flag2 == false) {
                this.userId = userId;
                break;
            }

            System.out.print("Enter User-Id : ");
            userId = input.nextLine();
            flag2 = false;
        }

        System.out.print("Enter Employee-Id : ");
        String employeeId = input.nextLine();

        while (true) {

            for (int i = 0; i < arr.length; i++) {
                if (arr[i] == null) {
                    break;
                }
                if (arr[i].getemployeeId() != null) {
                    if (arr[i].getemployeeId().equals(employeeId)) {
                        System.out.println("Employee-Id already exist!");
                        flag = true;
                    }
                }
            }

            if (flag == false) {
                this.userId = userId;
                break;
            }

            System.out.print("Enter Employee-Id : ");
            employeeId = input.nextLine();
            flag = false;
        }

        System.out.print("Enter SectionName : ");
        String sectionName = input.nextLine();

        System.out.print("Enter Designation : ");
        String designation = input.nextLine();

        this.employeeId = employeeId;
        this.sectionName = sectionName;
        this.designation = designation;
    }

    final public void showDetails(int birthYear) throws ParseException {
        if (this.dateOfBirth.getYear() + 1900 == birthYear) {
            System.out.println("--------------------------------------------------------------");
            super.showDetails((this.dateOfBirth.getYear() + 1900));
            System.out.println("\tEmployeeID : " + employeeId);
            System.out.println("\tSectionName : " + sectionName);
            System.out.println("\tDesignation  : " + designation);
            System.out.println("--------------------------------------------------------------");

        }

    }

    final public void detailsforuserId(String userId) throws ParseException {
        if (this.userId.equals(userId)) {
            System.out.println("--------------------------------------------------------------");
            super.showDetails((this.dateOfBirth.getYear() + 1900));
            System.out.println("\tEmployeeID : " + employeeId);
            System.out.println("\tSectionName : " + sectionName);
            System.out.println("\tDesignation  : " + designation);
            System.out.println("--------------------------------------------------------------");

        }
    }

    public void detailsforemployeeId(String employeeId) throws ParseException {
        if (this.employeeId.equals(employeeId)) {
            System.out.println("--------------------------------------------------------------");
            super.showDetails((this.dateOfBirth.getYear() + 1900));
            System.out.println("\tEmployeeID : " + employeeId);
            System.out.println("\tSectionName : " + sectionName);
            System.out.println("\tDesignation  : " + designation);
            System.out.println("--------------------------------------------------------------");

        }
    }

    final public void checkDesignation(Staff s1, Staff s2) {
        if (s1.designation.equals(s2.designation)) {
            System.out.println("Same Designation!");
        } else {
            System.out.println("Different Designation!");
        }
    }
}

public class assn7 {

    public static void main(String[] args) throws ParseException {

        Scanner input = new Scanner(System.in);

        Student[] student = new Student[100];
        Faculty[] faculty = new Faculty[100];
        Staff[] staff = new Staff[100];
        System.out.println("\t Welcome Sir! to IIITG DataBase");

        int i = 0, k = 0, l = 0;
        while (true) {
            System.out.println("--------------------------------------------------------------");
            System.out.println("\t\t0 - User");
            System.out.println("\t\t1 - Faculty");
            System.out.println("\t\t2 - Student");
            System.out.println("\t\t3 - Staff");
            System.out.println("\t\t4 - Exit");
            System.out.println("--------------------------------------------------------------");
            System.out.print("Enter Your Choice : ");
            int choice = input.nextInt();
            input.nextLine();
            if (choice == 0) {
                System.out.println("Object of an abstract class cannot be created");
            } else if (choice == 1) {
                System.out.println("--------------------------------------------------------------");
                System.out.println("\t\t0 - setvaluesByConstructor()");
                System.out.println("\t\t1 - setDetails()");
                System.out.println("\t\t2 - ShowDetails()");
                System.out.println("\t\t3 - displayDetails()");
                System.out.println("\t\t4 - compareDepartment()");
                System.out.println("\t\t5 - backToHome()");
                System.out.println("--------------------------------------------------------------");

                System.out.print("Enter Your Choice : ");
                int choice1 = input.nextInt();
                input.nextLine();
                if (choice1 == 0) {
                    System.out.print("Enter Name : ");
                    String name = input.nextLine();

                    System.out.print("Enter DateOfBirth (dd/MM/yyyy) : ");
                    String date = input.nextLine();
                    SimpleDateFormat formatter1 = new SimpleDateFormat("dd/MM/yyyy");
                    Date dateOfBirth = formatter1.parse(date);

                    System.out.print("Enter User-Id : ");
                    String userId = input.nextLine();
                    Boolean flag2 = false;

                    for (int j = 0; j < k; j++) {
                        flag2 = faculty[j].checkuserId(userId);
                        if (flag2) {
                            break;
                        }
                    }

                    System.out.print("Enter EmployeeId : ");
                    String employeeId = input.nextLine();
                    Boolean flag1 = false;

                    for (int j = 0; j < k; j++) {
                        flag1 = faculty[j].checkemployeeId(employeeId);
                        if (flag1) {
                            break;
                        }
                    }

                    System.out.print("Enter DepartmentName : ");
                    String departmentName = input.nextLine();

                    System.out.print("Enter NoOfPublications : ");
                    int noOfPublications = input.nextInt();
                    input.nextLine();
                    if (!flag1 && !flag2) {
                        Faculty object = new Faculty(name, dateOfBirth, userId, employeeId, departmentName,
                                noOfPublications);
                        faculty[k] = object;
                        k++;
                    } else if (flag1) {
                        System.out.println("Employee-Id already exist!");
                    } else if (flag2) {
                        System.out.println("User-Id already exist!");

                    }
                } else if (choice1 == 1) {
                    Faculty object = new Faculty();
                    faculty[k] = object;
                    faculty[k].setDetails(faculty);
                    k++;
                } else if (choice1 == 2) {
                    System.out.print("Enter the Birth-Year to get the details : ");
                    int year = input.nextInt();
                    input.nextLine();

                    for (int j = 0; j < k; j++) {
                        faculty[j].showDetails(year);
                    }

                } else if (choice1 == 3) {

                    System.out.println("--------------------------------------------------------------");
                    System.out.println("\t\t1 - Based on User-Id");
                    System.out.println("\t\t2 - Based on Employee-Id");
                    System.out.println("\t\t3 - Based on Birth-Year");
                    System.out.println("\t\t4 - backToHome()");
                    System.out.println("--------------------------------------------------------------");
                    System.out.print("Enter Your Choice : ");
                    int choice2 = input.nextInt();
                    input.nextLine();

                    if (choice2 == 1) {
                        System.out.print("Enter User-Id : ");
                        String userId = input.nextLine();
                        for (int j = 0; j < k; j++) {
                            faculty[j].detailsforuserId(userId);
                        }
                    } else if (choice2 == 2) {
                        System.out.print("Enter Employee-Id : ");
                        String employeeId = input.nextLine();
                        for (int j = 0; j < k; j++) {
                            faculty[j].detailsforemployeeId(employeeId);
                        }
                    } else if (choice2 == 3) {
                        System.out.print("Enter Birth-Year : ");
                        int dateOfBirth = input.nextInt();
                        input.nextLine();
                        for (int j = 0; j < k; j++) {
                            faculty[j].showDetails(dateOfBirth);
                        }
                    }
                } else if (choice1 == 4) {
                    System.out.print("Enter User-Id of User 1 : ");
                    String id1 = input.nextLine();
                    System.out.print("Enter User-Id of User 2 : ");
                    String id2 = input.nextLine();

                    Faculty f1 = null, f2 = null;

                    for (int j = 0; j < k; j++) {
                        if (faculty[j] == null) {
                            continue;
                        }
                        if (id1.equals(faculty[j].getuserId())) {
                            f1 = faculty[j];
                        }
                    }
                    for (int j = 0; j < k; j++) {
                        if (faculty[j] == null) {
                            continue;
                        }

                        if (id2.equals(faculty[j].getuserId())) {
                            f2 = faculty[j];
                        }
                    }
                    if (f1 != null && f2 != null) {
                        f1.checkDepartment(f1, f2);
                    }

                }

            } else if (choice == 2) {
                System.out.println("--------------------------------------------------------------");
                System.out.println("\t\t0 - setvaluesByConstructor()");
                System.out.println("\t\t1 - setDetails()");
                System.out.println("\t\t2 - showDetails()");
                System.out.println("\t\t3 - displayDetails()");
                System.out.println("\t\t5 - backToHome()");
                System.out.println("--------------------------------------------------------------");

                System.out.print("Enter Your Choice : ");
                int choice1 = input.nextInt();
                input.nextLine();
                if (choice1 == 0) {

                    System.out.print("Enter Name : ");
                    String name = input.nextLine();

                    System.out.print("Enter DateOfBirth (dd/MM/yyyy) : ");
                    String date = input.nextLine();
                    SimpleDateFormat formatter1 = new SimpleDateFormat("dd/MM/yyyy");
                    Date dateOfBirth = formatter1.parse(date);

                    System.out.print("Enter User-Id : ");
                    String userId = input.nextLine();
                    Boolean flag2 = false;
                    for (int j = 0; j < i; j++) {
                        flag2 = student[j].checkuserId(userId);
                        if (flag2) {
                            break;
                        }
                    }

                    System.out.print("Enter Roll-No : ");
                    int rollno = input.nextInt();
                    input.nextLine();
                    Boolean flag1 = false;
                    for (int j = 0; j < i; j++) {
                        flag1 = student[j].checkrollno(rollno);
                        if (flag1) {
                            break;
                        }
                    }

                    System.out.print("Enter Semester : ");
                    int semester = input.nextInt();
                    input.nextLine();

                    System.out.print("Enter CPI : ");
                    float cpi = input.nextFloat();
                    input.nextLine();

                    if (!flag1 && !flag2) {
                        Student object = new Student(name, dateOfBirth, userId, rollno, semester, cpi);
                        student[i] = object;
                        i++;
                    } else if (flag1) {
                        System.out.println("Roll-No already exist!");
                    } else if (flag2) {
                        System.out.println("User-Id already exist!");
                    }
                } else if (choice1 == 1) {
                    Student object = new Student();
                    student[i] = object;
                    student[i].setDetails(student);

                    i++;
                } else if (choice1 == 2) {
                    System.out.print("Enter the Birth-Year to get the details : ");
                    int year = input.nextInt();
                    for (int j = 0; j < i; j++) {
                        student[j].showDetails(year);
                    }

                } else if (choice1 == 3) {
                    System.out.println("--------------------------------------------------------------");
                    System.out.println("\t\t1 - Based on User-Id");
                    System.out.println("\t\t2 - Based on Roll-No");
                    System.out.println("\t\t3 - Based on Birth-Year");
                    System.out.println("\t\t4 - backToHome()");
                    System.out.println("--------------------------------------------------------------");
                    System.out.print("Enter Your Choice : ");
                    int choice2 = input.nextInt();
                    input.nextLine();

                    if (choice2 == 1) {
                        System.out.print("Ener User-Id : ");
                        String userId = input.nextLine();
                        for (int j = 0; j < i; j++) {
                            student[j].detailsforuserId(userId);
                        }
                    } else if (choice2 == 2) {
                        System.out.print("Enter Roll-No : ");
                        int rollno = input.nextInt();
                        input.nextLine();
                        for (int j = 0; j < i; j++) {
                            student[j].detailsforRollno(rollno);
                        }
                    } else if (choice2 == 3) {
                        System.out.print("Enter Birth-Year : ");
                        int dateOfBirth = input.nextInt();
                        input.nextLine();

                        for (int j = 0; j < i; j++) {
                            student[j].showDetails(dateOfBirth);
                        }
                    }
                }

            } else if (choice == 3) {
                System.out.println("--------------------------------------------------------------");
                System.out.println("\t\t0 - setvaluesByConstructor()");
                System.out.println("\t\t1 - setDetails()");
                System.out.println("\t\t2 - ShowDetails()");
                System.out.println("\t\t3 - displayDetails()");
                System.out.println("\t\t4 - compareDesignation()");
                System.out.println("\t\t5 - backToHome()");
                System.out.println("--------------------------------------------------------------");

                System.out.print("Enter Your Choice : ");
                int choice1 = input.nextInt();
                input.nextLine();
                if (choice1 == 0) {
                    System.out.print("Enter Name : ");
                    String name = input.nextLine();

                    System.out.print("Enter DateOfBirth (dd/MM/yyyy) : ");
                    String date = input.nextLine();
                    SimpleDateFormat formatter1 = new SimpleDateFormat("dd/MM/yyyy");
                    Date dateOfBirth = formatter1.parse(date);

                    System.out.print("Enter User-Id : ");
                    String userId = input.nextLine();
                    Boolean flag2 = false;
                    for (int j = 0; j < l; j++) {
                        flag2 = staff[j].checkuserId(userId);
                        if (flag2) {
                            break;
                        }
                    }

                    System.out.print("Enter EmployeeId : ");
                    String employeeId = input.nextLine();
                    Boolean flag1 = false;

                    for (int j = 0; j < l; j++) {
                        flag1 = staff[j].checkemployeeId(employeeId);
                        if (flag1) {
                            break;
                        }
                    }

                    System.out.print("Enter SectionName : ");
                    String sectionName = input.nextLine();

                    System.out.print("Enter Designation : ");
                    String designation = input.nextLine();

                    if (!flag1 && !flag2) {
                        Staff object = new Staff(name, dateOfBirth, userId, employeeId, sectionName, designation);
                        staff[l] = object;
                        l++;
                    } else if (flag1) {
                        System.out.println("Employee-Id already exist!");
                    } else if (flag2) {
                        System.out.println("User-Id already exist!");

                    }
                } else if (choice1 == 1) {
                    Staff object = new Staff();

                    staff[l] = object;
                    staff[l].setDetails(staff);
                    l++;
                } else if (choice1 == 2) {
                    System.out.print("Enter the Birth-Year to get the details : ");
                    int year = input.nextInt();
                    input.nextLine();
                    for (int j = 0; j < l; j++) {
                        staff[j].showDetails(year);
                    }
                } else if (choice1 == 3) {
                    System.out.println("--------------------------------------------------------------");
                    System.out.println("\t\t1 - Based on User-Id");
                    System.out.println("\t\t2 - Based on Employee-Id");
                    System.out.println("\t\t3 - Based on Birth-Year");
                    System.out.println("\t\t4 - backToHome()");
                    System.out.println("--------------------------------------------------------------");
                    System.out.print("Enter Your Choice : ");
                    int choice2 = input.nextInt();
                    input.nextLine();
                    if (choice2 == 1) {
                        System.out.print("Enter User-ID : ");
                        String userId = input.nextLine();
                        for (int j = 0; j < l; j++) {
                            staff[j].detailsforuserId(userId);
                        }
                    } else if (choice2 == 2) {
                        System.out.print("Enter Employee-Id : ");
                        String employeeId = input.nextLine();
                        for (int j = 0; j < l; j++) {
                            staff[j].detailsforemployeeId(employeeId);
                        }
                    } else if (choice2 == 3) {
                        System.out.print("Enter Birth-Year : ");
                        int dateOfBirth = input.nextInt();
                        input.nextLine();
                        for (int j = 0; j < l; j++) {
                            staff[j].showDetails(dateOfBirth);
                        }
                    }

                } else if (choice1 == 4) {
                    System.out.print("Enter UserId of user 1 : ");
                    String id1 = input.nextLine();
                    System.out.print("Enter UserId of user 2 : ");
                    String id2 = input.nextLine();
                    Staff s1 = null, s2 = null;

                    for (int j = 0; j < l; j++) {
                        if (staff[j] == null) {
                            continue;
                        }
                        if (id1.equals(staff[j].getuserId())) {
                            s1 = staff[j];
                        }
                    }
                    for (int j = 0; j < l; j++) {
                        if (staff[j] == null) {
                            continue;
                        }

                        if (id2.equals(staff[j].getuserId())) {
                            s2 = staff[j];
                        }
                    }
                    if (s1 != null && s2 != null) {
                        s1.checkDesignation(s1, s2);
                    }

                }

            }

            else if (choice == 4) {
                break;
            } else {
                System.out.println("Invalid Choice!");
            }
        }
        input.close();
    }
}
