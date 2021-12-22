#include "cuteml/fileIO.hpp"

#include <fstream>
#include <optional>

namespace cuteml::IO
{
std::optional<std::string> loadFileContent(const std::filesystem::path& path)
{
    namespace fs = std::filesystem;
    if(!fs::exists(path))
    {
        return std::nullopt;
    }

    if(std::ifstream file(path, std::ios_base::ate); file.is_open())
    {
        const auto fileSize = file.tellg();
        std::string fileContent(fileSize, '\0');

        file.seekg(0);
        file.read(fileContent.data(), fileSize);

        if(file.good())
            return std::make_optional(std::move(fileContent));
    }
    return std::nullopt;
}
} // namespace cuteml::IO
