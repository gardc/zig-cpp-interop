#include "wrapper.h"
#include <iostream>

void say_hi()
{
    std::cout << "Hello from C++! Now calling Zig function:" << std::endl;
    hello_from_zig();
}
