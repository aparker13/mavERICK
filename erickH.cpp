//Author: Erick Herrera
//Starting Date: 2/21/2017
//Group:6  - Space Maverick

#include <iostream>
#include "header.h"
#include "ppm.cpp"
#include <GL/glx.h>
using namespace std;

Ppmimage *backgroundImage=NULL;
GLuint backgroundTexture;
int background = 1;

Ppmimage *healthImage = NULL;
GLuint healthTexture;
int health = 1;

void GAMEOVERSCREEN (void);
void showGAMEOVERSCREEN ();
void MaverickBackground();
void MaverickHealth();

void Maverick () {
    for (int i = 0; i < 10; i++) {
	    cout << "mavERICK";
	    cout << "\n";
    }
}


void Maverick2 (int yres) {
    char name[10] = {"mavERICK"};

    Rect maverick;
    glEnable(GL_TEXTURE_2D);

    maverick.bot = yres/11;
    maverick.left = 850;
    maverick.center = 0;
    ggprint16(&maverick, 0, 0x00ffffff, name);
}

void MaverickHealthFill (float health) {
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex2f(0, 0);
	glVertex2f(1, 0);
	glVertex2f(2, 0);
	glVertex2f(3, 0);
	glVertex2f(4, 0);
	glVertex2f(5, 0);
	glVertex2f(1, health);
	glVertex2f(0, health);
	glEnd();
}

void init_opengl(void)
{
    //OpenGL initialization
    glViewport(0, 0, xres, yres);
    //Initialize matrices
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    //This sets 2D mode (no perspective)
    glOrtho(0, xres, 0, yres, -1, 1);
    //
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_FOG);
    glDisable(GL_CULL_FACE);
    //
    //Clear the screen to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    //Do this to allow fonts
    glEnable(GL_TEXTURE_2D);
    initialize_fonts(); 

    glGenTextures(1, &backgroundTexture);
    backgroundImage = ppm6GetImage("./assets/background.ppm");
    int w = backgroundImage->width;
    int h = backgroundImage->height;
    glBindTexture(GL_TEXTURE_2D, backgroundTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, backgroundImage->data);

    glGenTextures(1, &healthTexture);
    healthImage = ppm6GetImage("./assets/healthBar.ppm");
    int healthW = healthImage->width;
    int healthH = healthImage->height;
    glBindTexture(GL_TEXTURE_2D, healthTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, healthW, healthH, 0, GL_RGB, GL_UNSIGNED_BYTE, healthImage->data);



}
/*    //Background and Gameover screens for the game. 
    background = ppm6GetImage("./assets/background.ppm");
    gameover = ppm6GetImage("./assets/gameover.ppm");

    //------Bullet ---------------------------------------------------
    glGenTextures(1, &bulletImage);
    bullet = ppm6GetImage("./assets/basicBullet.ppm");
    int bulletW = bullet->width;
    int bulletH = bullet->height;
    glBindTexture(GL_TEXTURE_2D, bulletImage);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, bulletW, bulletH, 0, GL_RGB, GL_UNSIGNED_BYTE, bullet->data);

    //------------High Score Image (Not the actual score) ------------
    glGenTextures(1, &highScoreImage);
    highScore = ppm6GetImage("./assets/highScore.ppm");
    int highScoreW = highScore->width;
    int highScoreH = highScore->height;
    glBindTexture(GL_TEXTURE_2D, highScoreImage);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, highScoreW, highScoreH, 0, GL_RGB, GL_UNSIGNED_BYTE, highScore->data);

    //-----------Basic Ship Image-------------------------------------
    glGenTextures(1, &shipImage);
    ship = ppm6GetImage("./assets/ship.ppm");
    int shipW = ship->width;
    int shipH = ship->height;
    glBindTexture(GL_TEXTURE_2D, shipImage);
    
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, shipW, shipH, 0, GL_RGB, GL_UNSIGNED_BYTE, ship->data);

    //-----------Ship Upgrade Image-----------------------------------
    glGenTextures(1, &shipUpgradeImage);
    shipUpgrade = ppm6GetImage("./assets/shipUpgrade.ppm");
    int shipUpgradeW = shipUpgrade->width;
    int shipUpgradeH = shipUpgrade->height;
    glBindTexture(GL_TEXTURE_2D, shipUpgradeImage);
    
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, shipUpgradeW, shipUpgradeH, 0, GL_RGB, GL_UNSIGNED_BYTE, shipUpgrade->data);

    //-----------Ship Upgrade 2 Image---------------------------------
    glGenTextures(1, &shipUpgrade2Image);
    shipUpgrade2 = ppm6GetImage("./assets/shipUpgrade2.ppm");
    int shipUpgrade2W = shipUpgrade2->width;
    int shipUpgrade2H = shipUpgrade2->height;
    glBindTexture(GL_TEXTURE_2D, shipUpgrade2Image);
    
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, shipUpgrade2W, shipUpgrade2H, 0, GL_RGB, GL_UNSIGNED_BYTE, shipUpgrade2->data);

    //-----------Ship Upgrade 3 Image---------------------------------
    glGenTextures(1, &shipUpgrade3Image);
    shipUpgrade3 = ppm6GetImage("./assets/shipUpgrade3.ppm");
    int shipUpgrade3W = shipUpgrade3->width;
    int shipUpgrade3H = shipUpgrade3->height;
    glBindTexture(GL_TEXTURE_2D, shipUpgrade3Image);
    
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, shipUpgrade3W, shipUpgrade3H, 0, GL_RGB, GL_UNSIGNED_BYTE, shipUpgrade3->data);

    //----------POWERUP TEST ----------------------------------------- (Not certain)
    glGenTextures(1, &powerupImage);
    powerup = ppm6GetImage("./assets/powerup.ppm");
    int powerupW = powerup->width;
    int powerupH = powerup->height;
    glBindTexture(GL_TEXTURE_2D, powerupImage);
    
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, powerupW, powerupH, 0, GL_RGB, GL_UNSIGNED_BYTE, powerup->data);

    //Function that changes the ship whenever it touches the powerup.
    //Background
    glGenTextures(1, &backgroundImage);
    int backgroundW = background->width;
    int backgroundH = background->height;
    glBindTexture(GL_TEXTURE_2D, backgroundImage);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, backgroundW, backgroundH, 0, GL_RGB, GL_UNSIGNED_BYTE, background->data);

    //Game over Screen
    glGenTextures(1, &gameoverImage);
    int gameoverW = gameover->width;
    int gameoverH = gameover->height;
    glBindTexture(GL_TEXTURE_2D, gameoverImage);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, gameoverW, gameoverH, 0, GL_RGB, GL_UNSIGNED_BYTE, gameover->data);

    glEnable(GL_TEXTURE_2D);
    initialize_fonts();
    
}*/

void MaverickBackground() {
    if(background) {
	glBindTexture(GL_TEXTURE_2D, backgroundTexture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f); glVertex2i(0,0);
	glTexCoord2f(0.0f, 0.0f); glVertex2i(0, yres);
	glTexCoord2f(1.0f, 0.0f); glVertex2i(xres, yres);
	glTexCoord2f(1.0f, 1.0f); glVertex2i(xres, 0);
	glEnd();
    }
}

void MaverickHealth() {
    if(health) {
	glBindTexture(GL_TEXTURE_2D, healthTexture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f); glVertex2i(0,0);
	glTexCoord2f(0.0f, 0.0f); glVertex2i(0, yres);
	glTexCoord2f(1.0f, 0.0f); glVertex2i(xres, yres);
	glTexCoord2f(1.0f, 1.0f); glVertex2i(xres, 0);
	glEnd();
    }
}
