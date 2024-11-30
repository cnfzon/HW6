#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card {
    const char* face;  // �j�p
    const char* suit;  // ���
};

typedef struct card Card;  

void fillDeck(Card* const wDeck, const char* wFace[], const char* wSuit[]);  //�P,�j�p,���
void shuffle(Card* const wDeck);    //52�i�Pdeck
void deal(const Card* const wDeck); //�o�Pdeck

int main(void) {
    Card deck[52]; //52�i�P

    const char* face[] = { "Ace", "Deuce", "Three", "Four", "Five",
                           "Six", "Seven", "Eight", "Nine", "Ten",
                           "Jack", "Queen", "King" };
    const char* suit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

    srand((unsigned int)time(NULL));  // �H���ƪ�l��

    fillDeck(deck, face, suit);       //��l�Ƽ��J�P

    shuffle(deck);                    //�~�P

    deal(deck);                       //�o�P

    return 0;
}

//��l�Ƽ��J�P
void fillDeck(Card* const wDeck, const char* wFace[], const char* wSuit[]) {
    for (int i = 0; i < 52; i++) {
        wDeck[i].face = wFace[i % 13];   // ���ȴ`��
        wDeck[i].suit = wSuit[i / 13];   // ���`��
    }
}

//�~�P���
void shuffle(Card* const wDeck) {
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;  // �H����ܤ@�i�P

        // �洫 wDeck[i] �M wDeck[j]
        Card temp = wDeck[i];
        wDeck[i] = wDeck[j];
        wDeck[j] = temp;
    }
}

//�o�P���
void deal(const Card* const wDeck) {
    for (int i = 0; i < 52; i++) {
        printf("%5s of %-8s%c", wDeck[i].face, wDeck[i].suit, (i + 1) % 4 == 0 ? '\n' : '\t');  // �C�� 4 �i�P
    }
}
