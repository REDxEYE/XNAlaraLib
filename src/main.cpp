#include <cstdint>
#include <string>

#include <binary_xps.hpp>

int main(int argc, char** argv) {
    std::string path = "D:\\CPP\\XNAlaraLib\\test_data\\xps.xps";
//    std::string path = "D:\\CPP\\XNAlaraLib\\test_data\\HeadCrab Classic - Half Life 2\\Generic_Item.mesh";
    if (XNA::XPS::BinaryXPS::check_magic(path)) {
        XNA::XPS::BinaryXPS file(path);
        file.parse_file();
        auto& model = file.get_model();
        return 1;
    }
    return -1;
}