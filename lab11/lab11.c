#include <stdio.h>
#include <stdlib.h>

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
    int is_int;
    int is_final;
};

void InitInch(struct Inch *inch) {
    inch->num = NULL;
    inch->size = 0;
    inch->is_int = 1;
    inch->is_final = 0;
}

void AddDigitToInch(struct Inch *inch, char c) {
    ++inch->size;
    if (inch->num == NULL) {
        inch->num = malloc(sizeof(char) * 2);
    } else {
        inch->num = realloc(inch->num, sizeof(char) * (inch->size + 1));
    }
    inch->num[inch->size - 1] = (char) c;
    inch->num[inch->size] = '\000';
    inch->is_int = inch->is_int ? c != '.' : 0;
}


void ResetInch(struct Inch *inch) {
    free(inch->num);
    inch->num = NULL;
    inch->size = 0;
    inch->is_int = 1;
    inch->is_final = 0;
}

double GetIntResult(struct Inch *inch) {
    double res = 0;
    for (int i = 0; i < inch->size - 2; ++i) {
        res = res * 10 + (inch->num[i] - '0');
    }
    return res * MM_IN_INCH;
}

double GetDoubleResult(struct Inch *inch) {
    double res = 0;
    int second = 0;
    int pow = 10;
    for (int i = 0; i < inch->size - 2; ++i) {
        if (!second && inch->num[i] != '.') {
            res = res * 10 + (inch->num[i] - '0');
        } else {
            ++second;
            res += (inch->num[i] - '0') / pow;
            pow *= 10;
        }
    }
    return res * MM_IN_INCH;
}

void Final(struct Inch *inch) {
    inch->is_final = 1;
    if (inch->is_int) {
        double res = GetIntResult(inch);
        printf("%gmm", res);
    } else {
        double res = GetDoubleResult(inch);
        printf("%gmm", res);
    }
    ResetInch(inch);
}

void PrintUnfinishedInch(struct Inch *inch) {
    printf("%s", inch->num);
    ResetInch(inch);
}

typedef enum {
    SEARCH, FIRST, DOT, SECOND, CHAR_I, CHAR_N
} State;


int main() {
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
