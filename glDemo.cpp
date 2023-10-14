/*************************************************************
 * 1. Name:
 *      team 7 Daniel Carr & Cayden Lords
 * 2. Assignment Name:
 *      Lab 04: Apollo 11 Visuals
 * 3. Assignment Description:
 *      Simulate the Apollo 11 landing
 * 4. What was the hardest part? Be as specific as possible.
 *      The hardest part was getting Github to sync up. The actual code was pretty simple.
 * 5. How long did it take for you to complete the assignment?
 *      2 hours
 *****************************************************************/

/**********************************************************************
 * GL Demo
 * Just a simple program to demonstrate how to create an Open GL window, 
 * draw something on the window, and accept simple user input
 **********************************************************************/
#include "lander.h"
#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ground.h"
using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(const Point& ptUpperRight) :
          ptStar(ptUpperRight.getX() - 20.0, ptUpperRight.getY() - 20.0),
          ground(ptUpperRight)
   { 

      phase = random(0, 255);
   }

   // this is just for test purposes.  Don't make member variables public!
   Point ptUpperRight;   // size of the screen
   unsigned char phase;  // phase of the star's blinking
   Ground ground;
   Point ptStar;
   int fuel = 5000;
   //double speed = 12.91;
   Lander apollo11 = Lander();
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface *pUI, void * p)
{
   ogstream gout;

   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo * pDemo = (Demo *)p;  

   // move the ship around
   pDemo->apollo11.moveLander(pUI);

   // draw the ground
   pDemo->ground.draw(gout);

   // draw the lander and its flames
   gout.drawLander(pDemo->apollo11.getLocation() /*position*/, pDemo->apollo11.getAngle().getRadians() /*angle*/);
   if (pDemo->apollo11.outOfFuel == false) {
       gout.drawLanderFlames(pDemo->apollo11.getLocation(), pDemo->apollo11.getAngle().getRadians(), /*angle*/
           pUI->isUp(), pUI->isLeft(), pUI->isRight());

   }

   // call gameover
   if (pDemo->ground.getElevation(pDemo->apollo11.getLocation()) < 0.0) {
       GameOver(pDemo->ground.onPlatform(pDemo->apollo11.getLocation(), 20), pDemo->apollo11.getSpeed());
   }

   // put some text on the screen
   gout.setf(ios::fixed);
   gout.setf(ios::showpoint);
   gout.precision(2);

   gout.setPosition(Point(30.0, 385.0));
   gout << "Fuel " << (int)pDemo->apollo11.getFuel() << " lbs" << "\n"; // change once lander set up

   gout.setPosition(Point(30.0, 372.0));
   gout << "Altitude " << (double)pDemo->ground.getElevation(pDemo->apollo11.getLocation()) << " meters" << "\n";

   gout.setPosition(Point(30.0, 359.0));
   gout << "Speed " << (double)pDemo->apollo11.getSpeed() << " m/s" << "\n";// change once lander set up


   // draw our little star
   for (int x = 0; x < 50; x++) {
       pDemo->ptStar.setX(random(0.0, /*pDemo->ptUpperRight.getX()*/400.0));
       pDemo->ptStar.setY(random(0.0, /*pDemo->ptUpperRight.getY()*/400.0));
       if (pDemo->ground.getElevation(pDemo->ptStar) > 0.0) {
           gout.drawStar(pDemo->ptStar, pDemo->phase);
       }
       else {
           x--;
       }

   }
}



/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance, 
   _In_opt_ HINSTANCE hPrevInstance, 
   _In_ PWSTR pCmdLine, 
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char ** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
   Point ptUpperRight(400.0, 400.0);
   Interface ui(0, NULL, 
                "Open GL Demo", 
                 ptUpperRight);

   // Initialize the game class
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);             

   return 0;
}
