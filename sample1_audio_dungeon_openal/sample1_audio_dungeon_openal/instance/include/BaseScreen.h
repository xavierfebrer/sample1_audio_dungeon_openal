#pragma once

#include "../../core/include/Screen.h"
#include "../../core/include/ImageView.h"
#include "../../core/include/Button.h"
#include "../../core/include/LinearEase.h"

class BaseScreen : public Screen {
public:
	BaseScreen(Game & game);
	virtual ~BaseScreen() override;

	virtual void create() override;
	virtual void resume() override;
	virtual void update(double deltaTime) override;
	virtual void render(double deltaTime) override;
	virtual void pause() override;
protected:
	virtual void initViews() = 0;
};
