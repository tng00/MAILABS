#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#define CONSONANTS (67108863u & ~(1u << ('a' - 'a') | 1u << ('e' - 'a') | 1u << ('i' - 'a') | 1u << ('o' - 'a') | 1u << ('u' - 'a')))
//66043630


int IsSeparator(char c) {
    return c == ' ' || c == '\n' || c == '\t' || c == ',' || c == EOF;
}

typedef enum {
    SEPARATOR, WORD
} State;

int main() {
    char c;
    int32_t word = 0;
    int32_t res = CONSONANTS;
    State state = SEPARATOR;
    while ((c = getchar()) != EOF) {
        switch (state) {
            case SEPARATOR:
                if (!IsSeparator(c)) {
                    c = tolower(c);
                    word |= 1u << (c - 'a');
                    state = WORD;
                }
                break;
            case WORD:
                if (!IsSeparator(c)) {
                    c = tolower(c);
                    word |= 1u << (c - 'a');
                } else {
                    res &= word;
                    word = 0;
                    state = SEPARATOR;
                }
                break;
        }
    }

    if (res > 0) {
        printf("YES, COMMON CONSONANT FOUND.");
    } else {
        printf("NO COMMON CONSONANT.");
    }
}
