import java.util.*;

public class q7_weak_password
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        String uname = scanner.nextLine();
        String password = scanner.nextLine();
        boolean flag = false;

        for(int i=0; i<uname.length()-2; i++)
        {
            String temp = uname.substring(i, i+3);
            if(password.contains(uname))
            {
                System.out.println("Weak password");
                flag = true;
                break;
            }
        }
        if(flag == false)
        {
            System.out.println("Not weak password");
        }
        scanner.close();
    }
}
