# 🐍 C++ for Pythonistas

**Write C++ like it's Python.**

This project brings Python-style syntax, functions, exceptions, and data structures into modern C++. It’s aimed at learners transitioning from Python to C++, or anyone who prefers Python’s readability.

---

## 🔧 What This Project Provides

✅ `pylist<T>` — Python-like list with methods like `append()`, `pop()`, `insert()`, `remove()`  
✅ `pydict<K, V>` — Python-like dictionary with `get()`, `pop()`, `keys()`, `values()`, `items()`, `clear()`, `copy()`  
✅ `print()` — C++ wrapper for `std::cout`  
✅ Python-like constants — `True`, `False`, `None`  
✅ Custom exceptions with ANSI-colored output — `IndexError`, `KeyError`, `ValueError`, `TypeError`, `ZeroDivisionError`  

All written in clean, modern C++ with beginner readability in mind.

---



# 📦 Example: input() and range()

## 🔹 `input(prompt)`

```cpp
#include "include/pycpp_io.hpp"

int main() {
    std::string name = input("What is your name? ");
    print("Hello", name);
    return 0;
}
```

---

## 🔹 `range(start, stop)` `(or range(stop))`

```cpp
#include "include/pycpp_iter.hpp"  // hypothetical or future header

for (int i : range(5)) {
    print(i);  // 0 to 4
}

for (int i : range(2, 6)) {
    print(i);  // 2 to 5
}
```

## 📦 Example: `pylist`

```cpp
#include "include/pycpp_data_structures.hpp"
#include "include/pycpp_keywords.hpp"

int main() {
    pylist<int> nums = {1, 2, 3};
    nums.append(4);
    nums.insert(1, 10);
    nums.remove(3);
    nums.pop();
    nums.print();  // Output: [1, 10, 2]

    return 0;
}

```
---
## 📦 Example: `pydict`

```cpp
#include "include/pycpp_data_structures.hpp"
#include "include/pycpp_exceptions.hpp"

int main() {
    pydict<std::string, int> ages = {
        {"Alice", 25},
        {"Bob", 30}
    };

    print(ages.get("Bob"));                    // 30
    print(ages.get("Eve"));   // throws KeyError            
    ages.set("Charlie", 22);
    ages.update({{"Bob", 31}});
    ages.print();  // {"Alice": 25, "Bob": 31, "Charlie": 22}

    for (auto key : ages.keys())
        print("Key:", key);

    auto age = ages.pop("Charlie");            // Removes and returns 22
    ages.clear();                              // Empties the dict
}
```

## ⚠️ Example: `Python-style Errors`

```cpp
try {
    pylist<int> empty;
    empty.pop();  // throws IndexError
} catch (const PyIndexError& e) {
    std::cout << e.what() << std::endl;
}

try {
    pydict<std::string, int> d = {{"x", 1}};
    d.get("y");  // throws KeyError
} catch (const PyKeyError& e) {
    std::cout << e.what() << std::endl;
}

```
Output:
```
IndexError: Pop from empty pylist
KeyError: key not found in pydict: 'y'
```