#include "../include/acash.h" // Подключаем заголовочный файл

ACCOUNT* CreateAccount(
    const char* identifier,
    const char* card_number,
    const char* currency,
    const char* card_type,
    const double balance
)
{
    // Динамическое выделение памяти для всей структуры 
    ACCOUNT* account = (ACCOUNT*)malloc(sizeof(ACCOUNT));  

    // Инициализация полей структуры
    strncpy(account->identifier, identifier, sizeof(account->identifier) - 1);
    strncpy(account->card_number, card_number, sizeof(account->card_number) - 1);
    strncpy(account->currency, currency, sizeof(account->currency) - 1);
    strncpy(account->card_type, card_type, sizeof(account->card_type) - 1);
    account->balance = balance;

    // Дата откртия (берется текущая дата с помощью <time.>)
    time_t my_time = time(NULL);
    struct tm current_time   = *localtime(&my_time);
    account->open_date.day   = current_time.tm_mday;
    account->open_date.month = current_time.tm_mon + 1;
    account->open_date.year  = current_time.tm_year + 1900;

    // Дата закртия (+6 лет к дате откртия)
    account->close_date.day   = account->open_date.day;
    account->close_date.month = account->open_date.month;
    account->close_date.year  = account->open_date.year + 6;

    return account;
}

void AccountInfo(const ACCOUNT* account)
{
    // Стартовое диалоговое окно
    printf("Вы хотите вывести все данные о карте или только определенные детали?\n"
            "1 - Вывестии всю информаю о карте.\n"
            "2 - Вывести определенную информаю\n"
    );

    short choice;
    do {
        printf("Введите ваш выбор (1 или 2): ");
        scanf("%hu", &choice);
        if (isalpha(choice)) {
            printf("Ошибка! Введите число!\n");
            choice = 0;
        }
    } while (choice < 1 || choice > 2);

    // Вывод всех данных или отдельной информации
    if (choice == 1) {
        printf("Идентификатор: %6s\n", account->identifier);
        printf("Номер карты: %6s\n", account->card_number);
        printf("Валюта: %6s\n", account->currency);
        printf("Тип карты: %s\n", account->card_type);
        printf("Баланс: %6.2lf\n", account->balance);
    } else {
        printf("Какую информацию о вашей расчетной карте вы хотели бы узнать?"
                "1. Идентификатор\n"
                "2. Номер карты\n"
                "3. Валюта\n"
                "4. Тип карты\n"
                "5. Баланс\n"
        );
        

        do {
            printf("Введите ваш выбор (1-5): ");
            scanf("%hu", &choice);
            if (isalpha(choice)) {
                printf("Ошибка! Введите число!\n");
                choice = 0;
            }
        } while (choice < 1 || choice > 5);

        switch (choice) {
            case 1:
                printf("Идентификатор: %6s\n", account->identifier);
                break;
            case 2:
                printf("Номер карты: %6s\n", account->card_number);
                break;
            case 3:
                printf("Валюта: %6s\n", account->currency);
                break;
            case 4:
                printf("Тип карты: %6s\n", account->card_type);
                break;
            case 5:
                printf("Баланс: %6.2lf\n", account->balance);
                break;
        }
    }
}

