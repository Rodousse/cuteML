#include "cuteml/File.hpp"

#include <cuteml/ExpressionTree.hpp>
#include <cuteml/fileIO.hpp>
#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "Hello friend\n";
    auto result = cuteml::IO::loadFileContent("./cuteml");
    std::cout << result.value_or("Arf not found...") << '\n';

    std::cout << cuteml::flatten<cuteml::FlattenMethod::PreorderTraversal>().empty();

    cuteml::File myFile("./CMakeCache.txt");
    std::cout << myFile.format() << std::endl;
    return 0;
}
