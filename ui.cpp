#include "ui.h"
#include "cell.h"

#include <stdlib.h>
#include <stdio.h>

#include <graphics.h>
#include <X11/Xlib.h> //for XinitThreads function

/*****************
      CLUI TODO: Change class to namespace
*****************/

void CLUI::printNeuronalNetwork(NeuronField Field) {
//   clearScreen();

   char field[XMAXSIZE][YMAXSIZE];

   for(int x = 0; x < XMAXSIZE; x++)
      for(int y = 0; y < YMAXSIZE; y++)
         field[x][y] = Field.getFieldType(x, y);

#ifdef TRACE
   printf("\n\n");
#endif
   
   printf("\t");
   for(int i = 0; i < XMAXSIZE; i++)
      printf("%d ", i);

   for(int j = 0; j < YMAXSIZE; j++) {
      printf("\n%d\t", j);
      for(int i = 0; i < XMAXSIZE; i++)
         printf("%c ", field[i][j]);
   }
   printf("\n");
}

void CLUI::clearScreen() {
   system("clear");
}


/*****************
      GUI TODO: Change class to namespace
*****************/

GUI::GUI() {
   XInitThreads();
   int gd=DETECT,gm;
   initgraph(&gd,&gm,NULL);
};

void GUI::clearScreen() {
   for(int i = 0; i < XMAXSIZE; i++)
      for(int j = 0; j < YMAXSIZE; j++)
         putpixel(i, j, BLACK);
};

void GUI::printNeuronalNetwork(NeuronField Field) {

   char field[XMAXSIZE][YMAXSIZE];

   for(int x = 0; x < XMAXSIZE; x++)
      for(int y = 0; y < YMAXSIZE; y++)
         field[x][y] = Field.getFieldType(x, y);
   
   for(int j = 0; j < YMAXSIZE; j++)
      for(int i = 0; i < XMAXSIZE; i++) {
         if (field[i][j] == NEURONSYMBOL) {putpixel(i, j, GREEN);};
         if (field[i][j] == AXONSYMBOL)   {putpixel(i, j, WHITE);};
      }
};
