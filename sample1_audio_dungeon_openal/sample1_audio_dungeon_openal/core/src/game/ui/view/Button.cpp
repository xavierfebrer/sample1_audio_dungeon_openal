#include "../../../../include/Button.h"

Button::Button(const std::shared_ptr<Graphics> & graphics, double x, double y, double width, double height,
	const Padding & padding,
	const std::string & text,
	const std::shared_ptr<Animation> & animBGUnpressed,
	const std::shared_ptr<Animation> & animBGPressed,
	const std::shared_ptr<Animation> & animBGDisabled,
	const std::shared_ptr<Animation> & animContentUnpressed,
	const std::shared_ptr<Animation> & animContentPressed,
	const std::shared_ptr<Animation> & animContentDisabled,
	const std::shared_ptr<OnClickListener> & onClickListener)
	: View(graphics, x, y, width, height),
	animBGUnpressed(animBGUnpressed), animBGPressed(animBGPressed), animBGDisabled(animBGDisabled),
	animContentUnpressed(animContentUnpressed), animContentPressed(animContentPressed), animContentDisabled(animContentDisabled), padding(padding),
	onClickListener(onClickListener), text(text) {
	prevPressedState = PressedState::NO_PRESSED;
	pressedState = PressedState::NO_PRESSED;
	setEnabled(true);
}

Button::~Button() {
}

void Button::resume() {
}

bool Button::input(double deltaTime, const PointerEventInfo & pointerEventInfo, bool consumed) {
	if (pointerEventInfo.pointerIndex == 0) {	// buttons only accept the main pointer to not confuse the user with mutliple indexes pressing multiple items, to simplify things
		if (!consumed) {
			return updateInput(deltaTime, pointerEventInfo);
		} else {
			restartViewAnimations();
			prevPressedState = PressedState::NO_PRESSED;
			pressedState = PressedState::NO_PRESSED;
			return true;
		}
	} else {
		return false;
	}
}

bool Button::updateInput(double deltaTime, const PointerEventInfo & pointerEventInfo) {
	if (isEnabled()) {
		currentEvent = updateInputInternal(deltaTime, pointerEventInfo);
		if (currentEvent != ButtonEvent::NONE) {
			restartViewAnimations();
			if (currentEvent == ButtonEvent::ON_PRESSED) {
				if (onClickListener) {
					onClickListener->onClickDown(*this);
				}
			} else if (currentEvent == ButtonEvent::ON_RELEASED) {
				if (onClickListener) {
					onClickListener->onClickUp(*this);
				}
			}
		}
	}
	return pressedState == PressedState::PRESSED;
}

Button::ButtonEvent Button::updateInputInternal(double deltaTime, const PointerEventInfo & pointerEventInfo) {
	currentEvent = ButtonEvent::NONE;
	if (prevPressedState == PressedState::NO_PRESSED) {
		if (pointerEventInfo.pointerEvent != PointerEvent::IDLE
			&& pointerEventInfo.pointerEvent != PointerEvent::UP
			&& CollisionUtil<>::collision(pointerEventInfo.xViewCamera, pointerEventInfo.yViewCamera, bounds)) {
			pressedState = PressedState::PRESSED;
			currentEvent = ButtonEvent::ON_PRESSED;
		}
	} else if (prevPressedState == PressedState::PRESSED) {
		if (pointerEventInfo.pointerEvent != PointerEvent::IDLE && pointerEventInfo.pointerEvent != PointerEvent::UP) {
			if (!CollisionUtil<>::collision(pointerEventInfo.xViewCamera, pointerEventInfo.yViewCamera, bounds)) {
				pressedState = PressedState::NO_PRESSED;
			}
		} else {
			if (CollisionUtil<>::collision(pointerEventInfo.xViewCamera, pointerEventInfo.yViewCamera, bounds)) {
				currentEvent = ButtonEvent::ON_RELEASED;
			}
			pressedState = PressedState::NO_PRESSED;
		}
	}
	prevPressedState = pressedState;
	return currentEvent;
}

void Button::update(double deltaTime) {
	View::update(deltaTime);
	updateViewAnimations(deltaTime);
}

void Button::updateViewAnimations(double deltaTime) {
	if (isEnabled()) {
		if (pressedState == PressedState::NO_PRESSED) {
			if (animBGUnpressed) {
				animBGUnpressed->update(deltaTime);
			}
			if (animContentUnpressed) {
				animContentUnpressed->update(deltaTime);
			}
		} else {
			if (animBGPressed) {
				animBGPressed->update(deltaTime);
			}
			if (animContentPressed) {
				animContentPressed->update(deltaTime);
			}
		}
	} else {
		if (animBGDisabled) {
			animBGDisabled->update(deltaTime);
		}
		if (animContentDisabled) {
			animContentDisabled->update(deltaTime);
		}
	}
}

void Button::render(double deltaTime) {
	if (isEnabled()) {
		if (pressedState == PressedState::NO_PRESSED) {
			if (animBGUnpressed) {
				graphics->render(animBGUnpressed->getCurrentStep().getItem(),
					bounds.x,
					bounds.y,
					bounds.w,
					bounds.h,
					0,
					getAlpha());
			}
			if (animContentUnpressed) {
				graphics->render(animContentUnpressed->getCurrentStep().getItem(),
					bounds.x + (bounds.w - getPaddingWidth()) * 0.5,
					bounds.y + (bounds.h - getPaddingHeight()) * 0.5,
					getPaddingWidth(),
					getPaddingHeight(),
					0,
					getAlpha());
			}
		} else {
			if (animBGPressed) {
				graphics->render(animBGPressed->getCurrentStep().getItem(),
					bounds.x,
					bounds.y,
					bounds.w,
					bounds.h,
					0,
					getAlpha());
			}
			if (animContentPressed) {
				graphics->render(animContentPressed->getCurrentStep().getItem(),
					bounds.x + (bounds.w - getPaddingWidth()) * 0.5,
					bounds.y + (bounds.h - getPaddingHeight()) * 0.5,
					getPaddingWidth(),
					getPaddingHeight(),
					0,
					getAlpha());
			}
		}
	} else {
		if (animBGDisabled) {
			graphics->render(animBGDisabled->getCurrentStep().getItem(),
				bounds.x,
				bounds.y,
				bounds.w,
				bounds.h,
				0,
				getAlpha());
		}
		if (animContentDisabled) {
			graphics->render(animContentDisabled->getCurrentStep().getItem(),
				bounds.x + (bounds.w - getPaddingWidth()) * 0.5,
				bounds.y + (bounds.h - getPaddingHeight()) * 0.5,
				getPaddingWidth(),
				getPaddingHeight(),
				0,
				getAlpha());
		}
	}
}

void Button::pause() {
}

void Button::setEnabled(bool enabled) {
	if (enabled && !isEnabled()) {
		restartViewAnimations();
	}
	View::setEnabled(enabled);
	if (!isEnabled()) {
		prevPressedState = PressedState::NO_PRESSED;
		pressedState = PressedState::NO_PRESSED;
	}
}

void Button::restartViewAnimations() {
	if (animBGUnpressed) {
		animBGUnpressed->restart();
	}
	if (animBGPressed) {
		animBGPressed->restart();
	}
	if (animBGDisabled) {
		animBGDisabled->restart();
	}
	if (animContentUnpressed) {
		animContentUnpressed->restart();
	}
	if (animContentPressed) {
		animContentPressed->restart();
	}
	if (animContentDisabled) {
		animContentDisabled->restart();
	}
}

void  Button::setPadding(const Padding & padding) {
	this->padding = padding;
}

const Padding & Button::getPadding() {
	return padding;
}

double Button::getPaddingWidth() {
	return bounds.w * padding.getHorizontalPercent();
}

double Button::getPaddingHeight() {
	return bounds.h * padding.getVerticalPercent();
}

bool Button::isPressed() {
	return pressedState == PressedState::PRESSED && isEnabled();
}