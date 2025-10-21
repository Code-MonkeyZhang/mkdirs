#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

// Utility function to determine if a path represents a directory (does not have an extension)
bool isDirectory(const std::string &pathStr)
{
    return !pathStr.empty() && pathStr.back() == '/';
}

// Function to create a file or directory, depending on whether the path has an extension
void createFileOrDir(const fs::path &path)
{
    if (isDirectory(path))
    {
        fs::create_directories(path);
    }
    else
    {
        // Ensure the parent directory exists before creating a file
        fs::create_directories(path.parent_path());
        std::ofstream file(path); // Create the file
    }
}

// The main function to create the structure
void CreateStruct(std::vector<std::pair<int, fs::path>> &pairs, const fs::path &rootPath)
{
    std::vector<std::pair<int, fs::path>> pathStack{};

    for (auto &current_pair : pairs)
    {
        int current_tab = current_pair.first;
        fs::path filename = current_pair.second;
        fs::path newPath;

        if (current_tab == 0) // If the current_tab is 0, create the file or directory in the root path
        {
            newPath = rootPath / filename;
            createFileOrDir(newPath);
            current_pair.second = newPath; // Update with whole absolute path

            if (isDirectory(current_pair.second)) // If the current pair is a directory, push it to the stack
            {
                pathStack.push_back(current_pair);
            }
        }
        else
        {
            // 如果 pathStack 为空，自动将 tab 调整为 0
            if (pathStack.empty())
            {
                std::cout << "Warning: No parent directory found for '" << filename
                          << "' (tab=" << current_tab << "), creating at root level (tab=0)" << std::endl;
                current_tab = 0;
                current_pair.first = 0;

                // 在根目录创建
                newPath = rootPath / filename;
                createFileOrDir(newPath);
                current_pair.second = newPath;

                if (isDirectory(current_pair.second))
                {
                    pathStack.push_back(current_pair);
                }
            }
            else
            {
                bool foundPreDir = false;
                int stack_index = pathStack.size() - 1; // 获取 pathStack 最后一个元素的索引号

                while (foundPreDir == false && stack_index >= 0)
                {
                    auto upper_pair = pathStack[stack_index];
                    // 往上找index小于current tab的dir, 那个就是自己的parent dir
                    if (upper_pair.first < current_tab && isDirectory(upper_pair.second))
                    {
                        newPath = upper_pair.second / filename;
                        createFileOrDir(newPath);
                        current_pair.second = newPath.string(); // Update with the new path
                        foundPreDir = true;

                        // if the current pair is a directory, push it to the stack
                        if (isDirectory(current_pair.second))
                        {
                            pathStack.push_back(current_pair);
                        }
                    }

                    if (stack_index == 0)
                    {
                        break;
                    }

                    stack_index--;
                }
            }
        }
    }
}

int main()
{
    std::vector<std::pair<int, fs::path>> lines;
    std::string line;

    std::cout << "Enter directory and file structure (press Enter on a blank line to finish):" << std::endl;

    while (true)
    {
        std::getline(std::cin, line); // Read input from the user

        if (line.empty())
        {
            // if User entered a blank line, stop reading input
            break;
        }

        int tabCount = 0;
        while (!line.empty() && line[0] == '\t')
        {
            // if user input an TAB, count it
            tabCount++;
            line = line.substr(1); // remove tab, then extract filename
        }
        lines.push_back({tabCount, (fs::path)line}); // store filename & tab count in vector
    }

    fs::path rootPath = fs::current_path(); // get current directory

    // Create file structure in root
    CreateStruct(lines, rootPath);
    std::cout << "Directories and files created successfully." << std::endl;
    return 0;
}