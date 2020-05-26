//
// Created by i.getsman on 22.05.2020.
//

#include <xps/header.hpp>

void XNA::XPS::Header::parse(BinaryIO& reader) {
    reader.read(&magic);
    reader.read(&version);
    aral = reader.read_xps_string();
    reader.read(&settings_size);
    machine = reader.read_xps_string();
    user = reader.read_xps_string();
    filename = reader.read_xps_string();
}
