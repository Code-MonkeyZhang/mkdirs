#include "../src/main.cpp" // Adjust the path as necessary
#include "test.hpp"
#include <iostream>

int main() {
    // Define the root path where the structure should be created
    fs::path rootPath = "../tests/test_folder"; // Adjust this path

    // Using the test cases
    try {
        CreateStruct(TestCases::lines1, rootPath);
        CreateStruct(TestCases::lines2, rootPath);
        CreateStruct(TestCases::lines3, rootPath);
        CreateStruct(TestCases::lines4, rootPath);
        CreateStruct(TestCases::lines5, rootPath);
        CreateStruct(TestCases::lines6, rootPath);
        CreateStruct(TestCases::lines7, rootPath);
        CreateStruct(TestCases::lines8, rootPath);
        CreateStruct(TestCases::lines9, rootPath); // Including the ninth test case
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1; // Return a non-zero value to indicate failure
    }

    std::cout << "All structures created successfully.\n";
    return 0; // Success
}
