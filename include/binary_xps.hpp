//
// Created by i.getsman on 22.05.2020.
//

#ifndef XNALARALIB_BINARY_XPS_HPP
#define XNALARALIB_BINARY_XPS_HPP


#include <string>
#include "binary_io.h"

#include <xps/model.hpp>

namespace XNA::XPS {
    class BinaryXPS {
    public:
        explicit BinaryXPS(const std::string& file_path);

        static bool check_magic(const std::string& file_path);

        void parse_file();

        inline const Model& get_model() {
            return model;
        }

    private:
        BinaryIO reader;
        Model model;
    };
}


#endif //XNALARALIB_BINARY_XPS_HPP
