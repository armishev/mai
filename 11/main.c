#include <stdio.h>

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int is_character(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_') || (c == '-');
}

int main(void)
{
    int state = 1, digit = 0, SumDigit = 0, prdigit = '~', SumPrDigit = 0, pr2digit = '~', SumPr2Digit = 0;
    unsigned BufferSize = 2;
    char symbol;
    int flag = 1;
    char buffer[BufferSize];
    while (fgets(buffer, BufferSize, stdin)){
        int i = 0;
        while (i < BufferSize && buffer[i] != 0) {
            symbol = buffer[i];
            switch (state) {
                case 1:
                    if(symbol == '-'){
                        flag=-1;
                    }else if(is_digit(symbol)){
                        digit = (digit * 10) + (symbol - '0');
                        SumDigit = SumDigit + (symbol - '0');
                        state = 2;
                    }else if(is_character(symbol)){
                        state = 3;
                    }
                    else if(symbol == ' ' || symbol == '\n'){
                        state = 1;
                    }
                    break;
                case 2:
                    if (is_digit(symbol)) {
                        digit = (digit * 10) + (symbol - '0');
                        SumDigit = SumDigit + (symbol - '0');
                        state = 2;
                    }else if(symbol == ' ' || symbol == '\n') {
                        state = 1;
                        pr2digit = prdigit;
                        SumPr2Digit = SumPrDigit;
                        prdigit = digit * flag;
                        SumPrDigit = SumDigit;
                        flag=1;
                        digit = 0;
                        SumDigit=0;
                    }else if (is_character(symbol)) {
                        state = 3;
                        digit=0;
                        SumDigit=0;
                    }
                    break;
                case 3:
                    if (is_digit(symbol) || is_character(symbol)) {
                        state = 3;
                    }else if (symbol == ' ' || symbol == '\n') {
                        state = 1;
                    }
                    break;
            }
            i++;
        }
    }

    if(digit!=0){
        printf("Number: %d\n", prdigit);
        printf("Sum: %d\n", SumPrDigit);
    }else{
        if(prdigit=='~') {
            printf("There is not enough numbers\n");
        }else{
            printf("Number: %d\n", pr2digit);
            printf("Sum: %d\n", SumPr2Digit);
        }
    }


}

