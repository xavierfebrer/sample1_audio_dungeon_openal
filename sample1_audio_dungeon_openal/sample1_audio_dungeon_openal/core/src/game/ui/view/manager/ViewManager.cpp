#include "../../../../../include/ViewManager.h"
#include "../../../../../include/Hack3dEngine.h"

ViewManager::ViewManager(Game & game) : game(game) {
	for (int i = 0; i < Input::MAX_POINTERS; i++) {
		pointerEvents.push_back(std::make_unique<PointerEventInfo>(i));
	}
}

ViewManager::~ViewManager() {
	clear();
}

void ViewManager::addView(const std::shared_ptr<View> & view) {
	views.push_back(view);
}

int ViewManager::removeView(const std::shared_ptr<View> & view) {
	int deletedPointer = 0;
	size_t sizeCurrentViews = views.size();
	if (sizeCurrentViews > 0) {
		for (size_t i = sizeCurrentViews - 1; i >= 0; i--) {
			if (views[i] == view) {
				views.erase(views.begin() + i);
				++deletedPointer;
			}
		}
	}
	return deletedPointer;
}

void ViewManager::clear() {
	views.clear();
}

void ViewManager::update(double deltaTime) {
	updateInput(deltaTime);
	updateState(deltaTime);
}

void ViewManager::updateInput(double deltaTime) {
	updatePointerEvents(deltaTime);
	sendPointerEventData(deltaTime);
}

void ViewManager::updatePointerEvents(double deltaTime) {
	for (int i = 0; i < pointerEvents.size(); ++i) {
		PointerEventInfo & pointerEventInfo = *pointerEvents[i];
		if (Hack3dEngine::get()->input->isPointerPressed(i)) {
			if (pointerEventInfo.pointerEvent == PointerEvent::IDLE) {
				pointerEventInfo.pointerEvent = PointerEvent::DOWN;
			} else if (pointerEventInfo.pointerEvent == PointerEvent::DOWN) {
				pointerEventInfo.pointerEvent = PointerEvent::MOVED;
			} else {
				pointerEventInfo.pointerEvent = PointerEvent::MOVED;
			}
		} else {
			if (pointerEventInfo.pointerEvent != PointerEvent::IDLE && pointerEventInfo.pointerEvent != PointerEvent::UP) {
				pointerEventInfo.pointerEvent = PointerEvent::UP;
			} else {
				pointerEventInfo.pointerEvent = PointerEvent::IDLE;
			}
		}
		const PointerInfo& pointerPos = Hack3dEngine::get()->input->getPointerInfo(i);
		pointerEventInfo.xScreen = pointerPos.x;
		pointerEventInfo.yScreen = pointerPos.y;

		Vec2<> worldPos(pointerPos.x, pointerPos.y);

		pointerEventInfo.xViewCamera = worldPos.x;
		pointerEventInfo.yViewCamera = worldPos.y;
	}
}

void ViewManager::sendPointerEventData(double deltaTime) {
	bool consumed;
	size_t sizeCurrentViews = views.size();
	if (sizeCurrentViews > 0) {
		for (size_t i = 0; i < pointerEvents.size(); ++i) {
			PointerEventInfo & pointerEventInfo = *pointerEvents[i];
			consumed = false;
			for (size_t j = sizeCurrentViews - 1; j >= 0; --j) {
				if (views[j]->input(deltaTime, pointerEventInfo, consumed)) {
					consumed = true;
				}
			}
		}
	}
}

void ViewManager::updateState(double deltaTime) {
	for (std::shared_ptr<View> view : views) {
		view->update(deltaTime);
	}
}

void ViewManager::render(double deltaTime) {
	for (std::shared_ptr<View> view : views) {
		view->render(deltaTime);
	}
}

void ViewManager::resume() {
	for (std::shared_ptr<View> view : views) {
		view->resume();
	}
}

void ViewManager::pause() {
	for (std::shared_ptr<View> view : views) {
		view->pause();
	}
}
