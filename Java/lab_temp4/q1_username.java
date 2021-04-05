import java.util.*;


public class q1_username
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        try
        {
            String user = scanner.nextLine();
            String pass = scanner.nextLine();
            String cpass = scanner.nextLine();
            if (user.length() < 8 || pass.length() < 8)
            {
                System.out.println("Invalid Credentials");
            }
            if (user.contains(" ") || pass.contains(" "))
            {
                System.out.println("Should not contain space");
            }

            if (!pass.equals(cpass))
            {
                System.out.println("Passwords dont match");
            }

            for (int i = 0; i <= user.length() - 3; i++)
            {
                String st = user.substring(i, i + 3);
                if (pass.contains(st))
                {
                    System.out.println("Invalid");
                }
            }
        }
        catch (NullPointerException e)
        {
            System.out.println("Null not allowed");
        }
        catch (InputMismatchException m)
        {
            System.out.println(m.getMessage());
        }
        catch (ArrayIndexOutOfBoundsException t)
        {
            System.out.println(t.getMessage());
        }
        scanner.close();
    }
}
