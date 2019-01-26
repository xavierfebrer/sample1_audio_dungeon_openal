#pragma once

#include "BaseScreen.h"
#include "MainMenuScreen.h"
#include "../../core/include/OpenALSound.h"

class EndScreen : public BaseScreen {
public:
	EndScreen(Game & game, bool win);
	virtual ~EndScreen() override;

	virtual void create() override;
	virtual void resume() override;
	virtual void update(double deltaTime) override;
	virtual void render(double deltaTime) override;
	virtual void pause() override;
protected:
	virtual void initViews() override;
private:
	bool win;
	std::shared_ptr<OpenALSound> endMusic = nullptr;

	void openMainMenuScreen();

	class ButtonBackOnClickListener : public OnClickListener {
	private:
		EndScreen & screen;
	public:
		ButtonBackOnClickListener(EndScreen & screen) : OnClickListener(), screen(screen) {
		}
		virtual ~ButtonBackOnClickListener() override {
		}
		virtual void onClickDown(View & view) override {
		}
		virtual void onClickUp(View & view) override {
			screen.openMainMenuScreen();
		}
	};
};
