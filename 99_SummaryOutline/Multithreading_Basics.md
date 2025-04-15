# Multithreading

### **Summary**
Synchronization in threads is a mechanism to:
- Prevent multiple threads from interfering with each other when accessing shared resources.
- Ensure thread safety and program correctness.
- Avoid issues like race conditions, data corruption, deadlocks, and resource contention.

It is achieved through techniques like **mutexes**, **locks**, **condition variables**, and **atomic operations**, depending on the complexity and nature of the shared resources.

---

When multiple threads access shared resources simultaneously:
1. **Race Conditions**:
   - Two or more threads modify shared data at the same time, leading to unpredictable or incorrect results.
   - Here in the below code, we expect the sharedCounter to have a value of `2000` after execution of both the threads. But since there is no synchronization the value will not be `2000` at the end of code execution.
   - What is wrong then in this case? Is it the integer 'i'
   - **Ans:** The issue is not with the variable `i`. Each thread has its own copy of i since it is a local variable in the `increment()` function. Both threads are accessing and modifying sharedCounter simultaneously without any **`synchronization`**
   - Since both t1 and t2 will access sharedCounter simultaneously, lets assume t1 read the value as 500 --> incremented by 1 --> at this point t2 is writing value of sharedPointer as 326 --> t1 overwrites sharedCounter 501 --> t2 reads value as 501
   - Example:
     ```cpp
     int sharedCounter = 0;

     void increment() {
         for (int i = 0; i < 1000; ++i) {
             ++sharedCounter; // Multiple threads might modify this simultaneously.
         }
     }

     int main() {
         std::thread t1(increment);
         std::thread t2(increment);
         t1.join();
         t2.join();
         std::cout << "Final counter: " << sharedCounter << std::endl; // Incorrect result!
         return 0;
     }
     ```
     Without synchronization, the threads might interfere with each other while updating `sharedCounter`, resulting in a value less than `2000`.

2. **Data Corruption**:
   - Without proper synchronization, threads may leave shared data in an inconsistent state.

3. **Thread Safety**:
   - Synchronization ensures that critical sections of code, where shared resources are accessed or modified, are executed by only one thread at a time.

<div style="page-break-after: always;"></div>

---

### **How is Synchronization Achieved?**

1. **Solution 1 : Mutex (Mutual Exclusion)**: Old way to do it
   - A `mutex` is a synchronization primitive that allows only one thread to access a critical section at a time.
   - Threads attempting to access the same resource must acquire the mutex first. If the mutex is already locked by another thread, the requesting thread will block until the mutex is released.
   - This is an old way since if you forget to unlock you might cause an error
   - The span of a mutex is until the mtx lock is in scope. When it is out of scope it automatically unlocks.
   - Example:
     ```cpp
     	#include <mutex>
        
        int sharedCounter = 0;
        std::mutex mtx;
        
		void increment() {
    		for (int i = 0; i < 1000; ++i) {
        		mtx.lock(); // Lock the mutex
        		++sharedCounter;
        		mtx.unlock(); // Unlock the mutex
    		}
		}

     ```

2. **Solution 2: Locks `std::lock_guard` & `std::unique_lock`**
   - This is more modern C++ way of doing multithreading. It is part of STL and you dont need to take care about the unlock of thread.
   - Locks are similar to mutexes, but they provide more fine-grained control.
   - Types:
     - **std::lock_guard**: Simplifies mutex usage by automatically locking and unlocking.
     - **std::unique_lock**: Provides more flexibility, such as deferred locking or condition variables.
        ```cpp       
		void increment() {
    		for (int i = 0; i < 1000; ++i) {
        		std::lock_guard<std::mutex> lock(mtx); // Automatically locks the mutex
        		++sharedCounter;
    		}
		}
        ```
3. **Solution 3: Atomic Operations**
   - For simple operations, such as incrementing a variable, you can use atomic variables.
   - **Advantage:** These are lock-free and thread-safe by design.
   - Example:
     ```cpp
     #include <atomic>
     #include <thread>
     #include <iostream>

     std::atomic<int> sharedCounter(0);

     void increment() {
         for (int i = 0; i < 1000; ++i) {
             ++sharedCounter; // Atomic increment
         }
     }


<div style="page-break-after: always;"></div>

---
## Adding conditions to threads `std::condition_variable`

**Use Case:**
- You want to ensure that a worker thread starts its task only after a certain condition is met. 
- For example: The main thread prepares some shared data (ready), and the worker thread should wait until the data is ready before proceeding.

**Condition Variables**:
   - Used to block a thread until a specific condition is met.
   - A thread waits for a condition variable while another thread signals it to resume execution.
   
**Solution with Condition Variables**
We use a condition variable (std::condition_variable) to:
- Put the worker thread into a waiting state.
- Notify the worker thread when the condition is met (using notify_one() or notify_all()).

**Explanation of Code below**
- Step 1: we initialize a condition variable and a shared flag to indicate readiness
- Step 2: We apply a lock on the thread we want to wait using `cv.wait(lock, [] { return dataReady; });`
- Step 3: set the ready flag and notify the thread using `cv.notify_one()`
- Also notice : consumer is using unique_lock and producer is using lock_gaurd
- `std::lock_guard` does not allow **unlocking** or **re-locking** of the mutex during its lifetime. Once locked, the std::lock_guard keeps the mutex locked until it goes out of scope.
- Also you will get a compilation error, because `cv.wait()` expects a `std::unique_lock` as its first parameter, not a `std::lock_guard`

**Example:**

```cpp
#include <iostream> #include <thread> #include <mutex> #include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool dataReady = false; // Shared flag to indicate readiness

void consumer() {
    std::unique_lock<std::mutex> lock(mtx); // Acquire the lock
    cv.wait(lock, [] { return dataReady; }); // Wait until dataReady is true
    std::cout << "Consumer: Data is ready. Processing data...\n";
}

void producer() {
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate data preparation
    {
        std::lock_guard<std::mutex> lock(mtx); // Acquire the lock
        dataReady = true; // Set the shared condition to true
        std::cout << "Producer: Data is ready.\n";
    }
    cv.notify_one(); // Notify the waiting consumer thread
}

int main() {
    std::thread t1(consumer);
    std::thread t2(producer);

    t1.join();
    t2.join();
    return 0;
}

```

<div style="page-break-after: always;"></div>


---

### **Common Synchronization Problems**
1. **Deadlocks**:
   - Occur when two or more threads wait for resources that the other threads hold, creating a circular dependency where no thread can proceed.
   - Example of a deadlock:
     ```cpp
     std::mutex mtx1, mtx2;

     void thread1() {
         std::lock_guard<std::mutex> lock1(mtx1);
         std::lock_guard<std::mutex> lock2(mtx2);
     }

     void thread2() {
         std::lock_guard<std::mutex> lock1(mtx2);
         std::lock_guard<std::mutex> lock2(mtx1);
     }
     ```

2. **Livelocks**:
   - Threads remain active but cannot make progress because they keep responding to each other’s actions.

3. **Starvation**:
   - A thread is perpetually denied access to resources because other threads keep "hogging" them.

---

<div style="page-break-after: always;"></div>

---
## Synchronization Primitive Theory

A synchronization primitive is a fundamental tool in concurrent programming used to manage coordination, execution order, and data safety among multiple threads or processes running concurrently[1][2]. These primitives ensure that:

1. Multiple threads don't simultaneously execute specific segments of code (critical sections)
2. The program and data remain in a consistent state
3. Deadlocks and race conditions are prevented or managed

Synchronization primitives are characterized by their atomic operations, which guarantee that the manipulation of these primitives cannot be interrupted by other threads[5]. This atomicity is crucial for maintaining thread safety and preventing race conditions.

## Common Synchronization Primitives

1. **Mutexes**: Provide mutual exclusion for shared resources
2. **Condition Variables**: Used to notify threads about the state of shared data
3. **Semaphores**: Control access to a limited number of resources
4. **Atomic Operations**: Ensure indivisible read-modify-write operations
5. **Barriers**: Synchronize multiple threads at a specific point in execution
6. **Latches**: Single-use coordination tools introduced in C++20

These primitives are typically provided by the operating system or programming language runtime, offering a standardized way for developers to manage concurrent access to shared resources and coordinate thread execution[8].

## Importance in Multithreading

Synchronization primitives are essential for creating reliable and predictable multithreaded applications. They help prevent common concurrency issues such as:

- Race conditions
- Deadlocks
- Data corruption
- Inconsistent program states

By using these primitives effectively, developers can ensure that their multithreaded programs behave correctly and efficiently, even in complex concurrent scenarios.

<div style="page-break-after: always;"></div>

---

## Latches vs Barriers C++20 features multithreading

Latches and barriers are synchronization primitives introduced in C++20 to help coordinate threads in concurrent programming.

## Latches (std::latch)

Latches are single-use synchronization tools that allow one or more threads to wait until a set number of operations have been completed. Key features include:

1. Initialized with a preset count.
2. Threads can decrement the count using the count_down() method.
3. Threads can wait until the count reaches zero using the wait() method.
4. Cannot be reset or reused once the count reaches zero.
```cpp
#include <latch> #include <thread>

std::latch latch(3);

void worker(int id) {
    // Work simulation
    latch.count_down();
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 1; i <= 3; ++i)
        threads.emplace_back(worker, i);
    
    latch.wait();
    // All workers have completed
}
```

## Barriers (std::barrier)

Barriers are reusable synchronization primitives that help manage repeated tasks by multiple threads. Key features include:

1. Can be used multiple times, unlike latches.
2. Allows execution of a completion function when the counter reaches zero.
3. Useful for coordinating threads across different phases of a distributed computation.
```cpp
#include <barrier> #include <thread>

std::barrier barrier(3, []{ std::cout << "Phase complete\n"; });

void worker(int id) {
    // Phase 1 work
    barrier.arrive_and_wait();
    // Phase 2 work
    barrier.arrive_and_wait();
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 1; i <= 3; ++i)
        threads.emplace_back(worker, i);
    
    // Threads will synchronize after each phase
}
```
<div style="page-break-after: always;"></div>
---
## Difference b/w Mutex vs Latches vs Barriers

Latches and barriers are synchronization primitives that differ from mutexes in several key aspects:

## Purpose and Usage

1. **Mutexes** are used for mutual exclusion, ensuring that only one thread can access a shared resource at a time[3].

2. **Latches** are single-use coordination tools that allow one or more threads to wait until a set number of operations have been completed[1][2].

3. **Barriers** are reusable synchronization mechanisms that enable multiple threads to synchronize at a specific point before proceeding[1][2].

## Functionality

1. **Mutexes** operate on a lock/unlock principle, where a thread acquires the lock to access a shared resource and releases it when done[3].

2. **Latches** use a countdown mechanism. Threads can decrement the count, and other threads wait until the count reaches zero[2][6].

3. **Barriers** synchronize a group of threads, allowing them to wait until all threads have reached the barrier point before proceeding[4][6].

## Reusability

1. **Mutexes** can be locked and unlocked multiple times.

2. **Latches** are single-use objects. Once the count reaches zero, they cannot be reset or reused[1][2].

3. **Barriers** are reusable. After all threads have synchronized, the barrier can be used again for the next phase or iteration[1][4].

## Performance and Implementation

Latches and barriers often use atomic operations and lock-free algorithms, potentially offering better performance than mutex-based solutions in certain scenarios[1].

## Use Cases

1. **Mutexes** are ideal for protecting shared resources in critical sections.

2. **Latches** are useful for one-time coordination events, such as program initialization or shutdown[2].

3. **Barriers** are effective for coordinating multiple threads across different phases of a distributed computation[3][4].

In summary, while mutexes focus on protecting shared resources, latches and barriers provide simpler and often more efficient mechanisms for thread coordination and synchronization in specific scenarios.

<div style="page-break-after: always;"></div>

---
## concept of memory order in atomic operations

Memory order in atomic operations is a crucial concept in C++ multithreading that specifies how memory accesses are ordered around atomic operations. It allows developers to fine-tune the synchronization behavior and performance of concurrent code.

### Key Aspects of Memory Order

1. **Synchronization Control**: Memory orders define the synchronization and ordering constraints for atomic operations, affecting how changes to memory are observed by different threads.

2. **Performance Optimization**: By choosing appropriate memory orders, developers can optimize performance by relaxing unnecessary synchronization.

3. **Visibility Guarantees**: Memory orders establish "happens-before" relationships, ensuring that changes made in one thread are visible to other threads under specific conditions.

## Types of Memory Orders

1. **Relaxed (memory_order_relaxed)**: Provides no synchronization or ordering guarantees beyond the atomicity of the operation itself.

2. **Acquire (memory_order_acquire)**: Ensures that subsequent reads in the same thread cannot be reordered before the atomic operation.

3. **Release (memory_order_release)**: Ensures that previous writes in the same thread cannot be reordered after the atomic operation.

4. **Acquire-Release (memory_order_acq_rel)**: Combines the effects of both acquire and release orders for read-modify-write operations.

5. **Sequential Consistency (memory_order_seq_cst)**: Provides the strongest guarantees, ensuring a total order of operations across all threads.

## Importance in Multithreading

Memory orders are essential for:

1. Preventing data races and ensuring thread safety.
2. Optimizing performance by avoiding unnecessary synchronization.
3. Implementing lock-free algorithms and data structures.

By carefully choosing the appropriate memory order, developers can create efficient and correct multithreaded code that balances performance and synchronization requirements.

<div style="page-break-after: always;"></div>

---
## lock_guard vs unique_lock vs scoped_lock

In C++, lock_guard, unique_lock, and scoped_lock are all RAII (Resource Acquisition Is Initialization) wrappers for mutexes, but they have different features and use cases:

## lock_guard

- Simplest and most straightforward
- Automatically locks the mutex on construction and unlocks on destruction
- Cannot be manually unlocked or relocked
- Suitable for simple, single-mutex scenarios

## unique_lock

- More flexible than lock_guard
- Can be constructed without immediately locking the mutex
- Allows manual locking, unlocking, and relocking
- Supports lock transfers and timed locking attempts
- Useful when more control over the lock is needed, such as with condition variables

## scoped_lock (C++17 and later)

- Can lock multiple mutexes simultaneously
- Prevents deadlocks when locking multiple mutexes
- Automatically unlocks all mutexes on destruction
- Replaces lock_guard for most use cases in modern C++

Key differences:

1. Flexibility: unique_lock is the most flexible, allowing manual lock management.
2. Multiple mutex support: scoped_lock can handle multiple mutexes, while lock_guard and unique_lock are designed for single mutexes.
3. Deadlock prevention: scoped_lock uses a deadlock avoidance algorithm when locking multiple mutexes.
4. Performance: lock_guard may have slightly less overhead due to its simplicity.

When to use each:

- Use scoped_lock by default in C++17 and later, especially when dealing with multiple mutexes.
- Use unique_lock when you need manual lock control or when working with condition variables.
- Use lock_guard in older codebases or when you prefer explicit, single-mutex locking for clarity.

While scoped_lock is generally recommended for new code, some developers still prefer lock_guard for its simplicity and explicit behavior, particularly when dealing with a single mutex.

---
