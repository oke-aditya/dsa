package strings;

import java.util.*;

public class rev_words
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        String sentence = scanner.nextLine();

        String words[] = sentence.split(" ");
        for(int i=0; i<words.length; i++)
        {
            String to_rev = words[i];
            
        }
        scanner.close();

    }
}
