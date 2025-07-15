// pycpp.hpp
#ifndef PYCPP_HPP
#define PYCPP_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Print like Python
inline void print() {
    cout << endl;
}

template<typename T, typename... Args>
inline void print(T first, Args... rest) {
    cout << first << " ";
    print(rest...);
}

// Input like Python
inline string input(const string& prompt = "") {
    cout << prompt;
    string value;
    getline(cin, value);
    return value;
}

// Input as int or float
inline int inputInt(const string& prompt = "") {
    return stoi(input(prompt));
}

inline float inputFloat(const string& prompt = "") {
    return stof(input(prompt));
}

// Length like Python
template<typename T>
inline size_t len(const T& container) {
    return container.size();
}

// Range like Python (for-each compatible)
inline vector<int> range(int end) {
    vector<int> r;
    for (int i = 0; i < end; ++i) r.push_back(i);
    return r;
}

inline vector<int> range(int start, int end, int step = 1) {
    vector<int> r;
    for (int i = start; (step > 0 ? i < end : i > end); i += step)
        r.push_back(i);
    return r;
}

#endif // PYCPP_HPP
