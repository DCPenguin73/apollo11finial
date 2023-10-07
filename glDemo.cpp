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
          angle(0.0),
          ptStar(ptUpperRight.getX() - 20.0, ptUpperRight.getY() - 20.0),
          ptLM(ptUpperRight.getX() / 2.0, ptUpperRight.getY() / 2.0),
          ground(ptUpperRight)
   { 

      phase = random(0, 255);
   }

   // this is just for test purposes.  Don't make member variables public!
   Point ptLM;           // location of the LM on the screen
   Point ptUpperRight;   // size of the screen
   double angle;         // angle the LM is pointing
   unsigned char phase;  // phase of the star's blinking
   Ground ground;
   Point ptStar;
   int fuel = 5000;
   double speed = 12.91;
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
   if (pUI->isRight()) {
       pDemo->angle -= 0.1;
       pDemo->ptLM.addX(1.0);
   }
   if (pUI->isLeft()) {
       pDemo->angle += 0.1;
       pDemo->ptLM.addX(-1.0);
   }
   if (pUI->isUp())
      pDemo->ptLM.addY(-1.0);
   if (pUI->isDown())
      pDemo->ptLM.addY(1.0);

   // draw the ground
   pDemo->ground.draw(gout);

   // draw the lander and its flames
   gout.drawLander(pDemo->ptLM /*position*/, pDemo->angle /*angle*/);
   gout.drawLanderFlames(pDemo->ptLM, pDemo->angle, /*angle*/
                    pUI->isDown(), pUI->isLeft(), pUI->isRight());

   // put some text on the screen
   gout.setf(ios::fixed);
   gout.setf(ios::showpoint);
   gout.precision(2);

   gout.setPosition(Point(30.0, 385.0));
   gout << "Fuel " << (int)pDemo->fuel << " lbs" << "\n"; // change once lander set up

   gout.setPosition(Point(30.0, 372.0));
   gout << "Altitude " << (double)pDemo->ground.getElevation(pDemo->ptLM) << " meters" << "\n";

   gout.setPosition(Point(30.0, 359.0));
   gout << "Speed " << (double)pDemo->speed << " m/s" << "\n";// change once lander set up


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
void GameOver(bool onPlatform, double Speed) {
    //THIS IS A STUB FUNCTION SO COOL MUCH WOW
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
