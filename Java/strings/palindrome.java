import java.io.*;
import java.util.*;

public class palindrome 
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        String s1 = scanner.nextLine();

        int start = 0;
        int end = s1.length() - 1;
        int fg = 1;

        while(start < end)
        {
            if(s1.charAt(start) != s1.charAt(end))
            {
                fg = 0;
                break;
            }
            start += 1;
            end -= 1;
        }
        if(fg == 1)
        {
            System.out.println("Palindrome");
        }
        else
        {
            System.out.println("Not a Palindrome");
        }
    }
}
