import java.util.*;

public class q3_rev_word
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        String line = scanner.nextLine();

        String arr[] = line.split(" ");

        String rev = "";

        for(String word : arr)
        {
            String temp = "";
            for(int i=word.length(); i>=0; i--)
            {
                temp += word.charAt(i);
            } 
            rev = rev + temp + " ";
        }
        System.out.println(rev);

        scanner.close();

    }

}
