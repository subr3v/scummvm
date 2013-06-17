/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

/*
 * This code is based on the original source code of Lord Avalot d'Argent version 1.3.
 * Copyright (c) 1994-1995 Mike, Mark and Thomas Thurman.
 */

#ifndef __trip42_h__
#define __trip42_h__

/* {$R+ but switch it off soon...} */

#include "graph.h"
/*#include "Crt.h"*/
/*#include "Gyro.h"*/
/*#include "Sticks.h"*/


const integer maxgetset = 10;

struct adxtype {
           varying_string<12> name; /* name of character */
           byte num; /* number of pictures */
           byte xl,yl; /* x & y lengths of pictures */
           byte seq; /* how many in one stride */
           word size; /* the size of one picture */
           byte fgc,bgc; /* foreground & background bubble colours */
};

class triptype {
public:
            adxtype a; /* vital statistics */
            byte face,step;
            integer x,y; /* current xy coords */
            array<0,1,integer> ox,oy;     /* last xy coords */
            shortint ix,iy; /* amount to move sprite by, each step */
            matrix<1,24,0,1,pointer> pic;     /* the pictures themselves */
            boolean quick,visible,homing,check_me;
            integer hx,hy; /* homing x & y coords */
            byte count; /* counts before changing step */

            triptype* init(byte spritenum);   /* loads & sets up the sprite */
            void original();    /* just sets Quick to false */
            void andexor();    /* drops sprite onto screen */
            void turn(byte whichway);      /* turns him round */
            void appear(integer wx,integer wy, byte wf); /* switches him on */
            void bounce();    /* bounces off walls. */
            void walk();    /* prepares for andexor, etc. */
            void walkto(integer xx,integer yy); /* home in on a point */
            void stophoming();    /* self-explanatory */
            void homestep();    /* calculates ix & iy for one homing step */
            void speed(shortint xx,shortint yy); /* sets ix & iy, non-homing, etc */
            void stopwalk();    /* Stops the sprite from moving */
            void chatter();    /* Sets up talk vars */
};

class getsettype {
public:
              array<1,maxgetset,fieldtype> gs;
              byte numleft;

              getsettype* init();
              void remember(fieldtype r);
              void recall(fieldtype& r);
};

const integer numtr = 5; /* current max no. of sprites */

void trippancy_link();

void loadtrip();

void tripkey(char dir);

void apped(byte trn,byte np);

void fliproom(byte room,byte ped);

boolean infield(byte x);          /* returns True if you're within field "x" */

boolean neardoor();        /* returns True if you're near a door! */

void readstick();


#ifdef __trip42_implementation__
#undef EXTERN
#define EXTERN
#endif

EXTERN array<1,numtr,triptype> tr;
EXTERN array<0,1,getsettype> getset;
#undef EXTERN
#define EXTERN extern


#endif
