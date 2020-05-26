//
// Created by i.getsman on 22.05.2020.
//

#include <xps/model.hpp>

void XNA::XPS::Model::parse(BinaryIO& reader) {
    header.parse(reader);
    if (!header.has_tangent()) {
        settings.resize(header.settings_size * 4);
        reader.read(settings.data(), settings.size());
    } else {
        uint32_t data_read = reader.tell();
        uint32_t hash = reader.read_u32();
        uint32_t item_count = reader.read_u32();

        for (uint32_t i = 0; i < item_count; i++) {
            uint32_t opt_type = reader.read_u32();
            uint32_t opt_count = reader.read_u32();
            uint32_t opt_info = reader.read_u32();

            switch (opt_type) {
                case 0: {
                    read_none(reader, opt_count);

                    break;
                }
                case 1: {
                    read_default_pose(reader, opt_count, opt_info);
                    break;
                }
                default: {
                    uint32_t loop_start = (reader.tell() - data_read) / 4;
                    uint32_t loop_finish = header.settings_size;
                    read_none(reader, loop_finish - loop_start);
                    break;
                }
            }
        }

    }
    auto bone_count = reader.read_u32();
    bones.resize(bone_count);
    for (uint32_t bone_id = 0; bone_id < bone_count; bone_id++) {
        bones[bone_id].parse(reader);
    }
    meshes.resize(reader.read_u32());
    for(auto& mesh:meshes){
        mesh.parse(reader,header,!bones.empty());
    }

}

void XNA::XPS::Model::read_none(BinaryIO& reader, uint32_t count) {
    std::vector<uint32_t> waste;
    waste.resize(count);
    for (uint32_t& i : waste) {
        reader.read(&i);
    }

}

void* XNA::XPS::Model::read_default_pose(BinaryIO& reader, uint32_t count, uint32_t info) {
    return nullptr;
}
