#include <stdio.h>

int main() {
    // ���� ���� ���� �ʱ�ȭ
    char previousItemName[50];
    float previousItemPrice;

    // ��û���� ���� �Է�
    strcpy(previousItemName, "��û����");
    previousItemPrice = 35000.0;

    // ���� ����
    float height, weight, waistsize;

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
    scanf_s("%f", &waistsize);
    if (waistsize <= 0) {
        printf("�߸��� �Է��Դϴ�. �㸮�ѷ��� ������� �մϴ�.\n");
        return 1; // ���α׷� ����
    }

    // �Է¹��� ���� ���
    printf("\n�� ��ü ����\n");
    printf("Ű: %.2f cm\n", height);
    printf("������: %.2f kg\n", weight);
    printf("�㸮�ѷ�: %.2f cm\n", waistsize);

    // ���� ���� ���� ���
    printf("\n���� ���� ����\n");
    printf("�����۸�: %s\n", previousItemName);
    printf("����: %.2f ��\n", previousItemPrice);

    return 0;
}
