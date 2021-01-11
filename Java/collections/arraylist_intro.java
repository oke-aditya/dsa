import java.util.*;

class arraylist_intro
{
    public static void main(String[] args) 
    {
        ArrayList <Integer> al1 = new ArrayList<Integer>(5);
        al1.add(1);
        al1.add(2);
        al1.add(3);
        System.out.println(al1);

        ArrayList <String> al2 = new ArrayList<String>();
        al2.add("Hello");
        al2.add("From");
        al2.add("List");
        System.out.println(al2);
        System.out.println(al2.size());
        System.out.println(al2.contains("Hello"));
        System.out.println(al2.indexOf("From"));
        System.out.println(al2.get(2));

        ArrayList <Integer> al3 = new ArrayList<Integer>();
        al3.add(20);
        al3.add(40);
        al3.add(60);

        System.out.println(al3);
        al3.set(0, 30);
        System.out.println(al3);

        Iterator <String> itr = al2.iterator();
        while(itr.hasNext())
        {
            System.out.println(itr.next());
        }

        ArrayList <Integer> al4 = new ArrayList<Integer>();
        al4.add(1);
        al4.add(2);
        al4.add(3);

        for(Integer x : al4)
        {
            System.out.println(x);
        }
    }

}
