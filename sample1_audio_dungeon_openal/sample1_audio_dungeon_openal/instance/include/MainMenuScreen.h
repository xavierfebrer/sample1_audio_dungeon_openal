#pragma once

#include "BaseScreen.h"
#include "GameScreen.h"

class MainMenuScreen : public BaseScreen {
public:
	MainMenuScreen(Game & game);
	virtual ~MainMenuScreen() override;

	virtual void create() override;
	virtual void resume() override;
	virtual void update(double deltaTime) override;
	virtual void render(double deltaTime) override;
	virtual void pause() override;
protected:
	virtual void initViews() override;
private:
	void openGameScreen();
	void exitGame();

	class ButtonPlayOnClickListener : public OnClickListener {
	private:
		MainMenuScreen & screen;
	public:
		ButtonPlayOnClickListener(MainMenuScreen & screen) : OnClickListener(), screen(screen) {
		}
		virtual ~ButtonPlayOnClickListener() override {
		}
		virtual void onClickDown(View & view) override {
		}
		virtual void onClickUp(View & view) override {
			screen.openGameScreen();
		}
	};
	class ButtonExitOnClickListener : public OnClickListener {
	private:
		MainMenuScreen & screen;
	public:
		ButtonExitOnClickListener(MainMenuScreen & screen) : OnClickListener(), screen(screen) {
		}
		virtual ~ButtonExitOnClickListener() override {
		}
		virtual void onClickDown(View & view) override {
		}
		virtual void onClickUp(View & view) override {
			screen.exitGame();
		}
	};
};
