import java.io.*;
import java.util.*;

public class stack_intro
{
    public static void main(String[] args)
    {
        Stack <Integer> st = new Stack<Integer>();
        st.push(10);
        st.push(20);
        st.push(30);

        System.out.println(st);

        while(!st.isEmpty())
        {
            System.out.print(st.pop() + " ");
        }
        System.out.println();
    }
    
}
