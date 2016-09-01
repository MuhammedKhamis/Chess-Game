#ifndef MUHAMMEDS_H_INCLUDED
#define MUHAMMEDS_H_INCLUDED

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//making linked list to save the moves
typedef struct reundo
{
    // to store the move
    char* moves;
    //to point to previous move ;
    struct reundo* pre ;
    //to point to next move
    struct reundo* next ;
    //in case of un or re do
    char place ;

}   reundo ;

typedef struct piece
{
    int c ;
    int d ;
}
piece;
void fillempty(char ar[][10]);

void putpieces(char ar[][10]);

void printchess(char ar[][10]);

void printlist(char ar[], int n);

int checkpiece(char* piece );

int checkmove(int x,int i , int j , int k ,int l,char ar[][10]);

int checkpown(int i , int j , int k ,int l,char ar[][10]);

int checkrook(int i,int j , int k , int l,char ar[][10]);

int checkbishop(int i,int j,int k,int l,char ar[][10]);

int checkknight(int i,int j, int k, int l);

int checkqueen(int i , int j , int k , int l,char ar[][10]);

int checkking(int i , int j , int k , int l,char ar[][10] );

int checktraprook(int i , int j , int k , int l,char ar[][10]);

int checktrapbishop(int i , int j , int k,int l , char ar[][10]);

int checktrapqueen(int i,int j , int k , int l,char ar[][10]);

char unredo (char ch,char ar[][10]);

void save (char ar[],char c);

int checkplayer(int x , char* piece);

void savefile(int x );

char movepiece (char* mv ,char ar[][10]);

void undoMove(char* mv,char place,char ar[][10]);

int load (char ar[][10]);

void checkpromotion(char mv[],char ar[][10]);

int preventThreatRook(int i, int j ,int k , int l ,char ar[][10]);

int preventThreatBishop(int i , int j , int k , int l, char ar[][10]);

int preventThreat(char ar[][10],piece check);

int stalmateValidation(int x , int y,char ar[][10]);

int openTrack(int x , int y,char ar[][10]);

#endif // MUHAMMEDS_H_INCLUDED
