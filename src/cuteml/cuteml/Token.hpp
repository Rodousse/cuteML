#pragma once

#include <string_view>
#include <vector>

namespace cuteml
{
enum class TokenType
{
    /// Carriage return, line feed, vertical tab, ...
    WhiteSpace,
    /// Blank
    Blank,
    /// Word that may contain a number
    AlphaNum,
    /// Number
    Digit,
    /// Special characters {}(),...
    Special
};

class Token
{
  public:
    Token(std::string_view content, TokenType type);
    Token(const Token&) = default;
    Token& operator=(const Token&) = default;
    Token(Token&&) noexcept = default;
    Token& operator=(Token&&) noexcept = default;

    std::string_view content() const noexcept;
    TokenType type() const noexcept;

  private:
    std::string_view m_content;
    TokenType m_type;
};

using TokenList = std::vector<Token>;
} // namespace cuteml
