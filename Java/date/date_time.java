import java.io.*;
import java.text.SimpleDateFormat;
import java.util.*;

public class date_time 
{
    public static void main(String[] args) 
    {
        // Date date = new Date();
        // System.out.print(date.toString());

        Date dnow = new Date();
        SimpleDateFormat ft = new SimpleDateFormat("E dd.MM.YYYY 'at' hh:mm:ss a zzz");
        System.out.println("Current Date: " + ft.format(dnow));
    }
}
