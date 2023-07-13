#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cmd_utils.h"

#define COMMOM_PASS_COUNT 199

char *commom_passwords[COMMOM_PASS_COUNT] =
{"12345","123456","123456789","test1","password","12345678","zinch","g_czechout","asdf","qwerty","1234567890","1234567",
"Aa123456","iloveyou","1234","abc123","111111","123123","dubsmash","test","princess","qwertyuiop","sunshine",
"BvtTest123","11111","ashley","00000","000000","password1","monkey","livetest","55555","soccer","charlie","asdfghjkl",
"654321","family","michael","123321","football","baseball","q1w2e3r4t5y6","nicole","jessica","purple","shadow","hannah",
"chocolate","michelle","daniel","maggie","qwerty123","hello","112233","jordan","tigger","666666","987654321","superman",
"12345678910","summer","1q2w3e4r5t","fitness","bailey","zxcvbnmfuckyou","121212","buster","butterfly","dragon",
"jennifer","amanda","justin","cookie","basketball","shopping","pepper","joshua","hunter","ginger","matthew",
"abcd1234","taylor","samantha","whatever","andrew","1qaz2wsx3edc","thomas","jasmine","animoto","madison","98765432",
"54321","flower","Password","maria","babygirl","lovely","sophie","Chegg123","computer","qwe123","anthony","1q2w3e4r",
"peanut","bubbles","asdasd","qwert","1qaz2wsx","pakistan","123qwe","liverpool","elizabeth","harley","chelsea",
"familia","yellow","william","george","7777777","loveme","123abc","letmein","oliver","batman","cheese","banana",
"testing","secret","angel","friends","jackson","aaaaaa","softball","chicken","lauren","andrea","welcome","asdfgh",
"robert","orange","Testing1","pokemon","555555","melissa","morgan","123123123","qazwsx","diamond","brandon",
"jesus","mickey","olivia","changeme","danielle","victoria","gabriel","123456a","0.00000000","loveyou","hockey",
"freedom","azerty","snoopy","skinny","myheritage","qwerty1","159753","forever","iloveu","killer","joseph","master",
"mustang","hellokitty","school","Password1","patrick","blink182","tinkerbell","rainbow","nathan","cooper","onedirection",
"alexander","jordan23","lol123","jasper","junior","q1w2e3r4","222222","11111111","benjamin","jonathan","passw0rd",
"123456789","a123456","samsung","123","love123"};

char* get_password_strength(char* password, char** common_words, int commom_words_count);


int main()
{
    char password[20], strength[10], choose;

    if(set_to_fullscreen()) fprintf(stderr, "Error 001");

    draw_box(DOUBLE_LINE, 40, 10, 70, 20);
    write_text("Password Test", 84, 21);
    write_text("# max. 20 characters", 72, 23);
    write_text("Password: ", 72, 25);

    do{
    move_cursor(83, 25);
    printf("                    ");
    move_cursor(83, 27);
    printf("       ");
    move_cursor(83, 25);

    scanf("%s", password);
    move_cursor(83, 27);

    strcpy(strength, get_password_strength(&password[0], commom_passwords, COMMOM_PASS_COUNT));

    if(strcmp(strength, "weak") == 0) set_text_color(LIGHT_RED);
    else if(strcmp(strength, "strong") == 0) set_text_color(LIGHT_GREEN);
    printf("%s", strength);

    set_text_color(WHITE);
    move_cursor(65, 32);

    printf("Do you want to try again ? (Any to try again, n to exit) ");
    fflush(stdin);

    }while(getc(stdin) != 110);



    return 0;

}

char* get_password_strength(char* password, char** common_words, int commom_words_count){
    int digit_counter = 0, lower_counter = 0, upper_counter = 0, i;
    static char strength[7];

    if(strlen(password) < 6) return "weak";

    for(int i = 0; i < commom_words_count; i++){
        if(strcmp(password, common_words[i]) == 0) return "weak";
        else if(strcmp(password, common_words[i]) > 0){
            if(strstr(password, common_words[i]) != NULL) return "weak";
        }
        else if(strstr(common_words[i], password) != NULL) return "weak";
    }

    for(i = 0; i < strlen(password); i++){
        if(isalpha(password[i])){
            if(isupper(password[i])) upper_counter++;
            else if(islower(password[i])) lower_counter++;
        }
        if(isdigit(password[i])) digit_counter++;
    }

    if(digit_counter == strlen(password)) return "weak";
    if(lower_counter == strlen(password)) return "weak";
    if(upper_counter == strlen(password)) return "weak";
    return "strong";

}
