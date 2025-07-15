#ifndef PYCPP_DATA_STRUCTURES_HPP
#define PYCPP_DATA_STRUCTURES_HPP

#include <vector>
#include <iostream>
#include <algorithm>

#include "pycpp_exceptions.hpp" 
#include <map> 
#include <sstream>

template<typename T>
std::string to_string(const T& key) {
    std::ostringstream oss;
    oss << key;
    return oss.str();
}

template<typename T>
class pylist {
private:
    std::vector<T> data;

public:
    pylist() {}

    pylist(std::initializer_list<T> init) : data(init) {}

    void append(const T& item) {
        data.push_back(item);
    }

    void pop() {
        if (data.empty()) {
            throw IndexError("pop from empty pylist");
        }
        data.pop_back();
    }

    void clear() {
        data.clear();
    }

    void insert(size_t index, const T& value) {
        if (index > data.size()) {
            throw IndexError("insert index out of range");
        }
        data.insert(data.begin() + index, value);
    }

    void remove(const T& value) {
        auto it = std::find(data.begin(), data.end(), value);
        if (it == data.end()) {
            throw ValueError("value not found in pylist");
        }
        data.erase(it);
    }

    T& operator[](size_t index) {
        if (index >= data.size()) {
            throw IndexError("index out of range in pylist");
        }
        return data[index];
    }

    size_t size() const {
        return data.size();
    }

    auto begin() { return data.begin(); }
    auto end() { return data.end(); }

    void print() {
        std::cout << "[";
        for (size_t i = 0; i < data.size(); ++i) {
            std::cout << data[i];
            if (i != data.size() - 1)
                std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
};



template<typename K, typename V>
class pydict {
private:
    std::map<K, V> data;

    // ------------------ KEY VIEW ------------------
    class KeyView {
        const std::map<K, V>& data;
    public:
        KeyView(const std::map<K, V>& d) : data(d) {}

        class Iterator {
            typename std::map<K, V>::const_iterator it;
        public:
            Iterator(typename std::map<K, V>::const_iterator i) : it(i) {}
            const K& operator*() const { return it->first; }
            Iterator& operator++() { ++it; return *this; }
            bool operator!=(const Iterator& other) const { return it != other.it; }
        };

        Iterator begin() const { return Iterator(data.begin()); }
        Iterator end() const { return Iterator(data.end()); }
    };

    // ------------------ VALUE VIEW ------------------
    class ValueView {
        const std::map<K, V>& data;
    public:
        ValueView(const std::map<K, V>& d) : data(d) {}

        class Iterator {
            typename std::map<K, V>::const_iterator it;
        public:
            Iterator(typename std::map<K, V>::const_iterator i) : it(i) {}
            const V& operator*() const { return it->second; }
            Iterator& operator++() { ++it; return *this; }
            bool operator!=(const Iterator& other) const { return it != other.it; }
        };

        Iterator begin() const { return Iterator(data.begin()); }
        Iterator end() const { return Iterator(data.end()); }
    };

public:
    // ------------------ Constructors ------------------
    pydict() {}
    pydict(std::initializer_list<std::pair<const K, V>> init) : data(init) {}

    pydict(typename std::map<K, V>::const_iterator begin,
       typename std::map<K, V>::const_iterator end) {
    for (auto it = begin; it != end; ++it) {
        data[it->first] = it->second;
    }
}

    // ------------------ Basic Methods ------------------
    void set(const K& key, const V& value) {
        data[key] = value;
    }

    V& get(const K& key) {
        auto it = data.find(key);
        if (it == data.end()) {
            throw KeyError("key not found in pydict: '" + key_to_string(key) + "'");
        }
        return it->second;
    }

    V get(const K& key, const V& default_value) const {
        auto it = data.find(key);
        return (it != data.end()) ? it->second : default_value;
    }

    V pop(const K& key) {
        auto it = data.find(key);
        if (it == data.end()) {
            throw KeyError("key not found in pydict: '" + to_string(key) + "'");
        }
        V value = it->second;
        data.erase(it);
        return value;
    }

    pydict<K, V> copy() const {
        return pydict<K, V>(data.begin(), data.end());
    }

    void clear() {
        data.clear();
    }


    void remove(const K& key) {
        if (!contains(key)) {
            throw KeyError("key not found in pydict: '" + key_to_string(key) + "'");
        }
        data.erase(key);
    }

    void update(const pydict<K, V>& other) {
        for (const auto& [k, v] : other.data) {
            data[k] = v;
        }
    }

    bool contains(const K& key) const {
        return data.find(key) != data.end();
    }

    size_t size() const {
        return data.size();
    }

    // ------------------ Python-like Views ------------------
    KeyView keys() const { return KeyView(data); }
    ValueView values() const { return ValueView(data); }
    const std::map<K, V>& items() const { return data; }

    // ------------------ Iteration & Display ------------------
    auto begin() { return data.begin(); }
    auto end() { return data.end(); }

    void print() {
        std::cout << "{";
        size_t i = 0;
        for (const auto& [key, value] : data) {
            std::cout << key << ": " << value;
            if (++i < data.size())
                std::cout << ", ";
        }
        std::cout << "}" << std::endl;
    }
};

#endif // PYCPP_DATA_STRUCTURES_HPP
