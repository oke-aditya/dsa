package object_oriented;

// An example to use interfaces.

// Interfaces contain only abstract methods.
// They are abstract and public by default.
// Do not have a Constructor.
// It's not a class. It makes multiple inheritence possible.
// One class can inherit multiple interfaces.
// It can contain only static and final variables that are public.
// A class should implement all methods in interface.

// A simple button interface

interface Button
{
    void set_button_color();
    void set_button_text();
    void on_click();

    // Adding any single method would force all the implemented classes
    // To code it

    // To avoid this we can use `default` and declare in place.
    default void test_method()
    {
        System.out.println("This is a test method");
    }

}

// An nterface can extend a interface
interface ThreeButton extends Button
{
    void location(int x, int y, int z);
}

interface TwoButton extends Button
{
    void location(int x, int y, int z);

}


// A class implements interface, not extends

class Reservation implements Button
{
    // We must implement all the three methods
    
    String color, text;
    
    @Override
    public void set_button_color()
    {
        color = "blue";
    }

    @Override
    public void set_button_text()
    {
        text = "hello";
    }

    @Override
    public void on_click()
    {
        System.out.println("Welcome to India");
    }
}

// class Cancellation implements Button
// {


// }

public class interfaces_intro
{
    public static void main(String[] args)
    {
        Reservation r1 = new Reservation();
        r1.on_click();

        // We can use the test method which is present in interface
        // We don't need to overload and use it.
        r1.test_method();

    }
}
