# CPP Module 00 - Introduction to C++

## Table of Contents

1. [Project Overview](#project-overview)
2. [Project Structure](#project-structure)
3. [Fundamental Concepts of C++](#fundamental-concepts-of-c)
4. [Exercise Breakdown](#exercise-breakdown)
   - [Ex00: Megaphone](#ex00-megaphone)
   - [Ex01: My Awesome PhoneBook](#ex01-my-awesome-phonebook)
   - [Ex02: Job of Your Dreams](#ex02-job-of-your-dreams)
5. [Compiling and Running](#compiling-and-running)
6. [Key Takeaways](#key-takeaways)

---

## Project Overview

The **CPP Module 00** introduces essential C++ concepts, focusing on transitioning from C to C++. This module emphasizes:

- The **differences between C and C++**
- **Encapsulation** using classes and objects
- **I/O streams** for input and output operations
- The **importance of memory management**

By completing this module, students will gain a solid foundation in **C++98**, preparing them for more advanced topics in object-oriented programming.

---

## Project Structure

```plaintext
CPP00/
├── ex00/
│   ├── megaphone.cpp
│   ├── Makefile
├── ex01/
│   ├── Phonebook.hpp
│   ├── Phonebook.cpp
│   ├── Contact.hpp
│   ├── Contact.cpp
│   ├── main.cpp
│   ├── Makefile
├── ex02/
│   ├── Account.hpp
│   ├── Account.cpp
│   ├── tests.cpp
│   ├── Makefile
└── README.md
```

---

## Fundamental Concepts of C++

### 1. Understanding Standard I/O Streams

Unlike **C** where we use `printf` and `scanf`, C++ introduces `std::cout` and `std::cin` from the `<iostream>` library.

```cpp
#include <iostream>
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

- `std::cout` prints to the console
- `std::endl` adds a newline
- `std::cin` is used for input

### 2. Namespaces and Scope

C++ allows **namespaces** to avoid name conflicts in larger projects:

```cpp
namespace myNamespace {
    void sayHello() { std::cout << "Hello!" << std::endl; }
}
int main() {
    myNamespace::sayHello();
    return 0;
}
```

### 3. Constants, Static Variables, and Object-Oriented Programming

#### Introduction to Object-Oriented Programming (OOP)

Object-Oriented Programming (OOP) is introduced in **Exercise 02** with the implementation of classes. OOP is a paradigm that allows structuring programs in a way that models real-world entities.

Key OOP concepts introduced in this module:

- **Encapsulation:** Keeping an object's data private and only exposing necessary functionalities through public methods.
- **Constructors & Destructors:** Special functions that initialize and clean up objects.
- **Static Members:** Attributes or methods shared among all instances of a class.

#### **Example: Creating a Class in C++**

```cpp
class Example {
private:
    int value;
public:
    Example(int v) : value(v) {} // Constructor
    ~Example() {} // Destructor
    void showValue() const { std::cout << "Value: " << value << std::endl; }
};

int main() {
    Example obj(42);
    obj.showValue();
    return 0;
}
```

- **`private`**: The variable `value` is only accessible within the class.

- **Constructor** (`Example(int v)`) initializes the object.

- **Destructor** (`~Example()`) cleans up the object when it goes out of scope.

- `const` defines immutable variables

- `static` ensures a variable retains its value between function calls

---

## Exercise Breakdown

### Ex00: Megaphone

#### **Objective:**

Convert user input into uppercase text and print it to the console.

#### **Concepts Covered:**

- Handling **command-line arguments** (`argc`, `argv`)
- Using **`std::toupper()`** to manipulate characters
- Output formatting with `std::cout`

#### **Implementation:**

```cpp
#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < argc; ++i)
        {
            for (size_t j = 0; j < std::strlen(argv[i]); ++j)
                std::cout << (char)std::toupper(argv[i][j]);
            if (i < argc - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
```

---

### Ex01: My Awesome PhoneBook

#### **Objective:**

Create a simple **contact management system** that allows users to:

1. `ADD` a new contact (up to 8 contacts stored in an array)
2. `SEARCH` existing contacts with formatted output
3. `EXIT` the program

#### **Concepts Covered:**

- Defining and using **classes**
- Encapsulation: using **private attributes** and **public methods**
- Formatting output using **`std::setw`**, which is used to set the width of an output field, ensuring that values align properly in formatted output. This is particularly useful when displaying tabular data in the terminal.

#### **Example:**

```cpp
#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::setw(10) << "Name" << std::setw(10) << "Age" << std::endl;
    std::cout << std::setw(10) << "Alice" << std::setw(10) << 25 << std::endl;
    std::cout << std::setw(10) << "Bob" << std::setw(10) << 30 << std::endl;
    return 0;
}
```

#### **Explanation:**

- `std::setw(n)`: Sets the field width to `n` characters.
- Right-aligns output by default.
- Useful for printing structured tables or aligning text properly.

---

### Ex02: Job of Your Dreams

#### **How to Test Our Implementation:**

To test our `Account.cpp` implementation effectively:

1. Compile the project:
```sh
make
```
2. Run the executable and redirect its output:
```sh
./bank > test.txt
```
3. Open the provided file `19920104_091532.log` and replace all timestamps with the one used in `test.txt`. You can do this using a text editor or a script.

4. Finally, compare both files:
```sh
diff test.txt 19920104_091532.log
```

If `diff` returns nothing, it means our output matches the expected log.
#### **Functions Used:**

##### `time()` and `localtime()` (from `<ctime>`)

- `time(nullptr)`: Returns the current time in seconds since **January 1, 1970** (Unix epoch).
- `localtime()`: Converts this time into a human-readable format (hours, minutes, etc.).
  ```cpp
  #include <iostream>
  #include <ctime>
  int main() {
      time_t now = time(nullptr);
      tm *ltm = localtime(&now);
      std::cout << "Current Time: " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << std::endl;
      return 0;
  }
  ```

##### `std::setfill()` (from `<iomanip>`)

- `std::setfill(char)`: Fills empty spaces in formatted output with a specified character.
  ```cpp
  #include <iostream>
  #include <iomanip>
  int main() {
      std::cout << std::setfill('-') << std::setw(10) << 42 << std::endl;
      return 0;
  }
  ```
  **Output:**
  ```
  --------42
  ```

#### **Objective:**

Reconstruct a missing `Account.cpp` file for a banking system using an existing **header file and test logs**.

#### **Concepts Covered:**

- Implementing a **class** from a given header (`Account.hpp`)
- Understanding **constructors and destructors**
- Managing **static class members**

## Compiling and Running

Each exercise includes a **Makefile** for easier compilation:

1. Navigate to the desired exercise:
   ```sh
   cd ex00
   ```
2. Compile the project:
   ```sh
   make
   ```
3. Run the program:
   ```sh
   ./<executable_name>
   ```
4. Clean compiled files:
   ```sh
   make clean
   ```
5. Remove all compiled files (including executables):
   ```sh
   make fclean
   ```
6. Recompile everything from scratch:
   ```sh
   make re
   ```

---

## Key Takeaways

By completing this module, we will have learned:

- The **basics of C++ I/O handling**
- **Object-Oriented Programming** concepts like **encapsulation**
- How to use **classes and member functions**
- Understanding **header files** and **static variables**

This module lays the foundation for **CPP01**, where we will explore **inheritance, operator overloading, and more advanced OOP techniques.**

