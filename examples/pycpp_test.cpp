#include "../include/pycpp.hpp"
#include "../include/pycpp_keywords.hpp"
#include "../include/pycpp_data_structures.hpp"
#include "../include/pycpp_exceptions.hpp"


using namespace py;


// void greet(str name) {
//     print("Hello", name);
// }

// float add(int a, int b) {
//     return a + b;
// }


int main(){

    // print("Hello world!");
    // print("This is C++, but it feels like Python 😎");


    // str name1 = "Treasure";
    // int age1 = 20;
    // float pi = 3.14;
    // bool is_happy = True;

    // print("Name:", name1);
    // print("Age:", age1);
    // print("Pi:", pi);
    // print("Happy?", is_happy);


    // str name2 = input("What is your name? ");
    // int age2 = inputInt("How old are you? ");

    // print("Nice to meet you,", name2);
    // print("You are", age2, "years old.");

    // int age3 = inputInt("Enter your age: ");

    // if (age3 >= 18) {
    //     print("You're an adult.");
    // } else {
    //     print("You're still young.");
    // }


    // for (int i : range(5)) {
    //     print("Counting:", i);
    // }

    // print("Now backwards:");
    // for (int i : range(5, 0, -1)) {
    //     print(i);
    // }


    // greet("Python C++ Learner");

    // float result = add(3, 5);
    // print("3 + 5 =", result);


    // vector<str> names = {"Mani", "Treas"};

    // print("lenght of the names =", len(names));



    // pylist<int> numbers = {10, 20, 30, 40};
    // numbers.print();

    // numbers.append(50);
    // numbers.print();
    
    // numbers.insert(2, 25);     // [10, 20, 25, 30, 40, 50]
    // numbers.print();

    // numbers.remove(30);        // [10, 20, 25, 40, 50]
    // numbers.print();

    // numbers.pop();             // [10, 20, 25, 40]
    // numbers.print();

    // numbers.clear();           // []
    // numbers.print();


    // print("Final list size:", len(numbers));
    // numbers.print(); 

    // pylist<int> nums = {1, 2, 3};
    // nums.print();
    // nums.append(4);
    // nums.pop();
    // nums.append(10);

    // print("List size:", len(nums));
    // nums.print();

    // nums[0] = 10;
    // print(nums[1]);

    // for (int x : nums) {
    //     print("Item:", x);
    // }


    //  try {
    //     throw PyIndexError("index 10 out of range");
    // } catch (const std::exception& e) {
    //     print(e.what());
    // }

    // // Example 2: PyValueError
    // try {
    //     throw PyValueError("invalid value passed to remove()");
    // } catch (const std::exception& e) {
    //     print(e.what());
    // }

    // // Example 3: PyTypeError
    // try {
    //     throw PyTypeError("expected int, got str");
    // } catch (const std::exception& e) {
    //     print(e.what());
    // }

    // // Example 4: PyKeyError
    // try {
    //     throw PyKeyError("key 'username' not found in dict");
    // } catch (const std::exception& e) {
    //     print(e.what());
    // }

    // // Example 5: PyZeroDivError
    // try {
    //     throw PyZeroDivError("division by zero");
    // } catch (const std::exception& e) {
    //     print(e.what());
    // }




    // pylist<int> nums = {10, 20, 30};

    // print("Initial list:");
    // nums.print();

    // // Try valid operations
    // nums.append(40);
    // nums.insert(1, 15);     // Insert at index 1
    // nums.remove(30);        // Remove value 30

    // print("\nAfter append, insert, and remove:");
    // nums.print();

    // // Try accessing a valid index
    // try {
    //     print("\nnums[0] =", nums[0]);
    // } catch (const std::exception& e) {
    //     print(e.what());
    // }

    // // ------------- Exception tests below -------------

    // // Test pop on empty list
    // try {
    //     pylist<int> empty;
    //     empty.pop();  // should throw PyIndexError
    // } catch (const std::exception& e) {
    //     print("\nCaught exception on pop():", e.what());
    // }

    // // Test invalid index access
    // try {
    //     int value = nums[100];  // should throw PyIndexError
    // } catch (const std::exception& e) {
    //     print("\nCaught exception on index access:", e.what());
    // }

    // // Test invalid insert
    // try {
    //     nums.insert(999, 50);  // should throw PyIndexError
    // } catch (const std::exception& e) {
    //     print("\nCaught exception on insert():", e.what());
    // }

    // // Test removing a missing value
    // try {
    //     nums.remove(999);  // should throw PyValueError
    // } catch (const std::exception& e) {
    //     print("\nCaught exception on remove():", e.what());
    // }


    // pydict<std::string, int> scores = {
    //     {"Alice", 90},
    //     {"Bob", 85}
    // };

    // scores.set("Charlie", 78);

    // print("Initial dict:");
    // scores.print();

    // print("\nAlice score:", scores.get("Alice"));

    // try {
    //     print("\nTrying unknown key:");
    //     scores.get("Daniel");  // should raise PyKeyError
    // } catch (const std::exception& e) {
    //     print(e.what());
    // }

    // scores.remove("Bob");

    // print("\nAfter removing Bob:");
    // scores.print();

    // print("\nKeys and values:");
    // for (const auto& [name, score] : scores) {
    //     print(name, "→", score);
    // }
    


    // pydict<std::string, int> ages = {
    //     {"Alice", 22},
    //     {"Bob", 25}
    // };

    // // .get()
    // int aliceAge = ages.get("Alice", -1);   // 22
    // int eveAge = ages.get("Eve", 0);        // 0
    // print("alice age", aliceAge);
    // print("eve age", eveAge);

    // // .keys()
    // for (auto key : ages.keys()) {
    //     std::cout << "key: " << key << "\n";
    // }

    // // .values()
    // for (auto val : ages.values()) {
    //     std::cout << "value: " << val << "\n";
    // }

    // // .items()
    // for (auto [k, v] : ages.items()) {
    //     std::cout << k << ": " << v << "\n";
    // }


    pydict<std::string, int> scores = {
        {"John", 90},
        {"Jane", 95}
    };

    int jane = scores.pop("Jane");           // 95
    int not_found = scores.pop("Doe");  
    // scores.pop("Ghost"); // throws KeyError

    pydict<std::string, int> backup = scores.copy(); // deep copy
    scores.clear();

    backup.print();  // still has data
    scores.print();  // empty


    return 0;
}
