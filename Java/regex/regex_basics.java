import java.util.regex.*;

public class regex_basics 
{
    public static void main(String[] args) 
    {
        // Pattern class
        String text = "This is text to be searched";
        String pattern = "is";

        boolean matches = Pattern.matches(pattern, text);
        System.out.println("matches = " + matches);
        
        String se = "This is the link https://www.google.com/hi-there";

        String str = ".*https://.*";

        pattern = Pattern.compile(str);
        Matcher matcher = Pattern.match(text);

        matches = matcher.matches();

        System.out.println("matches = " + matches);

        String [] split = pattern.split(text);

        System.out.println("Split length = " + split.length);

    }
}
