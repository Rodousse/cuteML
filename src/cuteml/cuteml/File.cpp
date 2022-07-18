#include "cuteml/File.hpp"

#include "cuteml/fileIO.hpp"
#include "cuteml/scanner.hpp"

namespace cuteml
{
File::File(const std::filesystem::path& path): m_content(IO::loadFileContent(path)) {}

std::string File::format()
{
    if(m_root)
        return m_root->format(FormatParameters{});
    return "";
}
const std::optional<std::string>& File::content() const
{
    return m_content;
}
} // namespace cuteml
