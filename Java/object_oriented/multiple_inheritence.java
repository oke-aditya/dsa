// package object_oriented;

// Multiple inheritance is not supported in java.
// To remove ambiguity.
// To provide more maintainable and clean design.

// Class A           Class B
//   |                |
//   V                V
//         Class C                  

// This is not allowed.
// Use Interface to implement Multiple Inheritence.

interface Car
{
    int speed=50;
    public void distanceTravelled();
}

interface Bus
{
    int distance = 70;
    public void speed();
}

class Vehicle implements Car, Bus
{
    int distancetravelled;
    int averagespeed;

    public void distanceTravelled()
    {
        distancetravelled = speed * distance;
        System.out.println(distancetravelled);
    }

    public void speed()
    {
        int averagespeed = distancetravelled / speed;
        System.out.println(averagespeed);
    }
}

public class multiple_inheritence
{
    public static void main(String[] args)
    {
        Vehicle v1 = new Vehicle();
        v1.distanceTravelled();
        v1.speed();
    }
}
