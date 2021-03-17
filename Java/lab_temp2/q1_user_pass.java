import java.util.*;

public class q1_user_pass
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        String uname = scanner.nextLine();
        String password = scanner.nextLine();
        String confirm_pass = scanner.nextLine();

        if(uname.isEmpty())
        {
            System.out.println("Username cannot be empty");
        }

        if(password.isEmpty())
        {
            System.out.println("Password cannot be empty");
        }

        if(password.length() < 8)
        {
            System.out.println("Length of password should be atleast 8 chracters");
        }

        if(confirm_pass.compareTo(password) != 0)
        {
            System.out.println("Password and Confirm Password should be same");
        }

        if(password.contains(uname))
        {
            System.out.println("Username should not contain password");
        }
        scanner.close();

    }
    
}
