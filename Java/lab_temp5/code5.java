import java.util.*;
import java.io.*;

class code5
{
    public static void main(String[] args) throws InterruptedException
    {

        account user = new account(2000);
        Thread thr1 = new Thread(new Runnable() {
            @Override
            public void run() {
                user.withdraw(30000);
            }
        });
        Thread thr2 = new Thread(new Runnable() {
            @Override
            public void run()
            {
                user.deposit(40000);
            }
        });
        thr1.start();
        thr2.start();
        thr1.join();
        thr2.join();
        System.out.println(user.balance);
    }
}

class account {
    public int balance;

    public account(int balance)
    {
        this.balance = balance;
    }

    public synchronized void withdraw(int withdraw_amount)
    {
        System.out.println("Withdrawal");
        while (withdraw_amount > this.balance)
        {
            System.out.println("Thread is waiting ");
            try
            {
                wait();
            } catch (Exception e)
            {
                System.out.println(e);
            }
        }
        System.out.println("Withdrawal happening ");
        this.balance = this.balance - withdraw_amount;
    }

    public synchronized void deposit(int deposit_amount)
    {
        System.out.println("Depositing");
        this.balance = this.balance + deposit_amount;
        System.out.println("I am notifying...");
        notify();
    }
}