#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#define SDL_MAIN_HANDLED
//#include <SDL2/SDL.h>        aha tova e ako e edna papka predi faila utochnqvam utochnqvam pakkata v koqto e faila  // a dolu promenih patq da vkliuchva i pakata SDL2, zatova raboti.
// da dovavq SDL.dll ot librart foldera rachno, ot project - properties - build options - link settings - add - ...
#include <SDL.h>
#include "Screen.h"
#include "Swarm.h"
using namespace std;

int main(int argc, char *argv[])
{
srand(time(0));

Screen screen;

if(screen.init() == false) {    //pak q vikam po tozi nachin prosto pestq redove i vreme kato q vikam i ma if ednovremenno

    cout << "Error initializing SDL." << endl;
}


Swarm swarm;


while(true) {   //dokato quit e false(dokato quit e razlichno ot true)
    // Update particles
    //Draw particles
    int elapsed = SDL_GetTicks();

    swarm.update(elapsed);

    unsigned char green = (1 + sin(elapsed*0.001)) * 128; // 0.001,2,3 255
    unsigned char red = (1 + sin(elapsed*0.0009)) * 100;
    unsigned char blue = (1 + sin(elapsed*0.0005)) * 128;

    const Particle* const pParticles = swarm.getParticles();

    for(int i = 0; i < Swarm::NPARTICLES; i++) {

        Particle particle = pParticles[i];

        int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
        int y =  particle.m_y  * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;

        screen.setPixel(x,y,red,green,blue);
    }




    screen.boxBlur();

    //Draw the screen
    screen.update();

    // Check for messages/events
    if(screen.processEvents() == false) {
    break;
   }
}


screen.close();

    return 0;
}
