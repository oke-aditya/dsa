package strings;


public class intro_string_buffer 
{
    public static void main(String[] args) 
    {
        // Creates mutable strings
        // Similar to string class but it is mutable
        StringBuffer s = new StringBuffer("");
        System.out.println(s.capacity());
        // Default capacity is 16.

        // 16 + length of string
        StringBuffer sb = new StringBuffer("Pokemon");
        System.out.println(sb.capacity());

        StringBuffer buff = new StringBuffer("internet of Things");
        System.out.println(buff.capacity());

        // buff = new StringBuffer(" ");
        // System.out.println(buff.capacity());

        buff.append(" Good ");
        System.out.println(buff);

        StringBuffer sb2 = new StringBuffer("Java");
        System.out.println(sb2);

        System.out.println(sb2.charAt(1));

        sb2.setCharAt(1, 'a');

        System.out.println(sb2);

        System.out.println(sb2.charAt(1));

    }
}
