// A simple macro to enable/disable debugging
#define DEBUG

// Our basic debug print function
template<typename T>
void debug_print(const T& value) {
#ifdef DEBUG
    std::cerr << value << std::endl; // Using cerr is good practice for debug output
#endif
}

// Overload for multiple arguments (variadic template for more advanced cases)
template<typename T, typename... Args>
void debug_print(const T& value, const Args&... args) {
#ifdef DEBUG
    std::cerr << value << " ";
    debug_print(args...);
#endif
}