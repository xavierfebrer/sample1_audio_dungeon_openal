#include "../../../../include/View.h"

const double View::MIN_ALPHA = 0;
const double View::MAX_ALPHA = 1;

View::View(const std::shared_ptr<Graphics> & graphics, double x, double y, double w, double h) : graphics(graphics), bounds(x, y, w, h) {
	setEnabled(true);
	setAlpha(View::MAX_ALPHA);
}

View::~View() {
}

void View::update(double deltaTime) {
	if (alphaAnimation) {
		alphaAnimation->update(deltaTime);
	}
	if (moveAnimation) {
		moveAnimation->update(deltaTime);
	}
}

const bool View::isEnabled() {
	return enabled;
}

void View::setEnabled(bool enabled) {
	this->enabled = enabled;
}

const double View::getAlpha() {
	return alpha;
}

void View::setAlpha(double alpha) {
	this->alpha = Util::minMax(alpha, View::MIN_ALPHA, View::MAX_ALPHA);
}

void View::incAlpha(double deltaAlpha) {
	setAlpha(getAlpha() + deltaAlpha);
}

const double View::getX() {
	return this->bounds.x;
}

void View::setX(double x) {
	this->bounds.x = x;
}

void View::incX(double deltaX) {
	setX(getX() + deltaX);
}

const double View::getY() {
	return this->bounds.y;
}

void View::setY(double y) {
	this->bounds.y = y;
}

void View::incY(double deltaY) {
	setY(getY() + deltaY);
}

void View::setPos(double x, double y) {
	setX(x);
	setY(y);
}

void View::setPos(const Vec2<> & pos) {
	setX(pos.x);
	setY(pos.y);
}

void View::incPos(double deltaX, double deltaY) {
	setPos(getX() + deltaX, getY() + deltaY);
}

const double View::getWidth() {
	return this->bounds.w;
}

void View::setWidth(double w) {
	this->bounds.w = w;
}

void View::incWidth(double deltaW) {
	setWidth(getWidth() + deltaW);
}

const double View::getHeight() {
	return this->bounds.h;
}

void View::setHeight(double h) {
	this->bounds.h = h;
}

void View::incHeight(double deltaH) {
	setHeight(getHeight() + deltaH);
}

void View::setSize(double w, double h) {
	setWidth(w);
	setHeight(h);
}

void View::setSize(const Vec2<>& size) {
	setWidth(size.x);
	setHeight(size.y);
}

void View::set(double x, double y, double w, double h) {
	setPos(x, y);
	setPos(w, h);
}

void View::set(const Vec2<>& pos, const Vec2<>& size) {
	setPos(pos);
	setSize(size);
}

void View::set(const Rect<>& bounds) {
	this->bounds = bounds;
}

const Rect<>& View::getBounds() {
	return bounds;
}

void View::setAlphaAnimation(double start, double end, double startDelay, double duration, std::unique_ptr<Ease> ease, const std::shared_ptr<AlphaAnimationListener> & listener) {
	alphaAnimation.reset(new AlphaEaseAnimation(start, end, startDelay, duration, std::move(ease),
		std::make_shared<InnerAlphaAnimationListener>(*this, listener)));
}

void View::setMoveAnimation(const Vec2<>& start, const Vec2<>& end, double startDelay, double duration, std::unique_ptr<Ease> ease, const std::shared_ptr<MoveAnimationListener> & listener) {
	moveAnimation.reset(new MoveEaseAnimation(start, end, startDelay, duration, std::move(ease),
		std::make_shared<InnerMoveAnimationListener>(*this, listener)));
}
