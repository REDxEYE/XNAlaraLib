//
// Created by i.getsman on 25.05.2020.
//

#ifndef XNALARALIB_BONE_HPP
#define XNALARALIB_BONE_HPP


#include <string>
#include <array>
#include <binary_io.h>

namespace XNA::XPS {
    class Bone {
    public:
        std::string name;
        uint16_t id;
        int16_t parent_id;
        std::array<float, 3> pos;

        void parse(BinaryIO& reader);
    };
}


#endif //XNALARALIB_BONE_HPP
