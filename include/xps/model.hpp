//
// Created by i.getsman on 22.05.2020.
//

#ifndef XNALARALIB_MODEL_HPP
#define XNALARALIB_MODEL_HPP


#include <binary_io.h>

#include <xps/header.hpp>
#include <xps/bone.hpp>
#include <xps/mesh.hpp>

namespace XNA::XPS {
    class Model {
    public:
        Header header;

        std::vector<uint8_t> settings;
        std::vector<Bone> bones;
        std::vector<Mesh> meshes;

        void parse(BinaryIO& reader);

        void read_none(BinaryIO& reader, uint32_t count);

        void* read_default_pose(BinaryIO& reader, uint32_t count, uint32_t info);
    };

}
#endif //XNALARALIB_MODEL_HPP
