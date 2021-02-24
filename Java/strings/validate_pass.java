package strings;

import java.util.*;

public class validate_pass
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        String usernmae = scanner.nextLine();
        String password = scanner.nextLine();
        String confirm_password = scanner.nextLine();

        if(usernmae.isEmpty())
        {
            System.out.println("Username is empty");
        }
        else if(password.isEmpty())
        {
            System.out.println("Password is empty");
        }

        if(password.length() < 8)
        {
            System.out.println("Password cannot be less than 8 characters");
        }

        if(password.contains(usernmae))
        {
            System.out.println("Password should not contain username");
        }

        if(!confirm_password.equals(password))
        {
            System.out.println("Password and confirm password should match");
        }

        System.out.println();

        scanner.close();
    }
    
}
