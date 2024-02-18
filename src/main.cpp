#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

// Utility function to determine if a path represents a directory (does not have an extension)
bool isDirectory(const fs::path &path)
{
    return path.extension().empty();
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
    { // use & to refer to the original pair
        int current_tab = current_pair.first;
        fs::path filename = current_pair.second;
        fs::path newPath;

        if (current_tab == 0) // If the current_tab is 0, create the file or directory in the root path
        {
            newPath = rootPath / filename; // cpp allows us to use / to concatenate paths, adopt the platform-specific separator
            createFileOrDir(newPath);
            current_pair.second = newPath; // Update with the new path

            if (isDirectory(current_pair.second)) // If the current pair is a directory, push it to the stack
            {
                pathStack.push_back(current_pair); // Push the new path to the stack
            }
        }
        else
        {
            bool foundPreDir = false;
            int stack_index = pathStack.size()-1;
            // search the stack upwards to find parent directory
            // start from previous stack (current_tab-1), stop when predir is found

            while (foundPreDir == false)
            {
                auto upper_pair = pathStack[stack_index];
                // if upper_pair is dir and its tab == current tab-1, indicate it's the parent dir
                if (upper_pair.first == (current_tab - 1) && isDirectory(upper_pair.second))
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

            if (!foundPreDir)
            {
                std::cerr << "Invalid input: Couldn't find a directory for " << filename << std::endl;
                // Handle invalid input as needed
            }
        }
    }
}


int main()
{
    std::vector<std::pair<int, fs::path>> lines;
    std::string line;

    std::cout << "Enter directory and file structure (press Enter on a blank line to finish):" << std::endl;

    // Read input from the user
    while (true)
    {
        std::getline(std::cin, line);
        if (line.empty())
        {
            // if User entered a blank line, stop reading input
            break;
        }

        int tabCount = 0;
        // Count leading tabs to determine level
        // if the line is a file or directory，and it starts with a tab
        // count # of tabs in loop
        while (!line.empty() && line[0] == '\t')
        {
            tabCount++;
            line = line.substr(1);
        }
        lines.push_back({tabCount, (fs::path)line});
    }

    for (const auto &line : lines)
    {
        std::cout << line.first << " " << line.second << std::endl;
    }


    // Assuming the tool runs in the current directory
    fs::path rootPath = fs::current_path();
    // Create the directory and file structure after collecting all inputs

    

    // CreateStruct(lines1, rootPath);
    // CreateStruct(lines2, rootPath);
    // CreateStruct(lines3, rootPath);
    // CreateStruct(lines4, rootPath);
    // CreateStruct(lines5, rootPath);
    // CreateStruct(lines6, rootPath);
    // CreateStruct(lines7, rootPath);
    // CreateStruct(lines8, rootPath);
    CreateStruct(lines, rootPath);
    std::cout << "Directories and files created successfully." << std::endl;
    return 0;
}