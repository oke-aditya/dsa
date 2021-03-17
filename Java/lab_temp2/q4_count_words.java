import java.util.*;

public class q4_count_words 
{
    public static void main(String[] args)
    {
        canner scanner = new Scanner(System.in);
        String sentence = scanner.nextLine();

        String words[] = sentence.split(" ");

        for(int i=0; i<words.length; i++)
        {
            String to_compare = words[i];
            int count = 0;

            for(int j=0; j<words.length; j++)
            {
                if(words[j].equals(to_compare))
                {
                    count += 1;
                }
            }
            System.out.println(to_compare + " " + count);
        }
        scanner.close();
        System.out.println();

    }
}
