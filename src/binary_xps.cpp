//
// Created by i.getsman on 22.05.2020.
//

#include "binary_xps.hpp"

XNA::XPS::BinaryXPS::BinaryXPS(const std::string& file_path) {
    reader.open(file_path);

}

bool XNA::XPS::BinaryXPS::check_magic(const std::string& file_path) {
    BinaryIO tmp(file_path);
    return tmp.read_u32() == 323232;
}

void XNA::XPS::BinaryXPS::parse_file() {
    model.parse(reader);

}
