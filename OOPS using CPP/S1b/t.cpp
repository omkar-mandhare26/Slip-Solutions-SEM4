#include <iostream>
#include <fstream>

int main()
{
    // Open source file for reading
    std::ifstream sourceFile("file1.txt");
    if (!sourceFile.is_open())
    {
        std::cerr << "Error: Unable to open source file." << std::endl;
        return 1;
    }

    // Open destination file for appending
    std::ofstream destinationFile("file3.txt", std::ios::app);
    if (!destinationFile.is_open())
    {
        std::cerr << "Error: Unable to open destination file." << std::endl;
        sourceFile.close();
        return 1;
    }

    // Read from source file and append to destination file
    char ch;
    while (sourceFile.get(ch))
    {
        destinationFile.put(ch);
    }

    // Close files
    sourceFile.close();
    destinationFile.close();

    std::cout << "Contents from source.txt appended to destination.txt successfully." << std::endl;

    return 0;
}
