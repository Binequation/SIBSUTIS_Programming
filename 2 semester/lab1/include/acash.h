#ifndef ACASH_H
#define ACASH_H

#include <stdio.h>  // I|O-stream
#include <time.h>   // Работа с временем (Дата открытия и взятие текущего времени)
#include <string.h> // Копирование строк, сравнение строк
#include <stdlib.h> // Использование динамической памяти
#include <ctype.h>  // Использование для проверки на букву


// Хранение состояния (типа) карты пользователя
#define DEBIT  "debit"
#define CREDIT "credit"
#define ESCROW "escrow"

// Хранение информации о дате создания
typedef struct {
    int day,
        month,
        year;
} DATE;

// Хранение данных о пользовательском счете
typedef struct {
    char identifier[50],  // Идентификатор
         card_number[50], // Номер расчетной карты
         currency[30],    // Валюта на карте 
         card_type[6];    // Тип карты (дебетовая, кредитная или эскроу)
    double balance;       // Баланс на счету
    
    DATE open_date,       // Дата открытия расчетной карты
         close_date;      // Дата закрытия расчетной карты
} ACCOUNT;

// Хранение данных о бонусной карте пользователя
typedef struct {
    double profit_percent,  // Процент начисления бонусов за каждую операцию
           current_balance; // Текущеее количество доступных бонусов
} BONUSES;

/* 
 *
 @brief: Конструктор (время создания берется от текущего момента).

 @param: const char* identifier  | Идентификатор расчетной карты
 @param: const char* card_number | Номер расчетной карты
 @param: const char* currency    | Валюта на счету
 @param: const char* card_type   | Тип карты: дебетовая, кредитная или эксроу
 @param: const double* balance   | Баланс на счету
 *
 *
*/
ACCOUNT* CreateAccount(
    const char* identifier,
    const char* card_number,
    const char* currency,
    const char* card_type,
    const double balance
);

/* 
 *
 @brief: Вывод информации о всей карте или отдельных полях расчетной карты
    
 @param: const ACCOUNT* account | Расчетная карта пользователя
 *
*/
void AccountInfo(const ACCOUNT* account);

/*
 @brief: Сравнения двух объектов структур (по датам, открытия, закрытия,
 балансу, типу карты).

 @param: const ACCOUNT* first_card  | Первая расчетная карта
 @param: const ACCOUNT* second_card | Вторая расчетная карта
 *
 *
*/
void CompareTwoCards(const ACCOUNT* first_card, const ACCOUNT* second_card);

/* 
 *
 @brief: Операция пополнения расчетной карты
 
 @param: ACCOUNT* account | Расчетная карта пользователя
 *
 *
*/
void DepositAccount(ACCOUNT* account);

/*
 *
 @brief: Операция снятия/оплаты

 @param: ACCOUNT* account | Расчетная карта пользователя
 *
 *
*/
void WithdrawMoney(ACCOUNT* account);

/*
 *
 @brief: Строковое представление объекта

 @param: const ACCOUNT* account | Расчетная карта пользователя
 *
*/
void StringCardRepresentation(const ACCOUNT* account);

/*
 *
 @brief: Расчёт списаний и накоплений счёта

 @param: const ACCOUNT* account | Расчетная карта пользователя
 *
 *
*/
void ProfitAndWithdraw(const ACCOUNT* account); 

/*
 *
 @brief: Операция перевода денежных средств с одного счёта на другой, со
взятием фиксированной комиссии при переводе денег со счёта с одной валютой,
на счёт с другой валютой.

 @param: const ACCOUNT* source_card  | Расчетная карта для отпправления перевода
 @param: ACCOUNT* destination_card   | Расчетная карта для получения перевода
 *
 *
*/
void Transfer(const ACCOUNT* source_card, ACCOUNT* destination_card);

/*
 *
 @brief: Проверка, закрыт счёт или нет, в указанной временной точке.

 @param const ACCOUNT* account | Расчетная карта пользователя 
 *
 *
*/
void IsAccountClosed(const ACCOUNT*  account);

/*
 *
 @brief: Начисление бонусов за различные операции

 @param: BONUSES* bonuse_account | Бонусная карта для начисления бонусов
 *
 *
*/
void GetBonuses(BONUSES* bonuse_account);

/*
 *
 @brief: Частичное погашение суммы с помощью бонусной карты 

 @param: const BONUSES* bonuse_account | Бонусная карта 
 @param: ACCOUNT* account              | Расчетная карта пользователя
 @param: int* price              | Сумма для оплаты 
 *
 *
*/
void UseBonuses(
    const BONUSES* bonuse_account,
    ACCOUNT* account,
    int* price
);

#endif
