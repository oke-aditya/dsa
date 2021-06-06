// package threading;

// Thread can be craeted in 2 ways
// extending the Thread class
// implementing the Runnable interface

import java.lang.Thread;

public class threading_intro {
    public static void main(String[] args) {
        Thread Thr1 = new Thread(new Runnable() {
            public void run() {
                // Thread.wait();
                Thr1.wait();
            }
        });
        Thr1.start();
    }
}
