#include <stdio.h>
#include <string.h>

// ����ü ����: �� ��ü ����
struct CustomerInfo {
    float height;
    float weight;
    float waistCircumference;
};

// ����ü ����: ���� ���� ����
struct PurchaseHistory {
    char itemName[50];
    float itemPrice;
};

int main() {
    // ���� ���� ���� �ʱ�ȭ
    struct PurchaseHistory previousPurchase;
    strcpy_s(previousPurchase.itemName, sizeof(previousPurchase.itemName), "��û����");
    previousPurchase.itemPrice = 35000.0;

    // ���� ����
    float height, weight, waistCircumference;

    // ����ڷκ��� Ű �Է� �ޱ� (������� ��)
    printf("Ű�� �Է��ϼ��� (���, cm): ");
    scanf_s("%f", &height);
    if (height <= 0) {
        printf("�߸��� �Է��Դϴ�. Ű�� ������� �մϴ�.\n");
        return 1; // ���α׷� ����
    }

    // ����ڷκ��� ������ �Է� �ޱ� (������� ��)
    printf("�����Ը� �Է��ϼ��� (���, kg): ");
    scanf_s("%f", &weight);
    if (weight <= 0) {
        printf("�߸��� �Է��Դϴ�. �����Դ� ������� �մϴ�.\n");
        return 1; // ���α׷� ����
    }

    // ����ڷκ��� �㸮�ѷ� �Է� �ޱ� (������� ��)
    printf("�㸮�ѷ��� �Է��ϼ��� (���, cm): ");
    scanf_s("%f", &waistCircumference);
    if (waistCircumference <= 0) {
        printf("�߸��� �Է��Դϴ�. �㸮�ѷ��� ������� �մϴ�.\n");
        return 1; // ���α׷� ����
    }

    // �Է¹��� ���� ���
    printf("\n�� ��ü ����\n");
    printf("Ű: %.2f cm\n", height);
    printf("������: %.2f kg\n", weight);
    printf("�㸮�ѷ�: %.2f cm\n", waistCircumference);

    // ���� ���� ���� ���
    printf("\n���� ���� ����\n");
    printf("�����۸�: %s\n", previousPurchase.itemName);
    printf("����: %.2f ��\n", previousPurchase.itemPrice);

    return 0;
}
