# PriorityQueue Class Template

A class template that implements a priority queue data structure. It uses a `std::list` to store elements in the queue and a comparator `MyComparator` to determine the priority of elements.

## Requirements

The type `T` used in the `PriorityQueue` class template must meet the following requirements:
- Must be streamable to `std::ostream` using the `<<` operator
- Must support subtraction using the `-` operator and return the same type `T`
- Must be comparable to an integer using the `<` operator and convert to `bool`

## Class Members
# PriorityQueue Class Template

A class template that implements a priority queue data structure. It uses a `std::list` to store elements in the queue and a comparator `MyComparator` to determine the priority of elements.

## Requirements

The type `T` used in the `PriorityQueue` class template must meet the following requirements:
- Must be streamable to `std::ostream` using the `<<` operator
- Must support subtraction using the `-` operator and return the same type `T`
- Must be comparable to an integer using the `<` operator and convert to `bool`

## Class Members
### Constructor
PriorityQueue();

### Mutators
void push(const T& t);
Inserts an element `t` into the priority queue.

### Accessors
T poll();
Retrieves and removes the highest-priority element from the queue. Throws an `std::exception` if the queue is empty.
