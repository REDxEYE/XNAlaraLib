#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdint>
#include <ios>
#include <vector>
#include <cxxabi.h>


class BinaryIO {
private:
    std::fstream file;

public:
    uint64_t pos = 0;

    explicit BinaryIO(const std::string& name);

    BinaryIO() {};

    ~BinaryIO();

    virtual void open(const std::string& name);

    virtual void read(uint8_t* buffer, uint64_t count);

    virtual void write(uint8_t* buffer, uint64_t count);

    template<typename T>
    void read(T* ptr) {
//        char * name = abi::__cxa_demangle(typeid(T).name(), 0, 0, NULL);
//        printf("Reading (%s) %i bytes. Pos:%lli\n",name,sizeof(T),tell());
//        fflush(stdout);
//        delete name;
        file.read((char*) ptr, sizeof(T));
        pos = tell();
    }

    template<typename T>
    T read() {
        T tmp;
        auto back = pos;
        read((uint8_t*) &tmp, sizeof(T));
//        if(pos-back!= sizeof(T)) throw std::overflow_error(("Invalid step, expected "+std::to_string(sizeof(T))+", got "+std::to_string(back-pos)).c_str());
        return tmp;
    }

    template<typename T>
    void write(T data) {
        write((uint8_t*) &data, sizeof(T));
        pos = tell();
    }

    uint8_t read_u8();

    int8_t read_i8();

    uint16_t read_u16();

    int16_t read_i16();

    uint32_t read_u32();

    int32_t read_i32();

    void write_u8(uint8_t value);

    void write_i8(int8_t value);

    void write_u16(uint16_t value);

    void write_i16(int16_t value);

    void write_u32(uint32_t value);

    void write_i32(int32_t value);

    std::string read_ascii(uint32_t len = 0);

    std::string read_xps_string();

    virtual uint64_t size();


    virtual uint64_t tell() { return file.tellg(); }

    virtual void seek(uint64_t offset, std::ios_base::seekdir dir = std::ios_base::beg);
};

class MemoryIO:public BinaryIO{
    std::stringstream file;

    explicit MemoryIO(const std::vector<uint8_t>& data){
        file.write((char*)data.data(),data.size());
    }
};