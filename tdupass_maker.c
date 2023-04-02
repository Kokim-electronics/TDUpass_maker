#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(void) {
    int ln, s, ko, re;
    char moji[256] = "23456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz!#$%%()*+-./:;=?@[]^_{}";
    do {
        printf("パスワードの長さ(10 <= length <= 20(12文字以上推奨)) : ");
        scanf("%d", &ln);
    } while (ln < 10 || 20 < ln);

    do {
        printf("生成個数 : ");
        scanf("%d", &ko);
    } while (ko < 1);

    srand((unsigned)time(NULL));

    printf("\n");
    char moji_used[100];
    for (int i = 0; i < ko; i++) {
        // char

        for (int ji = 0; ji < ln + 1; ji++) {
            moji_used[ji] = 's';
        }

        for (int j = 0; j < ln; j++) {
            int hantei = 0;
            s = rand() % (80);

            if (j != 0) {
                for (int k = 0; k < ln; k++) {
                    if (moji_used[k] == moji[s]) {
                        hantei = 1;
                    }
                }
            }
            if (hantei == 0) {
                printf("%c", moji[s]);
                moji_used[j] = moji[s];

            } else {
                j--;
            }
        }
        printf("\n");
    }
    printf("\n終了するには半角数字 + Enter");
    scanf("%d", &re);
}
