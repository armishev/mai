#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

typedef u_int16_t ElementType;
typedef u_int8_t ByteType;

bool checkint8(ByteType character){
    return (character & 128) == 0;
}

bool checkint16_1(ByteType character){
    character = character >> 5;
    return (character == 6);
}

bool checkint16_2(ByteType character){
    character = character >> 6;
    return (character == 2);
}

ElementType getelement(FILE* element){
    ByteType character = fgetc(element);
    if(character == EOF) return 0;
    if(checkint8(character)){
        return tolower(character);
    }
    else if(isspace(character) || character == '\n' || character == '\0'){
        return character;
    }
    else if(checkint16_1(character)){
        ByteType character2 = fgetc(element);
        if(checkint16_2(character2)) {
            return tolower(((character << 8) | (character2)));
        }
        return 0;
        }
    return 0;
}


bool checkVowel(character){
    if ((character == 'a') || (character == 'e') || (character == 'i') || (character == 'o') || (character == 'u')  || (character == 'y')){
        return 1;
    }
    if ((character == 53424) || (character == 53438) || (character == 53645) || (character == 53429) || (character == 53643)  || (character == 53635)  || (character == 53649) || (character == 53646) || (character == 53647) || (character == 53432) || (character == 53392) || (character == 53406) || (character == 53421) || (character == 53397) || (character == 53400) || (character == 53419) || (character == 53411) || (character == 53377) || (character == 53422) || (character == 53423)){
        return 1;
    }
    return 0;
}

int main(void)
{
    FILE* element = fopen("input.txt", "r");
    ElementType character = 1;
    bool condition1 = 0;
    bool condition2 = 0;
    bool condition = 0;
    bool cond = 0;
    bool space = 1;
    unsigned int k = 0;
    while(character != 0){
        character = getelement(element);
        if(!(isspace(character) || character == '\0')){
            k++;
            if(space){
                condition1 = checkVowel(character);
                space=0;
            }else {
                space=0;
                condition2 = checkVowel(character);
            }
        }else{
            space = 1;
            if (condition2 && condition1){
                condition =1;
            }else if((condition1 == 1) && (k==1)){
                cond = 1;
            }
            k=0;
        }
    }
    if((condition) || (cond)){
        printf("FOUND suitable words\n");
    }
    else{
        printf("DIDNT FIND suitable words\n");
    }

}
