import java.util.*;
import java.io.*;

class code2
{
    public static void main(String[] args) throws InterruptedException
    {
        account user = new account(20000);
        Thread thr1 = new Thread(new Runnable()
        {
            @Override
            public void run()
            {
                for (int i = 0; i < 50; i++)
                {
                    user.withdraw(100);
                }
            }
        }
        );

        Thread thr2 = new Thread(new Runnable()
        {
            @Override
            public void run()
            {
                for (int i = 0; i < 50; i++)
                {
                    user.withdraw(100);
                }
            }
        }
        );
        thr1.start();
        thr2.start();
        thr1.join();
        thr2.join();
        System.out.println(user.balance);
    }
}

class account
{
    public int balance;

    public account(int balance)
    {
        this.balance = balance;
    }

    public synchronized void withdraw(int withdraw_amount)
    {
        this.balance = this.balance - withdraw_amount;
    }
}
