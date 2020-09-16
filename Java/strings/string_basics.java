import java.io.*;
import java.util.*;

public class string_basics 
{
    public static void main(String[] args) 
    {
        String str = "Hello";
        String s1 = new String("Hello");
        String s2 = new String("Hello");
        System.out.println(str);
        System.out.println(s1);
        System.out.println((s1 == str));

        System.out.println(s1.equals(str));
        System.out.println(s1.equals(s2));
    }
}

