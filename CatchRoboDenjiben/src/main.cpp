#include <mbed.h>
#include <DENJIBEN.h>

#define DENJIBEN  PA_13

DigitalOut d_1(DENJIBEN);

DigitalIn BT(USER_BUTTON);

Denjiben DB(d_1);

int main() {

  if(BT)
  {
    DB.open();
  }

  if(!BT)
  {
    DB.close();
  }  
  
}