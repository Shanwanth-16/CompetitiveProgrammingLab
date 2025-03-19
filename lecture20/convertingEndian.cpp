#include <iostream>
#include <cstdint>  // For uint32_t

// Function to convert from Little Endian to Big Endian
uint32_t convertEndian(uint32_t num) {
    return ((num >> 24) & 0x000000FF) |      // Move byte 0 to byte 3
           ((num >> 8)  & 0x0000FF00) |      // Move byte 1 to byte 2
           ((num << 8)  & 0x00FF0000) |      // Move byte 2 to byte 1
           ((num << 24) & 0xFF000000);       // Move byte 3 to byte 0
}

int main() {
    uint32_t A = 0x12345678;  //hexadecimal num

    // Print original value (Little Endian representation)
    std::cout << "Original (Little Endian): 0x" << std::hex << A << std::endl;

    // Convert to Big Endian
    uint32_t B = convertEndian(A);
    std::cout << "Converted (Big Endian): 0x" << std::hex << B << std::endl;

    // Now, convert it back to Little Endian
    uint32_t C = convertEndian(B);
    std::cout << "Converted back to Little Endian: 0x" << std::hex << C << std::endl;

    return 0;
}
