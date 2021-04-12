import java.util.*;
import java.io.*;

class code4
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
        });
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
        });
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

    public void withdraw(int withdraw_amount)
    {
        synchronized (this)
        {
            System.out.println("Withdraw");
            try
            {
                Thread.sleep(200);
            }catch (Exception e)
            {
                System.out.println(e);
            }
            this.balance = this.balance - withdraw_amount;
        }
    }

    public synchronized void deposit(int deposit_amount)
    {
        System.out.println("This is deposit");
        this.balance = this.balance + deposit_amount;
    }
}
