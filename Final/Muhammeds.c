/*******************************************************************************************************************************
********************************************************************************************************************************
********************************************************************************************************************************
********************************************************************************************************************************
**************************************************< Chess Game >****************************************************************
********************************************************************************************************************************
****************************************************  Made By   ****************************************************************
********************<Mohammed Daifalla>**************************************************<Muhammed Essam Khamis>****************
********************************************************************************************************************************
*******************************************************************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Muhammeds.h"
piece black = {8,5};
piece white = {1,5};
reundo* Head = NULL ;
reundo* Cru = NULL ;
void fillempty(char ar[][10])
{
    //determine the main lines of the program
    int i ,j;
    for(i=0; i<10; i++)
        for(j=0; j<10; j++)
        {
            if((i==0&&j==0)||(i==9&&j==9)||(i==0&&j==9)||(i==9&&j==0))
                ar[i][j]='#';
            else if ((i==0||i==9)&&j>0)
                ar[i][j]=64+j;
            else if((j==0||j==9)&&i>0)
                ar[i][j]= 57-i ;
            else if ((i+j)%2==0)
                ar[i][j]='-';
            else
                ar[i][j]='.';
        }
}
void putpieces(char ar[][10])
{
    //to put pieces
    int j;
    for(j=1; j<9; j++)
    {
        ar[2][j]='p';
        ar[7][j]='P';
        switch(j)
        {
        case 1 :
            ar[1][j]='r';
            ar[8][j]='R';
            break;
        case 2 :
            ar[1][j]='n';
            ar[8][j]='N';
            break;
        case 3 :
            ar[1][j]='b';
            ar[8][j]='B';
            break;
        case 4 :
            ar[1][j]='q';
            ar[8][j]='Q';
            break;
        case 5 :
            ar[1][j]='k';
            ar[8][j]='K';
            break;
        case 6 :
            ar[1][j]='b';
            ar[8][j]='B';
            break;
        case 7 :
            ar[1][j]='n';
            ar[8][j]='N';
            break;
        case 8 :
            ar[1][j]='r';
            ar[8][j]='R';
            break;
        }
    }

}
void printchess(char ar[][10])
{
    //print all the board and pieces with formatting
    int x ,y ;
    for(x=0; x<10; x++)
    {
        for(y=0; y<10; y++)
        {
            // Formatting
            printf("|");
            printf(" %c ",ar[x][y]);
        }
        printf("|");
        printf("\n");
        for(y=0; y<11; y++)
        {
            printf("|");
            if(y!=10)
                printf("___");
        }
        printf("\n");
    }
}
void printlist(char ar[], int n)
{
    int i ;
    printf("\nList :\n");
    for (i=0; i<=n; i++)
    {
        if(ar[i]>'A'&&ar[i]<'Z')
            printf("%c ",ar[i]);

    }
        printf("\t\t\t");
    for (i=0; i<=n; i++)
    {
        if(ar[i]>'a'&&ar[i]<'z')
            printf("%c ",ar[i]);

    }
    printf("\n");
}

int checkpiece(char* piece )
{
    if(*piece=='p'||*piece=='P')
        return 1 ;
    if(*piece=='r'||*piece=='R')
        return 2 ;
    if(*piece=='n'||*piece=='N')
        return 3 ;
    if(*piece=='b'||*piece=='B')
        return 4 ;
    if(*piece=='q'||*piece=='Q')
        return 5 ;
    if(*piece=='k'||*piece=='K')
        return 6 ;

    return 0 ;

}

int checkmove(int x,int i , int j , int k ,int l,char ar[][10])
{
    int y =0;
    if(l>0&&l<9&&k<9&&k>0)
    {
        switch(x)
        {
        case 1 :
            y=checkpown(i,j,k,l,ar);
            break ;
        case 2 :
            y=checkrook(i,j,k,l,ar);
            break ;
        case 4 :
            y=checkbishop(i,j,k,l,ar);
            break ;
        case 3 :
            y=checkknight(i,j,k,l);
            break ;
        case 5 :
            y=checkqueen(i,j,k,l,ar);
            break ;
        case 6 :
            y=checkking(i,j,k,l,ar);
            break ;
        }
    }
    return y ;
}
int checkpown(int i , int j , int k ,int l,char ar[][10])
{
    if(abs(j-l)<=1)
    {
        if((i-k)>0&&ar[i][j]=='P')
        {
            if(i-k==1&&abs(j-l)==1&&ar[k][l]!='.'&&ar[k][l]!='-')
                return 1 ;
            if(i==7&&j==l&&i-k==2)
                return 1 ;
            if(i-k==1&&j==l&&(ar[k][l]=='.'||ar[k][l]=='-'))
                return 1 ;


        }
        else if ((i-k)<0&&ar[i][j]=='p')
        {
            if(i-k==-1&&abs(j-l)==1&&ar[k][l]!='.'&&ar[k][l]!='-')
                return 1 ;
            if(i==2&&j==l&&i-k==-2)
                return 1 ;
            if(i-k==-1&&j==l&&(ar[k][l]=='.'||ar[k][l]=='-'))
                return 1 ;
        }


    }

    return 0;
}
int checkrook(int i,int j , int k , int l,char ar[][10])
{
    if((i==k&&j!=l)||(l==j&&i!=k))
        if(checktraprook(i,j,k,l,ar))
            return 2 ;
    return 0 ;
}
int checkbishop(int i,int j,int k,int l,char ar[][10])
{
    if((i+j)%2==(k+l)%2 && abs(i-k)==abs(j-l))
        if(checktrapbishop(i,j,k,l,ar))
            return 4;

    return 0;
}
int checkknight(int i,int j, int k, int l)
{
    if((i+j)%2!=(k+l)%2)
        if(abs(i-k)+abs(j-l)==3)
            return 3;

    return 0 ;
}
int checkqueen(int i , int j , int k , int l,char ar[][10])
{
    if((i==k&&j!=l)||(l==j&&i!=k))
    {
        if(checktraprook(i,j,k,l,ar))
            return 5;
    }
    else if((i+j)%2==(k+l)%2 && abs(i-k)==abs(j-l))
    {
        if (checktrapbishop(i,j,k,l,ar))
            return 5 ;
    }

    return 0 ;
}
int checkking(int i , int j , int k , int l,char ar[][10] )
{
    if(abs(i-k)==1||abs(j-l)==1)
        if(openTrack(k,l,ar)==0)
            return 6;

    return 0 ;
}
int checktraprook(int i , int j , int k , int l,char ar[][10])
{
    int trap = 2 ;
    int big,small ;
    //check if moving vertical
    if(j==l)
    {
        //determine who is bigger
        if (i>k)
        {
            small =k+1;
            big = i;
        }
        else
        {
            big = k ;
            small = i+1;
        }
        //looping from the small to the big
        for(; small<big; small++)
        {
            //if not empty then the move invalid
            if(ar[small][j]!='.'&&ar[small][j]!='-')
            {
                trap = 0 ;
                break ;
            }
        }
    }
    else
    {
        if(j>l)
        {
            big = j ;
            small = l+1;
        }
        else
        {
            big =l ;
            small= j+1;

        }
        // move from the start to end or vice versa
        for(; small<big; small++)
        {
            //if not empty then the move invalid
            if(ar[k][small]!='.'&&ar[k][small]!='-')
            {
                trap= 0 ;
                break ;
            }
        }
    }
    //return 0 or 2 only
    return trap ;
}
int checktrapbishop(int i , int j , int k,int l , char ar[][10])
{
    // check if friend or not
    int x,y,n, trap = 3;
    if((ar[i][j]<91&&ar[i][j]>64&&ar[k][l]<91&&ar[k][l]>64)||(ar[i][j]<123&&ar[i][j]>96&&ar[k][l]<123&&ar[k][l]>96))
    {
        trap = 0;
        return trap ;
    }
    if((i-k)/(j-l)>0)
    {
        if(i>k)
        {
            x=k+1;
            y=l+1;
            n=i-k;
        }
        else
        {
            x=i+1;
            y=j+1;
            n=k-i;
        }
        for(; n>1; n--,x++,y++)
        {
            if(ar[x][y]!='.'&&ar[x][y]!='-')
            {
                trap = 0 ;
                break ;
            }
        }
    }
    else
    {
        if(i>k)
        {
            x=k+1;
            y=l-1;
            n=i-k;
        }
        else
        {
            y=j-1;
            x=i+1;
            n=k-i;
        }
        for(; n>1; n--,x++,y--)
        {
            if(ar[x][y]!='.'&&ar[x][y]!='-')
            {
                trap = 0;
                break ;
            }
        }


    }
    return trap ;

}
int checktrapqueen(int i,int j , int k , int l,char ar[][10])
{
    int trap = 5 ;
    if(i==k||j==l)
    {
        if(checktraprook(i,j,k,l,ar))
            return trap;
    }
    if(abs(i-k)==abs(j-l))
    {
        if (checktrapbishop(i,j,k,l,ar))
            return trap;
    }
    return 0 ;
}
void save (char ar[],char c )
{
    reundo* mv = malloc(sizeof(reundo));
    if(mv!=NULL)
    {
        if(Head==NULL)
        {
            reundo* last = malloc(sizeof(reundo));
            last-> moves = "last" ;
            last->place = '0' ;
            last->pre=Head;
            last->next=NULL;
            Head=last;
            Cru=Head;
            mv->moves= ar ;
            mv->place= c;
            Cru->next =mv;
            mv->pre=Cru;
            mv->next = NULL;
            Head=mv;
            Cru=Head;
        }
        else
        {
             //strcpy(mv->moves,ar);
            mv->moves= ar ;
            mv->place= c;
            Cru->next =mv;
            mv->pre=Cru;
            mv->next = NULL;
            Head=mv;
            Cru=Head;
        }

    }

}
char unredo (char ch,char ar[][10])
{
    char n='0' ;
    if(Cru==NULL)
        return n ;
    //to undo press z
    if(ch=='z')
    {
        //
        if(Cru==NULL||strcmp(Cru->moves,"last")==0)
            return n;
        char mv[6];
        strcpy(mv,Cru->moves);
        char place = Cru->place;
        if(place!='.'&&place!='-')
            n=place;
        undoMove(mv,place,ar);
        if(Cru->pre!=NULL)
            Cru=Cru->pre;
    }
    if(ch=='y')
    {
        if(Cru==NULL||Cru->next==NULL)
            return n ;
        Cru=Cru->next;
        char mv[6];
        strcpy(mv,Cru->moves);
        //char place = Cru->place;
        n = movepiece(mv,ar);

    }
    return n ;
}
// check Who is playing
int checkplayer(int x , char* piece)
{
    if(x%2==0&&*piece>96&&*piece<122)
        return 1 ;
    if(x%2==1&&*piece>64&&*piece<90)
        return 1 ;
    return 0 ;
}
// load the file
int load (char ar[][10])
{
    int counter=0;
    FILE* fp = fopen("Tmp.txt","r");
    char mv[6];
    while(!feof(fp))
    {
        fscanf(fp," %s ",mv);

        movepiece(mv,ar);
        //checkpromotion(mv,ar);
        if(strlen(mv)==5)
        {
            checkpromotion(mv,ar);
        }
        system("cls");
        printchess(ar);
        counter++;
    }
    fclose(fp);
    return counter;
}

//save the file
void savefile(int x )
{
    FILE* fp = fopen("Tmp.txt","w");
    int y = 1;
    reundo* save = Head;
    if (save!=NULL)
    {
        for(; y<x; save=save->pre,y++);
        for(; save!=NULL; save=save->next)
        {
            fputs(save->moves,fp);
            fputs("\n",fp);
        }

    }
    fclose(fp);
}

void undoMove(char mv[],char place,char ar[][10])
{
    int j=mv[0]%64;
    int i=-1*mv[1]+57;
    int l=mv[2]%64;
    int k=-1*mv[3]+57;
    if(strlen(mv)==4)
    {
        ar[i][j]=ar[k][l];
    }
    if(strlen(mv)==5)
    {
        if(isupper(ar[k][l]))
            ar[i][j]='P';
        else
            ar[i][j]='p';
    }
    ar[k][l]=place;
}
char movepiece(char* mv ,char ar[][10])
{
    char n='0';
    int j=mv[0]%64;
    int i=-1*mv[1]+57;
    int l=mv[2]%64;
    int k=-1*mv[3]+57;
    if(ar[k][l]!='.'&&ar[k][l]!='-')
        n=ar[k][l];
    ar[k][l]=ar[i][j];
    if((i+j)%2==1)
        ar[i][j]='.';
    else
        ar[i][j]='-';

    return n ;
}
void checkpromotion(char mv[],char ar[][10])
{
    int l=mv[2]%64;
    int k=-1*mv[3]+57;
    if(checkpiece(&(ar[k][l]))==1)
    {
        if(isupper(ar[k][l])&&k==1)
            ar[k][l]=toupper(mv[4]);
        if(islower(ar[k][l])&&k==8)
            ar[k][l]=tolower(mv[4]);
    }

}
int check (int k , int l ,int x , int y,char ar[][10])
{
    if(checkpown(k,l,x,y,ar))
        return 1 ;
    if(checkbishop(k,l,x,y,ar))
        return 1 ;
    if(checkqueen(k,l,x,y,ar))
        return 1 ;
    if (checkrook(k,l,x,y,ar))
        return 1 ;
    if(checkknight(k,l,x,y))
        return 1 ;
    return 0 ;
}
int openTrack(int x , int y,char ar[][10])
{
    int i,j,white=1;
    if (isupper(ar[x][y]))
        white=0;
    for (i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            if(!white)
            {
                if(check(i,j,x,y,ar)&&(ar[i][j]=='b'||ar[i][j]=='r'||ar[i][j]=='q'||ar[i][j]=='p'))
                    return 1 ;
            }
            if(white)
            {
                if(check(i,j,x,y,ar)&&(ar[i][j]=='B'||ar[i][j]=='R'||ar[i][j]=='Q'||ar[i][j]=='P'))
                    return 1 ;
            }

        }
    }
    return 0;
}
int runKingRun(int x, int y,char ar[][10])
{
    int i,j,find =0;
    for(i=x-1; i<x+2&&find==0; i++)
    {
        for(j=y-1; j<j+2&&find==0; j++)
        {
            if(isupper(ar[x][y]))
            {
                int tmp=ar[i][j];
                ar[i][j]='K';
                if(openTrack(i,j,ar)==0)
                {
                    find = 1 ;

                }
                ar[i][j]=tmp;
            }
            else
            {
                int tmp=ar[i][j];
                ar[i][j]='k';
                if(openTrack(i,j,ar)==0)
                {
                    find = 1 ;

                }
                ar[i][j]=tmp;
            }

        }
    }
    return find ;
}
int preventThreat(char ar[][10],piece check)
{
    int p=0;
    if(isupper(ar[check.c][check.d]))
    {
        if(ar[check.c][check.d]=='R')
            p=preventThreatRook(check.c,check.d,white.c,white.d,ar);
        else if (ar[check.c][check.d]=='B')
            p=preventThreatBishop(check.c ,check.d,white.c , white.d,ar);
        else if (ar[check.c][check.d]=='Q')
        {
            if(check.c==white.c||check.d==white.d)
                p=preventThreatRook(check.c,check.d,white.c,white.d,ar);
            else
                p=preventThreatBishop(check.c ,check.d,white.c , white.d,ar);
        }
    }
    else
    {
        if(ar[check.c][check.d]=='r')
            p=preventThreatRook(check.c,check.d,black.c,black.d,ar);
        else if (ar[check.c][check.d]=='b')
            p=preventThreatBishop(check.c ,check.d,black.c , black.d,ar);
        else if (ar[check.c][check.d]=='q')
        {
            if(check.c==black.c||check.d==black.d)
                p=preventThreatRook(check.c,check.d,black.c,black.d,ar);
            else
                p=preventThreatBishop(check.c ,check.d,black.c , black.d,ar);
        }
    }
    return p ;
}
//
int preventThreatRook(int i, int j ,int k , int l ,char ar[][10])
{
    int big , small ,u,v, upper1=0,lower1=0;
    if(j==l)
    {
        if(i>k)
        {
            small = k;
            big=i;
        }
        else
        {
            big=k+1;
            small=i+1;
        }
        for(; small<big; small++)
        {
            for(u=0; u<9; u++)
            {
                for(v=0; v<9; v++)
                {
                    int check = checkpiece(&ar[u][v]);
                    if(check&&checkmove(check,u,v,small,l,ar))
                    {
                        if(isupper(ar[u][v]))
                            upper1++ ;
                        else
                            lower1++ ;
                    }
                }
            }
        }
    }
    else
    {
        if(j>l)
        {
            big = j ;
            small = l;
        }
        else
        {
            big =l ;
            small= j+1;

        }
        // move from the start to end or vice versa
        for(; small<big; small++)
        {
            //if not empty then the move invalid
            for(u=0; u<9; u++)
            {
                for(v=0; v<9; v++)
                {
                    int check = checkpiece(&ar[u][v]);
                    if(check&&checkmove(check,u,v,small,l,ar))
                    {
                        if(isupper(ar[u][v]))
                            upper1++;
                        else
                            lower1++;
                    }
                }

            }
        }
    }
    if(isupper(ar[k][l]))
        return upper1;
    else
        return lower1;
}

int preventThreatBishop(int i , int j , int k , int l, char ar[][10])
{
    int x,y,n,lower , upper ,u,v;
    if((i-k)/(j-l)>0)
    {
        if(i>k)
        {
            x=k+1;
            y=l+1;
            n=i-k;
        }
        else
        {
            x=i;
            y=j;
            n=k-i;
        }
        for(; n>0; n--,x++,y++)
        {
            for(u=0; u<9; u++)
            {
                for(v=0; v<9; v++)
                {
                    int check = checkpiece(&ar[u][v]);
                    if(check&&checkmove(check,u,v,x,y,ar))
                    {
                        if(isupper(ar[u][v]))
                            upper++;
                        else
                            lower++;
                    }
                }
            }
        }
    }
    else
    {
        if(i>k)
        {
            x=k;
            y=l;
            n=i-k;
        }
        else
        {
            y=j-1;
            x=i+1;
            n=k-i;
        }
        for(; n>0; n--,x++,y--)
        {
            for(u=0; u<9; u++)
            {
                for(v=0; v<9; v++)
                {
                    int check = checkpiece(&ar[u][v]);
                    if(check&&checkmove(check,u,v,x,y,ar))
                    {
                        if(isupper(ar[u][v]))
                            upper++;
                        else
                            lower++;
                    }
                }

            }


        }
    }
    if(isupper(ar[k][l]))
        return upper;
    else
        return lower;
}
int stalmateValidation(int x, int y ,char ar[][10])
{
    int i,j;
    char testboard[10][10];
    memcpy(testboard,ar,100);
    for(i=1; i<9; i++)
    {
        for(j=1; j<9; j++)
        {
            if(testboard[i][j]!='-'&&testboard[i][j]!='.')
            {
                testboard[i][j]=(i+j)%2==0 ? '-' : '.' ;
                if(!openTrack(x,y,testboard))
                {
                    return 0;
                }
                testboard[i][j]=ar[i][j];
            }

        }
    }
    return 1 ;
}
