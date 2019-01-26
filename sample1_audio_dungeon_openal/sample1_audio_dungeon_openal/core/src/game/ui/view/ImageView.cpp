#include "../../../../include/ImageView.h"

ImageView::ImageView(const std::shared_ptr<Graphics> & graphics, double x, double y, double width, double height,
	const Padding & padding, const std::string & text,
	std::unique_ptr<Animation> animBG,
	std::unique_ptr<Animation> animBGDisabled,
	std::unique_ptr<Animation> animContent,
	std::unique_ptr<Animation> animContentDisabled)
	: View(graphics, x, y, width, height),
	animBG(std::move(animBG)), animBGDisabled(std::move(animBGDisabled)), animContent(std::move(animContent)), animContentDisabled(std::move(animContentDisabled)),
	padding(padding), text(text) {
	setEnabled(true);
}

ImageView::~ImageView() {
}

void ImageView::resume() {
}

bool ImageView::input(double deltaTime, const PointerEventInfo & pointerEventInfo, bool consumed) {
	return false;
}

void ImageView::update(double deltaTime) {
	View::update(deltaTime);
	updateViewAnimations(deltaTime);
}

void ImageView::updateViewAnimations(double deltaTime) {
	if (isEnabled()) {
		if (animBG) {
			animBG->update(deltaTime);
		}
		if (animContent) {
			animContent->update(deltaTime);
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

void ImageView::render(double deltaTime) {
	if (isEnabled()) {
		if (animBG) {
			graphics->render(animBG->getCurrentStep().getItem(),
				bounds.x,
				bounds.y,
				bounds.w,
				bounds.h,
				0,
				getAlpha());
		}
		if (animContent) {
			graphics->render(animContent->getCurrentStep().getItem(),
				bounds.x + (bounds.w - getPaddingWidth()) * 0.5,
				bounds.y + (bounds.h - getPaddingHeight()) * 0.5,
				getPaddingWidth(),
				getPaddingHeight(),
				0,
				getAlpha());
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

void ImageView::pause() {
}

void ImageView::setEnabled(bool enabled) {
	if (enabled && !isEnabled()) {
		restartViewAnimations();
	}
	View::setEnabled(enabled);
}

void ImageView::restartViewAnimations() {
	if (animBG) {
		animBG->restart();
	}
	if (animContent) {
		animContent->restart();
	}
	if (animBGDisabled) {
		animBGDisabled->restart();
	}
	if (animContentDisabled) {
		animContentDisabled->restart();
	}
}

void  ImageView::setPadding(const Padding & padding) {
	this->padding = padding;
}

const Padding & ImageView::getPadding() {
	return padding;
}

double ImageView::getPaddingWidth() {
	return bounds.w * padding.getHorizontalPercent();
}

double ImageView::getPaddingHeight() {
	return bounds.h * padding.getVerticalPercent();
}
