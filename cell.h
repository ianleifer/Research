#ifndef CELL_H
#define CELL_H

#include "cmn_struct.h"

#define STARTBATTERYCHARGE                3
#define MAXNUMBEROFCONNECTIONSPERNEURON   10

/**********************
      Cell
**********************/

class Cell {
protected:
   struct Coordinates coord;
public:
   struct Coordinates getCoord();
};

/**********************
      Neuron
**********************/

class Neuron : public Cell {
private:
   int NeuronId;

/**********************
      Connections
**********************/

   struct Axon axon;
   struct Coordinates axonEnd;
   int dendrRad;
   Neuron *connection[MAXNUMBEROFCONNECTIONSPERNEURON];
   int numberOfConnections;

/**********************
      Firing
**********************/

   bool isFired;
   int batteryCharge;

public:

/**********************
      Creation and deletition
**********************/

   static int NeuronCounter;
   void resetIdCounter();
   Neuron(int x = -1, int y = -1);
   ~Neuron();
   void setCoordinates(int x, int y);

/**********************
      Connections
**********************/

   int growAxon(int length, double azimuth = -1);
   int growDendr(int delta);
   int addConnection(Neuron *tmpConnection);

/**********************
      Firing
**********************/

   bool checkIfFired();
   void fire();
   void spreadImpulse();
   void chargeBattery();
   void unchargeBattery();
   void printConnections();

/**********************
      Interface
**********************/

   int getNeuronId();
   struct Coordinates getAxonEnd();
   int getDendrRad();
   int getAxonLength();
   double getAxonAzimuth();
   int getNumberOfConnections();
   int getBatteryCharge();
};

#endif
