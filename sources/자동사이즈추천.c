#include <stdio.h>

// ����ü ����: �� ����
struct CustomerInfo {
    float height;
    float weight;
    int waistSize;
    char size[3]; // S, M, L, XL
};

// ����ü ����: ���� ����
struct PurchaseHistory {
    char itemName[50];
    float price;
    char size[3]; // S, M, L, XL
};

// �Լ� ����
float purchaseProduct(char itemName[], float price, struct CustomerInfo* customer, struct PurchaseHistory* purchaseHistory, int* numPurchase);

int main() {
    // ����ü ���� ����
    struct CustomerInfo customer;

    // ���� ���� ���� �迭 ����
    struct PurchaseHistory purchaseHistory[10];  // �ִ� 10���� ���� ���� ���� ����
    int numPurchase = 0;  // ������� ����� ���� ���� ����

    // ������ ���� �Է� ��û
    printf("������ Ű�� �Է��ϼ��� (cm): ");
    scanf_s("%f", &customer.height, sizeof(customer.height));

    printf("������ �����Ը� �Է��ϼ��� (kg): ");
    scanf_s("%f", &customer.weight, sizeof(customer.weight));

    printf("������ �㸮�ѷ��� �Է��ϼ��� (cm): ");
    scanf_s("%d", &customer.waistSize, sizeof(customer.waistSize));

    // �Է¹��� ���� ���
    printf("\n������ ��ü ����:\n");
    printf("Ű: %.2f cm\n", customer.height);
    printf("������: %.2f kg\n", customer.weight);
    printf("�㸮�ѷ�: %d cm\n", customer.waistSize);

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
        purchaseHistory[numPurchase].price = purchaseProduct("���̵� ��� ���� ����", 59000, &customer, purchaseHistory, &numPurchase);
        break;
    case 2:
        purchaseHistory[numPurchase].price = purchaseProduct("���� �� ���̵� ������", 54000, &customer, purchaseHistory, &numPurchase);
        break;
    case 3:
        purchaseHistory[numPurchase].price = purchaseProduct("�� ���� ���̵� ����", 56000, &customer, purchaseHistory, &numPurchase);
        break;
    case 4:
        purchaseHistory[numPurchase].price = purchaseProduct("���� �� ���̵� ����", 46000, &customer, purchaseHistory, &numPurchase);
        break;
    case 5:
        purchaseHistory[numPurchase].price = purchaseProduct("���� ���̵� ī�� ����", 42000, &customer, purchaseHistory, &numPurchase);
        break;
    case 6:
        purchaseHistory[numPurchase].price = purchaseProduct("���̵� ���� ���� ����", 34000, &customer, purchaseHistory, &numPurchase);
        break;
    default:
        printf("�߸��� �����Դϴ�.\n");
        return 1;
    }

    // ���� ���� ���� ���
    printf("\n=== ���� ���� ���� ===\n");
    for (int i = 0; i <= numPurchase; i++) {
        printf("%d. %s (Size: %s) - $%.2f\n", i + 1, purchaseHistory[i].itemName, purchaseHistory[i].size, purchaseHistory[i].price);
    }

    return 0;
}

// �� ���� �Լ�
float purchaseProduct(char itemName[], float price, struct CustomerInfo* customer, struct PurchaseHistory* purchaseHistory, int* numPurchase) {
    struct PurchaseHistory purchase;
    strcpy_s(purchase.itemName, sizeof(purchase.itemName), itemName);
    purchase.price = price;

    // ����ڿ��� ������ ��õ
    printf("\n=== ������ ��õ ===\n");
    printf("|---------------------|------------------|-----------------|----------------|\n");
    printf("|        ������       |       Ű(cm)      |     ������(kg)   |  �㸮�ѷ�(cm)  |\n");
    printf("|---------------------|------------------|-----------------|----------------|\n");
    printf("|          S          |     160 - 170     |     50 - 65      |    70 - 80     |\n");
    printf("|---------------------|------------------|-----------------|----------------|\n");
    printf("|          M          |     170 - 180     |     65 - 75      |    80 - 90     |\n");
    printf("|---------------------|------------------|-----------------|----------------|\n");
    printf("|          L          |     180 - 190     |     75 - 90      |    90 - 100    |\n");
    printf("|---------------------|------------------|-----------------|----------------|\n");
    printf("|          XL         |     190 �̻�      |     90 �̻�      |   100 �̻�     |\n");
    printf("|---------------------|------------------|-----------------|----------------|\n");

    // ����ڿ��� ������ ����
    printf("\n����� �����ϼ��� (S, M, L, XL): ");
    scanf_s("%2s", purchase.size, sizeof(purchase.size));

    // �� ���� ���� ���
    printf("%s�� �����Ͽ����ϴ�. ����: $%.2f, ������: %s\n", purchase.itemName, purchase.price, purchase.size);

    // ���� ���� ������ �߰�
    strcpy_s(purchaseHistory[*numPurchase].size, sizeof(purchase.size), purchase.size);
    (*numPurchase)++;

    return purchase.price;
}
