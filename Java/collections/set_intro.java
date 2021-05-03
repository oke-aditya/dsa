package collections;

import java.util.*;

// Few important features of HashSet are: 

//     Implements Set Interface.
//     The underlying data structure for HashSet is Hashtable.
//     As it implements the Set Interface, duplicate values are not allowed.
//     Objects that you insert in HashSet are not guaranteed to be inserted in the same order. Objects are inserted based on their hash code.
//     NULL elements are allowed in HashSet.
//     HashSet also implements Serializable and Cloneable interfaces.
//  All the classes of Set interface internally backed up by Map.
//  HashSet uses HashMap for storing its object internally.
// HashMap we need a key-value pair, but in HashSet, we are passing only one value. 
// HashSet does not store duplicate items,  if you give two Objects that are equal then it stores only the first.

// The HashSet class implements the Set
// interface, backed by a hash table which is actually a HashMap instance. No guarantee is made as to the iteration order of the set
//  which means that the class does not guarantee the
// constant order of elements over time. This class permits the null element. 

// The LinkedHashSet is an ordered version of HashSet that maintains a doubly-linked
// List across all elements. When the iteration order is needed to be maintained this
// class is used. When iterating through a HashSet the order is unpredictable, while a
// LinkedHashSet lets us iterate through the elements in the order in which they were
// inserted. When cycling through LinkedHashSet using an iterator,
// the elements will be returned in the order in which they were inserted.

// TreeSet is one of the most important implementations of the SortedSet interface
// in Java that uses a Tree for storage. The ordering of the elements is
// maintained by a set using their natural ordering whether or not an explicit
// comparator is provided. This must be consistent with equals if it is to correctly
// implement the Set interface. It can also be ordered by a Comparator provided at set
// creation time, depending on which constructor is used. The TreeSet implements a NavigableSet interface by inheriting AbstractSet class.

public class set_intro
{
    public static void main(String[] args)
    {
        HashSet <String> hs1 = new HashSet <String>();
        hs1.add("Hello");
        hs1.add("From");
        hs1.add("Hello");
        hs1.add("Set");

        System.out.println(hs1);

        LinkedHashSet <String> lsh1 = new LinkedHashSet <String> ();
        lsh1.add("Hello");
        lsh1.add("From");
        lsh1.add("Linked");
        lsh1.add("Hash");
        lsh1.add("Set");

        System.out.println(lsh1);

        Object arr [] = hs1.toArray();
        for(int j=0; j<arr.length; j++)
        {
            System.out.println(arr[j]);
        }

        SortedSet <String> ss1 = new TreeSet <String>();
        ss1.add("Hello");
        ss1.add("From");
        ss1.add("Sorted");
        ss1.add("Set");

        System.out.println(ss1);

        Object obj [] = ss1.toArray();
        // System.out.println(obj);

        for(int j=0; j<obj.length; j++)
        {
            System.out.println(obj[j]);
        }

        TreeSet<String> ts1 = new TreeSet<String>();

        // Elements are added using add() method
        ts1.add("A");
        ts1.add("B");
        ts1.add("C");
    
        // Duplicates will not get insert
        ts1.add("C");
    
        // Elements get stored in default natural
        // Sorting Order(Ascending)
        System.out.println(ts1);

    }
    
}
