import java.util.*;

public class q6_string_bin {
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.next();
        String hex = "";
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str.charAt(i);
            int in = (int) ch;
            hex += Integer.toBinaryString(in);
        }
        System.out.println(hex);
        scanner.close();
    }
}
