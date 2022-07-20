/*
  Showing numbers, chars and phrases
                             A (seg[0] in this project)
                            ---
F (seg[5] in this project) |   | B (seg[1] in this project)
                           |   |
                            --- G (seg[6] in this project)
E (seg[4] in this project) |   |
                           |   | C (seg[2] in this project)
                            ---  . dot or dicimal (seg[7] in this project)
                             D (seg[3] in this project)

 */


#include "pico/stdlib.h"
#include <stdio.h>
#include "timer.cpp"

#define A 17
#define B 16
#define C 14
#define D 13
#define E 12
#define F 18
#define G 19
#define DP 15 // decimal

int seg[] = {A,B,C,D,E,F,G,DP};

int chars = 37;

char Chars[37][9] = {
        {'0',1,1,1,1,1,1,0,0},//0
        {'1',0,1,1,0,0,0,0,0},//1
        {'2',1,1,0,1,1,0,1,0},//2
        {'3',1,1,1,1,0,0,1,0},//3
        {'4',0,1,1,0,0,1,1,0},//4
        {'5',1,0,1,1,0,1,1,0},//5
        {'6',1,0,1,1,1,1,1,0},//6
        {'7',1,1,1,0,0,0,0,0},//7
        {'8',1,1,1,1,1,1,1,0},//8
        {'9',1,1,1,1,0,1,1,0},//9
        {'a',1,1,1,0,1,1,1,0},//A/10
        {'b',0,0,1,1,1,1,1,0},//b/11
        {'c',1,0,0,1,1,1,0,0},//C/12
        {'d',0,1,1,1,1,0,1,0},//d/13
        {'e',1,0,0,1,1,1,1,0},//E/14
        {'f',1,0,0,0,1,1,1,0},//F/15
        {'g',1,0,1,1,1,1,0,0},//G/16
        {'h',0,1,1,0,1,1,1,0},//H/17
        {'i',0,0,0,0,1,1,0,0},//I/18
        {'j',0,1,1,1,1,0,0,0},//J/19
        {'l',0,0,0,1,1,1,0,0},//L/20
        {'n',0,0,1,0,1,0,1,0},//n/21
        {'o',0,0,1,1,1,0,1,0},//o/22
        {'p',1,1,0,0,1,1,1,0},//P/23
        {'q',1,1,1,0,0,1,1,0},//q/24
        {'r',0,0,0,0,1,0,1,0},//r/25
        {'s',1,0,1,1,0,1,1,0},//S/26   looks like number 5
        {'t',0,0,0,1,1,1,1,0},//t/27
        {'u',0,1,1,1,1,1,0,0},//U/28
        {'y',0,1,1,1,0,1,1,0},//y/29
        {'-',0,0,0,0,0,0,1,0},//-/30
        {'.',0,0,0,0,0,0,0,1},//./31
        {']',1,1,1,1,0,0,0,0},//]/32
        {'[',1,0,0,1,1,1,0,0},//[/33
        {'_',0,0,0,1,0,0,0,0},//_/34
        {'@',1,0,1,1,1,0,1,0},//_/35
        {'*',1,0,0,1,0,0,0,0},//_/36
};

void render(char simbul){
    int enter;
    for (int i = 0;i<chars;i++){
        if(Chars[i][0]==simbul) {enter=i;
            break;}
    }
    for (int i = 0; i < 7; i++) {
        gpio_put(seg[i], Chars[enter][i+1]);
    }
}

void cleen() {
    for (int i = 0; i < 7; i++) {
        gpio_put(seg[i],0);
    }
}

int main() {
    stdio_init_all();

    gpio_init(seg[0]);
    gpio_init(seg[1]);
    gpio_init(seg[2]);
    gpio_init(seg[3]);
    gpio_init(seg[4]);
    gpio_init(seg[5]);
    gpio_init(seg[6]);
    gpio_init(seg[7]);

    gpio_set_dir(seg[0],GPIO_OUT);
    gpio_set_dir(seg[1],GPIO_OUT);
    gpio_set_dir(seg[2],GPIO_OUT);
    gpio_set_dir(seg[3],GPIO_OUT);
    gpio_set_dir(seg[4],GPIO_OUT);
    gpio_set_dir(seg[5],GPIO_OUT);
    gpio_set_dir(seg[6],GPIO_OUT);
    gpio_set_dir(seg[7],GPIO_OUT);

    while(!timer_fired) {
        char eye[] = {'@', '*', '\0'};
        for (int i = 0; i < sizeof(eye) - 1; i++) {
            render(eye[i]);
            sleep_ms(100);
            cleen();
        }
        for (int i = 0; i < sizeof(eye) - 1; i++) {
            render(eye[i]);
            sleep_ms(700);
            cleen();
        }
    }
}
