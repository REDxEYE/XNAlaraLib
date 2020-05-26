//
// Created by i.getsman on 22.05.2020.
//

#ifndef XNALARALIB_HEADER_HPP
#define XNALARALIB_HEADER_HPP

#include <cstdint>
#include <string>
#include <binary_io.h>

namespace XNA::XPS {
    class Header {
    public:
        uint32_t magic;
        struct {
            uint16_t major;
            uint16_t minor;
        } version;
        std::string aral;
        uint32_t settings_size;
        std::string machine;
        std::string user;
        std::string filename;

        void parse(BinaryIO& reader);

        inline bool has_tangent() {
            return version.minor <= 12 && version.major <= 2;
        }

        inline bool has_var_weight() {
            return version.major >= 3;
        }
    };
}
#endif //XNALARALIB_HEADER_HPP
