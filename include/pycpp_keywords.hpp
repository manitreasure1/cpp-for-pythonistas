#ifndef PYCPP_KEYWORDS_HPP
#define PYCPP_KEYWORDS_HPP

#include <string>

namespace py {
    using str = std::string;
    
    constexpr bool True = true;
    constexpr bool False = false;
    constexpr auto None = nullptr;
}

#endif // PYCPP_KEYWORDS_HPP
