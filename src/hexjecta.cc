#include <cstddef>
#include <ios>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <filesystem>
#include <byteswap.h>



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

std::vector<std::uint32_t> convert_and_swap(const std::vector<char>& buffer) {
    size_t num_elements = buffer.size() / 4;
    std::vector<std::uint32_t> result;
    result.reserve(num_elements);

    const unsigned char* src = reinterpret_cast<const unsigned char*>(buffer.data());

    for (size_t i = 0; i < num_elements; ++i) {
        size_t idx = i * 4;
        
        // Manual bit-shifting constructs the uint32_t value byte-by-byte.
        std::uint32_t val = (static_cast<std::uint32_t>(src[idx + 0]) << 24) |
                            (static_cast<std::uint32_t>(src[idx + 1]) << 16) |
                            (static_cast<std::uint32_t>(src[idx + 2]) << 8)  |
                            (static_cast<std::uint32_t>(src[idx + 3]));
                            
        result.push_back(val);
    }

    return result;
}


int main(int argc, char *argv[]) {

    char user_def[100]; 

    fparse(argv[1]);

    return 0;
}
