#include <simplecpp>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <ctime>
#include <fstream>
using namespace simplecpp;

//movingObject.h
#ifndef _MOVINGOBJECT_INCLUDED_
#define _MOVINGOBJECT_INCLUDED_

#include <simplecpp>
#include <vector>
#include <composite.h>
#include <sprite.h>

using namespace simplecpp;

class MovingObject : public Sprite {
  vector<Sprite*> parts;
  double vx, vy;
  double ax, ay;
  bool paused;
  void initMO(double argvx, double argvy, double argax, double argay, bool argpaused=true) {
    vx=argvx; vy=argvy; ax=argax; ay=argay; paused=argpaused;
  }
 public:
 MovingObject(double argvx, double argvy, double argax, double argay, bool argpaused=true)
    : Sprite() {
    initMO(argvx, argvy, argax, argay, argpaused);
  }
 MovingObject(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : Sprite() {
   double angle_rad = angle_deg*PI/180.0;
   double argvx = speed*cos(angle_rad);
   double argvy = -speed*sin(angle_rad);
   initMO(argvx, argvy, argax, argay, argpaused);
  }
  void set_vx(double argvx) { vx = argvx; }
  void set_vy(double argvy) { vy = argvy; }
  void set_ax(double argax) { ax = argax; }
  void set_ay(double argay) { ay = argay; }
  double getXPos();
  double getYPos();
  void reset_all(double argx, double argy, double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta);

  void pause() { paused = true; }
  void unpause() { paused = false; }
  bool isPaused() { return paused; }

  void addPart(Sprite* p) {
    parts.push_back(p);
  }
  void nextStep(double t);
  void getAttachedTo(MovingObject *m);
};

#endif

//MovingObject.cpp

void MovingObject::nextStep(double t) {
  if(paused) { return; }
  //cerr << "x=" << getXPos() << ",y=" << getYPos() << endl;
  //cerr << "vx=" << vx << ",vy=" << vy << endl;
  //cerr << "ax=" << ax << ",ay=" << ay << endl;

  for(size_t i=0; i<parts.size(); i++){
    parts[i]->move(vx*t, vy*t);
  }
  vx += ax*t;
  vy += ay*t;
} // End MovingObject::nextStep()

double MovingObject::getXPos() {
  return (parts.size() > 0) ? parts[0]->getX() : -1;
}

double MovingObject::getYPos() {
  return (parts.size() > 0) ? parts[0]->getY() : -1;
}

void MovingObject::reset_all(double argx, double argy, double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) {
  for(size_t i=0; i<parts.size(); i++){
    parts[i]->moveTo(argx, argy);
  }
  double angle_rad = angle_deg*PI/180.0;
  double argvx = speed*cos(angle_rad);
  double argvy = -speed*sin(angle_rad);
  vx = argvx; vy = argvy; ax = argax; ay = argay; paused = argpaused;
} // End MovingObject::reset_all()

void MovingObject::getAttachedTo(MovingObject *m) {
  double xpos = m->getXPos();
  double ypos = m->getYPos();
  for(size_t i=0; i<parts.size(); i++){
    parts[i]->moveTo(xpos, ypos);
  }
  initMO(m->vx, m->vy, m->ax, m->ay, m->paused);
}

//coin.h
#ifndef __COIN_H__
#define __COIN_H__



class Coin : public MovingObject {
  double coin_start_x;
  double coin_start_y;
  double release_speed;
  double release_angle_deg;
  double coin_ax;
  double coin_ay;

  // Moving parts
  Circle coin_circle;

 public:
 Coin(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed;
    release_angle_deg = angle_deg;
    coin_ax = argax;
    coin_ay = argay;
    initCoin();
  }

  void initCoin();
  void resetCoin();

}; // End class Coin

#endif

//coin2.h
#ifndef __COIN2_H__
#define __COIN2_H__



class Coin2 : public MovingObject {
  double coin2_start_x;
  double coin2_start_y;
  double release_speed;
  double release_angle_deg;
  double coin_ax;
  double coin_ay;

  // Moving parts
  Circle coin2_circle;

 public:
 Coin2(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed;
    release_angle_deg = angle_deg;
    coin_ax = argax;
    coin_ay = argay;
    initCoin2();
  }

  void initCoin2();
  void resetCoin2();

}; // End class Coin2

#endif

//coin3.h
#ifndef __COIN3_H__
#define __COIN3_H__



class Coin3 : public MovingObject {
  double coin3_start_x;
  double coin3_start_y;
  double release_speed;
  double release_angle_deg;
  double coin_ax;
  double coin_ay;

  // Moving parts
  Circle coin3_circle;

 public:
 Coin3(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed;
    release_angle_deg = angle_deg;
    coin_ax = argax;
    coin_ay = argay;
    initCoin3();
  }

  void initCoin3();
  void resetCoin3();

}; // End class Coin3

#endif

//coin4.h
#ifndef __COIN4_H__
#define __COIN4_H__



class Coin4 : public MovingObject {
  double coin4_start_x;
  double coin4_start_y;
  double release_speed;
  double release_angle_deg;
  double coin_ax;
  double coin_ay;

  // Moving parts
  Circle coin4_circle;

 public:
 Coin4(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed;
    release_angle_deg = angle_deg;
    coin_ax = argax;
    coin_ay = argay;
    initCoin4();
  }

  void initCoin4();
  void resetCoin4();

}; // End class Coin4

#endif




//lasso.h
#ifndef __LASSO_H__
#define __LASSO_H__

//#define WINDOW_X 1200
//#define WINDOW_Y 960
#define WINDOW_X 800
#define WINDOW_Y 600

#define STEP_TIME 0.05

#define PLAY_X_START 100
#define PLAY_Y_START 0
#define PLAY_X_WIDTH (WINDOW_X-PLAY_X_START)
#define PLAY_Y_HEIGHT (WINDOW_Y-100)

#define LASSO_X_OFFSET 100
#define LASSO_Y_HEIGHT 100
#define LASSO_BAND_LENGTH LASSO_X_OFFSET
#define LASSO_THICKNESS 5

#define COIN_GAP 1

#define RELEASE_ANGLE_STEP_DEG 5
#define MIN_RELEASE_ANGLE_DEG 0
#define MAX_RELEASE_ANGLE_DEG 90
#define INIT_RELEASE_ANGLE_DEG 45

#define RELEASE_SPEED_STEP 20
#define MIN_RELEASE_SPEED 0
#define MAX_RELEASE_SPEED 200
#define INIT_RELEASE_SPEED 100

#define COIN_SPEED 120
#define COIN_ANGLE_DEG 70

#define COIN2_SPEED 130
#define COIN2_ANGLE_DEG 100

#define COIN3_SPEED 120
#define COIN3_ANGLE_DEG 90

#define COIN4_SPEED 10
#define COIN4_ANGLE_DEG 270

int life = 3;
int tim = 240;
int magnet=1;
float currTime4 = 0;

#define LASSO_G 30
#define COIN_G 30

#define LASSO_SIZE 10
double LASSO_RADIUS = 50;
double LASSO_RADIUS2 = 50;
#define COIN_SIZE 5

class Lasso : public MovingObject {
  double lasso_start_x;
  double lasso_start_y;
  double release_speed;
  double release_angle_deg;
  double lasso_ax;
  double lasso_ay;

  // Moving parts
  Circle lasso_circle;
  Circle lasso_loop;

  // Non-moving parts
  Line lasso_line;
  Line lasso_band;

  // State info
  bool lasso_looped;
  Coin *the_coin;
  Coin2 *the_coin2;
  Coin3 *the_coin3;
  Coin4 *the_coin4;
  int num_coins;

  void initLasso();
 public:
 Lasso(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed;
    release_angle_deg = angle_deg;
    lasso_ax = argax;
    lasso_ay = argay;
    initLasso();
  }

  void draw_lasso_band();
  void yank();
  void loopit();
  void addAngle(double angle_deg);
  void addSpeed(double speed);

  void nextStep(double t);
  void check_for_coin(Coin *coin);
  void check_for_coin2(Coin2 *coin2);
  void check_for_coin3(Coin3 *coin3);
  void check_for_coin4(Coin4 *coin4);
  int getNumCoins() { return num_coins; }

}; // End class Lasso

#endif

//coin.h

void Coin::initCoin() {
  coin_start_x = (PLAY_X_START+WINDOW_X)/2-100;
  coin_start_y = PLAY_Y_HEIGHT;
  coin_circle.reset(coin_start_x, coin_start_y, COIN_SIZE);
  coin_circle.setColor(COLOR(255,215,0));
  coin_circle.setFill(true);
  addPart(&coin_circle);
}

void Coin::resetCoin() {
  double coin_speed = COIN_SPEED;
  double coin_angle_deg = COIN_ANGLE_DEG;
  coin_ax = 0;
  coin_ay = COIN_G;
  bool paused = true, rtheta = true;
  reset_all(coin_start_x, coin_start_y, coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
}


//coin2.h

void Coin2::initCoin2() {
  coin2_start_x = (PLAY_X_START+WINDOW_X)/2+100;
  coin2_start_y = PLAY_Y_HEIGHT;
  coin2_circle.reset(coin2_start_x, coin2_start_y, COIN_SIZE);
  coin2_circle.setColor(COLOR(255,0,0));
  coin2_circle.setFill(true);
  addPart(&coin2_circle);
}

void Coin2::resetCoin2() {
  double coin_speed = COIN2_SPEED;
  double coin_angle_deg = COIN2_ANGLE_DEG;
  coin_ax = 0;
  coin_ay = COIN_G;
  bool paused = true, rtheta = true;
  reset_all(coin2_start_x, coin2_start_y, coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
}


//coin3.h

void Coin3::initCoin3() {
  coin3_start_x = (PLAY_X_START+WINDOW_X)/2;
  coin3_start_y = PLAY_Y_HEIGHT;
  coin3_circle.reset(coin3_start_x, coin3_start_y, COIN_SIZE);
  coin3_circle.setColor(COLOR(0,0,0));
  coin3_circle.setFill(true);
  addPart(&coin3_circle);
}

void Coin3::resetCoin3() {
  double coin_speed = COIN3_SPEED;
  double coin_angle_deg = COIN3_ANGLE_DEG;
  coin_ax = 0;
  coin_ay = COIN_G;
  bool paused = true, rtheta = true;
  reset_all(coin3_start_x, coin3_start_y, coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
}

//coin3.h

void Coin4::initCoin4() {
  coin4_start_x = (PLAY_X_START+WINDOW_X)/2;
  coin4_start_y = -10;
  coin4_circle.reset(coin4_start_x, coin4_start_y, COIN_SIZE);
  coin4_circle.setColor(COLOR(34,139,34));
  coin4_circle.setFill(true);
  addPart(&coin4_circle);
}

void Coin4::resetCoin4() {
  double coin_speed = COIN4_SPEED;
  double coin_angle_deg = COIN4_ANGLE_DEG;
  coin_ax = 0;
  coin_ay = COIN_G;
  bool paused = true, rtheta = true;
  reset_all(coin4_start_x, coin4_start_y, coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
}


//lasso.cpp

void Lasso::draw_lasso_band() {
  double len = (release_speed/MAX_RELEASE_SPEED)*LASSO_BAND_LENGTH;
  double arad = release_angle_deg*PI/180.0;
  double xlen = len*cos(arad);
  double ylen = len*sin(arad);
  lasso_band.reset(lasso_start_x, lasso_start_y, (lasso_start_x-xlen), (lasso_start_y+ylen));
  lasso_band.setThickness(LASSO_THICKNESS);
} // End Lasso::draw_lasso_band()

void Lasso::initLasso() {
  lasso_start_x = (PLAY_X_START+LASSO_X_OFFSET);
  lasso_start_y = (PLAY_Y_HEIGHT-LASSO_Y_HEIGHT);
  lasso_circle.reset(lasso_start_x, lasso_start_y, LASSO_SIZE);
  lasso_circle.setColor(COLOR(255,0,0));
  lasso_circle.setFill(true);
  lasso_loop.reset(lasso_start_x, lasso_start_y, LASSO_SIZE/2);
  lasso_loop.setColor(COLOR(165,42,42));
  lasso_loop.setFill(true);
  addPart(&lasso_circle);
  addPart(&lasso_loop);
  lasso_looped = false;
  the_coin = NULL;
  the_coin2 = NULL;
  the_coin3 = NULL;
  the_coin4 = NULL;
  num_coins = 0;

  lasso_line.reset(lasso_start_x, lasso_start_y, lasso_start_x, lasso_start_y);
  lasso_line.setColor(COLOR(165,42,42));

  lasso_band.setColor(COLOR(138,43,226));
  draw_lasso_band();

} // End Lasso::initLasso()

void Lasso::yank() {
  bool paused = true, rtheta = true;
  reset_all(lasso_start_x, lasso_start_y, release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
  lasso_loop.reset(lasso_start_x, lasso_start_y, LASSO_SIZE/2);
  lasso_loop.setFill(true);
  lasso_looped = false;
  if(the_coin != NULL) {
    num_coins++;
    the_coin->resetCoin();
    the_coin=NULL;
  }
  if(the_coin2 !=NULL)
  {
    num_coins+=2;
    the_coin2->resetCoin2();
    the_coin2=NULL;
  }
  if(the_coin3!=NULL)
  {
    life--;
    num_coins-=2;
    the_coin3->resetCoin3();
    the_coin3=NULL;
  }
    if(the_coin4!=NULL)
  {
    tim+=30;
    life++;
    num_coins+=2;
    the_coin4->resetCoin4();
    the_coin4=NULL;
  }
} // End Lasso::yank()

void Lasso::loopit() {
  if(lasso_looped) { return; } // Already looped
  lasso_loop.reset(getXPos(), getYPos(), LASSO_RADIUS);
  lasso_loop.setFill(false);
  lasso_looped = true;
} // End Lasso::loopit()

void Lasso::addAngle(double angle_deg) {
  release_angle_deg += angle_deg;
  if(release_angle_deg < MIN_RELEASE_ANGLE_DEG) { release_angle_deg = MIN_RELEASE_ANGLE_DEG; }
  if(release_angle_deg > MAX_RELEASE_ANGLE_DEG) { release_angle_deg = MAX_RELEASE_ANGLE_DEG; }
  bool paused = true, rtheta = true;
  reset_all(lasso_start_x, lasso_start_y, release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
} // End Lasso::addAngle()

void Lasso::addSpeed(double speed) {
  release_speed += speed;
  if(release_speed < MIN_RELEASE_SPEED) { release_speed = MIN_RELEASE_SPEED; }
  if(release_speed > MAX_RELEASE_SPEED) { release_speed = MAX_RELEASE_SPEED; }
  bool paused = true, rtheta = true;
  reset_all(lasso_start_x, lasso_start_y, release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
} // End Lasso::addSpeed()

void Lasso::nextStep(double stepTime) {
  draw_lasso_band();
  MovingObject::nextStep(stepTime);
  if(getYPos() > PLAY_Y_HEIGHT) { yank(); }
  lasso_line.reset(lasso_start_x, lasso_start_y, getXPos(), getYPos());
} // End Lasso::nextStep()

void Lasso::check_for_coin(Coin *coinPtr) {
  double lasso_x = getXPos();
  double lasso_y = getYPos();
  double coin_x = coinPtr->getXPos();
  double coin_y = coinPtr->getYPos();
  double xdiff = (lasso_x - coin_x);
  double ydiff = (lasso_y - coin_y);
  double distance = sqrt((xdiff*xdiff)+(ydiff*ydiff));
  if(distance <= LASSO_RADIUS) {
    the_coin = coinPtr;
    the_coin->getAttachedTo(this);
  }
} // End Lasso::check_for_coin()

void Lasso::check_for_coin2(Coin2 *coinPtr2) {
  double lasso_x = getXPos();
  double lasso_y = getYPos();
  double coin2_x = coinPtr2->getXPos();
  double coin2_y = coinPtr2->getYPos();
  double xdiff = (lasso_x - coin2_x);
  double ydiff = (lasso_y - coin2_y);
  double distance = sqrt((xdiff*xdiff)+(ydiff*ydiff));
  if(distance <= LASSO_RADIUS) {
    the_coin2 = coinPtr2;
    the_coin2->getAttachedTo(this);
  }
} // End Lasso::check_for_coin()

void Lasso::check_for_coin3(Coin3 *coinPtr3) {
  double lasso_x = getXPos();
  double lasso_y = getYPos();
  double coin3_x = coinPtr3->getXPos();
  double coin3_y = coinPtr3->getYPos();
  double xdiff = (lasso_x - coin3_x);
  double ydiff = (lasso_y - coin3_y);
  double distance = sqrt((xdiff*xdiff)+(ydiff*ydiff));
  if(distance <= LASSO_RADIUS2) {
    the_coin3 = coinPtr3;
    the_coin3->getAttachedTo(this);
  }
} // End Lasso::check_for_coin()


void Lasso::check_for_coin4(Coin4 *coinPtr4) {
  double lasso_x = getXPos();
  double lasso_y = getYPos();
  double coin4_x = coinPtr4->getXPos();
  double coin4_y = coinPtr4->getYPos();
  double xdiff = (lasso_x - coin4_x);
  double ydiff = (lasso_y - coin4_y);
  double distance = sqrt((xdiff*xdiff)+(ydiff*ydiff));
  if(distance <= LASSO_RADIUS) {
    the_coin4 = coinPtr4;
    the_coin4->getAttachedTo(this);
    currTime4 = 0;
  }
} // End Lasso::check_for_coin()




main_program {

  initCanvas("Lasso", WINDOW_X, WINDOW_Y);
  int stepCount = 0;
  float stepTime = STEP_TIME;
  float runTime = -1; // sec; -ve means infinite
  float currTime1 = 0;
  float currTime2 = 0;
  float currTime3 = 0;
  bool freeplay=false;


  ofstream obj1;
    ifstream obj2;
    obj2.open("HighScores.txt");
    char a[50];
    obj2.getline(a,50);
    string name1;
    int score1;
    obj2>>name1;
    obj2>>score1;
    string name2;
    int score2;
    obj2>>name2;
    obj2>>score2;
    string name3;
    int score3;
    obj2>>name3;
    obj2>>score3;
    obj2.close();
    string name4;
    int score4;

  Text Title(400,25,"LASSO GAME");
  Rectangle S(400,100,120,50);
  Text S1(400,100,"Start Game");
  Rectangle C(400,200,120,50);
  Text S2(400,200,"Controls & Rules");
  Rectangle CR(400,300,120,50);
  Text S3(400,300,"Credits");
  Rectangle Q(400,400,120,50);
  Text S4(400,400,"Quit Game");

  Text S5(400,500,"COPYRIGHT. ALL RIGHTS RESERVED 200100083");
  Text S6(400,520,"Lasso game is property of the CS101 grading scheme");
  Text S7(400,540,"Version 1.1");

  while(true)
  {
    int pos=getClick();
    int x=pos/65536;
    int y=pos%65536;
    if(x>=350&&x<=450)
    {
        if(y>=75&&y<=125)
        break;
        else if(y>=175&&y<=225)
        {
            std::ifstream f("Ins.txt");
            if(f.is_open())
            std::cout << f.rdbuf();
            f.close();
            continue;
        }
        else if(y>=275&&y<=375)
        {
            S.hide();
            C.hide();
            Q.hide();
            S1.hide();
            S2.hide();
            S3.hide();
            S4.hide();
            S5.hide();
            S6.hide();
            S7.hide();
            CR.hide();
            Text CR1(400,100,"CREDITS");
            Text CR2(400,200,"Kameswari Ma'am");
            Text CR3(400,300,"Bhaskaran Sir");
            Text CR4(400,400,"Sahasra Ranjan TA");
            Text CR5(400,500,"Saumya Goyal TA");
            Rectangle EX(100,100,100,50);
            Text EXI(100,100,"Go Back");
            while(true)
            {
                int gamp=getClick();
                int xx=gamp/65536;
                int yy=gamp%65536;
                if(xx>=50&&xx<=150&&yy>=75&&yy<=125)
                goto TAG;
                else
                continue;
            }
           TAG: CR1.hide();
            CR2.hide();
            CR3.hide();
            CR4.hide();
            CR5.hide();
            EX.hide();
            EXI.hide();
            S.show();
            C.show();
            Q.show();
            S1.show();
            S2.show();
            S3.show();
            S4.show();
            S5.show();
            S6.show();
            S7.show();
            CR.show();
            continue;
        }
        else if(y>=375&&y<=425)
        exit(0);
        else
        continue;
    }
    else
    continue;
  }

    S.hide();
    C.hide();
    Q.hide();
    S1.hide();
    S2.hide();
    S3.hide();
    S4.hide();
    S5.hide();
    S6.hide();
    S7.hide();
    CR.hide();

    Rectangle M1(400,350,100,50);
    Rectangle M2(400,450,100,50);
    Text Mode1(400,350,"Classic");
    Text Mode2(400,450,"Freeplay");

    while(true)
    {
        int pos=getClick();
        int x=pos/65536;
        int y=pos%65536;
        if(x>=350&&x<=450)
        {
            if(y>=325&&y<=375)
            {
            freeplay=false;
            break;
            }
            else if(y>=425&&y<=475)
            {
            freeplay=true;
            break;
            }
            else
            continue;
        }
        else
        continue;
    }
    M1.hide();
    M2.hide();
    Mode1.hide();
    Mode2.hide();

    if(!freeplay){

  int difficulty;
  Text T1(700,30,"Difficulty:");
  Text T2(700,80,"Easy");
  Text T3(700,130,"Medium");
  Text T4(700,180,"Hard");
  Rectangle R1(700,80,100,46);
  Rectangle R2(700,130,100,46);
  Rectangle R3(700,180,100,46);
  while(true)
  {
    int pos=getClick();
    int x=pos/65536;
    int y=pos%65536;
    if(x>=650&&x<=750)
    {
        if(y>=57&&y<=103)
        {
            difficulty=1;
            R2.hide();
            T3.hide();
            R3.hide();
            T4.hide();
            break;
        }
        else if(y>=107&&y<=153)
        {
            difficulty=2;
            R1.hide();
            T2.hide();
            R3.hide();
            T4.hide();
            break;
        }
        else if(y>=157&&y<=203)
        {
            difficulty=3;
            R1.hide();
            T2.hide();
            R2.hide();
            T3.hide();
            break;
        }
        else
        continue;
    }
    else
    continue;
  }

  double magtime=0;
  tim=tim-30*difficulty;
  auto start = std::chrono::system_clock::now();
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds =(end-start);


  char timpi[256];
  sprintf(timpi, "Time Left: %d",(int)(tim-elapsed_seconds.count()));
  Text timing(400, 100, timpi);

  int coinsRequired=30;
  char coinRequirement[256];
  sprintf(coinRequirement, "Coins Required to Win: %d", coinsRequired);
  Text Required(400, 80, coinRequirement);

  char Lives[256];
  sprintf(Lives, "Lives: %d", life);
  Text Lifes(400,60, Lives);

  // Draw lasso at start position
  double release_speed = INIT_RELEASE_SPEED; // m/s
  double release_angle_deg = INIT_RELEASE_ANGLE_DEG; // degrees
  double lasso_ax = 0;
  double lasso_ay = LASSO_G;
  bool paused = true;
  bool rtheta = true;
  Lasso lasso(release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);

  Line b1(0, PLAY_Y_HEIGHT, WINDOW_X, PLAY_Y_HEIGHT);
  b1.setColor(COLOR("blue"));
  Line b2(PLAY_X_START, 0, PLAY_X_START, WINDOW_Y);
  b2.setColor(COLOR("blue"));

  string msg("Cmd: _");
  Text charPressed(PLAY_X_START+50, PLAY_Y_HEIGHT+20, msg);
  char coinScoreStr[256];
  sprintf(coinScoreStr, "Coins: %d", lasso.getNumCoins());
  Text coinScore(PLAY_X_START+50, PLAY_Y_HEIGHT+50, coinScoreStr);

  paused = true; rtheta = true;
  double coin_speed = COIN_SPEED;
  double coin_angle_deg = COIN_ANGLE_DEG;
  double coin_ax = 0;
  double coin_ay = COIN_G;
  double coin2_speed = COIN2_SPEED;
  double coin2_angle_deg = COIN2_ANGLE_DEG;
  double coin3_speed = COIN3_SPEED;
  double coin3_angle_deg = COIN3_ANGLE_DEG;
  double coin4_speed = COIN4_SPEED;
  double coin4_angle_deg = COIN4_ANGLE_DEG;
  Coin coin(coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
  Coin2 coin2(coin2_speed, coin2_angle_deg, coin_ax, coin_ay, paused, rtheta);
  Coin3 coin3(coin3_speed, coin3_angle_deg, coin_ax, coin_ay, paused, rtheta);
  Coin4 coin4(coin4_speed, coin4_angle_deg, coin_ax, coin_ay, paused, rtheta);
  // After every COIN_GAP sec, make the coin jump
  double last_coin_jump_end = 0;
  double last_coin2_jump_end = 0;
  double last_coin3_jump_end = 0;
  double last_coin4_jump_end = 0;

  // When t is pressed, throw lasso
  // If lasso within range, make coin stick
  // When y is pressed, yank lasso
  // When l is pressed, loop lasso
  // When q is pressed, quit

  for(;;) {

    auto end = std::chrono::system_clock::now();
    elapsed_seconds = end-start;
    sprintf(timpi, "Time Left: %d",(int)(tim-elapsed_seconds.count()));
    timing.setMessage(timpi);
    if(elapsed_seconds.count()>tim||life==0)
    {
        Text LOSE(400,400,"YOU LOSE. TRY AGAIN NEXT TIME");
        wait(5);
        exit(0);
    }


    if((runTime > 0) && (currTime1 > runTime)) { break; }

    XEvent e;
    bool pendingEv = checkEvent(e);
    if(pendingEv) {
      char c = charFromEvent(e);
      msg[msg.length()-1] = c;
      charPressed.setMessage(msg);
      switch(c) {
      case 't':
	lasso.unpause();
	break;
      case 'y':
	lasso.yank();
	break;
      case 'l':
	lasso.loopit();
	if(!coin.isPaused())
	lasso.check_for_coin(&coin);
	if(!coin2.isPaused())
	lasso.check_for_coin2(&coin2);
	if(!coin3.isPaused())
	lasso.check_for_coin3(&coin3);
	if(!coin4.isPaused())
	lasso.check_for_coin4(&coin4);
	wait(STEP_TIME*5);
	break;
      case 's':
	if(lasso.isPaused()) { lasso.addAngle(-RELEASE_ANGLE_STEP_DEG);	}
	break;
      case 'w':
	if(lasso.isPaused()) { lasso.addAngle(+RELEASE_ANGLE_STEP_DEG); }
	break;
      case 'a':
	if(lasso.isPaused()&&difficulty!=3) { lasso.addSpeed(-RELEASE_SPEED_STEP); }
	break;
      case 'd':
	if(lasso.isPaused()&&difficulty!=3) { lasso.addSpeed(+RELEASE_SPEED_STEP); }
	break;
      case 'm':
      if(magnet==1){LASSO_RADIUS = 70; LASSO_RADIUS2 = 0; magtime=elapsed_seconds.count(); magnet--;}
      break;
      case 'q':
	exit(0);
      default:
	break;
      }
    }

    if(elapsed_seconds.count()-10-magtime>0)
    {
        LASSO_RADIUS = 50;
        LASSO_RADIUS2 = 50;
    }

    lasso.nextStep(stepTime);

    coin.nextStep(stepTime);
    if(coin.isPaused()) {
      if((currTime1-last_coin_jump_end) >= COIN_GAP) {
	coin.unpause();
      }
    }

    if(coin.getYPos() > PLAY_Y_HEIGHT) {
      coin.resetCoin();
      last_coin_jump_end = currTime1;
    }


    coin2.nextStep(stepTime);
    if(coin2.isPaused()) {
      if((currTime2-last_coin2_jump_end) >=5*COIN_GAP) {
	coin2.unpause();
      }
    }

    if(coin2.getYPos() > PLAY_Y_HEIGHT) {
      coin2.resetCoin2();
      last_coin2_jump_end = currTime2;
    }


    coin3.nextStep(stepTime);
    if(coin3.isPaused()) {
      if((currTime3-last_coin3_jump_end) >= COIN_GAP) {
	coin3.unpause();
      }
    }

    if(coin3.getYPos() > PLAY_Y_HEIGHT) {
      coin3.resetCoin3();
      last_coin3_jump_end = currTime3;
    }

     coin4.nextStep(stepTime);
    if(coin4.isPaused()) {
      if((currTime4-last_coin4_jump_end) >= 20*COIN_GAP) {
	coin4.unpause();
      }
    }

    if(coin4.getYPos() > PLAY_Y_HEIGHT) {
      coin4.resetCoin4();
      last_coin4_jump_end = currTime4;
    }

    sprintf(Lives, "Lives: %d", life);
    Lifes.setMessage(Lives);


    sprintf(coinScoreStr, "Coins: %d", lasso.getNumCoins());
    coinScore.setMessage(coinScoreStr);

    if(lasso.getNumCoins()>=coinsRequired)
    {
        Text WIN(400,400,"YOU WIN. CONGRATULATIONS!!");
        wait(5);
        exit(0);
    }

    stepCount++;
    currTime1 += stepTime;
    currTime2 += stepTime;
    currTime3 += stepTime;
    currTime4 += stepTime;
    wait(stepTime);
  } // End for(;;)
  wait(3);
}


  // Draw lasso at start position
  double release_speed = INIT_RELEASE_SPEED; // m/s
  double release_angle_deg = INIT_RELEASE_ANGLE_DEG; // degrees
  double lasso_ax = 0;
  double lasso_ay = LASSO_G;
  bool paused = true;
  bool rtheta = true;
  Lasso lasso(release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);

  double magtime=0;
  auto start = std::chrono::system_clock::now();
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds =(end-start);

  Line b1(0, PLAY_Y_HEIGHT, WINDOW_X, PLAY_Y_HEIGHT);
  b1.setColor(COLOR("blue"));
  Line b2(PLAY_X_START, 0, PLAY_X_START, WINDOW_Y);
  b2.setColor(COLOR("blue"));

  string msg("Cmd: _");
  Text charPressed(PLAY_X_START+50, PLAY_Y_HEIGHT+20, msg);
  char coinScoreStr[256];
  sprintf(coinScoreStr, "Coins: %d", lasso.getNumCoins());
  Text coinScore(PLAY_X_START+50, PLAY_Y_HEIGHT+50, coinScoreStr);

  paused = true; rtheta = true;
  double coin_speed = COIN_SPEED;
  double coin_angle_deg = COIN_ANGLE_DEG;
  double coin_ax = 0;
  double coin_ay = COIN_G;
  double coin2_speed = COIN2_SPEED;
  double coin2_angle_deg = COIN2_ANGLE_DEG;
  double coin3_speed = COIN3_SPEED;
  double coin3_angle_deg = COIN3_ANGLE_DEG;
  Coin coin(coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
  Coin2 coin2(coin2_speed, coin2_angle_deg, coin_ax, coin_ay, paused, rtheta);
  Coin3 coin3(coin3_speed, coin3_angle_deg, coin_ax, coin_ay, paused, rtheta);
  // After every COIN_GAP sec, make the coin jump
  double last_coin_jump_end = 0;
  double last_coin2_jump_end = 0;
  double last_coin3_jump_end = 0;


  for(;;) {
        if((runTime > 0) && (currTime1 > runTime)) { break; }

    XEvent e;
    bool pendingEv = checkEvent(e);
    if(pendingEv) {
      char c = charFromEvent(e);
      msg[msg.length()-1] = c;
      charPressed.setMessage(msg);
      switch(c) {
      case 't':
	lasso.unpause();
	break;
      case 'y':
	lasso.yank();
	break;
      case 'l':
	lasso.loopit();
	if(!coin.isPaused())
	lasso.check_for_coin(&coin);
	if(!coin2.isPaused())
	lasso.check_for_coin2(&coin2);
	if(!coin3.isPaused())
	lasso.check_for_coin3(&coin3);
	wait(STEP_TIME*5);
	break;
      case 's':
	if(lasso.isPaused()) { lasso.addAngle(-RELEASE_ANGLE_STEP_DEG);	}
	break;
      case 'w':
	if(lasso.isPaused()) { lasso.addAngle(+RELEASE_ANGLE_STEP_DEG); }
	break;
      case 'a':
	if(lasso.isPaused()) { lasso.addSpeed(-RELEASE_SPEED_STEP); }
	break;
      case 'd':
	if(lasso.isPaused()) { lasso.addSpeed(+RELEASE_SPEED_STEP); }
	break;
      case 'm':
      if(magnet==1){LASSO_RADIUS = 70; LASSO_RADIUS2 = 0; magtime=elapsed_seconds.count(); magnet--;}
      break;
      case 'q':
	exit(0);
      default:
	break;
      }
    }

    if(elapsed_seconds.count()-10-magtime>0)
    {
        LASSO_RADIUS = 50;
        LASSO_RADIUS2 = 50;
    }

    lasso.nextStep(stepTime);

    coin.nextStep(stepTime);
    if(coin.isPaused()) {
      if((currTime1-last_coin_jump_end) >= COIN_GAP) {
	coin.unpause();
      }
    }

    if(coin.getYPos() > PLAY_Y_HEIGHT) {
    break;
      last_coin_jump_end = currTime1;
    }


    coin2.nextStep(stepTime);
    if(coin2.isPaused()) {
      if((currTime2-last_coin2_jump_end) >=5*COIN_GAP) {
	coin2.unpause();
      }
    }

    if(coin2.getYPos() > PLAY_Y_HEIGHT) {
    break;
      last_coin2_jump_end = currTime2;
    }


    coin3.nextStep(stepTime);
    if(coin3.isPaused()) {
      if((currTime3-last_coin3_jump_end) >= COIN_GAP) {
	coin3.unpause();
      }
    }

    if(coin3.getYPos() > PLAY_Y_HEIGHT) {
      coin3.resetCoin3();
      last_coin3_jump_end = currTime3;
    }


    sprintf(coinScoreStr, "Coins: %d", lasso.getNumCoins());
    coinScore.setMessage(coinScoreStr);


    stepCount++;
    currTime1 += stepTime;
    currTime2 += stepTime;
    currTime3 += stepTime;
    currTime4 += stepTime;
    wait(stepTime);

  }
  score4=lasso.getNumCoins();
  char FINALSCORE[256];
  sprintf(FINALSCORE, "GAME OVER. Your final score is: %d", lasso.getNumCoins());
  Text FinalScore(400,300,FINALSCORE);

  Text Prompt(400,425,"Enter name: (Press '.' to end name)");
  string name("");
  Text LetterEntered(400,450,name);
  while(true)
  {
        XEvent g;
    bool pendingEv = checkEvent(g);
    if(pendingEv) {
      char c = charFromEvent(g);
      if(c=='.')
      break;
      name+=c;
      LetterEntered.setMessage(name);
  }
}
  Prompt.hide();
  LetterEntered.hide();

  name4=name;
  if(score4>score1)
  {
    score3=score2;
    score2=score1;
    score1=score4;
    name3=name2;
    name2=name1;
    name1=name4;
  }
  else if(score4>score2)
  {
    score3=score2;
    score2=score4;
    name3=name2;
    name2=name4;
  }
  else if(score4>score3)
  {
    score3=score4;
    name3=name4;
  }

   cout<<a<<"\n";
    cout<<name1<<" "<<score1<<"\n";
    cout<<name2<<" "<<score2<<"\n";
    cout<<name3<<" "<<score3<<"\n";

  obj1.open("HighScores.txt");
    obj1<<a<<"\n";
    obj1<<name1<<" "<<score1<<"\n";
    obj1<<name2<<" "<<score2<<"\n";
    obj1<<name3<<" "<<score3<<"\n";

  wait(5);

} // End main_program
