import java.util.*;

class dependent {
    public String name;
    public String DOB;
    public String phoneno;

    public void setinfo(String name, String DOB, String phoneno) {
        this.DOB = DOB;
        this.name = name;
        this.phoneno = phoneno;
    }

    public void displayinfo() {
        System.out.println(" " + name + " " + DOB + " " + phoneno + " ");
    }
}

class faculty {
    public String name;
    private double salary;
    public String type;
    public String id;
    dependent d = new dependent();

    faculty(String type) {
        this.type = type.toLowerCase();
        try {
            SetSalary(this.type);
        } catch (ArithmeticException e) {
            System.out.println("Arithmetic exception!");
        }
    }

    public void SetSalary(String type) {
        switch (type) {
        case "professor":
            this.salary = 150000 + (0.3) * 150000;
            break;
        case "associate professor":
            this.salary = 120000 + 0.2 * 120000;
            break;
        case "assistant professor":
            ;
            this.salary = 100000 + (0.1) * 100000;
            break;
        case "tra":
            this.salary = 20000;
            break;
        }
    }

    public void getinfo() throws InputMismatchException, NullPointerException {
        Scanner scanner = new Scanner(System.in);
        System.out.println("enter name, id: ");
        name = scanner.nextLine();
        id = scanner.nextLine();
        if (!type.equals("tra")) {
            System.out.println("enter dependent's name, phoneno, DOB: ");
            String dname = scanner.nextLine();
            String dob = scanner.nextLine();
            String dphone = scanner.nextLine();
            d.setinfo(dname, dob, dphone);
        }
    }

    public void displayinfo() {
        System.out.println("(Name, id, salary) : ");
        System.out.println("(" + name + "," + id + "," + salary + ")");
        if (!type.equals("tra"))
            d.displayinfo();
    }
}

public class q3_faculty {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        faculty s[] = new faculty[3];
        for (int i = 0; i < 3; i++) {
            System.out.println("Enter type: ");
            String type = input.nextLine();
            s[i] = new faculty(type);
            try {
                s[i].getinfo();
            } catch (InputMismatchException e) {
                System.out.println(e.getMessage());
            } catch (NullPointerException e) {
                System.out.println("Null pointer exception!");
            }
        }
        System.out.println("enter id to search:");
        String id = input.nextLine();
        for (int i = 0; i < 3; i++) {
            if (id.equals(s[i].id)) {
                try {
                    s[i].displayinfo();
                } catch (NullPointerException e) {
                    System.out.println("Null pointer exception!");
                }
            }
        }

    }
}