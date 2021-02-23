package strings;

import java.util.*;

public class vov_cons 
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);

        char ch = scanner.next().charAt(0);

        if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
        {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' 
            || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            {
                System.out.println("Vowel");
            }
            else
            {
                System.out.println("Consonant");
            }
        }
        else
        {
            System.out.println("Not an alphabet");
        }
        scanner.close();
    }
}

