#include <stdio.h>
#include "사이즈추천.h"

// 함수 선언
float purchaseProduct(char itemName[], float price, struct CustomerInfo* customer, struct PurchaseHistory* purchaseHistory, int* numPurchase);
void shoppingLoop();

int main() {
    struct CustomerInfo customer;
    // 고객에게 정보 입력 요청
    printf("고객님의 키를 입력하세요 (cm): ");
    scanf_s("%f", &customer.height, sizeof(customer.height));

    printf("고객님의 몸무게를 입력하세요 (kg): ");
    scanf_s("%f", &customer.weight, sizeof(customer.weight));

    printf("고객님의 허리둘레를 입력하세요 ** 반드시 cm 기준으로 입력해주셍. (cm): ");
    scanf_s("%d", &customer.waistSize, sizeof(customer.waistSize));

    // 입력받은 정보 출력
    printf("\n고객님의 신체 정보:\n");
    printf("키: %.2f cm\n", customer.height);
    printf("몸무게: %.2f kg\n", customer.weight);
    printf("허리둘레: %d cm\n", customer.waistSize);

    shoppingLoop();

    return 0;
}

// 쇼핑 루프
void shoppingLoop();
   

// 옷 구매 함수
float purchaseProduct(char itemName[], float price, struct CustomerInfo* customer, struct PurchaseHistory* purchaseHistory, int* numPurchase);
   