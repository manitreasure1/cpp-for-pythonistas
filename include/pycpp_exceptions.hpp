#ifndef PYCPP_EXCEPTIONS_HPP
#define PYCPP_EXCEPTIONS_HPP

#include <stdexcept>
#include <string>

#define ANSI_RED     "\033[31m"
#define ANSI_YELLOW  "\033[33m"
#define ANSI_RESET   "\033[0m"

// 🔧 Base class to reduce repetition
class PyBaseException : public std::runtime_error {
    protected:
        std::string full_msg;

        static std::string make_colored(const std::string& err_type, const std::string& msg) {
            return std::string(ANSI_YELLOW) + err_type + ": " +
                   ANSI_RED + msg + ANSI_RESET;
        }

    public:
        PyBaseException(const std::string& type, const std::string& msg)
            : std::runtime_error(msg), full_msg(make_colored(type, msg)) {}

        const char* what() const noexcept override {
            return full_msg.c_str();
        }
    };

    // 🔥 Python-style exception classes

class IndexError : public PyBaseException {
        public:
            IndexError(const std::string& msg) : PyBaseException("IndexError", msg) {}
};

class ValueError : public PyBaseException {
    public:
        ValueError(const std::string& msg) : PyBaseException("ValueError", msg) {}
};

class TypeError : public PyBaseException {
    public:
        TypeError(const std::string& msg) : PyBaseException("TypeError", msg) {}
};

class KeyError : public PyBaseException {
    public:
        KeyError(const std::string& msg) : PyBaseException("KeyError", msg) {}
};

class ZeroDivisionError : public PyBaseException {
    public:
        ZeroDivisionError(const std::string& msg) : PyBaseException("ZeroDivisionError", msg) {}
};

class AttributeError : public PyBaseException {
    public:
        AttributeError(const std::string& msg) : PyBaseException("AttributeError", msg) {}
};

class NameError : public PyBaseException {
    public:
        NameError(const std::string& msg) : PyBaseException("NameError", msg) {}
};

class ImportError : public PyBaseException {
    public:
        ImportError(const std::string& msg) : PyBaseException("ImportError", msg) {}
};

class RuntimeError : public PyBaseException {
    public:
        RuntimeError(const std::string& msg) : PyBaseException("RuntimeError", msg) {}
};

class NotImplementedError : public PyBaseException {
    public:
        NotImplementedError(const std::string& msg) : PyBaseException("NotImplementedError", msg) {}
};

class StopIteration : public PyBaseException {
    public:
        StopIteration(const std::string& msg) : PyBaseException("StopIteration", msg) {}
};

#endif // PYCPP_EXCEPTIONS_HPP
