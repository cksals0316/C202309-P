#ifndef SIZE_RECOMMENDATION_H
#define SIZE_RECOMMENDATION_H

// 구조체 정의: 고객 정보
struct CustomerInfo {
    float height;
    float weight;
    int waistSize;
    char size[3]; // S, M, L, XL
};

// 구조체 정의: 구매 내역
struct PurchaseHistory {
    char itemName[50];
    float price;
    char size[3]; // S, M, L, XL
};

// 함수 선언
void shoppingLoop();
float purchaseProduct(char itemName[], float price, struct CustomerInfo* customer, struct PurchaseHistory* purchaseHistory, int* numPurchase);

#endif // SIZE_RECOMMENDATION_H
