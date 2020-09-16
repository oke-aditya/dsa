import java.io.*;
import java.util.*;

public class string_ops 
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        String s1 = scanner.nextLine();
        String s2 = scanner.nextLine();

        System.out.println(s1);
        System.out.println(s2);

        System.out.println(s1.length() + " " + s2.length());
        System.out.println(s1.concat(s2));
        System.out.print(s1.toUpperCase());

    }
}
