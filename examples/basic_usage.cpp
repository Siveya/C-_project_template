#include <iostream>
#include "module1/module1.h"
#include "module2/module2.h"
#include "version.h"

int main()
{
    std::cout << "Template Library Version: " << VERSION << std::endl;
    std::cout << "Version Major: " << VERSION_MAJOR << std::endl;
    std::cout << "Version Minor: " << VERSION_MINOR << std::endl;
    std::cout << "Version Patch: " << VERSION_PATCH << std::endl;

    // 使用 module1
    std::cout << "\nTesting Module 1:\n";
    module1::greet("World");

    // 使用 module2
    std::cout << "\nTesting Module 2:\n";
    module2::greet("World");

    return 0;
}
