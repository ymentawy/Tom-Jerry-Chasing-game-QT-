#ifndef TOM.C
#define TOM.C
#include "tom.h"
#include <QTimer>
#include <QDebug>
using namespace std;


       jerry* jerryptr;
tom::tom(int data[11][11])
{   
       QPixmap image("tom.png");
       image = image.scaledToWidth(45);
       image = image.scaledToHeight(45);
       setPixmap(image);
       setPos(300, 500);
       row = 9;
       column = 5;
       for (int i = 0; i < 11; i++){
           for (int j = 0; j < 11; j++){
               boardData[i][j] = data[i][j];}
}

       for(int x=0;x<59;x++){
            for(int y=0;y<59;y++){
                     Graph[x][y]=0;
                }
                }
       for(int x=0;x<11;x++){
            for(int y=0;y<11;y++){
                if(boardData[x][y]>=0){
                    if(boardData[x-1][y]>=0){
                    Graph[boardData[x][y]][boardData[x-1][y]]=1;
                    }
                    if(boardData[x+1][y]>=0){
                    Graph[boardData[x][y]][boardData[x+1][y]]=1;
                    }
                    if(boardData[x][y+1]>=0){
                        Graph[boardData[x][y]][boardData[x][y+1]]=1;
                        }

                    if(boardData[x][y-1]>=0){
                    Graph[boardData[x][y]][boardData[x][y-1]]=1;
                    }
                }


            }
       }
       QTimer *timer = new QTimer(this);
       connect(timer, SIGNAL(timeout()), this, SLOT(movetom()));
       timer->start(1000);
}
QVector<QVector<int>> tom::Dijkstra(int Graph[59][59], int startVertex)
{
    int temp[COUNT][COUNT];
    for (int i = 0; i < COUNT; i++)
    {
        for (int j = 0; j < COUNT; j++)
        {
            if (Graph[i][j] == 0)
                temp[i][j] = 999;
            else
                temp[i][j] = Graph[i][j];
        }
    }
    bool done[COUNT];
    int previous[COUNT];
    float cost[COUNT];
    // 1st Row:
    for (int i = 0; i < COUNT; i++)
    {
        if (i == startVertex)
        {
            previous[i] = -1;
            cost[i] = 0;
            done[i] = true;
        }
        else
        {
            previous[i] = startVertex;
            cost[i] = temp[startVertex][i];
            done[i] = false;
        }
    }
    // All Rows:
    int count = 1;
    while (count < COUNT)
    {
        // Determine which vertex to visit.
        int minimum = 999, visitedVertex;
        for (int i = 0; i < COUNT; i++)
        {
            if (done[i] == false && cost[i] < minimum)
            {
                minimum = cost[i];
                visitedVertex = i;
            }
        }
        // Visit the vertex.
        done[visitedVertex] = true;

        // Check whether there are shorter paths.
        for (int i = 0; i < COUNT; i++)
        {
            if (done[i] == false)
            {
                if ((cost[visitedVertex] + temp[visitedVertex][i]) < cost[i])
                {
                    previous[i] = visitedVertex;
                    cost[i] = (cost[visitedVertex] + temp[visitedVertex][i]);
                }
            }
        }
        count++;
    }
    // Extract the paths.
    QVector<QVector<int>> paths;
    paths.resize(COUNT);
    int j;
    for (int i = 0; i < COUNT; i++)
    {
        paths[i].push_back(i);
        if (i != startVertex)
        {
            j = i;
            do
            {
                j = previous[j];
                paths[i].insert(paths[i].begin(), j);
            } while (j != startVertex);
        }
    }
    return paths;
}
int tom::convertpos(){
   return boardData[row][column];
}
void tom::movetom()
{
   if(jerry::isinvisible==false){
        if(jerry::gameended==false){
     int y=  convertpos();
  QVector<QVector<int>> paths= Dijkstra(Graph,y);
    int z=jerry::row;
  int x=jerry::column;
       int p= boardData[z][x];

       if(boardData[row-1][column]==paths[p][1]){
           if(row-1!=6||column!=4){
       row--;
           }

       }
     else if(boardData[row+1][column]==paths[p][1]){
                if(row+1!=5||column!=5){
       row++;
                }

       }
      else if(boardData[row][column+1]==paths[p][1]){
              if(row!=6||column+1!=4){
          column++;
           }}

      else if(boardData[row][column-1]==paths[p][1]){
            if(row!=6||column-1!=5){
      column--;
            }
       }
         setPos(50 + 50 * column, 50 + 50 * row);

}

   }
   else{


    if(jerry::gameended==false){

        srand(time(NULL));
   int random=rand()%4;
   if(random==0){
    if (boardData[row - 1][column] >= 0&&row-1!=6|boardData[row - 1][column] >= 0&&column!=4)
    {
    row--;

    }
    else if ( boardData[row + 1][column] >= 0&&row+1!=5|boardData[row + 1][column] >= 0&&column!=5)
    {
row++;


    }
    else if ( boardData[row][column + 1] >= 0&&row!=6|boardData[row][column+1] >= 0&&column+1!=4)
    {
    column++;

    }
    else if (boardData[row][column - 1] >= 0&&row!=6|boardData[row][column-1] >= 0&&column-1!=5)
    {
  column--;

    }
   }else if(random==1){

       if (boardData[row + 1][column] >= 0&&row+1!=5|boardData[row + 1][column] >= 0&&column!=5)
              {
  row++;


              }
      else if (boardData[row - 1][column] >= 0&&row-1!=6|boardData[row - 1][column] >= 0&&column!=4)
       {
       row--;

       }
       else if ( boardData[row][column + 1] >= 0&&row!=6|boardData[row][column+1] >= 0&&column+1!=4)
       {
       column++;

       }
       else if ( boardData[row][column - 1] >= 0&&row!=6|boardData[row][column-1] >= 0&&column-1!=5)
       {
     column--;

       }

   }else if(random==2){

       if ( boardData[row][column + 1] >= 0&&row!=6|boardData[row][column+1] >= 0&&column+1!=4)
              {
       column++;

              }
     else if ( boardData[row + 1][column] >= 0&&row+1!=5|boardData[row + 1][column] >= 0&&column!=5)
              {
  row++;


              }
      else if (boardData[row - 1][column] >= 0&&row-1!=6|boardData[row - 1][column] >= 0&&column!=4)
       {
       row--;

       }
       else if ( boardData[row][column - 1] >= 0&&row!=6|boardData[row][column-1] >= 0&&column-1!=5)
       {
     column--;

       }
   }else if(random==3){
       if (  boardData[row][column - 1] >= 0&&row!=6|boardData[row][column-1] >= 0&&column-1!=5)
             {
                 column--;
             }
      else if ( boardData[row][column + 1] >= 0&&row!=6|boardData[row][column+1] >= 0&&column+1!=4)
              {
       column++;

              }
     else if ( boardData[row + 1][column] >= 0&&row+1!=5|boardData[row + 1][column] >= 0&&column!=5)
              {
  row++;


              }
      else if (boardData[row - 1][column] >= 0&&row-1!=6|boardData[row - 1][column] >= 0&&column!=5)
       {
         column--;


       }
   }
    setPos(50 + 50 * column, 50 + 50 * row);
}
   }


}
#endif
