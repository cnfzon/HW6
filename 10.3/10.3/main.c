#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card {
    const char* face;  // 大小
    const char* suit;  // 花色
};

typedef struct card Card;  

void fillDeck(Card* const wDeck, const char* wFace[], const char* wSuit[]);  //牌,大小,花色
void shuffle(Card* const wDeck);    //52張牌deck
void deal(const Card* const wDeck); //發牌deck

int main(void) {
    Card deck[52]; //52張牌

    const char* face[] = { "Ace", "Deuce", "Three", "Four", "Five",
                           "Six", "Seven", "Eight", "Nine", "Ten",
                           "Jack", "Queen", "King" };
    const char* suit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

    srand((unsigned int)time(NULL));  // 隨機數初始化

    fillDeck(deck, face, suit);       //初始化撲克牌

    shuffle(deck);                    //洗牌

    deal(deck);                       //發牌

    return 0;
}

//初始化撲克牌
void fillDeck(Card* const wDeck, const char* wFace[], const char* wSuit[]) {
    for (int i = 0; i < 52; i++) {
        wDeck[i].face = wFace[i % 13];   // 面值循環
        wDeck[i].suit = wSuit[i / 13];   // 花色循環
    }
}

//洗牌函數
void shuffle(Card* const wDeck) {
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;  // 隨機選擇一張牌

        // 交換 wDeck[i] 和 wDeck[j]
        Card temp = wDeck[i];
        wDeck[i] = wDeck[j];
        wDeck[j] = temp;
    }
}

//發牌函數
void deal(const Card* const wDeck) {
    for (int i = 0; i < 52; i++) {
        printf("%5s of %-8s%c", wDeck[i].face, wDeck[i].suit, (i + 1) % 4 == 0 ? '\n' : '\t');  // 每行 4 張牌
    }
}
