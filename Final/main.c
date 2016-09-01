#include <stdio.h>
#include <string.h>
#include "cs50.h"
#include "Muhammeds.h"

int main()
{
    int n=0,l,i,j,k,len,counter=0 ;
    char* piece ;
    char ar[10][10];
    char loselist[33]= {'0'};
    fillempty(ar);
    putpieces(ar);
    printchess(ar);
    printlist(loselist,n);
    printf("Enter the Move or \"quit\" to exit or \"l\" to load : ");
    char* mv = GetString();
    while(strcmp(mv,"quit")!=0)
    {
        fflush(stdin);
        len = strlen(mv);
        if(len<=3)
        {
            if(mv[0]=='l'&&counter==0)
            {

               counter=load(ar);
               printlist(loselist,n);
                printf("Enter the Move or \"quit\" to exit or \"s\" to load : ");
                mv = GetString();

            }
            else if (mv[0]=='s'&&counter>0)
            {
                savefile(counter);
                system("cls");
                printchess(ar);
                 printlist(loselist,n);
                printf("Enter the Move or \"quit\" to exit or \"s\" to load : ");
                mv= GetString();

            }
            else if(counter==0)
            {
                system("cls");
                printchess(ar);
                printlist(loselist,n);
                printf("Enter the Move or \"quit\" to exit or \"l\" to load : ");
                mv = GetString();
            }
            else if ((mv[0]=='z'||mv[0]=='y')&&counter>0)
            {
                char x = unredo(mv[0],ar);
                if(x!='0')
                {
                    if(mv[0]=='z')
                    {
                       n--;
                       loselist[n]='0';
                       counter--;
                    }
                    else
                    {
                       loselist[n]=x;
                        n++;
                        counter++;
                    }
                }

                system("cls");
                printchess(ar);
                printlist(loselist,n);
                printf("Enter the Move or \"quit\" to exit or \"s\" to load : ");
                mv = GetString();
            }
            else if (counter>0)
            {
                system("cls");
                printchess(ar);
                printlist(loselist,n);
                printf("Enter Move or \"quit\" to Exit or \'s\' to save : ");
                mv = GetString();
            }
        }
        else if(len==4||len==5)
        {
            j=atoi(mv);
            i=atoi((mv+1));
            l=atoi((mv+2));
            k=atoi((mv+3));

            if(j!=0||l!=0||i==0||k==0)
            {
                if (counter>0)
                {
                    system("cls");
                    printchess(ar);
                    printlist(loselist,n);
                    printf("Enter Move or \"quit\" to Exit or \'s\' to save : ");
                }

                else
                {
                    system("cls");
                    printchess(ar);
                    printlist(loselist,n);
                    printf("Enter Move or \"quit\" to Exit or \"l\" to load: ");
                }

                mv = GetString();
            }

            else
            {
                j=mv[0]%64;
                i=-1*mv[1]+57;
                l=mv[2]%64;
                k=-1*mv[3]+57;
                piece= &(ar[i][j]);
                int check1 = checkpiece(piece);
                int check2 = checkmove(check1,i,j,k,l,ar);
                int check3 = checkplayer(counter,piece);
                if(check1==check2&&check1!=0&&check3)
                {
                    save(mv,ar[k][l]);
                    if(ar[k][l]!='.' && ar[k][l]!='-')
                    {
                        loselist[n]= ar[k][l];
                        n++;
                    }
                movepiece(mv,ar);
                checkpromotion(mv,ar);
                system("cls");
                printchess(ar);
                counter++;

                }
                system("cls");
                printchess(ar);
                printlist(loselist,n);
                printf("\nEnter Move or \"quit\" to Exit or \'s\' to save : ");
                mv = GetString();


            }

        }
        else
        {
            system("cls");
            printchess(ar);
            printlist(loselist,n);
            printf("Enter Move or \"quit\" to Exit or \'s\' to save : ");
            mv= GetString();
        }


    }


    return 0;
}
