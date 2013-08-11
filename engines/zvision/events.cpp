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

#include "zvision/zvision.h"
#include "zvision/console.h"
#include "common/events.h"
#include "engines/util.h"

#include "zvision/cursor_manager.h"
#include "zvision/render_manager.h"
#include "zvision/mouse_event.h"

namespace ZVision {

void ZVision::registerMouseEvent(const MouseEvent &event) {
	_mouseEvents.push_back(event);
}

void ZVision::clearAllMouseEvents() {
	_mouseEvents.clear();
}

void ZVision::processEvents() {
	while (_eventMan->pollEvent(_event)) {
		switch (_event.type) {
		case Common::EVENT_LBUTTONDOWN:
			onMouseDown(_event.mouse);
			break;

		case Common::EVENT_LBUTTONUP:
			onMouseUp(_event.mouse);
			break;

		case Common::EVENT_RBUTTONDOWN:
			break;

		case Common::EVENT_MOUSEMOVE:
			onMouseMove(_event.mouse);
			break;

		case Common::EVENT_KEYDOWN:
			switch (_event.kbd.keycode) {
			case Common::KEYCODE_d:
				if (_event.kbd.hasFlags(Common::KBD_CTRL)) {
					// Start the debugger
					_console->attach();
					_console->onFrame();
				}
				break;
			case Common::KEYCODE_q:
				if (_event.kbd.hasFlags(Common::KBD_CTRL))
					quitGame();
				break;
			case Common::KEYCODE_F1:
				cycleThroughCursors();
				break;
			default:
				break;
			}

			onKeyDown(_event.kbd.keycode);
			break;

		default:
			break;
		}
	}
}

void ZVision::onMouseDown(const Common::Point &pos) {
	_cursorManager->cursorDown(true);
}

void ZVision::onMouseUp(const Common::Point &pos) {
	_cursorManager->cursorDown(false);

	Common::Point imageCoord(_renderManager->convertToImageCoords(pos));

	for (Common::List<MouseEvent>::iterator iter = _mouseEvents.begin(); iter != _mouseEvents.end(); iter++) {
		if (iter->withinHotspot(imageCoord)) {
			iter->onClick(this);
		}
	}
}

void ZVision::onMouseMove(const Common::Point &pos) {
	Common::Point imageCoord(_renderManager->convertToImageCoords(pos));

	bool isWithinAHotspot = false;
	for (Common::List<MouseEvent>::iterator iter = _mouseEvents.begin(); iter != _mouseEvents.end(); iter++) {
		if (iter->withinHotspot(imageCoord)) {
			_cursorManager->changeCursor(iter->getHoverCursor());
			isWithinAHotspot = true;
		}
	}



	if (!isWithinAHotspot) {
		_cursorManager->revertToIdle();
	}
}

void ZVision::onKeyDown(uint keyCode) {

}

} // End of namespace ZVision
