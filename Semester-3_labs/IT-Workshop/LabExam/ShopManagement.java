import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.lang.*;

// (itemCode, price, AvailableQty)

class Item {
    protected int itemcode;
    protected int price;
    protected int AvailableQty;

    Item() {

    }

    Item(int itemcode, int price, int AvailableQty) {
        this.itemcode = itemcode;
        this.price = price;
        this.AvailableQty = AvailableQty;
    }

    public void modifyStock(int itemcode) {
        if (this.itemcode == itemcode) {
            Scanner input = new Scanner(System.in);

            System.out.print("Enter AvailableQty : ");
            int newAvailableQty = input.nextInt();
            input.nextLine();

            System.out.print("Enter Price : ");
            int newprice = input.nextInt();
            input.nextLine();

            this.price = newprice;
            this.AvailableQty = newAvailableQty;
        } else {
            System.out.println("Not Found");
        }
    }

    public int getYear(String dateOfSell) {
        return Integer.parseInt(dateOfSell.substring(6, 10));
    }

    public int getMonth(String dateOfSell) {
        return Integer.parseInt(dateOfSell.substring(3, 5));
    }

    public int getDay(String dateOfSell) {
        return Integer.parseInt(dateOfSell.substring(0, 2));
    }

    public Boolean checkQuantity(int quantity) {
        if (this.AvailableQty >= quantity) {
            return true;
        }
        return false;
    }

    public Boolean checkItemcode(int itemcode) {
        if (this.itemcode == itemcode) {
            return true;
        }
        return false;
    }

    public static boolean isValidDate(String date) {
        String regex = "^[0-3][0-9]/[0-1][0-9]/[0-9]{4}$";
        Pattern p = Pattern.compile(regex);
        if (date == null) {
            return false;
        }
        Matcher m = p.matcher(date);
        return m.matches();
    }

}

// (userID, name, dateOfBirth, Address, PAN,password)
class User {
    protected String name;
    protected String dateOfBirth;
    protected String email;
    protected String userId;
    protected String address;
    protected String pan;
    protected String password;

    public Boolean checkUserId(String userId) {
        if (this.userId.equals(userId) && userId != null && this.userId != null) {
            return true;
        }
        return false;
    }

}

class FoodItem extends Item {
    private String dateOfExpiry;

    FoodItem(String dateOfExpiry, int itemcode, int price, int AvailableQty) {
        super(itemcode, price, AvailableQty);
        this.dateOfExpiry = dateOfExpiry;
    }

}

class NonFoodItem extends Item {
    private int warrentyPeriod;

    NonFoodItem(int warrentyPeriod, int itemcode, int price, int AvailableQty) {
        super(itemcode, price, AvailableQty);
        this.warrentyPeriod = warrentyPeriod;
    }

    public int returnCount(int itemcode) {
        if (this.itemcode == itemcode) {
            return AvailableQty;
        }
        return -1;
    }
}

// (dateOfJoining, salary, permissibleOperations)
class Admin extends User {

    private String dateOfJoining;
    private int salary;
    private int permissibleOperations;

    Admin() {

    }

    Admin(String name, String dateOfBirth, String userId, String address, String pan, String dateOfJoining, int salary,
            int permissibleOperations, String password) {
        this.name = name;
        this.dateOfBirth = dateOfBirth;
        this.userId = userId;
        this.address = address;
        this.pan = pan;
        this.salary = salary;
        this.dateOfJoining = dateOfJoining;
        this.permissibleOperations = permissibleOperations;
        this.password = password;
    }

    // addNewStock (item):
    public void addNewStock(ArrayList<Item> ItemDataBase) {
        Scanner input = new Scanner(System.in);
        System.out.println("------------------------------------------------------------------------------");
        System.out.println("\t1 - FoodItem");
        System.out.println("\t2 - NonFoodItem");
        System.out.println("\t3 - cancel()");
        System.out.println("------------------------------------------------------------------------------");
        System.out.print("Enter Choice : ");
        int choice = input.nextInt();
        input.nextLine();

        if (choice == 1) {
            try {
                System.out.print("Enter Itemcode : ");
                int itemcode = input.nextInt();
                input.nextLine();

                System.out.print("Enter Price : ");
                int price = input.nextInt();
                input.nextLine();

                System.out.print("Enter AvailableQty : ");
                int AvailableQty = input.nextInt();
                input.nextLine();

                System.out.print("Enter dateOfExpiry : ");
                String dateOfExpiry = input.nextLine();
                while (!Item.isValidDate(dateOfExpiry)) {
                    System.out.println("Invalid Date Please Re-Enter!");
                    dateOfExpiry = input.nextLine();
                }
                FoodItem newitem = new FoodItem(dateOfExpiry, itemcode, price, AvailableQty);
                ItemDataBase.add(newitem);
            } catch (InputMismatchException e) {
                System.out.println("ArithmeticException");
                System.out.println("Input a Integer!");
                addNewStock(ItemDataBase);
            }

        } else if (choice == 2) {
            try {
                System.out.print("Enter Itemcode : ");
                int itemcode = input.nextInt();
                input.nextLine();

                System.out.print("Enter Price : ");
                int price = input.nextInt();
                input.nextLine();

                System.out.print("Enter AvailableQty : ");
                int AvailableQty = input.nextInt();
                input.nextLine();

                System.out.print("Enter warrentyPeriod (Months): ");
                int warrentyPeriod = input.nextInt();
                input.nextLine();

                NonFoodItem newitem = new NonFoodItem(warrentyPeriod, itemcode, price, AvailableQty);
                ItemDataBase.add(newitem);
            } catch (InputMismatchException e) {
                System.out.println(e);
                System.out.println("Input a Integer!");
                addNewStock(ItemDataBase);
            }

        }
    }

    public static void deleteStock(ArrayList<Item> ItemDataBase, int indexofItemcode) {
        ItemDataBase.remove(indexofItemcode);
    }

}

// (dateOfJoining, salary, dutyHourPerDay)
class General extends User {
    private String dateOfJoining;
    private int salary;
    private int dutyHourPerDay;

    General() {

    }

    General(String name, String dateOfBirth, String userId, String address, String pan, String dateOfJoining,
            int salary,
            int dutyHourPerDay, String password) {
        this.name = name;
        this.dateOfBirth = dateOfBirth;
        this.userId = userId;
        this.address = address;
        this.pan = pan;
        this.salary = salary;
        this.dateOfJoining = dateOfJoining;
        this.dutyHourPerDay = dutyHourPerDay;
        this.password = password;
    }

    public static void displayStock(ArrayList<Item> ItemDataBase, int itemcode) {
        for (Item user : ItemDataBase) {
            if (user.itemcode == itemcode) {
                if (user instanceof FoodItem) {
                    System.out.println("FoodItem : ");
                } else {
                    System.out.println("NonFoodItem : ");
                }
                System.out.println("------------------------------------------------------------------------------");
                System.out.println("\tItemcode : " + user.itemcode);
                System.out.println("\tPrice : " + user.price);
                System.out.println("\tAvailableQty : " + user.AvailableQty);
                System.out.println("------------------------------------------------------------------------------");
            }
        }
    }

    public void sellItem(ArrayList<Sell> SellItemDataBase, ArrayList<Item> ItemDataBase) {

        Scanner input = new Scanner(System.in);
        System.out.println("------------------------------------------------------------------------------");
        System.out.println("\t1 - FoodItem");
        System.out.println("\t2 - NonFoodItem");
        System.out.println("\t3 - cancel()");
        System.out.println("------------------------------------------------------------------------------");
        System.out.print("Enter Choice : ");
        int choice = input.nextInt();
        input.nextLine();

        if (choice == 1) {
            System.out.print("Enter itemcode : ");
            int itemcode = input.nextInt();
            input.nextLine();

            System.out.print("Enter quantity : ");
            int quantity = input.nextInt();
            input.nextLine();

            System.out.print("Enter dateOfSell (dd/mm/yyyy): ");
            String dateOfSell = input.nextLine();
            while (!Item.isValidDate(dateOfSell)) {
                System.out.println("Invalid Date Please Re-Enter!");
                dateOfSell = input.nextLine();
            }
            System.out.print("Enter totalAmount : ");
            int totalAmount = input.nextInt();
            input.nextLine();

            for (Item checkItem : ItemDataBase) {
                if (checkItem.checkItemcode(itemcode) && checkItem instanceof FoodItem) {
                    if (checkItem.checkQuantity(quantity)) {
                        Sell sellNewItem = new Sell(dateOfSell, itemcode, quantity, totalAmount);
                        SellItemDataBase.add(sellNewItem);
                        checkItem.AvailableQty -= quantity;
                        break;
                    } else {
                        checkItem = null;
                        System.out.println("Not Sufficient Stock Available!");
                        break;
                    }
                } else {
                    System.out.println("Item is not present in stock!");
                    break;
                }
            }
        } else if (choice == 2) {
            System.out.print("Enter itemcode : ");
            int itemcode = input.nextInt();
            input.nextLine();

            System.out.print("Enter quantity : ");
            int quantity = input.nextInt();
            input.nextLine();

            System.out.print("Enter dateOfSell (dd/mm/yyyy): ");
            String dateOfSell = input.nextLine();
            while (!Item.isValidDate(dateOfSell)) {
                System.out.println("Invalid Date Please Re-Enter!");
                dateOfSell = input.nextLine();
            }
            System.out.print("Enter totalAmount : ");
            int totalAmount = input.nextInt();
            input.nextLine();

            for (Item checkItem : ItemDataBase) {
                if (checkItem.checkItemcode(itemcode) && checkItem instanceof NonFoodItem) {
                    if (checkItem.checkQuantity(quantity)) {
                        Sell sellNewItem = new Sell(dateOfSell, itemcode, quantity, totalAmount);
                        SellItemDataBase.add(sellNewItem);
                        checkItem.AvailableQty -= quantity;
                        break;
                    } else {
                        checkItem = null;
                        System.out.println("Not Sufficient Stock Available!");
                        break;
                    }
                } else {
                    System.out.println("Item is not present in stock!");
                    break;
                }
            }
        }

    }

    // int dateOfReturn, int itemcode, int returnAmount
    public void returnItem(ArrayList<Return> ReturnDataBase, ArrayList<Item> ItemDataBase) {
        Boolean flag = false;
        Scanner input = new Scanner(System.in);
        System.out.print("Enter itemcode : ");
        int itemcode = input.nextInt();
        input.nextLine();

        Boolean check = true;
        while (!flag) {
            try {
                for (Item item : ItemDataBase) {
                    if (item.checkItemcode(itemcode)) {
                        if (item instanceof NonFoodItem) {
                            flag = true;
                            break;
                        }
                    } else {
                        System.out.println("No such item exist!");
                        check = false;
                        break;
                    }
                }
                if (!check) {
                    return;
                }
                if (!flag) {
                    throw new FoodItemReturnException("Can't Return Food Item");
                }
            } catch (FoodItemReturnException e) {
                System.out.println(e);
                System.out.println("Re-Enter!");
                itemcode = input.nextInt();
            }
        }
        input.nextLine();

        System.out.print("Enter dateOfReturn (dd/mm/yyyy): ");
        String dateOfReturn = input.nextLine();

        while (!Item.isValidDate(dateOfReturn)) {
            System.out.println("Invalid Date Please Re-Enter!");
            dateOfReturn = input.nextLine();
        }

        System.out.print("Enter quantity : ");
        int quantity = input.nextInt();
        input.nextLine();

        System.out.print("Enter returnAmount : ");
        int returnAmount = input.nextInt();
        input.nextLine();

        for (Item checkItem : ItemDataBase) {
            if (checkItem.checkItemcode(itemcode) && checkItem instanceof NonFoodItem) {
                Return returnSoldItem = new Return(dateOfReturn, itemcode, quantity, returnAmount);
                ReturnDataBase.add(returnSoldItem);
                checkItem.AvailableQty += quantity;
                break;
            } else {
                System.out.println("Item is not present in stock!");
                break;
            }
        }

    }
}

// (dateOfSell, itemCode, quantity, totalAmount)
class Sell extends Item {
    private String dateOfSell;
    private int itemcode;
    private int quantity;
    private int totalAmount;

    Sell() {

    }

    Sell(String dateOfSell, int itemcode, int quantity, int totalAmount) {
        this.dateOfSell = dateOfSell;
        this.itemcode = itemcode;
        this.quantity = quantity;
        this.totalAmount = totalAmount;
    }

    public void displaySell(String startDate, String endDate) {

        if (getYear(this.dateOfSell) >= getYear(startDate)
                && getYear(this.dateOfSell) <= getYear(endDate)
                && getMonth(this.dateOfSell) >= getMonth(startDate)
                && getMonth(this.dateOfSell) <= getMonth(endDate)
                && getDay(this.dateOfSell) <= getDay(endDate) &&
                getDay(this.dateOfSell) >= getDay(startDate)) {
            System.out.println("------------------------------------------------------------------------------");
            System.out.println("\tdateOfSell : " + this.dateOfSell);
            System.out.println("\titemcode : " + this.itemcode);
            System.out.println("\tquantity : " + this.quantity);
            System.out.println("\ttotalAmount : " + this.totalAmount);
            System.out.println("------------------------------------------------------------------------------");
        }
    }
}

// (dateOfReturn,itemCode,quantity,returnAmount)
class Return extends Item {
    private String dateOfReturn;
    private int itemcode;
    private int quantity;
    private int returnAmount;

    Return() {

    }

    Return(String dateOfReturn, int itemcode, int quantity, int returnAmount) {
        this.dateOfReturn = dateOfReturn;
        this.itemcode = itemcode;
        this.quantity = quantity;
        this.returnAmount = returnAmount;
    }

    public void displayReturn(String startDate, String endDate) {

        if (getYear(this.dateOfReturn) >= getYear(startDate)
                && getYear(this.dateOfReturn) <= getYear(endDate)
                && getMonth(this.dateOfReturn) >= getMonth(startDate)
                && getMonth(this.dateOfReturn) <= getMonth(endDate)
                && getDay(this.dateOfReturn) <= getDay(endDate) &&
                getDay(this.dateOfReturn) >= getDay(startDate)) {
            System.out.println("------------------------------------------------------------------------------");
            System.out.println("\tdateOfReturn : " + this.dateOfReturn);
            System.out.println("\titemcode : " + this.itemcode);
            System.out.println("\tquantity : " + this.quantity);
            System.out.println("\ttotalAmount : " + this.returnAmount);
            System.out.println("------------------------------------------------------------------------------");
        }
    }

}

class InvalidRangeOfSearch extends Exception {
    InvalidRangeOfSearch(String str) {
        super(str);
    }
}

class ItemNotFound extends Exception {
    ItemNotFound(String str) {
        super(str);
    }
}

class FoodItemReturnException extends Exception {
    FoodItemReturnException(String str) {
        super(str);
    }
}

public class ShopManagement {

    static ArrayList<User> mainuser = new ArrayList<User>();
    static ArrayList<Item> ItemDataBase = new ArrayList<Item>();
    static ArrayList<Sell> SellDataBase = new ArrayList<Sell>();
    static ArrayList<Return> ReturnDataBase = new ArrayList<Return>();

    static int getYear(String date) {
        return Integer.parseInt(date.substring(6, 10));
    }

    static int getMonth(String date) {
        return Integer.parseInt(date.substring(3, 5));
    }

    static int getDay(String date) {
        return Integer.parseInt(date.substring(0, 2));
    }

    static boolean isValidDate(String date) {
        String regex = "^[0-3][0-9]/[0-1][0-9]/[0-9]{4}$";
        Pattern p = Pattern.compile(regex);
        if (date == null) {
            return false;
        }
        Matcher m = p.matcher(date);
        return m.matches();
    }

    static boolean isValidPAN(String pan) {
        String regex = "^[A-Z0-9]*{12}";
        Pattern p = Pattern.compile(regex);
        if (pan == null) {
            return false;
        }
        Matcher m = p.matcher(pan);
        return m.matches();
    }

    static boolean isValidMail(String email) {
        String regex = "^(.+)@(.+)$";
        Pattern p = Pattern.compile(regex);
        if (email == null) {
            return false;
        }
        Matcher m = p.matcher(email);
        return m.matches();
    }

    static boolean isValidpass(String password) {
        String regex = ".{6,}";
        Pattern p = Pattern.compile(regex);
        if (password == null) {
            return false;
        }
        Matcher m = p.matcher(password);
        return m.matches();
    }

    static void adminControlSystem() {

        while (true) {
            Scanner input = new Scanner(System.in);
            System.out.println("------------------------------------------------------------------------------");
            System.out.println("\t1 - addNewStock()");
            System.out.println("\t2 - deleteStock()");
            System.out.println("\t3 - modifyStock()");
            System.out.println("\t4 - logout()");
            System.out.println("------------------------------------------------------------------------------");
            System.out.print("Enter Your Choice : ");
            int choice = input.nextInt();
            input.nextLine();

            if (choice == 1) {
                Admin admin = new Admin();
                admin.addNewStock(ItemDataBase);
            } else if (choice == 2) {
                Boolean check = false;
                while (!check) {
                    try {
                        System.out.print("Enter itemcode : ");
                        int itemcode = input.nextInt();
                        input.nextLine();

                        int flag = 0, i = 0;
                        for (Item user : ItemDataBase) {
                            if (user.itemcode == itemcode) {
                                flag = 1;
                                check = true;
                                break;
                            }
                            i++;
                        }
                        if (flag == 1) {
                            Admin.deleteStock(ItemDataBase, i);
                        } else {
                            throw new ItemNotFound("Item Not Found!");
                        }
                    } catch (ItemNotFound e) {
                        System.out.println(e);
                        System.out.println("Re-enter!");
                    }
                }

            } else if (choice == 3) {

                Boolean check = false;
                while (!check) {
                    try {
                        System.out.print("Enter itemcode : ");
                        int itemcode = input.nextInt();
                        input.nextLine();

                        for (Item user : ItemDataBase) {
                            if (user.itemcode == itemcode) {
                                user.modifyStock(itemcode);
                                check = true;
                                break;
                            }
                        }
                        if (!check) {
                            throw new ItemNotFound("Item Not Found!");
                        }
                    } catch (ItemNotFound e) {
                        System.out.println(e);
                        System.out.println("Re-enter!");
                    }
                }
            } else if (choice == 4) {
                break;
            }
        }
    }

    static void generalControlSystem() {
        while (true) {
            Scanner input = new Scanner(System.in);
            System.out.println("------------------------------------------------------------------------------");
            System.out.println("\t1 - sellItem()");
            System.out.println("\t2 - returnItem()");
            System.out.println("\t3 - displayStock()");
            System.out.println("\t4 - displaySell()");
            System.out.println("\t5 - displayReturn()");
            System.out.println("\t6 - logout()");
            System.out.println("------------------------------------------------------------------------------");
            System.out.print("Enter Your Choice : ");
            int choice = input.nextInt();
            input.nextLine();

            if (choice == 1) {
                for (User user : mainuser) {
                    if (user instanceof General) {
                        ((General) user).sellItem(SellDataBase, ItemDataBase);
                        break;
                    }
                }

            } else if (choice == 2) {
                for (User user : mainuser) {
                    if (user instanceof General) {
                        ((General) user).returnItem(ReturnDataBase, ItemDataBase);
                        break;
                    }
                }

            } else if (choice == 3) {
                System.out.print("Enter itemcode : ");
                int itemcode = input.nextInt();
                input.nextLine();
                General.displayStock(ItemDataBase, itemcode);

            } else if (choice == 4) {
                System.out.print("Enter startDate (dd/mm/yyyy) : ");
                String startDate = input.nextLine();
                while (!isValidDate(startDate)) {
                    System.out.println("Invalid Date Please Re-Enter!");
                    startDate = input.nextLine();
                }

                System.out.print("Enter endDate (dd/mm/yyyy) : ");
                String endDate = input.nextLine();
                while (!isValidDate(endDate)) {
                    System.out.println("Invalid Date Please Re-Enter!");
                    endDate = input.nextLine();
                }

                Boolean flag = false;
                while (!flag) {
                    try {
                        if (getYear(startDate) != getYear(endDate) || getMonth(endDate) > 6 + getMonth(startDate)) {
                            throw new InvalidRangeOfSearch("Out of search Range");
                        } else {
                            flag = true;
                        }
                    } catch (InvalidRangeOfSearch e) {
                        System.out.println(e);
                        System.out.println("Re-Enter!");
                        System.out.print("Enter startDate (dd/mm/yyyy) : ");
                        startDate = input.nextLine();
                        while (!isValidDate(startDate)) {
                            System.out.println("Invalid Date Please Re-Enter!");
                            startDate = input.nextLine();
                        }

                        System.out.print("Enter endDate (dd/mm/yyyy) : ");
                        endDate = input.nextLine();
                        while (!isValidDate(endDate)) {
                            System.out.println("Invalid Date Please Re-Enter!");
                            endDate = input.nextLine();
                        }
                    }
                }

                for (Sell user : SellDataBase) {
                    user.displaySell(startDate, endDate);
                }

            } else if (choice == 5) {
                System.out.print("Enter startDate (dd/mm/yyyy) : ");
                String startDate = input.nextLine();
                while (!isValidDate(startDate)) {
                    System.out.println("Invalid Date Please Re-Enter!");
                    startDate = input.nextLine();
                }

                System.out.print("Enter endDate (dd/mm/yyyy) : ");
                String endDate = input.nextLine();
                while (!isValidDate(endDate)) {
                    System.out.println("Invalid Date Please Re-Enter!");
                    endDate = input.nextLine();
                }
                Boolean flag = false;
                while (!flag) {
                    try {
                        if (getYear(startDate) != getYear(endDate) || getMonth(endDate) > 6 + getMonth(startDate)) {
                            throw new InvalidRangeOfSearch("Out of search Range");
                        } else {
                            flag = true;
                        }
                    } catch (InvalidRangeOfSearch e) {
                        System.out.println(e);
                        System.out.println("Re-Enter!");
                        System.out.print("Enter startDate (dd/mm/yyyy) : ");
                        startDate = input.nextLine();
                        while (!isValidDate(startDate)) {
                            System.out.println("Invalid Date Please Re-Enter!");
                            startDate = input.nextLine();
                        }

                        System.out.print("Enter endDate (dd/mm/yyyy) : ");
                        endDate = input.nextLine();
                        while (!isValidDate(endDate)) {
                            System.out.println("Invalid Date Please Re-Enter!");
                            endDate = input.nextLine();
                        }
                    }
                }
                for (Return user : ReturnDataBase) {
                    user.displayReturn(startDate, endDate);
                }

            } else if (choice == 6) {
                break;
            }
        }
    }

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.println("Welcome to our Shop");

        while (true) {
            System.out.println("------------------------------------------------------------------------------");
            System.out.println("\t1 - Add Admin User");
            System.out.println("\t2 - Add General User");
            System.out.println("\t3 - signin");
            System.out.println("\t4 - exit()");
            System.out.println("------------------------------------------------------------------------------");
            System.out.print("Enter Your Choice : ");
            int choice = input.nextInt();
            input.nextLine();

            if (choice == 1) {
                // For Admin User
                System.out.print("Enter name : ");
                String name = input.nextLine();

                System.out.print("Enter dateOfBirth (dd/mm/yyyy): ");
                String dateOfBirth = input.nextLine();

                while (!isValidDate(dateOfBirth)) {
                    System.out.println("Invalid Date Please Re-Enter!");
                    dateOfBirth = input.nextLine();
                }

                System.out.print("Enter userId : ");
                String userId = input.nextLine();
                System.out.println("userId :" + userId);
                for (User user : mainuser) {
                    if (user == null)
                        continue;

                    if (user.checkUserId(userId) && user instanceof Admin
                            && userId != null) {
                        while (true) {
                            System.out.print("userId already exist Enter again! : ");
                            userId = input.nextLine();
                            if (!user.checkUserId(userId)) {
                                break;
                            }
                        }
                        break;
                    }
                }

                System.out.print("Enter Password (atleast 6 letters) : ");
                String password = input.nextLine();

                while (!isValidpass(password)) {
                    System.out.println("Too weak Please Re-Enter!");
                    password = input.nextLine();
                }

                System.out.print("Enter address : ");
                String address = input.nextLine();

                System.out.print("Enter pan (12/16 characters long) : ");
                String pan = input.nextLine();

                System.out.print("Enter salary : ");
                int salary = input.nextInt();
                input.nextLine();

                System.out.print("Enter dateOfJoining (dd/mm/yyyy) : ");
                String dateOfJoining = input.nextLine();
                while (!isValidDate(dateOfJoining)) {
                    System.out.println("Invalid Date Please Re-Enter!");
                    dateOfJoining = input.nextLine();
                }

                System.out.print("Enter permissibleOperations (A D M): ");
                int permissibleOperations = input.nextInt();

                Admin admin = new Admin(name, dateOfBirth, userId, address, pan, dateOfJoining, salary,
                        permissibleOperations, password);
                mainuser.add(admin);

            } else if (choice == 2) {
                // For general user
                System.out.print("Enter name : ");
                String name = input.nextLine();

                System.out.print("Enter dateOfBirth (dd/mm/yyyy) : ");
                String dateOfBirth = input.nextLine();
                while (!isValidDate(dateOfBirth)) {
                    System.out.println("Invalid Date Please Re-Enter!");
                    dateOfBirth = input.nextLine();
                }

                System.out.print("Enter userId : ");
                String userId = input.nextLine();
                for (User user : mainuser) {
                    if (user == null)
                        continue;
                    if (user.checkUserId(userId) && userId != null) {
                        while (true) {
                            System.out.print("userId already exist Enter again! : ");
                            userId = input.nextLine();
                            if (!user.checkUserId(userId)) {
                                break;
                            }
                        }
                        break;
                    }
                }

                System.out.print("Enter Password (atleast 6 letters) : ");
                String password = input.nextLine();
                while (!isValidpass(password)) {
                    System.out.println("Too weak Please Re-Enter!");
                    password = input.nextLine();
                }

                System.out.print("Enter address : ");
                String address = input.nextLine();

                System.out.print("Enter pan (12/16 characters long): ");
                String pan = input.nextLine();

                System.out.print("Enter salary : ");
                int salary = input.nextInt();
                input.nextLine();

                System.out.print("Enter dateOfJoining (dd/mm/yyyy): ");
                String dateOfJoining = input.nextLine();
                while (!isValidDate(dateOfJoining)) {
                    System.out.println("Invalid Date Please Re-Enter!");
                    dateOfJoining = input.nextLine();
                }

                System.out.print("Enter dutyHourPerDay : ");
                int dutyHourPerDay = input.nextInt();

                General general = new General(name, dateOfBirth, userId, address, pan, dateOfJoining, salary,
                        dutyHourPerDay, password);
                mainuser.add(general);

            } else if (choice == 3) {
                System.out.print("Enter userId : ");
                String userId = input.nextLine();

                System.out.print("Enter password : ");
                String password = input.nextLine();

                Boolean flag = false;
                for (User user : mainuser) {
                    if (userId != null && user.userId.equals(userId) && user.password.equals(password)
                            && user instanceof Admin) {
                        System.out
                                .println(
                                        "------------------------------------------------------------------------------");
                        System.out.println("\tAuthenticated as " + user.name + "\n\tWelcome! " + user.name);
                        System.out
                                .println(
                                        "------------------------------------------------------------------------------");
                        adminControlSystem();
                        flag = true;
                        break;
                    } else if (userId != null && user.userId.equals(userId) && user.password.equals(password)
                            && user instanceof General) {
                        System.out
                                .println(
                                        "------------------------------------------------------------------------------");
                        System.out.println("\tAuthenticated as " + user.name + "\n\tWelcome! " + user.name);
                        System.out
                                .println(
                                        "------------------------------------------------------------------------------");
                        generalControlSystem();
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    System.out.println("No such user exist :");
                }
            } else if (choice == 4) {
                break;
            } else if (choice == 5) {
                System.out.println("User id's are :");
                for (User user : mainuser) {

                    System.out.println(user.userId);
                }
            }

        }
    }
}
