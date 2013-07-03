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

#include "common/scummsys.h"

#include "zvision/result_action.h"
#include "zvision/zvision.h"

namespace ZVision {

// ActionAdd
//////////////////////////////////////////////////////////////////////////////

ActionAdd::ActionAdd(Common::String line) {
	sscanf(line.c_str(), ":add(%u,%hhu)", &_key, &_value);
}

bool ActionAdd::execute(ZVision *zVision) {
	zVision->getScriptManager()->addToStateValue(_key, _value);
	return true;
}


// ActionAssign
//////////////////////////////////////////////////////////////////////////////

ActionAssign::ActionAssign(Common::String line) {
	sscanf(line.c_str(), ":assign(%u, %hhu)", &_key, &_value);
}

bool ActionAssign::execute(ZVision *zVision) {
	zVision->getScriptManager()->setStateValue(_key, _value);
	return true;
}


// ActionRandom
//////////////////////////////////////////////////////////////////////////////

ActionRandom::ActionRandom(Common::String line) {
	sscanf(line.c_str(), ":random:%u, %u)", &_key, &_max);
}

bool ActionRandom::execute(ZVision *zVision) {
	uint32 randNumber = zVision->getRandomSource()->getRandomNumber(_max);
	zVision->getScriptManager()->setStateValue(_key, randNumber);
	return true;
}

} // End of namespace ZVision
