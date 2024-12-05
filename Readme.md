# README for C++ Module 09: STL     
Standard Template Library

## Overview

This project is part of **C++ Module 09**, focusing on mastering the **Standard Template Library (STL)** while adhering strictly to **C++98 standards**. Each exercise emphasizes efficient data handling, algorithmic problem-solving, and STL container usage. The constraints encourage thoughtful container choices for optimal solutions and provide insight into real-world problem solving.

---

## Exercises Breakdown

### 1. **Bitcoin Exchange (Exercise 00)**

**Purpose**  
The goal is to parse, validate, and process input to calculate Bitcoin value based on historical exchange rates.

**Container Choice: `std::map`**  
- A `std::map` is used to store historical exchange rates with dates as keys, allowing fast lookups for specific or nearest earlier dates (using `lower_bound`).

**Key Features**:
- **Database Parsing**: Reads exchange rates from a CSV file and stores them in a `std::map`.
- **Input Validation**: Ensures inputs follow the `YYYY-MM-DD | value` format and checks for valid ranges.
- **Calculation Logic**: Finds the closest historical rate for a given date and calculates the Bitcoin value.

**Why `std::map`**  
- `std::map` is ideal for storing sorted key-value pairs and efficiently finding the closest date with `lower_bound`.  
- The logarithmic complexity of lookups ensures fast calculations even with large datasets.

**Usage**:
- Compile:
  ```make```


### Run:

```./btc input.txt```
### Additional Commands:     
```make run```: Runs the program with the example given    
```make valgrind```: Runs the program with example given & Valgrind to check for memory leaks.       
```make totalvalgrind```: Runs t.p. with example and additional flags for valgrind   
```make sanitize```: Compiles and runs the program with example & address sanitizers.   

## 2. **Reverse Polish Notation (Exercise 01)**      
**Purpose**
- This exercise implements an RPN calculator to evaluate mathematical expressions in postfix notation.

**Container Choice: `std::stack`**  
- A `std::stack` is used to store operands during expression evaluation and performs operations on the topmost elements.    

      
**Key Features**:
- **Expression Parsing**: Processes space-separated tokens for numbers and operators (+, -, *, /).
- **Error Handling**: Catches errors such as insufficient operands or invalid operators.
- **Evaluation**: The stack stores operands and computes results by popping operands and applying operators.
     
**Why `std::stack`**
- `std::stack` is the best choice for a stack-based calculator, as it provides LIFO (Last In, First Out) functionality.
- The nature of postfix notation requires pushing operands onto the stack and applying operators to the top elements, which is a perfect fit for a stack.   
   
**Usage**:   
- Compile:
```make```
### Run:

```./rpn "3 4 + 2 *"```

### Additional Commands:
```make run```: Runs the program with example given    
```make valgrind```: Runs the program with example given & Valgrind to check for memory leaks.       
```make totalvalgrind```: Runs t.p. with example and additional flags for valgrind   
```make sanitize```: Compiles and runs the program with example & address sanitizers.   


### 3. **PmergeMe (Exercise 02)**
**Purpose**
- This exercise involves sorting a sequence of positive integers using the merge-insert sort algorithm (Ford-Johnson algorithm) and measuring performance.

**Container Choices: `std::vector` and `std::list`**

- A `std::vector` is used to handle random-access, while a std::list is used to benefit from efficient insertions and deletions.
 
**Key Features**:

- **Merge-Insertion Sort**: The program implements Ford-Johnson sorting, utilizing a combination of merge and insertion sorts.
- **Performance Measurement**: The time taken to sort is measured and displayed.
- **Multiple Containers**: The program demonstrates sorting with both a std::vector and a std::list and compares performance.   
   
**Why `std::vector`**   
`std::vector` is used for fast random access, making it ideal for algorithms that require frequent access to specific elements, like sorting.
It provides contiguous memory storage, which ensures better cache locality, resulting in faster performance for large datasets.   
   
**Why `std::list`**   
`std::list` is used for operations that require efficient insertion and deletion of elements, which can be beneficial in some parts of the sorting algorithm.   
Also, I was mistakenly assuming that `std::deque` was not to be used, thus unnecessarily complicating my life.

**Usage**:

- Compile:
```make```
- Run:
```./pmergeMe  42 2 988 322 45 65 654 3 52```
### Additional Commands:
```make run```: Runs the program with example given.   
```make valgrind```: Runs the program with example given & Valgrind to check for memory leaks.       
```make totalvalgrind```: Runs t.p. with example and additional flags for valgrind.    
```make sanitize```: Compiles and runs the program with example & address sanitizers.    
```make shuff```: Compiles and runs the program with 3000 random numbers (does not work on mac, but you can run ```./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`   to get the same outcome)```.    
### Special treat:
-Uncomment the lines 93, 97 & 108 and you will be able to see the **Ford-Johnson algorithm** in action and printed in the terminal.
## Conclusion
- This project demonstrates practical uses of STL containers (std::map, std::stack, std::vector, std::list) in C++, emphasizing their efficiency and suitability for solving various algorithmic problems. Each exercise highlights the importance of choosing the right container for the task at hand, ensuring optimal performance and correctness.

- By using the appropriate STL containers, efficient algorithms, and performance testing with tools like Valgrind and sanitizers, the project emphasizes best practices in C++ software development.
