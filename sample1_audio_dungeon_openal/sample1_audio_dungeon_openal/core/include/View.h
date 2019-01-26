#pragma once

#include "Util.h"
#include "Graphics.h"
#include "AlphaEaseAnimation.h"
#include "MoveEaseAnimation.h"

class View {
private:
	bool enabled;
	double alpha;
protected:
	Rect<> bounds;
	std::shared_ptr<Graphics> graphics;
	std::unique_ptr<AlphaEaseAnimation> alphaAnimation;
	std::unique_ptr<MoveEaseAnimation> moveAnimation;
public:
	static const double MIN_ALPHA;
	static const double MAX_ALPHA;

	View(const std::shared_ptr<Graphics> & graphics, double x, double y, double width, double height);
	virtual ~View();

	virtual void resume() = 0;
	virtual bool input(double deltaTime, const PointerEventInfo& pointerEventInfo, bool consumed) = 0;
	virtual void update(double deltaTime);
	virtual void render(double deltaTime) = 0;
	virtual void pause() = 0;
	const bool isEnabled();
	virtual void setEnabled(bool enabled);
	const double getAlpha();
	void setAlpha(double alpha);
	void incAlpha(double deltaAlpha);
	const double getX();
	void setX(double x);
	void incX(double deltaX);
	const double getY();
	void setY(double y);
	void incY(double deltaY);
	void setPos(double x, double y);
	void setPos(const Vec2<> & pos);
	void incPos(double deltaX, double deltaY);
	const double getWidth();
	void setWidth(double width);
	void incWidth(double deltaWidth);
	const double getHeight();
	void setHeight(double height);
	void incHeight(double deltaHeight);
	void setSize(double width, double height);
	void setSize(const Vec2<> & size);
	void set(double x, double y, double width, double height);
	void set(const Vec2<> & pos, const Vec2<> & size);
	void set(const Rect<> & bounds);
	const Rect<> & getBounds();
	void setAlphaAnimation(double start, double end, double startDelay, double duration,
		std::unique_ptr<Ease> ease, const std::shared_ptr<AlphaAnimationListener> & listener);
	void setMoveAnimation(const Vec2<> & start, const Vec2<> & end, double startDelay, double duration,
		std::unique_ptr<Ease> ease, const std::shared_ptr<MoveAnimationListener> & listener);

	class InnerAlphaAnimationListener : public AlphaAnimationListener {
	private:
		View& view;
		std::shared_ptr<AlphaAnimationListener> listener;
	public:
		InnerAlphaAnimationListener(View& view, const std::shared_ptr<AlphaAnimationListener> & listener)
			: AlphaAnimationListener(), view(view), listener(listener) {
		}

		virtual ~InnerAlphaAnimationListener() override {
		}

		virtual void onAnimationStarted(double value) {
			view.setAlpha(value);
			if (listener) {
				listener->onAnimationStarted(value);
			}
		}
		virtual void onAnimationUpdated(double value) {
			view.setAlpha(value);
			if (listener) {
				listener->onAnimationUpdated(value);
			}
		}
		virtual void onAnimationEnded(double value) {
			view.setAlpha(value);
			if (listener) {
				listener->onAnimationEnded(value);
			}
		}
	};

	class InnerMoveAnimationListener : public MoveAnimationListener {
	private:
		View& view;
		std::shared_ptr<MoveAnimationListener> listener;
	public:
		InnerMoveAnimationListener(View& view, const std::shared_ptr<MoveAnimationListener> & listener)
			: MoveAnimationListener(), view(view), listener(listener) {
		}

		virtual ~InnerMoveAnimationListener() override {
		}

		virtual void onAnimationStarted(const Vec2<> & value) {
			view.setPos(value);
			if (listener) {
				listener->onAnimationStarted(value);
			}
		}
		virtual void onAnimationUpdated(const Vec2<> & value) {
			view.setPos(value);
			if (listener) {
				listener->onAnimationUpdated(value);
			}
		}
		virtual void onAnimationEnded(const Vec2<> & value) {
			view.setPos(value);
			if (listener) {
				listener->onAnimationEnded(value);
			}
		}
	};
};
