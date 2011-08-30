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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef NEVERHOOD_MODULE2200_H
#define NEVERHOOD_MODULE2200_H

#include "neverhood/neverhood.h"
#include "neverhood/module.h"
#include "neverhood/scene.h"

namespace Neverhood {

// Module2200

class Module2200 : public Module {
public:
	Module2200(NeverhoodEngine *vm, Module *parentModule, int which);
	virtual ~Module2200();
protected:
	void createScene2201(int which);			
	void createScene2202(int which);			
	void createScene2203(int which);			
	void createScene2204(int which);			
	void createScene2205(int which);			
	void createScene2206(int which);			
	void createScene2207(int which);			
	void createScene2208(int which);			
	void createScene2209(int which);			
	void createScene2210(int which);			
	void createScene2211(int which);			
	void createScene2212(int which);			
	void createScene2213(int which);			
	void createScene2214(int which);			
	void createScene2215(int which);			
	void createScene2216(int which);			
	void createScene2217(int which);			
	void createScene2218(int which);			
	void createScene2219(int which);			
	void createScene2220(int which);			
	void createScene2221(int which);			
	void createScene2222(int which);			
	void createScene2223(int which);			
	void createScene2224(int which);			
	void createScene2225(int which);			
	void createScene2226(int which);			
	void createScene2227(int which);			
	void createScene2228(int which);			
	void createScene2229(int which);			
	void createScene2230(int which);			
	void createScene2231(int which);			
	void createScene2232(int which);			
	void createScene2233(int which);			
	void createScene2234(int which);			
	void createScene2235(int which);			
	void createScene2236(int which);			
	void createScene2237(int which);			
	void createScene2238(int which);			
	void createScene2239(int which);			
	void createScene2240(int which);			
	void createScene2241(int which);			
	void createScene2242(int which);			
	void createScene2243(int which);			
	void createScene2244(int which);			
	void createScene2245(int which);			
	void createScene2246(int which);			
	void createScene2247(int which);			
	void createScene2248(int which);			
	void updateScene2201();			
	void updateScene2202();			
	void updateScene2203();			
	void updateScene2204();			
	void updateScene2205();			
	void updateScene2206();			
	void updateScene2207();			
	void updateScene2208();			
	void updateScene2209();			
	void updateScene2210();			
	void updateScene2211();			
	void updateScene2212();			
	void updateScene2213();			
	void updateScene2214();			
	void updateScene2215();			
	void updateScene2216();			
	void updateScene2217();			
	void updateScene2218();			
	void updateScene2219();			
	void updateScene2220();			
	void updateScene2221();			
	void updateScene2222();			
	void updateScene2223();			
	void updateScene2224();			
	void updateScene2225();			
	void updateScene2226();			
	void updateScene2227();			
	void updateScene2228();			
	void updateScene2229();			
	void updateScene2230();			
	void updateScene2231();			
	void updateScene2232();			
	void updateScene2233();			
	void updateScene2234();			
	void updateScene2235();			
	void updateScene2236();			
	void updateScene2237();			
	void updateScene2238();			
	void updateScene2239();			
	void updateScene2240();			
	void updateScene2241();			
	void updateScene2242();			
	void updateScene2243();			
	void updateScene2244();			
	void updateScene2245();			
	void updateScene2246();			
	void updateScene2247();			
	void updateScene2248();			
};

// Scene2201

static const NPoint kClass444Points[] = {
	{305, 305},
	{321, 305},
	{336, 305},
	{305, 319},
	{321, 319},
	{336, 319},
	{305, 332},
	{321, 332},
	{336, 333}
};

static const uint32 kClass444FileHashes[] = {
	0x88134A44,
	0xAA124340,
	0xB8124602,
	0xA902464C,
	0x890A4244,
	0xA8124642,
	0xB812C204,
	0x381A4A4C
};

class AsScene2201CeilingFan : public AnimatedSprite {
public:
	AsScene2201CeilingFan(NeverhoodEngine *vm);
};

class AsScene2201Door : public AnimatedSprite {
public:
	AsScene2201Door(NeverhoodEngine *vm, Klayman *klayman, Sprite *doorLightSprite, bool flag1);
protected:
	SoundResource _soundResource;
	Klayman *_klayman;
	Sprite *_doorLightSprite;
	bool _doorOpen;
	int _countdown;
	void update();
	uint32 handleMessage(int messageNum, const MessageParam &param, Entity *sender);
	void stOpenDoor();
	void stCloseDoor();
};

class Class444 : public StaticSprite {
public:
	Class444(NeverhoodEngine *vm, int pointIndex, int spriteIndex);
};

class Scene2201 : public Scene {
public:
	Scene2201(NeverhoodEngine *vm, Module *parentModule, int which);
	~Scene2201();
protected:
	NRect _rect1;
	NRect _rect2;
	Sprite *_doorLightSprite;
	Sprite *_asDoor;
	Sprite *_ssDoorButton;
	Sprite *_asTape;
	bool _soundFlag;
	void update();
	uint32 handleMessage(int messageNum, const MessageParam &param, Entity *sender);
};

class SsScene2202PuzzleTile : public StaticSprite {
public:
	SsScene2202PuzzleTile(NeverhoodEngine *vm, Scene *parentScene, int16 tileIndex, int16 value);
protected:
	Scene *_parentScene;	
	int16 _value;
	int16 _tileIndex;
	int16 _newX, _newY;
	int16 _xDelta, _yDelta;
	int16 _xIncr;
	int16 _yIncr;
	int16 _errValue;
	int16 _counter;
	int16 _xFlagPos;
	bool _counterDirection;
	bool _isMoving;
	SoundResource _soundResource1;
	SoundResource _soundResource2;
	void update();
	uint32 handleMessage(int messageNum, const MessageParam &param, Entity *sender);
	void suMoveTileX();
	void suMoveTileY();
	void moveTile(int16 newTileIndex);
	void stopMoving();
};

class Scene2202 : public Scene {
public:
	Scene2202(NeverhoodEngine *vm, Module *parentModule, int which);
	~Scene2202();
protected:
	SoundResource _soundResource1;
	SoundResource _soundResource2;
	Sprite *_movingTileSprite;
	Sprite *_doneMovingTileSprite;
	bool _isTileMoving;
	int16 _movingTileIndex;
	int _surfacePriority;
	bool _leaveScene;
	bool _isSolved;
	void update();
	uint32 handleMessage(int messageNum, const MessageParam &param, Entity *sender);
	int16 getFreeTileIndex(int16 index);
	bool testIsSolved();	
};

} // End of namespace Neverhood

#endif /* NEVERHOOD_MODULE2200_H */
