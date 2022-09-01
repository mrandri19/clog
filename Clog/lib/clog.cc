#include <string>
#include <iostream>
#include <filesystem>
#include <string_view>

namespace clog_lib
{
    namespace fs = std::filesystem;
    using std::string;

    string Indent(const string &s, int level)
    {
        return string(level * 4, ' ') + s;
    }

    void PrintDirectory(const fs::path &path, int depth)
    {
        for (const auto &dir_entry : fs::directory_iterator(path))
        {
            if (dir_entry.is_regular_file())
            {
                std::cout << Indent(dir_entry.path().string(), depth) << std::endl;
            }
            else if (dir_entry.is_directory())
            {
                std::cout << Indent(dir_entry.path().string(), depth) << std::endl;
                PrintDirectory(dir_entry.path(), depth + 1);
            }
        }
    }

    void ClearDirectory(const fs::path &path)
    {
        for (const auto &dir_entry : fs::directory_iterator(path))
        {
            fs::remove_all(dir_entry);
        }
    }

    void CopyDirectory(const fs::path &source_dir, const fs::path &output_dir)
    {
        for (const auto &dir_entry : fs::directory_iterator(source_dir))
        {
            if (dir_entry.is_regular_file())
            {
                fs::copy(dir_entry.path(), output_dir);
            }
            else if (dir_entry.is_directory())
            {
                fs::path new_dir = output_dir / dir_entry.path().filename();
                fs::create_directory(new_dir);
                CopyDirectory(dir_entry, new_dir);
            }
        }
    }

    void Run(std::string_view source_dir_s, std::string_view output_dir_s)
    {
        fs::path source_dir{source_dir_s};
        fs::path output_dir{output_dir_s};
        if (fs::exists(output_dir))
        {
            ClearDirectory(output_dir);
        }
        else
        {
            fs::create_directory(output_dir);
        }

        std::cout << "########## site_source contents ########## " << std::endl;
        PrintDirectory(source_dir, 0);

        std::cout << "########## copying directories ########## " << std::endl;
        CopyDirectory(source_dir, output_dir);

        std::cout << "########## site_output contents ########## " << std::endl;
        PrintDirectory(output_dir, 0);
    }
}
