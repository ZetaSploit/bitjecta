#include <ios>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <filesystem>


void fparse(const std::string& file_name) {
    std::ifstream file(file_name, std::ios::binary);
    std::filesystem::path filePath = file_name;

    if (std::filesystem::exists(filePath) && std::filesystem::is_regular_file(filePath)) {
        ;
    } else {
        std::cout << "File does not exist.\n";
    } 

    file.seekg(0, std::ios::end);
    std::streamsize total_size = file.tellg();

    file.seekg(0, std::ios::beg);
    std::vector<char> buffer(total_size);

    
    file.read(buffer.data(), total_size);

    std::streamsize bytes_read = file.gcount();

    for (std::streamsize i = 0; i < bytes_read; ++i) { 

        std::cout << std::hex << std::setw(2) << std::setfill('0') << (static_cast<unsigned int>(static_cast<unsigned char>(buffer[i]))) << " ";
        if ((i + 1) % 16 == 0)
            std::cout << '\n';
    }

    std::cout << '\n';
}
int main(int argc, char *argv[]) {

    char user_def[100];

    //std::cout << "Enter the file to be parsed: ";
    //std::cin >> user_def;

    fparse(argv[1]);

    return 0;
}
