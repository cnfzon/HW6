#include <stdio.h>

struct card {
    char* face;  // �j�p
    char* suit;  // ���
};

int main(void) {
    struct card aCard;        // aCard���c�ܼ�
    struct card* cardPtr;     // ���Vcard���c������cardPtr

    //string address��ȵ�aCard
    aCard.face = "Ace";
    aCard.suit = "Spades";

    cardPtr = &aCard;         // aCard address��ȵ�cardPtr ����

    printf("%s%s%s\n%s%s%s\n%s%s%s\n", 
        aCard.face, " of ", aCard.suit,        // �����I�saCard
        cardPtr->face, " of ", cardPtr->suit,  // ���ЩI�s
        (*cardPtr).face, " of ", (*cardPtr).suit
    );

    return 0;
}
