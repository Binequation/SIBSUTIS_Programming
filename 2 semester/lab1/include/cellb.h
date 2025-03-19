#ifndef CELLB_H
#define CELLB_H

#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

typedef struct {
    uint8_t data[12]; // Хранит все поля
} cellB;

// Методы для работы с cellB
cellB* init_cell();
void destroy_cell(cellB* cell);

// Геттеры и сеттеры для полей
// Уникальный идентификатор (32 бита)
uint32_t get_id(const cellB* cell);
void set_id(cellB* cell, uint32_t id);

// Размер (16 бит)
uint16_t get_size(const cellB* cell);
void set_size(cellB* cell, uint16_t size);

// Тип доступа (2 бита)
uint8_t get_type(const cellB* cell);
void set_type(cellB* cell, uint8_t val);

// Уровень безопасности (3 бита)
uint8_t get_sec_lvl(const cellB* cell);
void set_sec_lvl(cellB* cell, uint8_t val);

// Наличие видеонаблюдения (1 бит)
uint8_t get_sec_video(const cellB* cell);
void set_sec_video(cellB* cell, uint8_t val);

// Стоимость аренды (16 бит)
uint16_t get_cost(const cellB* cell);
void set_cost(cellB* cell, uint16_t cost);

// Срок аренды (8 бит)
uint8_t get_rent(const cellB* cell);
void set_rent(cellB* cell, uint8_t term);

#endif