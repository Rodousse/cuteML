#include <regex>

// Import module regex
// Captures : 1 : import
//            2 : module
//            3 : version
//            4 : as (optional)
//            5 : Qualifier (optional)
std::regex importModule("(import)\s+(\w+(?:.\w+)+?)\s+(\d.\d+)(?:\s+(as)\s+(\w+))?");

// Import directory regex
// Captures : 1 : import
//            2 : directory or javascript path
//            3 : as (optional)
//            4 : Qualifier (optional)
std::regex importDirectoryOrJavascript("(import)\s+(\".+\")(?:\s+(as)\s+(\w+))?");
