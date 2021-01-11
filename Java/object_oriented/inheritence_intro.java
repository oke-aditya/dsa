// Synatax for inheritence
// class subClass extends superClass
import java.util.*;

class Animal
{
    void king()
    {
        System.out.println("Lion");
    }
}

class NextAnimal extends Animal
{
    void nextking()
    {
        System.out.println("Tiger");
    }
}

public class inheritence_intro 
{
    public static void main(String[] args)
    {
        NextAnimal new_a = new NextAnimal();
        new_a.nextking();
        new_a.king();
    }
}
