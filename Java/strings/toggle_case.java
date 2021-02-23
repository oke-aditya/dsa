package strings;

import java.util.*;

class toggle_case
{
    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        
        String str = scanner.nextLine();

        String str2 = "";

        for(int i=0; i<str.length(); i++)
        {
            if(Character.isUpperCase(str.charAt(i)))
            {
                str2 += Character.toLowerCase(str.charAt(i));
            }
            else
            {
                str2 += Character.toUpperCase(str.charAt(i));
            }
        }
        System.out.println(str2);
        scanner.close();
    }
}
