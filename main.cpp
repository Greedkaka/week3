#include "console.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#define BOARD_SIZE 15
#define MOVE_DELAY 60
#define WALL_VERTICAL_STRING "┃"
#define WALL_HORIZONTAL_STRING "━"
#define WALL_RIGHT_TOP_STRING "┓"
#define WALL_LEFT_TOP_STRING "┏"
#define WALL_RIGHT_BOTTOM_STRING "┛"
#define WALL_LEFT_BOTTOM_STRING "┗"
#define SNAKE_STRING "■"
#define SNAKE_BODY_STRING "■"
#define APPLE_STRING "●"
using namespace console;

void map(){
  draw(0,0,"┏");
  for (int x1=1; x1<BOARD_SIZE-1; x1++)
    draw(x1,0,"━");
  draw(BOARD_SIZE-1,0,"┓");
  
  for(int y1=1; y1<BOARD_SIZE-1; y1++){
    draw(0,y1,"┃");
    draw(BOARD_SIZE-1,y1,"┃");
  }

  draw(0,BOARD_SIZE-1,"┗");
  for (int x1=1; x1<BOARD_SIZE-1; x1++)
    draw(x1,BOARD_SIZE-1,"━");
  draw(BOARD_SIZE-1,BOARD_SIZE-1,"┛");
}

int main(){
  srand((unsigned int)time(NULL));
  int count=1,score=0,timer=0,xa=rand()%(BOARD_SIZE-2)+1,ya=rand()%(BOARD_SIZE-2)+1;
  std::string last="r";
  std::string snake[2][(BOARD_SIZE-2)*(BOARD_SIZE-2)];//뱀이 가야할 방향을 저장
  int snake_place[2][(BOARD_SIZE-2)*(BOARD_SIZE-2)];//몸톰의 좌표 저장
  init();
  map();

  while(true){
    clear();
    map();
    
    if (key(K_LEFT)) {
      x--;
      last="l";
    }
    if (key(K_RIGHT)) {
      x++;
      last="r";
    }
    if (key(K_UP)) {
      y--;
      last="u";
    }
    if (key(K_DOWN)){ 
      y++;
      last="d";
    }
    if (key(K_ESC)) 
      break;
    if(key(K_OTHER))
    if(key(K_NONE))

    if(x==0 || x==BOARD_SIZE-1 || y==0 || y==BOARD_SIZE-1){
      draw(BOARD_SIZE/2,BOARD_SIZE/2,"YOU LOSE!");
      draw(BOARD_SIZE/2,BOARD_SIZE/2+1,"Try again? (Enter)");
      if (key(K_ESC)) 
        break;
      if (key(K_ENTER)) {//죽었을때
        init();
        xa=rand()%(BOARD_SIZE-2)+1;
        ya=rand()%(BOARD_SIZE-2)+1;
        for(int y1=0; y1<count; y1++){
          for(int x1=0; x1<count; x1++){
            snake[y1][x1]="";
            snake_place[y1][x1]=0;
          }
        }
        count=0;
        score=0;
        last="r";
        continue;
      }
    }

    draw(x,y,SNAKE_STRING);//머리
    draw(xa,ya,APPLE_STRING);//사과

    if(x==xa && y==ya){//사과 먹을때
      snake[0][count]=SNAKE_BODY_STRING;
      count++;
      score+=10;
      xa=rand()%(BOARD_SIZE-2)+1;
      ya=rand()%(BOARD_SIZE-2)+1;
      
      for(int y1=0; y1<count; y1++){//사과와 뱀의 위치를 다르게
        for(int x1=0; x1<count; x1++){
          if(xa==snake_place[y1][x1]){
            xa=rand()%(BOARD_SIZE-2)+1;
            ya=rand()%(BOARD_SIZE-2)+1;
            y1=-1;
            break;
          }
        }
      }
    }
    for(int x1=0; !(snake[0][x1].size() == 0) && x1<(BOARD_SIZE-2)*(BOARD_SIZE-2); x1++){
      //if(xa)
    }//xy좌표가 한 칸  씩 이동
    

    draw(BOARD_SIZE/2,BOARD_SIZE,"Score : "+std::to_string(score));
    if(timer>=MOVE_DELAY)
      timer=0;
    timer++;

    wait();
  }
  return 0;
}
// int apple_place(int bodt_place[],int a){
//   for(int x1=0; x1<count; x1++){
//     if(a==body_place[0][x1])
//       return rand()%(BOARD_SIZE-2)+1;
//   }
// }