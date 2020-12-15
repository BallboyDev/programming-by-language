#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    char* room;
    double room_num[10] = {0,};
    int i, max = 0;
    room  = malloc(sizeof(char) * 8);

    gets(room);

    for(i = 0; room[i] != '\0'; i++){
        //printf("%c\n", room[i]);
        
        if((room[i] - '0') == 9) {room_num[6]++;}
        else{room_num[room[i]-'0']++;}
    }
    room_num[6] = ceil(room_num[6] / 2);
    for(i = 0; i < 10; i++){
        if(max < room_num[i]){
            max = room_num[i];
        }
        //printf("%f ", room_num[i]);
    }
    printf("%d", max);
}