#pragma once

#include "View.h"
#include "Animation.h"
#include "Padding.h"
#include "OnClickListener.h"
#include "../include/CollisionUtil.h"

class Button : public View {
public:
	enum class PressedState {
		NO_PRESSED,
		PRESSED
	};

	enum class ButtonEvent {
		ON_PRESSED,
		ON_RELEASED,
		NONE
	};
	std::string text;
	MyColor textColor = MyColor(1, 1, 1, 1);
	bool inheritTextAlphaFromView = true;

	Button(const std::shared_ptr<Graphics> & graphics, double x, double y, double width, double height,
		const Padding & padding = Padding(),
		const std::string & text = "",
		const std::shared_ptr<Animation> & animBGUnpressed = nullptr,
		const std::shared_ptr<Animation> & animBGPressed = nullptr,
		const std::shared_ptr<Animation> & animBGDisabled = nullptr,
		const std::shared_ptr<Animation> & animContentUnpressed = nullptr,
		const std::shared_ptr<Animation> & animContentPressed = nullptr,
		const std::shared_ptr<Animation> & animContentDisabled = nullptr,
		const std::shared_ptr<OnClickListener> & onClickListener = nullptr);
	virtual ~Button();

	virtual void resume() override;
	virtual bool input(double deltaTime, const PointerEventInfo& pointerEventInfo, bool consumed) override;
	virtual void update(double deltaTime) override;
	virtual void render(double deltaTime) override;
	virtual void pause() override;
	virtual void setEnabled(bool enabled) override;
	void restartViewAnimations();
	void setPadding(const Padding & padding);
	const Padding & getPadding();
	double getPaddingWidth();
	double getPaddingHeight();
	bool isPressed();
private:
	std::shared_ptr<Animation> animBGUnpressed;
	std::shared_ptr<Animation> animBGPressed;
	std::shared_ptr<Animation> animBGDisabled;
	std::shared_ptr<Animation> animContentUnpressed;
	std::shared_ptr<Animation> animContentPressed;
	std::shared_ptr<Animation> animContentDisabled;
	Padding padding;
	PressedState prevPressedState;
	PressedState pressedState;
	ButtonEvent currentEvent;
	std::shared_ptr<OnClickListener> onClickListener;

	bool updateInput(double deltaTime, const PointerEventInfo & pointerEventInfo);
	ButtonEvent updateInputInternal(double deltaTime, const PointerEventInfo & pointerEventInfo);
	void updateViewAnimations(double deltaTime);
};
