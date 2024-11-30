#include <stdio.h>

struct card {
    char* face;  // 大小
    char* suit;  // 花色
};

int main(void) {
    struct card aCard;        // aCard結構變數
    struct card* cardPtr;     // 指向card結構的指標cardPtr

    //string address賦值給aCard
    aCard.face = "Ace";
    aCard.suit = "Spades";

    cardPtr = &aCard;         // aCard address賦值給cardPtr 指標

    printf("%s%s%s\n%s%s%s\n%s%s%s\n", 
        aCard.face, " of ", aCard.suit,        // 直接呼叫aCard
        cardPtr->face, " of ", cardPtr->suit,  // 指標呼叫
        (*cardPtr).face, " of ", (*cardPtr).suit
    );

    return 0;
}
