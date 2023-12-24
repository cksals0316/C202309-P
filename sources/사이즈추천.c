#include <stdio.h>
#include <string.h>
#include "사이즈추천.h"

void shoppingLoop() {
    struct PurchaseHistory purchaseHistory[10];  // 최대 10개의 구매 내역 저장 가능
    int numPurchase = 0;  // 현재까지 저장된 구매 내역 개수
    struct CustomerInfo customer;

    do {
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
            purchaseHistory[numPurchase].price = 59000;  // 직접 가격 할당
            purchaseProduct("와이드 밴딩 데님 바지", purchaseHistory[numPurchase].price, &customer, purchaseHistory, &numPurchase);
            break;
        case 2:
            purchaseHistory[numPurchase].price = 54000;  // 직접 가격 할당
            purchaseProduct("윈터 울 와이드 슬랙스", purchaseHistory[numPurchase].price, &customer, purchaseHistory, &numPurchase);
            break;
        case 3:
            purchaseHistory[numPurchase].price = 56000;  // 직접 가격 할당
            purchaseProduct("골덴 워싱 와이드 팬츠", purchaseHistory[numPurchase].price, &customer, purchaseHistory, &numPurchase);
            break;
        case 4:
            purchaseHistory[numPurchase].price = 46000;  // 직접 가격 할당
            purchaseProduct("워싱 블랙 와이드 데님", purchaseHistory[numPurchase].price, &customer, purchaseHistory, &numPurchase);
            break;
        case 5:
            purchaseHistory[numPurchase].price = 42000;  // 직접 가격 할당
            purchaseProduct("델리 와이드 카고 데님", purchaseHistory[numPurchase].price, &customer, purchaseHistory, &numPurchase);
            break;
        case 6:
            purchaseHistory[numPurchase].price = 34000;  // 직접 가격 할당
            purchaseProduct("와이드 하프 데님 쇼츠", purchaseHistory[numPurchase].price, &customer, purchaseHistory, &numPurchase);
            break;
        default:
            printf("잘못된 선택입니다.\n");
            return 1;
        }


        // 사용자에게 계속 쇼핑할지 여부 확인
        char continueShopping;
        printf("\n계속해서 쇼핑하시겠습니까? (Y/N): ");
        scanf_s(" %c", &continueShopping, sizeof(continueShopping));

        if (continueShopping != 'Y' && continueShopping != 'y') {
            printf("\n쇼핑을 종료합니다. 이전 구매 내역:\n");

            // 이전 구매 내역 출력
            for (int i = 0; i < numPurchase; ++i) {
                printf("제품명: %s, 가격: $%.2f, 사이즈: %s\n", purchaseHistory[i].itemName, purchaseHistory[i].price, purchaseHistory[i].size);
            }

            return;
        }

    } while (1);
}

// 옷 구매 함수
float purchaseProduct(char itemName[], float price, struct CustomerInfo* customer, struct PurchaseHistory* purchaseHistory, int* numPurchase) {
    struct PurchaseHistory purchase;
    strcpy_s(purchase.itemName, sizeof(purchase.itemName), itemName);
    purchase.price = price;

    // 사용자에게 사이즈 추천

    printf("저희 매장 회원님들의 평균 옷 사이즈 표입니다.\n");
    printf("\n=== 사이즈 추천 ===\n");
    printf("|---------------------|------------------|-----------------|----------------|\n");
    printf("|        사이즈       |       키(cm)     |     몸무게(kg)  |  허리둘레(cm)  |\n");
    printf("|---------------------|------------------|-----------------|----------------|\n");
    printf("|          S          |     160 - 170    |     50 - 65     |    70 - 80     |\n");
    printf("|---------------------|------------------|-----------------|----------------|\n");
    printf("|          M          |     170 - 180    |     65 - 75     |    80 - 90     |\n");
    printf("|---------------------|------------------|-----------------|----------------|\n");
    printf("|          L          |     180 - 190    |     75 - 90     |    90 - 100    |\n");
    printf("|---------------------|------------------|-----------------|----------------|\n");
    printf("|          XL         |     190 이상     |     90 이상     |   100 이상     |\n");
    printf("|---------------------|------------------|-----------------|----------------|\n");

    // 사용자에게 사이즈 선택
    printf("\n사이즈를 선택하세요 (S, M, L, XL): ");
    scanf_s("%2s", purchase.size, sizeof(purchase.size));

    // 사용자가 선택한 사이즈와 표에 제시된 범위의 사이즈를 비교
    if ((strcmp(purchase.size, "S") != 0 && customer->height >= 160 && customer->height <= 170 && customer->weight >= 50 && customer->weight <= 65 && customer->waistSize >= 70 && customer->waistSize <= 80) ||
        (strcmp(purchase.size, "M") != 0 && customer->height >= 170 && customer->height <= 180 && customer->weight >= 65 && customer->weight <= 75 && customer->waistSize >= 80 && customer->waistSize <= 90) ||
        (strcmp(purchase.size, "L") != 0 && customer->height >= 180 && customer->height <= 190 && customer->weight >= 75 && customer->weight <= 90 && customer->waistSize >= 90 && customer->waistSize <= 100) ||
        (strcmp(purchase.size, "XL") != 0 && customer->height >= 190 && customer->weight >= 90 && customer->waistSize >= 100)) {

        char confirm;
        printf("\n사이즈가 맞지 않습니다. 그래도 구입하시겠습니까? (Y/N): ");
        scanf_s(" %c", &confirm, sizeof(confirm));

        if (confirm != 'Y' && confirm != 'y') {
            printf("구매가 취소되었습니다.\n");
            return 0.0;  // 구매가 취소되었으므로 가격을 반환하지 않음
        }
    }

    // 옷 구매 정보 출력
    printf("%s를 구매하였습니다. 가격: $%.2f, 사이즈: %s\n", purchase.itemName, purchase.price, purchase.size);

    // 이전 구매 내역에 추가
    strncpy_s(purchaseHistory[*numPurchase].itemName, sizeof(purchaseHistory[*numPurchase].itemName), purchase.itemName, _TRUNCATE);
    strncpy_s(purchaseHistory[*numPurchase].size, sizeof(purchaseHistory[*numPurchase].size), purchase.size, _TRUNCATE);
    (*numPurchase)++;

    return purchase.price;
}
