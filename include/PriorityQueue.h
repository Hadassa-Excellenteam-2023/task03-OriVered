#pragma once

#include <iostream>
#include <list>
#include <exception>

/* Struct Comparator Require for Priority Queue*/
template<typename T>
struct MyComparator {
	T operator()(T a, T b) const {
		return a - b;
	}
};

/* Requirements for template */
template <typename T>
concept Streamable = requires(T a, std::ostream & os) {
	{ os << a };
};

template <typename T>
concept Subtractable = requires(T a, T b) {
	{ a - b } -> std::same_as<T>;
};

template <typename T>
concept ComparableToInteger = requires(T a, int i) {
	{ a < i } -> std::convertible_to<bool>;
};

/* PriorityQueue class template*/
template <typename T>
class PriorityQueue {
	using list = std::list<T>;
	using exception = std::exception;
public:

	/* Constructor */
	PriorityQueue();

	/* Mutator */
	void push(const T& t); 

	/* Accessor */
	T poll();

private:
	/* Privete member*/
	list m_queue;
};

template<typename T>
PriorityQueue<T>::PriorityQueue()
	: m_queue(){
}

template<typename T>
void PriorityQueue<T>::push(const T& t) {
    auto it = m_queue.begin();
    while (it != m_queue.end() && MyComparator<T>{}(*it, t) < 0) {
        ++it;
    }
    m_queue.insert(it, t);
}

template<typename T>
T PriorityQueue<T>::poll() {
	if (m_queue.empty()) {
		throw std::exception("PriorityQueue empty!");
	}

	T highest_priority_element = m_queue.front();
	m_queue.erase(m_queue.begin());
	return highest_priority_element;
}


