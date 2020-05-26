//
// Created by i.getsman on 25.05.2020.
//

#include "xps/mesh.hpp"

void XNA::XPS::Mesh::parse(BinaryIO& reader, XNA::XPS::Header header, bool has_bones) {
    bool var_weight = header.has_var_weight();
    bool has_tangent = header.has_tangent();


    name = reader.read_xps_string();
    if (name.empty())name = "NO_NAME";

    uint32_t uv_layer_count = reader.read_u32();

    textures.resize(reader.read_u32());

    for (auto& texture:textures) {
        texture.name = reader.read_xps_string();
        reader.read(&texture.uv_layer_id);
        if (texture.uv_layer_id > uv_layer_count) {
            printf("ERROR: texture UV_LAYER_ID > UV_LAYER_COUNT %i>%i", texture.uv_layer_id, uv_layer_count);
        }
    }
    vertices.resize(reader.read_u32());
    for (auto& vertex:vertices) {
        reader.read(&vertex.pos);
        reader.read(&vertex.normal);
        reader.read(&vertex.color);
        vertex.uv_layers.resize(uv_layer_count);
        for (auto& uv_layer:vertex.uv_layers) {
            reader.read(&uv_layer);

            if (has_tangent){
                reader.seek(4*4,std::ios::cur);
            }
        }
        if (has_bones) {
            if (var_weight) { vertex.weights.resize(reader.read_u16()); }
            else { vertex.weights.resize(4); }


            for (auto& weight:vertex.weights) {
                reader.read(&weight.first);
            }
            for (auto& weight:vertex.weights) {
                reader.read(&weight.second);
            }
        }
    }
    faces.resize(reader.read_u32());
    for (auto& face:faces) {
        reader.read(&face);
    }

}
