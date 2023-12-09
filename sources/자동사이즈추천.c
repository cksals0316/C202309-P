#include <stdio.h>

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
float purchaseProduct(char itemName[], float price, struct CustomerInfo* customer, struct PurchaseHistory* purchaseHistory, int* numPurchase);

int main() {
    // 구조체 변수 선언
    struct CustomerInfo customer;

    // 이전 구매 내역 배열 선언
    struct PurchaseHistory purchaseHistory[10];  // 최대 10개의 구매 내역 저장 가능
    int numPurchase = 0;  // 현재까지 저장된 구매 내역 개수

    // 고객에게 정보 입력 요청
    printf("고객님의 키를 입력하세요 (cm): ");
    scanf_s("%f", &customer.height, sizeof(customer.height));

    printf("고객님의 몸무게를 입력하세요 (kg): ");
    scanf_s("%f", &customer.weight, sizeof(customer.weight));

    printf("고객님의 허리둘레를 입력하세요 (cm): ");
    scanf_s("%d", &customer.waistSize, sizeof(customer.waistSize));

    // 입력받은 정보 출력
    printf("\n고객님의 신체 정보:\n");
    printf("키: %.2f cm\n", customer.height);
    printf("몸무게: %.2f kg\n", customer.weight);
    printf("허리둘레: %d cm\n", customer.waistSize);

    // 옷 구매 창 표시 및 옷 구매
    printf("\n=== 옷 구매 창 ===\n");
    printf("1. 와이드 밴딩 데님 바지 - 59000원\n");
    printf("2. 윈터 울 와이드 슬랙스 - 54000원\n");
    printf("3. 골덴 워싱 와이드 팬츠 - 56000원\n");
    printf("4. 워싱 블랙 와이드 데님 - 46000원\n");
    printf("5. 델리 와이드 카고 데님 - 42000원\n");
    printf("6. 와이드 하프 데님 쇼츠 - 34000원\n");

    int choice;
    printf("\n구매할 제품 번호를 선택하세요 (1-6): ");
    scanf_s("%d", &choice, sizeof(choice));

    // 선택한 제품에 따라 가격 계산 및 구매 내역에 추가
    switch (choice) {
    case 1:
        purchaseHistory[numPurchase].price = purchaseProduct("와이드 밴딩 데님 바지", 59000, &customer, purchaseHistory, &numPurchase);
        break;
    case 2:
        purchaseHistory[numPurchase].price = purchaseProduct("윈터 울 와이드 슬랙스", 54000, &customer, purchaseHistory, &numPurchase);
        break;
    case 3:
        purchaseHistory[numPurchase].price = purchaseProduct("골덴 워싱 와이드 팬츠", 56000, &customer, purchaseHistory, &numPurchase);
        break;
    case 4:
        purchaseHistory[numPurchase].price = purchaseProduct("워싱 블랙 와이드 데님", 46000, &customer, purchaseHistory, &numPurchase);
        break;
    case 5:
        purchaseHistory[numPurchase].price = purchaseProduct("델리 와이드 카고 데님", 42000, &customer, purchaseHistory, &numPurchase);
        break;
    case 6:
        purchaseHistory[numPurchase].price = purchaseProduct("와이드 하프 데님 쇼츠", 34000, &customer, purchaseHistory, &numPurchase);
        break;
    default:
        printf("잘못된 선택입니다.\n");
        return 1;
    }

    // 이전 구매 내역 출력
    printf("\n=== 이전 구매 내역 ===\n");
    for (int i = 0; i <= numPurchase; i++) {
        printf("%d. %s (Size: %s) - $%.2f\n", i + 1, purchaseHistory[i].itemName, purchaseHistory[i].size, purchaseHistory[i].price);
    }

    return 0;
}

// 옷 구매 함수
float purchaseProduct(char itemName[], float price, struct CustomerInfo* customer, struct PurchaseHistory* purchaseHistory, int* numPurchase) {
    struct PurchaseHistory purchase;
    strcpy_s(purchase.itemName, sizeof(purchase.itemName), itemName);
    purchase.price = price;

    // 사용자에게 사이즈 추천
    printf("\n=== 사이즈 추천 ===\n");
    printf("|---------------------|------------------|-----------------|----------------|\n");
    printf("|        사이즈       |       키(cm)      |     몸무게(kg)   |  허리둘레(cm)  |\n");
    printf("|---------------------|------------------|-----------------|----------------|\n");
    printf("|          S          |     160 - 170     |     50 - 65      |    70 - 80     |\n");
    printf("|---------------------|------------------|-----------------|----------------|\n");
    printf("|          M          |     170 - 180     |     65 - 75      |    80 - 90     |\n");
    printf("|---------------------|------------------|-----------------|----------------|\n");
    printf("|          L          |     180 - 190     |     75 - 90      |    90 - 100    |\n");
    printf("|---------------------|------------------|-----------------|----------------|\n");
    printf("|          XL         |     190 이상      |     90 이상      |   100 이상     |\n");
    printf("|---------------------|------------------|-----------------|----------------|\n");

    // 사용자에게 사이즈 선택
    printf("\n사이즈를 선택하세요 (S, M, L, XL): ");
    scanf_s("%2s", purchase.size, sizeof(purchase.size));

    // 옷 구매 정보 출력
    printf("%s를 구매하였습니다. 가격: $%.2f, 사이즈: %s\n", purchase.itemName, purchase.price, purchase.size);

    // 이전 구매 내역에 추가
    strcpy_s(purchaseHistory[*numPurchase].size, sizeof(purchase.size), purchase.size);
    (*numPurchase)++;

    return purchase.price;
}
