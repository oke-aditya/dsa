// package threading;
// Thread scheduler in java is the part of the JVM that decides which thread should run.

// There is no guarantee that which runnable thread will be chosen to run by the thread scheduler.

// Only one thread at a time can run in a single process.

// The thread scheduler mainly uses preemptive or time slicing scheduling to schedule the threads.

// Thread scheduler can be based on thread priority.

// Preemptive scheduling :
 
// Under preemptive scheduling the highest priority task executes until it
//  Enters  the waiting or dead  states or a higher priority task  comes into existence.

// Time slicing:
 
// Under time slicing, a task executes for a predefined slice of time and then reenters
// the pool of ready tasks. The scheduler then determines which task should execute next, based on priority and other factors.

// Description:
// All Java threads have a priority and the thread with he highest priority is scheduled to run by the JVM .

// In case two threads have the same priority a FIFO ordering is followed.

// Thread Priorities:

// JVM selects to run a Runnable thread with the highest priority.

// All Java threads have a priority in the range 1-10.

// Top priority is 10, lowest priority is 1.Normal priority by default is 5.

// Thread.MIN_PRIORITY - minimum thread priority.
// Thread.MAX_PRIORITY - maximum thread priority.
// Thread.NORM_PRIORITY - maximum thread priority.

public class thread_scheduling
{

    
}
