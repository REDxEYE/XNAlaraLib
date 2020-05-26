//
// Created by i.getsman on 25.05.2020.
//

#ifndef XNALARALIB_MESH_HPP
#define XNALARALIB_MESH_HPP

#include <string>
#include <vector>
#include <array>

#include <binary_io.h>
#include <xps/header.hpp>

/*self.name = name
self.textures = textures
self.vertices = vertices
self.faces = faces
self.uvCount = uvCount*/
namespace XNA::XPS {
    class Mesh {
    public:
        struct Vertex {
            std::array<float, 3> pos{0.0};
            std::array<float, 3> normal{0.0};
            std::array<uint8_t , 4> color{0};
            std::vector<std::array<float, 2>> uv_layers;
            std::vector<std::pair<uint16_t, float>> weights;
        };
        struct Texture {
            std::string name = "TEXTURE";
            uint32_t uv_layer_id = 0;
        };

        std::string name;
        std::vector<Texture> textures;
        std::vector<Vertex> vertices;
        std::vector<std::array<uint32_t, 3>> faces;

        void parse(BinaryIO& reader, XNA::XPS::Header header, bool has_bones);

    };
}

#endif //XNALARALIB_MESH_HPP
