#include <stdio.h>
#include <string.h>

// 구조체 정의: 고객 신체 정보
struct CustomerInfo {
    float height;
    float weight;
    float waistCircumference;
};

// 구조체 정의: 이전 구매 내역
struct PurchaseHistory {
    char itemName[50];
    float itemPrice;
};

int main() {
    // 이전 구매 내역 초기화
    struct PurchaseHistory previousPurchase;
    strcpy_s(previousPurchase.itemName, sizeof(previousPurchase.itemName), "흑청바지");
    previousPurchase.itemPrice = 35000.0;

    // 변수 선언
    float height, weight, waistCircumference;

    // 사용자로부터 키 입력 받기 (양수여야 함)
    printf("키를 입력하세요 (양수, cm): ");
    scanf_s("%f", &height);
    if (height <= 0) {
        printf("잘못된 입력입니다. 키는 양수여야 합니다.\n");
        return 1; // 프로그램 종료
    }

    // 사용자로부터 몸무게 입력 받기 (양수여야 함)
    printf("몸무게를 입력하세요 (양수, kg): ");
    scanf_s("%f", &weight);
    if (weight <= 0) {
        printf("잘못된 입력입니다. 몸무게는 양수여야 합니다.\n");
        return 1; // 프로그램 종료
    }

    // 사용자로부터 허리둘레 입력 받기 (양수여야 함)
    printf("허리둘레를 입력하세요 (양수, cm): ");
    scanf_s("%f", &waistCircumference);
    if (waistCircumference <= 0) {
        printf("잘못된 입력입니다. 허리둘레는 양수여야 합니다.\n");
        return 1; // 프로그램 종료
    }

    // 입력받은 정보 출력
    printf("\n고객 신체 정보\n");
    printf("키: %.2f cm\n", height);
    printf("몸무게: %.2f kg\n", weight);
    printf("허리둘레: %.2f cm\n", waistCircumference);

    // 이전 구매 내역 출력
    printf("\n이전 구매 내역\n");
    printf("아이템명: %s\n", previousPurchase.itemName);
    printf("가격: %.2f 원\n", previousPurchase.itemPrice);

    return 0;
}
