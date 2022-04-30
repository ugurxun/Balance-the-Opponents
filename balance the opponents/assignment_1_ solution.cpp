#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define PI  3.14159265358979323846

using namespace std;

double random_angle(); //assign random angle [0,360]
double random_radius(double radiusCircularArea); //assign random radius [S/16]
double initial_positions(double side); //determine initial positions
double degree(double angle); //convert angle radian to degree

int main()
{
     //variable definitions
     double S,radiusCircularArea,sideLengthRedArea;
     double o1X_info[25],o1Y_info[25],o2X_info[25],o2Y_info[25],mpX_info[25],mpY_info[25];
     double o1_distance[25],o2_distance[25],mp_distance[25];
     double radius1,radius2,angle1,angle2;

     srand(time(NULL)); // to change the values for every runnig process

     S=64.0; // one length of the table
     sideLengthRedArea=S/2; // one length of red area
     radiusCircularArea=S/16; //radius of circular area

     o1X_info[0] = initial_positions(sideLengthRedArea); // assigned initial positions for other player1 in x axis
     o1Y_info[0] = initial_positions(sideLengthRedArea); // assigned initial positions for other player1 in y axis
     o2X_info[0] = initial_positions(sideLengthRedArea); // assigned initial positions for other player2 in x axis
     o2Y_info[0] = initial_positions(sideLengthRedArea); // assigned initial positions for other player2 in y axis
     mpX_info[0] = (o1X_info[0] + o2X_info[0])*(-1) ; // determined initial positions for my player in x axis
     mpY_info[0] = (o1Y_info[0] + o2Y_info[0])*(-1) ; // determined initial positions for my player in y axis

     o1_distance[0]=sqrt( pow(o1X_info[0],2) + pow(o1Y_info[0],2) );// determined distance to origin for other player1
     o2_distance[0]=sqrt( pow(o2X_info[0],2) + pow(o2Y_info[0],2) );// determined distance to origin for other player2
     mp_distance[0]=sqrt( pow(mpX_info[0],2) + pow(mpY_info[0],2) );// determined distance to origin for my player

     for(int i=1;i<25;i++){ //created to make the calculations for other 24 time instants

        radius1 = random_radius(S/16); //assigned random radius for other player 1 [0,S/16]
        radius2 = random_radius(S/16); //assigned random radius for other player 2 [0,S/16]
        angle1  = random_angle(); //assigned random angle for other player 1 [0,360]
        angle2  = random_angle(); //assigned random angle for other player 2 [0,360]

        o1X_info[i] = o1X_info[i-1] + radius1 * cos(degree(angle1)); //determined new position of other player1 in x axis with polar coords.
        o1Y_info[i] = o1Y_info[i-1] + radius1 * sin(degree(angle1)); //determined new position of other player1 in y axis with polar coords.
        o2X_info[i] = o2X_info[i-1] + radius2 * cos(degree(angle2)); //determined new position of other player2 in x axis with polar coords.
        o2Y_info[i] = o2Y_info[i-1] + radius2 * sin(degree(angle2)); //determined new position of other player2 in y axis with polar coords.
        mpX_info[i] = (o1X_info[i] + o2X_info[i])*(-1); //determined new position of my player in x axises
        mpY_info[i] = (o1Y_info[i] + o2Y_info[i])*(-1); //determined new position of my player in y axises

        while((o1X_info[i]>(S/4))||(o1Y_info[i]>(S/4))||(o2X_info[i]>(S/4))||(o2Y_info[i]>(S/4))){
        //created to control being in limited area [-S/4,+S/4] for x and y axises
        //assigned variables are the same with above to get a value in limited area

        radius1 = random_radius(S/16);
        radius2 = random_radius(S/16);
        angle1  = random_angle();
        angle2  = random_angle();

        o1X_info[i] = o1X_info[i-1] + radius1 * cos(degree(angle1));
        o1Y_info[i] = o1Y_info[i-1] + radius1 * sin(degree(angle1));
        o2X_info[i] = o2X_info[i-1] + radius2 * cos(degree(angle2));
        o2Y_info[i] = o2Y_info[i-1] + radius2 * sin(degree(angle2));
        mpX_info[i] = (o1X_info[i] + o2X_info[i])*(-1);
        mpY_info[i] = (o1Y_info[i] + o2Y_info[i])*(-1);
        }

        while((o1X_info[i]<(S/-4))||(o1Y_info[i]<(S/-4))||(o2X_info[i]<(S/-4))||(o2Y_info[i]<(S/-4))){
        //created to control being in limited area [-S/4,+S/4] for x and y axises
        //assigned variables are the same with above to get a value in limited area

        radius1 = random_radius(S/16);
        radius2 = random_radius(S/16);
        angle1  = random_angle();
        angle2  = random_angle();

        o1X_info[i] = o1X_info[i-1] + radius1 * cos(degree(angle1));
        o1Y_info[i] = o1Y_info[i-1] + radius1 * sin(degree(angle1));
        o2X_info[i] = o2X_info[i-1] + radius2 * cos(degree(angle2));
        o2Y_info[i] = o2Y_info[i-1] + radius2 * sin(degree(angle2));
        mpX_info[i] = (o1X_info[i] + o2X_info[i])*(-1);
        mpY_info[i] = (o1Y_info[i] + o2Y_info[i])*(-1);
        }

        o1_distance[i]=sqrt( pow(o1X_info[i],2) + pow(o1Y_info[i],2) );// determined new distance to origin for other player1
        o2_distance[i]=sqrt( pow(o2X_info[i],2) + pow(o2Y_info[i],2) );// determined new distance to origin for other player2
        mp_distance[i]=sqrt( pow(mpX_info[i],2) + pow(mpY_info[i],2) );// determined new distance to origin for my player

     }


     for(int j=0;j<25;j++){
      //printed the values on the screen for each time instant (25)

      cout<<j+1<<". TIME INSTANT"<<endl;
      cout<<"Other Player 1 Coordinates = ("<<o1X_info[j]<<" , "<<o1Y_info[j]<<")"<<endl;
      cout<<"Other Player 2 Coordinates = ("<<o2X_info[j]<<" , "<<o2Y_info[j]<<")"<<endl;
      cout<<"My Player Coordinates      = ("<<mpX_info[j]<<" , "<<mpY_info[j]<<")"<<endl;
      cout<<"Distance of Other Player 1 = "<<o1_distance[j]<<endl;
      cout<<"Distance of other Player 2 = "<<o2_distance[j]<<endl;
      cout<<"Distance of My Player      = "<<mp_distance[j]<<endl;
      cout<<endl;
     }



}
double initial_positions(double side){


     return (((((double)rand()) / ((double)RAND_MAX))*side)-side/2 );
     // to get a random value in determined interval
     // e.g for side=32 our created interval is [-16,16]
}
double degree(double angle){

    return (angle*PI/180);
    //to convert radian angles to degree
}

double random_angle(){

     return (((double)rand()) / ((double)RAND_MAX))*360;
     // to get an angle [0,360] interval
}

double random_radius(double radiusCircularArea){

     return (((double)rand()) / ((double)RAND_MAX))*radiusCircularArea;
     // to get a radius in determined interval
     //e.g for radiusCircularArea = 4 our interval is [0,4]
}



