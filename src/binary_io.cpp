#include <binary_io.h>

BinaryIO::BinaryIO(const std::string& name) {
    open(name);
}

void BinaryIO::open(const std::string& name) {
    file.open(name, std::ios::binary | std::ios::in | std::ios::out);
}

BinaryIO::~BinaryIO() {
    file.close();
}

void BinaryIO::read(uint8_t* buffer, uint64_t count) {
//    printf("Reading %i bytes. Pos:%lli\n",count,tell());
//    fflush(stdout);
    file.read((char*) buffer, count);
    pos = tell();
}

void BinaryIO::write(uint8_t* buffer, uint64_t count) {
    file.write((char*) buffer, count);
    pos = tell();
}


uint8_t BinaryIO::read_u8() {
    return read<uint8_t>();
}

int8_t BinaryIO::read_i8() {
    return read<int8_t>();
}

uint16_t BinaryIO::read_u16() {
    return read<uint16_t>();
}

int16_t BinaryIO::read_i16() {
    return read<int16_t>();
}

uint32_t BinaryIO::read_u32() {
    return read<uint32_t>();
}

int32_t BinaryIO::read_i32() {
    return read<int32_t>();
}

void BinaryIO::write_u8(uint8_t value) {
    write<uint8_t>(value);
}

void BinaryIO::write_i8(int8_t value) {
    write<int8_t>(value);
}

void BinaryIO::write_u16(uint16_t value) {
    write<uint16_t>(value);
}

void BinaryIO::write_i16(int16_t value) {
    write<int16_t>(value);
}

void BinaryIO::write_u32(uint32_t value) {
    write<uint32_t>(value);
}

void BinaryIO::write_i32(int32_t value) {
    write<int32_t>(value);
}

std::string BinaryIO::read_ascii(uint32_t len) {
    std::string output;
    if (len > 0) {
        output.resize(len);
        read((uint8_t*) output.data(), len);
    } else {
        char c = read_i8();
        while (c != 0) {
            output.push_back(c);
            c = read_i8();
        }
    }
    return output;
}

uint64_t BinaryIO::size() {
    uint64_t pos = tell();
    seek(0, std::ios_base::end);
    uint64_t size = tell();
    seek(pos);
    return size;
}

void BinaryIO::seek(uint64_t offset, std::ios_base::seekdir dir) { file.seekg(offset, dir);pos=tell(); }

std::string BinaryIO::read_xps_string() {
    uint32_t size = read_u8();
    if (size > 128) {
        size = (size % 128) + (read_u8() * 128);
    }
    return read_ascii(size);
}
