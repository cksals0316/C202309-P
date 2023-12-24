#ifndef SIZE_RECOMMENDATION_H
#define SIZE_RECOMMENDATION_H

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
void shoppingLoop();
float purchaseProduct(char itemName[], float price, struct CustomerInfo* customer, struct PurchaseHistory* purchaseHistory, int* numPurchase);

#endif // SIZE_RECOMMENDATION_H
