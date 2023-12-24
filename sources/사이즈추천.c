#include <stdio.h>
#include <string.h>
#include "��������õ.h"

void shoppingLoop() {
    struct PurchaseHistory purchaseHistory[10];  // �ִ� 10���� ���� ���� ���� ����
    int numPurchase = 0;  // ������� ����� ���� ���� ����
    struct CustomerInfo customer;

    do {
        // �� ���� â ǥ�� �� �� ����
        printf("\n=== �� ���� â ===\n");
        printf("1. ���̵� ��� ���� ���� - 59000��\n");
        printf("2. ���� �� ���̵� ������ - 54000��\n");
        printf("3. �� ���� ���̵� ���� - 56000��\n");
        printf("4. ���� �� ���̵� ���� - 46000��\n");
        printf("5. ���� ���̵� ī�� ���� - 42000��\n");
        printf("6. ���̵� ���� ���� ���� - 34000��\n");

        int choice;
        printf("\n������ ��ǰ ��ȣ�� �����ϼ��� (1-6): ");
        scanf_s("%d", &choice, sizeof(choice));

        // ������ ��ǰ�� ���� ���� ��� �� ���� ������ �߰�
        switch (choice) {
        case 1:
            purchaseHistory[numPurchase].price = 59000;  // ���� ���� �Ҵ�
            purchaseProduct("���̵� ��� ���� ����", purchaseHistory[numPurchase].price, &customer, purchaseHistory, &numPurchase);
            break;
        case 2:
            purchaseHistory[numPurchase].price = 54000;  // ���� ���� �Ҵ�
            purchaseProduct("���� �� ���̵� ������", purchaseHistory[numPurchase].price, &customer, purchaseHistory, &numPurchase);
            break;
        case 3:
            purchaseHistory[numPurchase].price = 56000;  // ���� ���� �Ҵ�
            purchaseProduct("�� ���� ���̵� ����", purchaseHistory[numPurchase].price, &customer, purchaseHistory, &numPurchase);
            break;
        case 4:
            purchaseHistory[numPurchase].price = 46000;  // ���� ���� �Ҵ�
            purchaseProduct("���� �� ���̵� ����", purchaseHistory[numPurchase].price, &customer, purchaseHistory, &numPurchase);
            break;
        case 5:
            purchaseHistory[numPurchase].price = 42000;  // ���� ���� �Ҵ�
            purchaseProduct("���� ���̵� ī�� ����", purchaseHistory[numPurchase].price, &customer, purchaseHistory, &numPurchase);
            break;
        case 6:
            purchaseHistory[numPurchase].price = 34000;  // ���� ���� �Ҵ�
            purchaseProduct("���̵� ���� ���� ����", purchaseHistory[numPurchase].price, &customer, purchaseHistory, &numPurchase);
            break;
        default:
            printf("�߸��� �����Դϴ�.\n");
            return 1;
        }


        // ����ڿ��� ��� �������� ���� Ȯ��
        char continueShopping;
        printf("\n����ؼ� �����Ͻðڽ��ϱ�? (Y/N): ");
        scanf_s(" %c", &continueShopping, sizeof(continueShopping));

        if (continueShopping != 'Y' && continueShopping != 'y') {
            printf("\n������ �����մϴ�. ���� ���� ����:\n");

            // ���� ���� ���� ���
            for (int i = 0; i < numPurchase; ++i) {
                printf("��ǰ��: %s, ����: $%.2f, ������: %s\n", purchaseHistory[i].itemName, purchaseHistory[i].price, purchaseHistory[i].size);
            }

            return;
        }

    } while (1);
}

// �� ���� �Լ�
float purchaseProduct(char itemName[], float price, struct CustomerInfo* customer, struct PurchaseHistory* purchaseHistory, int* numPurchase) {
    struct PurchaseHistory purchase;
    strcpy_s(purchase.itemName, sizeof(purchase.itemName), itemName);
    purchase.price = price;

    // ����ڿ��� ������ ��õ

    printf("���� ���� ȸ���Ե��� ��� �� ������ ǥ�Դϴ�.\n");
    printf("\n=== ������ ��õ ===\n");
    printf("|---------------------|------------------|-----------------|----------------|\n");
    printf("|        ������       |       Ű(cm)     |     ������(kg)  |  �㸮�ѷ�(cm)  |\n");
    printf("|---------------------|------------------|-----------------|----------------|\n");
    printf("|          S          |     160 - 170    |     50 - 65     |    70 - 80     |\n");
    printf("|---------------------|------------------|-----------------|----------------|\n");
    printf("|          M          |     170 - 180    |     65 - 75     |    80 - 90     |\n");
    printf("|---------------------|------------------|-----------------|----------------|\n");
    printf("|          L          |     180 - 190    |     75 - 90     |    90 - 100    |\n");
    printf("|---------------------|------------------|-----------------|----------------|\n");
    printf("|          XL         |     190 �̻�     |     90 �̻�     |   100 �̻�     |\n");
    printf("|---------------------|------------------|-----------------|----------------|\n");

    // ����ڿ��� ������ ����
    printf("\n����� �����ϼ��� (S, M, L, XL): ");
    scanf_s("%2s", purchase.size, sizeof(purchase.size));

    // ����ڰ� ������ ������� ǥ�� ���õ� ������ ����� ��
    if ((strcmp(purchase.size, "S") != 0 && customer->height >= 160 && customer->height <= 170 && customer->weight >= 50 && customer->weight <= 65 && customer->waistSize >= 70 && customer->waistSize <= 80) ||
        (strcmp(purchase.size, "M") != 0 && customer->height >= 170 && customer->height <= 180 && customer->weight >= 65 && customer->weight <= 75 && customer->waistSize >= 80 && customer->waistSize <= 90) ||
        (strcmp(purchase.size, "L") != 0 && customer->height >= 180 && customer->height <= 190 && customer->weight >= 75 && customer->weight <= 90 && customer->waistSize >= 90 && customer->waistSize <= 100) ||
        (strcmp(purchase.size, "XL") != 0 && customer->height >= 190 && customer->weight >= 90 && customer->waistSize >= 100)) {

        char confirm;
        printf("\n����� ���� �ʽ��ϴ�. �׷��� �����Ͻðڽ��ϱ�? (Y/N): ");
        scanf_s(" %c", &confirm, sizeof(confirm));

        if (confirm != 'Y' && confirm != 'y') {
            printf("���Ű� ��ҵǾ����ϴ�.\n");
            return 0.0;  // ���Ű� ��ҵǾ����Ƿ� ������ ��ȯ���� ����
        }
    }

    // �� ���� ���� ���
    printf("%s�� �����Ͽ����ϴ�. ����: $%.2f, ������: %s\n", purchase.itemName, purchase.price, purchase.size);

    // ���� ���� ������ �߰�
    strncpy_s(purchaseHistory[*numPurchase].itemName, sizeof(purchaseHistory[*numPurchase].itemName), purchase.itemName, _TRUNCATE);
    strncpy_s(purchaseHistory[*numPurchase].size, sizeof(purchaseHistory[*numPurchase].size), purchase.size, _TRUNCATE);
    (*numPurchase)++;

    return purchase.price;
}
