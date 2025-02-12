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
            perror("Ошибка! Введите число!\n");
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
        
        // Проверка на попадание в диапазон от (1-5) и отсутствия букв
        do {
            printf("Введите ваш выбор (1-5): ");
            scanf("%hu", &choice);
            if (isalpha(choice)) {
                perror("Ошибка! Введите число!\n");
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

void CompareTwoCards(const ACCOUNT* first_card, const ACCOUNT* second_card)
{
    printf("Первая карта имеет идентификатор: %s\n. "
           "Вторая карта имеет идентификатор: %s\n\n",
            first_card->identifier,
            second_card->identifier
    );
    // Сравнение баланса
    if (first_card->balance > second_card->balance)
        printf("Баланс первой карты больше баланса второй (1: %lf, 2: %lf\n)",
                first_card->balance, second_card->balance);
    else if (first_card->balance < second_card->balance)
        printf("Баланс первой карты меньше баланса второй (1: %lf, 2: %lf\n)",
                first_card->balance, second_card->balance);
    else 
        printf("Балансы на двух картах эквивалентны (1; %lf, 2: %lf\n)",
                first_card->balance, second_card->balance);

    // Сравнение по датам открытия/закрытия
    if (first_card->open_date.year == second_card->open_date.year) {
        printf("Обе карты были открыты в одно время!\n");
        printf("Дата открытия: %2d.%2d.%4d\n",
                first_card->open_date.day,
                first_card->open_date.month,
                first_card->open_date.year
        );
        printf("Дата закрытия: %2d.%2d.%4d\n",
                first_card->open_date.day,
                first_card->open_date.month,
                first_card->open_date.year
        );
    } else {
        printf("Карты имеют разную дату открытия и закрытия.\n");

        // Первая карта
        printf("Идентификатор: %s\n", first_card->identifier);
        printf("Дата открытия карты: %2d.%2d.%4d\n",
                first_card->open_date.day,
                first_card->open_date.month,
                first_card->open_date.year
        );
        printf("Дата закрытия карты: %2d.%2d.%4d\n\n",
                first_card->close_date.day,
                first_card->close_date.month,
                first_card->close_date.year
        );

        // Вторая карта
        printf("Идентификатор: %s", second_card->identifier);
        printf("Дата открытия карты: %2d.%2d.%4d\n",
                second_card->open_date.day,
                second_card->open_date.month,
                second_card->open_date.year
        );
        printf("Дата закрытия карты: %2d.%2d.%4d\n\n",
                second_card->close_date.day,
                second_card->close_date.month,
                second_card->close_date.year
        );
    }        

    // Сравнение по типу карт
    if (first_card->card_type == second_card->card_type) 
        printf("Обе карты имеют одинаковый тип: %s", first_card->card_type);
    else {
        printf("Идентификатор: %s, тип: %s\n", 
                first_card->identifier,
                first_card->card_type
        );
        printf("идентификатор: %s, тип: %s\n\n",
                second_card->identifier,
                second_card->card_type
        );
    }
}

void DepositAccount(ACCOUNT* account, const double sum_to_deposit) 
{
    // Проверяем чтобы была введена положительная сумма внесения
    if (sum_to_deposit <= 0) {
        printf("Ошибка! Сумма для внесения должна быть положительной!\n");
        exit(-1);
    }
    

    // Добавляем сумму внесения и отображаем баланс
    account->balance += sum_to_deposit;
    printf("Внесено: %.2lf%s\n", sum_to_deposit, account->currency);
    printf("Текущий баланс: %.2lf%s\n\n", account->balance, account->currency);
}

void WithdrawMoney(ACCOUNT* account, const double sum_to_withdraw)
{
    // Проверка чтобы была введена положительная сумма снятия
    if (sum_to_withdraw <= 0) {
        printf("Ошибка! Сумма для внесения должна быть положительной!\n");
        exit(-1);
    }

    // Достаточно баланса, чтобы снять деньги
    if (account->balance - sum_to_withdraw > 0) {
        account->balance -= sum_to_withdraw;
        
        // Отображаем баланс
        printf("Снято: %.2lf%s\n", sum_to_withdraw, account->currency);
        printf("Текущий баланс: %.2lf%s\n\n", account->balance, account->currency);
    } else {
        printf("На вашем счете недостаточно денег.\n");
        exit(-1);
    } 
}
