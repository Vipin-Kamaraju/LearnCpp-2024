Intel's **oneAPI Threading Building Blocks (oneTBB)** is a comprehensive C++ library designed to facilitate parallel programming by providing a range of classes and functions. Here's an overview of its primary components:

### 1. **Parallel Algorithms**
- **`parallel_for`**: Executes loop iterations in parallel.
- **`parallel_reduce`**: Combines parallel iteration with reduction operations.
- **`parallel_scan`**: Performs parallel prefix operations.
- **`parallel_sort`**: Sorts collections in parallel.
- **`parallel_pipeline`**: Manages parallel execution of pipeline stages.
- **`parallel_invoke`**: Executes multiple functions concurrently.

### 2. **Concurrent Containers**
- **`concurrent_queue`**: Thread-safe FIFO queue.
- **`concurrent_priority_queue`**: Thread-safe priority queue.
- **`concurrent_vector`**: Dynamic array supporting concurrent growth.
- **`concurrent_hash_map`**: Thread-safe hash map.
- **`concurrent_unordered_map`**: Thread-safe unordered map.
- **`concurrent_unordered_set`**: Thread-safe unordered set.

### 3. **Memory Allocation**
- **`scalable_malloc`**: Efficient memory allocation for multithreaded applications.
- **`scalable_free`**: Deallocates memory allocated by `scalable_malloc`.
- **`scalable_allocator`**: STL-compatible allocator using scalable memory allocation.
- **`cache_aligned_allocator`**: Allocates cache-aligned memory.

### 4. **Synchronization Primitives**
- **`mutex`**: Standard mutex for thread synchronization.
- **`spin_mutex`**: Lightweight mutex with spin-waiting.
- **`queuing_mutex`**: Fair mutex ensuring FIFO ordering.
- **`spin_rw_mutex`**: Spin-locking reader-writer mutex.
- **`queuing_rw_mutex`**: Queuing reader-writer mutex.
- **`recursive_mutex`**: Mutex allowing recursive locking by the same thread.

### 5. **Task Scheduler**
- **`task_group`**: Manages a group of tasks.
- **`task_arena`**: Controls task execution environments.
- **`task_scheduler_handle`**: Manages the lifetime of the task scheduler.

### 6. **Flow Graph**
- **`flow::graph`**: Defines a dependency graph for tasks.
- **`flow::continue_node`**: Node that executes upon receiving a continue message.
- **`flow::function_node`**: Node that applies a function to incoming messages.
- **`flow::join_node`**: Synchronizes multiple input messages.
- **`flow::split_node`**: Splits a tuple into separate messages.

