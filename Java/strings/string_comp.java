package strings;

import java.util.*;

public class string_comp 
{    
    public static void main(String[] args) 
    {
        String str1 = "Dhoni";
        Scanner scanner = new Scanner(System.in);
        String inp1 = scanner.next();
        
        if(inp1.equals(str1))
        {
            System.out.print("They are equal");
        }
        else
        {
            System.out.print("Not equal");
        }
        scanner.close();
    }
}
