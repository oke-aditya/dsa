import java.io.*;
import java.util.*;

public class string_builtin_methods 
{
    public static void main(String[] args) 
    {
        String s = "Hardik Pandya";
        System.out.println(s.substring(7));
        System.out.println(s.substring(0, 5));
        String s1 = s.replace('i', 'c');
        System.out.println(s1);

        String s2 = "Hello everyone good evening";
        System.out.println(s2.contains("everyone"));
        System.out.println(s2.contains("evening"));
        System.out.println(s2.contains("ebening"));

        int value = 19;
        String s3 = String.valueOf(value);
        System.out.println(s3);
        String s4 = "" + value;
        System.out.println(s4);

    }    
}
