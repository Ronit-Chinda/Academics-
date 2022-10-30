import java.util.*;
import java.util.regex.*;

class User {

    protected String name;
    protected String pincode;
    protected String pan;
    protected String dateOfBirth;
    protected String email;

    public boolean isValidName(String name) {
        String regex = "^[A-Z]{1}[a-z]*";
        Pattern p = Pattern.compile(regex);
        if (name == null) {
            return false;
        }
        Matcher m = p.matcher(name);
        return m.matches();
    }

    public boolean isValidPinCode(String pincode) {
        String regex = "^[1-9]{1}[0-9]{5}";
        Pattern p = Pattern.compile(regex);
        if (pincode == null) {
            return false;
        }
        Matcher m = p.matcher(pincode);
        return m.matches();
    }

    public boolean isValidDOB(String dateOfBirth) {
        String regex = "^[0-1][0-9]/[0-3][0-9]/[0-9]{4}$";
        Pattern p = Pattern.compile(regex);
        if (dateOfBirth == null) {
            return false;
        }
        Matcher m = p.matcher(dateOfBirth);
        return m.matches();
    }

    public boolean isValidPAN(String pan) {
        String regex = "^[A-Z0-9]*$";
        Pattern p = Pattern.compile(regex);
        if (pan == null) {
            return false;
        }
        Matcher m = p.matcher(pan);
        return m.matches();
    }

    public boolean isValidMail(String email) {
        String regex = "^(.+)@(.+)$";
        Pattern p = Pattern.compile(regex);
        if (email == null) {
            return false;
        }
        Matcher m = p.matcher(email);
        return m.matches();
    }

    public void setDetails() {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter Name (First Letter must be Capital rest lower-case) : ");
        String name = input.nextLine();

        while (!isValidName(name)) {
            System.out.println("Invalid Name Please Re-Enter!");
            name = input.nextLine();
        }
        this.name = name;

        System.out.print("Enter DateOfBirth (mm/dd/yyyy) : ");
        String dateOfBirth = input.nextLine();

        while (!isValidDOB(dateOfBirth)) {
            System.out.println("Invalid DateOfBirth Please Re-Enter!");
            dateOfBirth = input.nextLine();
        }
        this.dateOfBirth = dateOfBirth;

        System.out.print("Enter Pincode : ");
        String pincode = input.nextLine();

        while (!isValidPinCode(pincode)) {
            System.out.println("Invalid Pincode Please Re-Enter!");
            pincode = input.nextLine();
        }
        this.pincode = pincode;

        System.out.print("Enter PAN number (Only Alphaneumeric with capital letters) : ");
        String pan = input.nextLine();
        while (!isValidPAN(pan)) {
            System.out.println("Invalid Please Re-Enter!");
            pan = input.nextLine();
        }
        this.pan = pan;

        System.out.print("Enter Email : ");
        String email = input.nextLine();

        while (!isValidMail(email)) {
            System.out.println("Invalid Please Re-Enter!");
            email = input.nextLine();
        }
        this.email = email;
    }

    public void showDetails(String dateOfBirth) {
        if (this.dateOfBirth.equals(dateOfBirth)) {

            System.out.println("\tName : " + name);
            System.out.println("\tDateOFBirth : " + dateOfBirth);
            System.out.println("\tPincode : " + pincode);
            System.out.println("\tEmail : " + email);
            System.out.println("\tPAN : " + pan);
        }
    }

    public void display() {
        System.out.println("\tName : " + name);
        System.out.println("\tDateOFBirth : " + dateOfBirth);
        System.out.println("\tPincode : " + pincode);
        System.out.println("\tEmail : " + email);
        System.out.println("\tPAN : " + pan);
    }
}

class Student extends User {

    private int rollno;
    private int semester;
    private float cpi;
    private String studentId;

    Student() {

    }

    final public int getrollNo() {
        return this.rollno;
    }

    final public void setDetails(ArrayList<User> students) {

        Scanner input = new Scanner(System.in);
        super.setDetails();

        Boolean flag = false;
        System.out.print("Enter Roll-No : ");
        int rollno = input.nextInt();
        input.nextLine();

        while (true) {

            for (User user : students) {
                if (user instanceof Student) {

                    if (((Student) user).getrollNo() == rollno) {
                        System.out.println("Rollno already exist!");
                        flag = true;
                    }
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

        System.out.print("Enter CPI : ");
        float cpi = input.nextFloat();
        input.nextLine();

        Boolean flag1 = false;
        System.out.print("Enter Student-Id : ");
        String studentId = input.nextLine();

        while (true) {

            for (User user : students) {
                if (user instanceof Student) {
                    if (((Student) user).getstudentId() != null) {
                        if (((Student) user).getstudentId().equals(studentId)) {
                            System.out.println("Student-Id already exist!");
                            flag1 = true;
                        }
                    }
                }
            }

            if (flag1 == false) {
                this.studentId = studentId;
                break;
            }

            System.out.print("Enter Student-Id : ");
            studentId = input.nextLine();
            flag1 = false;
        }

        this.semester = semester;
        this.cpi = cpi;
        this.studentId = studentId;
    }

    final public void showDetails(String dateOfbirth) {
        if (this.dateOfBirth.equals(dateOfbirth)) {
            System.out.println("--------------------------------------------------------------");
            super.showDetails(dateOfbirth);
            System.out.println("\tRoll-No : " + rollno);
            System.out.println("\tSemester : " + semester);
            System.out.println("\tCPI : " + cpi);
            System.out.println("--------------------------------------------------------------");
        }
    }

    public void detailsforstudentId(String studentId) {
        if (this.studentId.equals(studentId)) {
            System.out.println("--------------------------------------------------------------");
            super.showDetails(dateOfBirth);
            System.out.println("\tRoll-No : " + rollno);
            System.out.println("\tSemester : " + semester);
            System.out.println("\tCPI : " + cpi);
            System.out.println("\tStudent-Id : " + studentId);
            System.out.println("--------------------------------------------------------------");
        }
    }

    public void detailsforRollno(int rollno) {
        if (this.rollno == rollno) {
            System.out.println("--------------------------------------------------------------");
            super.showDetails(dateOfBirth);
            System.out.println("\tRoll-No : " + rollno);
            System.out.println("\tSemester : " + semester);
            System.out.println("\tCPI : " + cpi);
            System.out.println("\tStudent-Id : " + studentId);
            System.out.println("--------------------------------------------------------------");
        }
    }

    public void display() {
        System.out.println("--------------------------------------------------------------");
        super.display();
        System.out.println("\tRoll-No : " + rollno);
        System.out.println("\tSemester : " + semester);
        System.out.println("\tCPI : " + cpi);
        System.out.println("\tStudent-Id : " + studentId);
        System.out.println("--------------------------------------------------------------");

    }

    public int getbirthYear() {
        return Integer.parseInt(dateOfBirth.substring(6, 10));
    }

    public String getstudentId() {
        return this.studentId;
    }
}

class Faculty extends User {
    private String employeeId;
    private String departmentName;
    private int noOfPublications;

    Faculty() {

    }

    final public void setDetails(ArrayList<User> faculty) {
        Scanner input = new Scanner(System.in);
        super.setDetails();

        System.out.print("Enter DepartmentName : ");
        String departmentName = input.nextLine();

        System.out.print("Enter NoOfPublications : ");
        int noOfPublications = input.nextInt();
        input.nextLine();

        Boolean flag = false;
        System.out.print("Enter Employee-Id : ");
        String employeeId = input.nextLine();

        while (true) {

            for (User user : faculty) {
                if (user instanceof Faculty) {
                    if (((Faculty) user).getemployeeId() != null) {
                        if (((Faculty) user).getemployeeId().equals(employeeId)) {
                            System.out.println("Employee-Id already exist!");
                            flag = true;
                        }
                    }
                }
            }

            if (flag == false) {
                this.employeeId = employeeId;
                break;
            }

            System.out.print("Enter Employee-Id : ");
            employeeId = input.nextLine();
            flag = false;
        }

        this.departmentName = departmentName;
        this.noOfPublications = noOfPublications;

    }

    final public void showDetails(String dateOfBirth) {
        if (this.dateOfBirth.equals(dateOfBirth)) {
            System.out.println("--------------------------------------------------------------");
            super.showDetails(dateOfBirth);
            System.out.println("\tEmployee-ID : " + employeeId);
            System.out.println("\tDepartmentName : " + departmentName);
            System.out.println("\tNoOfPublications  : " + noOfPublications);
            System.out.println("--------------------------------------------------------------");
        }
    }

    final public void detailsforemployeeId(String employeeId) {
        if (this.employeeId.equals(employeeId)) {
            System.out.println("--------------------------------------------------------------");
            super.showDetails(dateOfBirth);
            System.out.println("\tEmployeeID : " + employeeId);
            System.out.println("\tDepartmentName : " + departmentName);
            System.out.println("\tNoOfPublications  : " + noOfPublications);
            System.out.println("--------------------------------------------------------------");
        }
    }

    public void checkDepartment(Faculty f1, Faculty f2) {

        if (f1.departmentName.equals(f2.departmentName)) {
            System.out.println("Same department!");
        } else {
            System.out.println("Different department!");
        }
    }

    public String getemployeeId() {
        return this.employeeId;
    }

    public void display() {
        System.out.println("--------------------------------------------------------------");
        super.display();
        System.out.println("\tEmployeeID : " + employeeId);
        System.out.println("\tDepartmentName : " + departmentName);
        System.out.println("\tNoOfPublications  : " + noOfPublications);
        System.out.println("--------------------------------------------------------------");

    }

    public int getbirthYear() {
        return Integer.parseInt(dateOfBirth.substring(6, 10));
    }

}

class Staff extends User {
    private String employeeId;
    private String sectionName;
    private String designation;

    Staff() {

    }

    final public void setDetails(ArrayList<User> staff) {
        Scanner input = new Scanner(System.in);
        super.setDetails();

        Boolean flag = false;
        System.out.print("Enter Employee-Id : ");
        String employeeId = input.nextLine();

        while (true) {

            for (User user : staff) {
                if (user instanceof Staff) {
                    if (((Staff) user).getemployeeId() != null) {
                        if (((Staff) user).getemployeeId().equals(employeeId)) {
                            System.out.println("Employee-Id already exist!");
                            flag = true;
                        }
                    }
                }
            }

            if (flag == false) {
                this.employeeId = employeeId;
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

        this.sectionName = sectionName;
        this.designation = designation;
    }

    final public void showDetails(String dateOfBirth) {
        if (this.dateOfBirth.equals(dateOfBirth)) {
            System.out.println("--------------------------------------------------------------");
            super.showDetails(dateOfBirth);
            System.out.println("\tEmployeeID : " + employeeId);
            System.out.println("\tSectionName : " + sectionName);
            System.out.println("\tDesignation  : " + designation);
            System.out.println("--------------------------------------------------------------");
        }

    }

    final public void detailsforemployeeId(String employeeId) {
        if (this.employeeId.equals(employeeId)) {
            System.out.println("--------------------------------------------------------------");
            super.showDetails(dateOfBirth);
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

    public String getemployeeId() {
        return this.employeeId;
    }

    public void display() {
        System.out.println("--------------------------------------------------------------");
        super.display();
        System.out.println("\tEmployeeID : " + employeeId);
        System.out.println("\tSectionName : " + sectionName);
        System.out.println("\tDesignation  : " + designation);
        System.out.println("--------------------------------------------------------------");

    }

    public int getbirthYear() {
        return Integer.parseInt(dateOfBirth.substring(6, 10));
    }

}

class Sortbyroll implements Comparator<Student> {

    public int compare(Student a, Student b) {

        return a.getrollNo() - b.getrollNo();
    }
}

class sortbyemployeeId implements Comparator<Faculty> {
    public int compare(Faculty f1, Faculty f2) {
        return f1.getemployeeId().compareTo(f2.getemployeeId());
    }
}

class sortbyemployeestaffId implements Comparator<Staff> {
    public int compare(Staff f1, Staff f2) {
        return f1.getemployeeId().compareTo(f2.getemployeeId());
    }
}

class sortbybirthYearstudent implements Comparator<Student> {

    @Override
    public int compare(Student s1, Student s2) {
        return s1.getbirthYear() - s2.getbirthYear();
    }
}

class sortbybirthYearfaculty implements Comparator<Faculty> {

    @Override
    public int compare(Faculty s1, Faculty s2) {
        return s1.getbirthYear() - s2.getbirthYear();
    }
}

class sortbybirthYearstaff implements Comparator<Staff> {

    @Override
    public int compare(Staff s1, Staff s2) {
        return s1.getbirthYear() - s2.getbirthYear();
    }
}

class sortbystudentId implements Comparator<Student> {
    public int compare(Student f1, Student f2) {
        return f1.getstudentId().compareTo(f2.getstudentId());
    }
}

public class Validate {
    public static void main(String args[]) {

        Scanner input = new Scanner(System.in);
        ArrayList<User> DataBase = new ArrayList<>();
        ArrayList<Faculty> faculty = new ArrayList<>();
        ArrayList<Staff> staff = new ArrayList<>();
        ArrayList<Student> students = new ArrayList<>();
        while (true) {
            System.out.println("--------------------------------------------------------------");
            System.out.println("\t\t1 - Faculty");
            System.out.println("\t\t2 - Student");
            System.out.println("\t\t3 - Staff");
            System.out.println("\t\t4 - Exit");
            System.out.println("--------------------------------------------------------------");
            System.out.print("Enter Your Choice : ");
            int choice = input.nextInt();

            if (choice == 1) {
                System.out.println("--------------------------------------------------------------");
                System.out.println("\t\t1 - setDetails()");
                System.out.println("\t\t2 - showDetails()");
                System.out.println("\t\t3 - compareDepartment()");
                System.out.println("\t\t4 - sort()");
                System.out.println("\t\t5 - backToHome()");
                System.out.println("--------------------------------------------------------------");

                System.out.print("Enter Your Choice : ");
                int choice1 = input.nextInt();
                input.nextLine();

                if (choice1 == 1) {
                    Faculty facultyobj = new Faculty();
                    facultyobj.setDetails(DataBase);
                    DataBase.add(facultyobj);
                    faculty.add(facultyobj);
                } else if (choice1 == 2) {

                    System.out.println("--------------------------------------------------------------");
                    System.out.println("\t\t1 - Based on Employee-Id");
                    System.out.println("\t\t2 - Based on DateOfBirth");
                    System.out.println("\t\t3 - backToHome()");
                    System.out.println("--------------------------------------------------------------");
                    System.out.print("Enter Your Choice : ");
                    int choice2 = input.nextInt();
                    input.nextLine();

                    if (choice2 == 1) {
                        System.out.print("Enter Employee-Id : ");
                        String employeeId = input.nextLine();

                        for (User user : DataBase) {
                            if (user instanceof Faculty) {
                                ((Faculty) user).detailsforemployeeId(employeeId);
                            }
                        }

                    } else if (choice2 == 2) {
                        System.out.print("Enter DateOfBirth : ");
                        String dateOfBirth = input.nextLine();
                        for (User user : DataBase) {
                            if (user instanceof Faculty) {
                                user.showDetails(dateOfBirth);
                            }
                        }
                    }

                } else if (choice1 == 3) {
                    Faculty f1 = null, f2 = null;
                    System.out.print("Enter Employee-Id of User 1 : ");
                    String id1 = input.nextLine();
                    System.out.print("Enter Employee-Id of User 2 : ");
                    String id2 = input.nextLine();
                    for (User user : DataBase) {
                        if (user instanceof Faculty) {
                            if (id1.equals(((Faculty) user).getemployeeId())) {
                                f1 = ((Faculty) user);
                            }

                        }
                        if (user instanceof Faculty) {
                            if (id2.equals(((Faculty) user).getemployeeId())) {
                                f2 = ((Faculty) user);
                            }
                        }
                    }
                    if (f1 != null) {
                        f1.checkDepartment(f1, f2);
                    }

                    else {
                        System.out.println("Unable to fetch data");
                    }

                } else if (choice1 == 4) {
                    System.out.println("--------------------------------------------------------------");
                    System.out.println("\t\t1 - Based on Employee-ID");
                    System.out.println("\t\t2 - Based on birthYear");
                    System.out.println("\t\t3 - backToHome()");
                    System.out.println("--------------------------------------------------------------");
                    System.out.print("Enter Your Choice : ");
                    int choice3 = input.nextInt();
                    input.nextLine();

                    if (choice3 == 1) {
                        Collections.sort(faculty, new sortbyemployeeId());
                        for (Faculty user : faculty) {
                            user.display();
                        }
                    } else if (choice3 == 2) {
                        Collections.sort(faculty, new sortbybirthYearfaculty());
                        for (Faculty user : faculty) {
                            user.display();
                        }

                    }
                }

            } else if (choice == 2) {
                System.out.println("--------------------------------------------------------------");
                System.out.println("\t\t1 - setDetails()");
                System.out.println("\t\t2 - showDetails()");
                System.out.println("\t\t3 - sort()");
                System.out.println("\t\t4 - backToHome()");
                System.out.println("--------------------------------------------------------------");

                System.out.print("Enter Your Choice : ");
                int choice1 = input.nextInt();
                input.nextLine();
                if (choice1 == 1) {
                    Student studentobj = new Student();
                    studentobj.setDetails(DataBase);
                    DataBase.add(studentobj);
                    students.add(studentobj);
                } else if (choice1 == 2) {
                    System.out.println("--------------------------------------------------------------");
                    System.out.println("\t\t1 - Based on Student-Id");
                    System.out.println("\t\t2 - Based on DateOfBirth");
                    System.out.println("\t\t3 - backToHome()");
                    System.out.println("--------------------------------------------------------------");
                    System.out.print("Enter Your Choice : ");
                    int choice2 = input.nextInt();
                    input.nextLine();

                    if (choice2 == 1) {
                        System.out.print("Enter Student-Id : ");
                        String studentId = input.nextLine();
                        for (User user : DataBase) {
                            if (user instanceof Student) {
                                ((Student) user).detailsforstudentId(studentId);
                            }
                        }

                    } else if (choice2 == 2) {
                        System.out.print("Enter DateOfBirth : ");
                        String dateOfBirth = input.nextLine();
                        for (User user : DataBase) {
                            if (user instanceof Student) {
                                user.showDetails(dateOfBirth);
                            }
                        }
                    }
                } else if (choice1 == 3) {
                    System.out.println("--------------------------------------------------------------");
                    System.out.println("\t\t1 - Based on Roll-no");
                    System.out.println("\t\t2 - Based on birthYear");
                    System.out.println("\t\t3 - Based on Student-Id");
                    System.out.println("\t\t4 - backToHome()");
                    System.out.println("--------------------------------------------------------------");
                    System.out.print("Enter Your Choice : ");
                    int choice3 = input.nextInt();
                    input.nextLine();

                    if (choice3 == 1) {
                        Collections.sort(students, new Sortbyroll());
                        for (Student user : students) {
                            user.display();
                        }
                    } else if (choice3 == 2) {
                        Collections.sort(students, new sortbybirthYearstudent());
                        for (Student user : students) {
                            user.display();
                        }
                    } else if (choice3 == 3) {
                        Collections.sort(students, new sortbystudentId());
                        for (Student user : students) {
                            user.display();
                        }
                    }
                }
            } else if (choice == 3) {
                System.out.println("--------------------------------------------------------------");
                System.out.println("\t\t1 - setDetails()");
                System.out.println("\t\t2 - ShowDetails()");
                System.out.println("\t\t3 - compareDesignation()");
                System.out.println("\t\t4 - sort()");
                System.out.println("\t\t5 - backToHome()");
                System.out.println("--------------------------------------------------------------");

                System.out.print("Enter Your Choice : ");
                int choice1 = input.nextInt();
                input.nextLine();
                if (choice1 == 1) {
                    Staff staffobj = new Staff();
                    staffobj.setDetails(DataBase);
                    DataBase.add(staffobj);
                    staff.add(staffobj);
                } else if (choice1 == 2) {
                    System.out.println("--------------------------------------------------------------");
                    System.out.println("\t\t1 - Based on Employee-Id");
                    System.out.println("\t\t2 - Based on DateOfBirth");
                    System.out.println("\t\t3 - backToHome()");
                    System.out.println("--------------------------------------------------------------");
                    System.out.print("Enter Your Choice : ");
                    int choice2 = input.nextInt();
                    input.nextLine();

                    if (choice2 == 1) {
                        System.out.print("Enter Employee-Id : ");
                        String employeeId = input.nextLine();
                        for (User user : DataBase) {
                            if (user instanceof Staff) {
                                ((Staff) user).detailsforemployeeId(employeeId);
                            }
                        }

                    } else if (choice2 == 2) {
                        System.out.print("Enter DateOfBirth : ");
                        String dateOfBirth = input.nextLine();
                        for (User user : DataBase) {
                            if (user instanceof Staff) {
                                user.showDetails(dateOfBirth);
                            }
                        }
                    }

                } else if (choice1 == 3) {
                    System.out.print("Enter Employee-Id of User 1 : ");
                    String id1 = input.nextLine();
                    System.out.print("Enter Employee-Id of User 2 : ");
                    String id2 = input.nextLine();
                    Staff s1 = null, s2 = null;
                    for (User user : DataBase) {
                        if (user instanceof Staff && id1.equals(((Staff) user).getemployeeId())) {
                            s1 = ((Staff) user);
                        }
                        if (user instanceof Staff && id2.equals(((Staff) user).getemployeeId())) {
                            s2 = ((Staff) user);
                        }
                    }
                    if (s1 != null) {
                        s1.checkDesignation(s1, s2);
                    }

                    else {
                        System.out.println("Unable to fetch data");
                    }

                } else if (choice1 == 4) {
                    System.out.println("--------------------------------------------------------------");
                    System.out.println("\t\t1 - Based on Employee-ID");
                    System.out.println("\t\t2 - Based on birthYear");
                    System.out.println("\t\t3 - backToHome()");
                    System.out.println("--------------------------------------------------------------");
                    System.out.print("Enter Your Choice : ");
                    int choice3 = input.nextInt();
                    input.nextLine();

                    if (choice3 == 1) {
                        Collections.sort(staff, new sortbyemployeestaffId());
                        for (Staff user : staff) {
                            user.display();
                        }
                    } else if (choice3 == 2) {
                        Collections.sort(staff, new sortbybirthYearstaff());
                        for (Staff user : staff) {
                            user.display();
                        }

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
