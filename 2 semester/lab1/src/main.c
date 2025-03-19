#include "../include/acash.h"
#include "../include/cellb.h"

int main() 
{
    ACCOUNT* account = CreateAccount(
        "User123", "123456789012345", "USD", "debit", 1000.0
    );

    cellB* cell = account->bank_cell; // Получаем ячейку из аккаунта
    if (cell) 
    {
        set_id(cell, 12345);          // Уникальный ID
        set_size(cell, 100);          
        set_type(cell, 1);            // Тип доступа (0-3)
        set_sec_lvl(cell, 4);         // Уровень безопасности (0-7)
        set_sec_video(cell, 1);       // Видеонаблюдение: 1 - есть
        set_cost(cell, 5000);         // Стоимость аренды в центах (50 USD)
        set_rent(cell, 12);           // Срок аренды в месяцах
    }

    AccountInfo(account);
    printf("Пополение наличных: ");
    DepositAccount(account, 500.0);   // Пополнение

    printf("Снятие наличных: ");
    WithdrawMoney(account, 200.0);    // Снятие

    // Освобождение памяти
    destroy_cell(account->bank_cell);
    free(account);
}