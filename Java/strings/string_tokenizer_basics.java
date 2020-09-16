import java.io.*;
import java.util.*;

public class string_tokenizer_basics 
{
    public static void main(String[] args) 
    {
        StringTokenizer st = new StringTokenizer("Try out this new stuff");

        while(st.hasMoreTokens())
        {
            System.out.println(st.nextToken());
        }
        
        StringTokenizer st2 = new StringTokenizer("Try, out, this, new, stuff");

        while(st2.hasMoreTokens())
        {
            System.out.println(st2.nextToken(","));
        }
    }    
}
