#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MM_IN_INCH 25.4

int IsDigit(char c) {
    return c >= '0' && c <= '9';
}

int IsSeparator(char c) {
    return c == ' ' || c == '\n' || c == '\t' || c == ',' || c == EOF;
}

struct Inch {
    char *num;
    size_t size;
};

void InitInch(struct Inch *inch) {
    inch->num = NULL;
    inch->size = 0;
    assert(inch->num == NULL && inch->size == 0);
}

void AddDigitToInch(struct Inch *inch, char c) {
    ++inch->size;
    if (inch->num == NULL) {
        inch->num = malloc(sizeof(char));
    } else {
        inch->num = realloc(inch->num, sizeof(char) * inch->size);
    }
    inch->num[inch->size - 1] = c;
    assert(inch->num[inch->size - 1] == c);
}

void ResetInch(struct Inch *inch) {
    free(inch->num);
    inch->num = NULL;
    inch->size = 0;
    assert(inch->num == NULL && inch->size == 0);
}

void Final(struct Inch *inch) {
    double res = strtod(inch->num, NULL) * MM_IN_INCH;
    printf("%gmm", res);
    assert(res == strtod(inch->num, NULL) * MM_IN_INCH);
    ResetInch(inch);
    assert(inch->num == NULL && inch->size == 0);
}

void PrintUnfinishedInch(struct Inch *inch) {
    printf("%s", inch->num);
    ResetInch(inch);
    assert(inch->num == NULL && inch->size == 0);
}


typedef enum {
    SEARCH, FIRST, DOT, SECOND, CHAR_I, CHAR_N
} State;


void UnitTests() {
    assert(IsDigit('c') == 0);
    assert(IsDigit('9') == 1);
    assert(IsSeparator('r') == 0);
    assert(IsSeparator('\t') == 1);
};

int main() {
    UnitTests();
    char c;
    char last_c = EOF;
    struct Inch inch;
    InitInch(&inch);
    State state = SEARCH;

    while ((c = getchar()) != EOF) {

        switch (state) {
            case SEARCH:
                if (IsDigit(c) && IsSeparator(last_c)) {
                    AddDigitToInch(&inch, c);
                    state = FIRST;
                } else {
                    printf("%c", c);
                }
                break;

            case FIRST:
                if (IsDigit(c) && inch.size > 0) {
                    AddDigitToInch(&inch, c);
                } else if (c == '.' && inch.size > 0) {
                    state = DOT;
                    AddDigitToInch(&inch, c);
                } else if (c == 'i' && inch.size > 0) {
                    state = CHAR_I;
                    AddDigitToInch(&inch, c);
                } else {
                    PrintUnfinishedInch(&inch);
                    printf("%c", c);
                    state = SEARCH;
                }
                break;

            case DOT:
                if (IsDigit(c) && inch.size > 0) {
                    AddDigitToInch(&inch, c);
                    state = SECOND;
                } else {
                    PrintUnfinishedInch(&inch);
                    printf("%c", c);
                    state = SEARCH;
                }
                break;

            case SECOND:
                if (IsDigit(c) && inch.size > 0) {
                    AddDigitToInch(&inch, c);
                } else if (c == 'i') {
                    AddDigitToInch(&inch, c);
                    state = CHAR_I;
                } else {
                    PrintUnfinishedInch(&inch);
                    printf("%c", c);
                    state = SEARCH;
                }
                break;

            case CHAR_I:
                if (c == 'n') {
                    AddDigitToInch(&inch, c);
                    state = CHAR_N;
                } else {
                    PrintUnfinishedInch(&inch);
                    printf("%c", c);
                    state = SEARCH;
                }
                break;

            case CHAR_N:
                if (IsSeparator(c) || c == '.') {
                    Final(&inch);
                    printf("%c", c);
                } else {
                    PrintUnfinishedInch(&inch);
                    printf("%c", c);
                }
                state = SEARCH;
                break;

            default:
                break;
        }

        last_c = c;
    }
}
