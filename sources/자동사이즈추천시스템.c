#include <stdio.h>
#include "��������õ.h"

// �Լ� ����
float purchaseProduct(char itemName[], float price, struct CustomerInfo* customer, struct PurchaseHistory* purchaseHistory, int* numPurchase);
void shoppingLoop();

int main() {
    struct CustomerInfo customer;
    // ������ ���� �Է� ��û
    printf("������ Ű�� �Է��ϼ��� (cm): ");
    scanf_s("%f", &customer.height, sizeof(customer.height));

    printf("������ �����Ը� �Է��ϼ��� (kg): ");
    scanf_s("%f", &customer.weight, sizeof(customer.weight));

    printf("������ �㸮�ѷ��� �Է��ϼ��� ** �ݵ�� cm �������� �Է����ּ�. (cm): ");
    scanf_s("%d", &customer.waistSize, sizeof(customer.waistSize));

    // �Է¹��� ���� ���
    printf("\n������ ��ü ����:\n");
    printf("Ű: %.2f cm\n", customer.height);
    printf("������: %.2f kg\n", customer.weight);
    printf("�㸮�ѷ�: %d cm\n", customer.waistSize);

    shoppingLoop();

    return 0;
}

// ���� ����
void shoppingLoop();
   

// �� ���� �Լ�
float purchaseProduct(char itemName[], float price, struct CustomerInfo* customer, struct PurchaseHistory* purchaseHistory, int* numPurchase);
   