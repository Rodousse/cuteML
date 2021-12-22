#include "cuteml/File.hpp"

#include "cuteml/fileIO.hpp"
#include "cuteml/scaner.hpp"

namespace cuteml
{
File::File(const std::filesystem::path& path):
  m_content(IO::loadFileContent(path)),
  m_root(m_content ? scanQmlContent(*m_content) : nullptr)
{
}

std::string File::format()
{
    if(m_root)
        return m_root->format(FormatParameters{});
    return "";
}
} // namespace cuteml
