#include "cuteml/File.hpp"
#include "cuteml/scanner.hpp"

#include <cuteml/fileIO.hpp>
#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "Hello friend\n";

    cuteml::File myFile(TEST_FILE);
    if(myFile.content())
    {
        auto result = cuteml::scanQmlContent(*myFile.content());
        for(auto token: result)
            std::cout << "\"" << token.content() << "\"";
    }
    return 0;
}
