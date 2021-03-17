import java.util.*;

public class q5_count_vowels
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        int count = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s.charAt(i) == 'a' || s.charAt(i) == 'e' || s.charAt(i) == 'i' || s.charAt(i) == 'o' || s.charAt(i) == 'u')
            {
                count += 1;
            }
        }
        System.out.println("Number of vowels = " + count);
        scanner.close();
    }
}
