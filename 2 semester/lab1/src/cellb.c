#include "../include/cellb.h"

cellB* init_cell() {
    cellB* cell = (cellB*)malloc(sizeof(cellB));
    if (cell) {
        for (size_t i = 0; i < sizeof(cellB); i++) {
            cell->data[i] = 0; // Инициализация нулями
        }
    }
    return cell;
}

void destroy_cell(cellB* cell) {
    free(cell);
}

uint32_t get_id(const cellB* cell) {
    return (cell->data[0] << 24) |
           (cell->data[1] << 16) |
           (cell->data[2] << 8) |
           cell->data[3];
}

void set_id(cellB* cell, uint32_t id) {
    cell->data[0] = (id >> 24) & 0xFF;
    cell->data[1] = (id >> 16) & 0xFF;
    cell->data[2] = (id >> 8) & 0xFF;
    cell->data[3] = id & 0xFF;
}

uint16_t get_size(const cellB* cell) {
    return (cell->data[4] << 8) | cell->data[5];
}

void set_size(cellB* cell, uint16_t size) {
    cell->data[4] = (size >> 8) & 0xFF;
    cell->data[5] = size & 0xFF;
}

uint8_t get_type(const cellB* cell) {
    return (cell->data[6] & 0x03);
}

void set_type(cellB* cell, uint8_t val) {
    val &= 0x03;
    cell->data[6] = (cell->data[6] & 0xFC) | val;
}

uint8_t get_sec_lvl(const cellB* cell) {
    return (cell->data[6] >> 2) & 0x07;
}

void set_sec_lvl(cellB* cell, uint8_t val) {
    val &= 0x07;
    cell->data[6] = (cell->data[6] & 0xF3) | (val << 2);
}

uint8_t get_sec_video(const cellB* cell) {
    return (cell->data[6] & 0x20) >> 5;
}

void set_sec_video(cellB* cell, uint8_t val) {
    val &= 0x01;
    cell->data[6] = (cell->data[6] & 0xDF) | (val << 5);
}

uint16_t get_cost(const cellB* cell) {
    return (cell->data[7] << 8) | cell->data[8];
}

void set_cost(cellB* cell, uint16_t cost) {
    cell->data[7] = (cost >> 8) & 0xFF;
    cell->data[8] = cost & 0xFF;
}

uint8_t get_rent(const cellB* cell) {
    return cell->data[9];
}

void set_rent(cellB* cell, uint8_t term) {
    cell->data[9] = term;
}