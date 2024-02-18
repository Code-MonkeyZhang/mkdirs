#ifndef TEST_HPP
#define TEST_HPP

#include <vector>
#include <utility> // For std::pair
#include <filesystem> // Requires C++17 or later

namespace fs = std::filesystem;

// Define test case structures
namespace TestCases {

    std::vector<std::pair<int, fs::path>> lines1 = {
        {0, "HelloWorld"},
        {1, "src"},
        {2, "HelloWorld.cpp"},
        {2, "main.cpp"},
        {1, "include"},
        {2, "HelloWorld.h"}
    };

    std::vector<std::pair<int, fs::path>> lines2 = {
        {0, "MyProject"},
        {1, "lib"},
        {2, "libmath"},
        {3, "math.cpp"},
        {3, "math.h"},
        {1, "app"},
        {2, "main.cpp"}
    };

    std::vector<std::pair<int, fs::path>> lines3 = {
        {0, "MixedContent"},
        {1, "docs"},
        {2, "README.md"},
        {1, "scripts"},
        {2, "install.sh"},
        {2, "deploy.py"}
    };

    std::vector<std::pair<int, fs::path>> lines4 = {
        {0, "EmptyDirectories"},
        {1, "emptyDir1"},
        {1, "emptyDir2"}
    };

    std::vector<std::pair<int, fs::path>> lines5 = {
        {0, "DeepNesting"},
        {1, "level1"},
        {2, "level2"},
        {3, "level3"},
        {4, "level4"}
    };

    std::vector<std::pair<int, fs::path>> lines6 = {
        {0, "MultipleFilesAndDirs"},
        {1, "dir1"},
        {1, "file1.txt"},
        {1, "dir2"},
        {1, "file2.txt"},
        {1, "dir3"}
    };

    std::vector<std::pair<int, fs::path>> lines7 = {
        {0, "MixedNestingAndFiles"},
        {1, "level1"},
        {2, "level2"},
        {3, "fileAtLevel3.txt"},
        {2, "anotherFileAtLevel2.txt"},
        {1, "fileAtLevel1.txt"}
    };

    std::vector<std::pair<int, fs::path>> lines8 = {
        {0, "ComplexStructure"},
        {1, "docs"},
        {2, "design"},
        {3, "specs.pdf"},
        {1, "src"},
        {2, "main.cpp"},
        {2, "util"},
        {3, "helpers.cpp"},
        {1, "emptyDir"},
        {2, "nestedEmptyDir"}
    };

    std::vector<std::pair<int, fs::path>> lines9 = {
        {0, "mkdirs"},
        {1, "README.md"},
        {1, "include"},
        {1, "src"},
        {1, "tests"},
        {1, "bin"},
    };

} // namespace TestCases

#endif // TEST_HPP
