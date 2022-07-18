#include "cuteml/scanner.hpp"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <list>
#include <string_view>

namespace
{
// Use [[maybe_unused]] to suppress warning because it's called via algorithm and not a direct function call
[[maybe_unused]] bool isalnum(unsigned char c)
{
    return std::isalnum(c);
}
[[maybe_unused]] bool isalpha(unsigned char c)
{
    return std::isalpha(c);
}
[[maybe_unused]] bool isdigit(unsigned char c)
{
    return std::isdigit(c);
}
[[maybe_unused]] bool isblank(unsigned char c)
{
    return std::isblank(c);
}
[[maybe_unused]] bool isspace(unsigned char c)
{
    return std::isspace(c);
}
[[maybe_unused]] bool isspaceoralnum(unsigned char c)
{
    return std::isspace(c) || std::isalnum(c);
}
[[maybe_unused]] bool iswhitespace(unsigned char c)
{
    return std::isspace(c) && !std::isblank(c);
}
} // namespace

namespace cuteml
{
Token::Token(std::string_view content, TokenType type): m_content(content), m_type(type) {}

std::string_view Token::content() const noexcept
{
    return m_content;
}

TokenType Token::type() const noexcept
{
    return m_type;
}

std::vector<Token> scanQmlContent(std::string_view fileContent)
{
    using namespace cuteml;
    std::vector<Token> tokenList{};
    auto tokenB = fileContent.cbegin();
    while(tokenB != fileContent.cend())
    {
        decltype(tokenB) tokenE;
        TokenType type;
        // Word that may contain a number
        if(::isalpha(*tokenB))
        {
            tokenE = std::find_if_not(tokenB, fileContent.cend(), ::isalnum);
            type = TokenType::AlphaNum;
        }
        // Number
        else if(::isdigit(*tokenB))
        {
            tokenE = std::find_if_not(tokenB, fileContent.cend(), ::isdigit);
            type = TokenType::Digit;
        }
        // Special characters {}(),...
        else if(!::isspace(*tokenB))
        {
            tokenE = tokenB + 1;
            type = TokenType::Special;
        }
        // carriage return, line feed, vertical tab, ...
        else if(::iswhitespace(*tokenB))
        {
            tokenE = std::find_if(tokenB + 1, fileContent.cend(), ::isspaceoralnum);
            type = TokenType::WhiteSpace;
        }
        // Blank
        else
        {
            tokenE = std::find_if_not(tokenB, fileContent.cend(), ::isblank);
            type = TokenType::Blank;
        }
        std::string_view content(tokenB, std::distance(tokenB, tokenE));
        tokenList.emplace_back(content, type);
        tokenB = tokenE;
    }
    return tokenList;
}
} // namespace cuteml

