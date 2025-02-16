#include "../include/acash.h" // Подключаем заголовочный файл

int main(void)
{
    ACCOUNT *accounts[MAX_ACCOUNTS] = {NULL}; // Массив для хранения карт
    int account_count = 0;                    // Счетчик созданных карт
    int choice;

    do
    {
        printf("\n=== Меню управления картами ===\n"
               "1. Создать новую карту\n"
               "2. Просмотр информации о карте\n"
               "3. Сравнение двух карт\n"
               "4. Внести деньги на карту\n"
               "5. Снять деньги с карты\n"
               "6. Перевести деньги между картами\n"
               "7. Работа с бонусами\n"
               "0. Выход\n"
               "===============================\n");
        printf("Введите ваш выбор: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: // Создание новой карты
                if (account_count >= MAX_ACCOUNTS)
                {
                    printf("Превышено максимальное количество карт (%d).\n",
                        MAX_ACCOUNTS);
                    break;
                }

                char identifier[IDENTIFIER_LIMIT], card_number[CARD_NUMBER_LIMIT],
                     currency[CURRENCY_NAME_LIMIT], card_type[CARD_TYPE_LIMIT];
                double balance;

                // Считывание полей структуры
                printf("Введите идентификатор карты: ");
                scanf("%s", identifier);
                printf("Введите номер карты: ");
                scanf("%s", card_number);
                printf("Введите валюту: ");
                scanf("%s", currency);
                printf("Введите тип карты (например, дебетовая/кредитная): ");
                scanf("%s", card_type);
                printf("Введите начальный баланс: ");
                scanf("%lf", &balance);

                // Добавление карты в общий пулл
                accounts[account_count] = CreateAccount
                (
                    identifier, 
                    card_number, 
                    currency, 
                    card_type, 
                    balance
                );

                // Проверка факта создания карты
                if (accounts[account_count])
                {
                    printf("Карта успешно создана!\n");
                    account_count++;
                }
                else
                    printf("Ошибка при создании карты.\n");
                break;

            case 2: // Просмотр информации о карте
                if (account_count == 0)
                {
                    printf("Сначала создайте хотя бы одну карту!\n");
                    break;
                }

                int index;
                printf("Выберите карту (1-%d): ", account_count);
                scanf("%d", &index);

                if (index < 1 || index > account_count)
                {
                    printf("Неверный выбор!\n");
                    break;
                }

                AccountInfo(accounts[index - 1]);
                break;

            case 3: // Сравнение двух карт
                if (account_count < 2)
                {
                    printf("Создайте хотя бы две карты для сравнения!\n");
                    break;
                }

                int index1, index2;
                printf("Выберите первую карту (1-%d): ", account_count);
                scanf("%d", &index1);
                printf("Выберите вторую карту (1-%d): ", account_count);
                scanf("%d", &index2);

                if (index1 < 1 || index1 > account_count || index2 < 1 || index2 > account_count || index1 == index2)
                {
                    printf("Неверный выбор!\n");
                    break;
                }

                CompareTwoCards(accounts[index1 - 1], accounts[index2 - 1]);
                break;

            case 4: // Внести деньги на карту
                if (account_count == 0)
                {
                    printf("Сначала создайте хотя бы одну карту!\n");
                    break;
                }

                int index;
                printf("Выберите карту (1-%d): ", account_count);
                scanf("%d", &index);

                if (index < 1 || index > account_count)
                {
                    printf("Неверный выбор!\n");
                    break;
                }

                double sum_to_deposit;
                printf("Введите сумму для внесения: ");
                scanf("%lf", &sum_to_deposit);

                DepositAccount(accounts[index - 1], sum_to_deposit);
                break;

            case 5: // Снять деньги с карты
                if (account_count == 0)
                {
                    printf("Сначала создайте хотя бы одну карту!\n");
                    break;
                }

                int index;
                printf("Выберите карту (1-%d): ", account_count);
                scanf("%d", &index);

                if (index < 1 || index > account_count)
                {
                    printf("Неверный выбор!\n");
                    break;
                }

                double sum_to_withdraw;
                printf("Введите сумму для снятия: ");
                scanf("%lf", &sum_to_withdraw);

                WithdrawMoney(accounts[index - 1], sum_to_withdraw);
                break;

            case 6: // Перевод денег между картами
                if (account_count < 2)
                {
                    printf("Создайте хотя бы две карты для перевода!\n");
                    break;
                }

                int index1, index2;
                printf("Выберите исходную карту (1-%d): ", account_count);
                scanf("%d", &index1);
                printf("Выберите целевую карту (1-%d): ", account_count);
                scanf("%d", &index2);

                if (index1 < 1 || index1 > account_count || index2 < 1 || index2 > account_count || index1 == index2)
                {
                    printf("Неверный выбор!\n");
                    break;
                }

                double amount, commission_rate;
                printf("Введите сумму перевода: ");
                scanf("%lf", &amount);
                printf("Введите комиссию (в процентах): ");
                scanf("%lf", &commission_rate);

                Transfer
                (
                    accounts[index1 - 1],
                    accounts[index2 - 1],
                    amount,
                    commission_rate / 100.0
                );
                break;

            case 7: // Работа с бонусами
                if (account_count == 0)
                {
                    printf("Сначала создайте хотя бы одну карту!\n");
                    break;
                }

                // Бонусная система (начальный баланс = 0, процент начисления = 5%)
                BONUSES bonuses = {0, 0.05}; 

                int index;
                printf("Выберите карту (1-%d): ", account_count);
                scanf("%d", &index);

                if (index < 1 || index > account_count)
                {
                    printf("Неверный выбор!\n");
                    break;
                }

                double amount;

                printf("Введите сумму для начисления бонусов: ");
                scanf("%lf", &amount);
                DepositWithBonuses(accounts[index - 1], &bonuses, amount);

                printf("Использовать бонусы? (Введите сумму): ");
                scanf("%lf", &amount);
                UseBonuses(&bonuses, amount);
                break;

            case 0:
                printf("Выход из программы.\n");
                for (int i = 0; i < account_count; i++)
                {
                    AccountDestroy(accounts[i]);
                    free(accounts[i]);
                }
                break;

            default:
                printf("Неверный выбор! Пожалуйста, выберите снова.\n");
        }
    } while (choice != 0);
}