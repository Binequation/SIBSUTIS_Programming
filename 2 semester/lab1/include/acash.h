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

// Ограничения при создании карты
#define IDENTIFIER_LIMIT    30
#define CARD_NUMBER_LIMIT   15
#define CURRENCY_NAME_LIMIT 20
#define CARD_TYPE_LIMIT     15


// Максимальное количество карт
#define MAX_ACCOUNTS 4 

// Лимит для отрицательного баланса кредитной карты
#define NEGATIVE_CREDIT_FIXED 10000

// Хранение информации о дате создания
typedef struct {
    int day,
        month,
        year;
} DATE;

// Хранение данных о пользовательском счете
typedef struct {
    char identifier[IDENTIFIER_LIMIT],     // Идентификатор
         card_number[CARD_NUMBER_LIMIT],   // Номер расчетной карты
         currency[CURRENCY_NAME_LIMIT],    // Валюта на карте 
         card_type[CARD_TYPE_LIMIT];       // Тип карты (дебетовая, кредитная или эскроу)
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
void DepositAccount(ACCOUNT* account, const double sum_to_deposit);

/*
 *
 @brief: Операция снятия/оплаты

 @param: ACCOUNT* account | Расчетная карта пользователя
 *
 *
*/
void WithdrawMoney(ACCOUNT* account, const double sum_to_withdraw);

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
void Transfer(
        ACCOUNT* source_card, 
        ACCOUNT* destination_card,
        const double amount, 
        const double commission_rate
);

/*
 *
 @brief: Проверка, закрыт счёт или нет, в указанной временной точке.

 @param const ACCOUNT* account | Расчетная карта пользователя 
 *
 *
*/
int IsAccountClosed(const ACCOUNT*  account);

/*
 *
 @brief: Начисление бонусов за различные операции

 @param: BONUSES* bonuse_account | Бонусная карта для начисления бонусов
 *
 *
*/
void GetBonuses(BONUSES* bonuses, const double amount);

/*
 *
 @brief: Частичное погашение суммы с помощью бонусной карты 

 @param: const BONUSES* bonuse_account | Бонусная карта 
 @param: ACCOUNT* account              | Расчетная карта пользователя
 @param: int* price                    | Сумма для оплаты 
 *
 *
*/
double UseBonuses(BONUSES* bonuses, const double max_amount);

/*
 *
 @brief: Пополнение счета с помощью бонусов
 
 @param: ACCOUNT* account    | Расчетная карта пользователя
 @param: BONUSES* bonuses    | Бонусная карта пользователя
 @param: const double amount | Сумма бонусов для пополения расчетной карты
 *
*/
void DepositWithBonuses(ACCOUNT* account, BONUSES* bonuses, const double amount);

/*
 *
 @brief: Снятие с помощью бонусов
 *
 @param: ACCOUNT* account    | Расчетная карта пользователя 
 @param: BONUSES* bonuses    | Бонусная карта пользователя
 @param: const double amount | Сумма бонусов для снятия
 *
*/
void WithdrawWithBonuses(ACCOUNT* account, BONUSES* bonuses, const double amount);

/*
 *
 @brief: Снятие денег с карты с помощью процентной записи
 *
 @param: ACCOUNT* acconut  | Расчетная карта
 @param: double percentage | Процентное соотношение для снятие
 *
*/
void WithdrawPercentage(ACCOUNT* account, double percentage);

/*
 *
 @brief: Пополение денег с помощью процентной записи
 *
 @param: ACCOUNT* account  | Расчетная карта
 @paraM: double percentage | Процентное соотношение для пополнения
 *
*/
void DepositPercentage(ACCOUNT* account, double percentage);

// "Деструктор" для освобождения ресурсов
void AccountDestroy(ACCOUNT* account); 

#endif
