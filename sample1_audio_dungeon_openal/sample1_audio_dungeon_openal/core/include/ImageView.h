#pragma once

#include "View.h"
#include "Animation.h"
#include "Padding.h"

class ImageView : public View {
public:
	std::string text;
	MyColor textColor = MyColor(1, 1, 1, 1);
	bool inheritTextAlphaFromView = true;

	ImageView(const std::shared_ptr<Graphics> & graphics, double x, double y, double width, double height,
		const Padding & padding = Padding(),
		const std::string & text = "",
		std::unique_ptr<Animation> animBG = nullptr,
		std::unique_ptr<Animation> animBGDisabled = nullptr,
		std::unique_ptr<Animation> animContent = nullptr,
		std::unique_ptr<Animation> animContentDisabled = nullptr);
	virtual ~ImageView() override;

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
private:
	std::unique_ptr<Animation> animBG;
	std::unique_ptr<Animation> animBGDisabled;
	std::unique_ptr<Animation> animContent;
	std::unique_ptr<Animation> animContentDisabled;
	Padding padding;

	void updateViewAnimations(double deltaTime);
};

