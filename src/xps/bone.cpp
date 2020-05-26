//
// Created by i.getsman on 25.05.2020.
//

#include "xps/bone.hpp"

void XNA::XPS::Bone::parse(BinaryIO& reader) {
    name = reader.read_xps_string();
    reader.read(&parent_id);
    reader.read(&pos);

}
