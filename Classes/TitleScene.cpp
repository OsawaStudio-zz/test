//
// Created by mk2382 on 2016/06/30.
//

#include "TitleScene.h"

USING_NS_CC;

Scene *TitleScene::createScene()
{
    Scene *scene { Scene::create() };

    Layer *layer { TitleScene::create() };

    scene->addChild(layer);

    return scene;
}

bool TitleScene::init()
{
    if(!Layer::init())
    {
        return false;
    }

    //画面サイズ
    Size visibleSize { Director::getInstance()->getVisibleSize() };

    //背景
    Sprite *bgSprite { Sprite::create("title_bg.png") };
    bgSprite->setPosition(visibleSize / 2);
    this->addChild(bgSprite);

    //ロゴ
    Sprite *logoSprite { Sprite::create("title_logo.png") };
    logoSprite->setPosition(Vec2(568.0f, 400.0f));
    this->addChild(logoSprite);

    //スタートボタンを追加
    ui::Button *startButton { ui::Button::create("title_start.png") };
    startButton->setPosition(Vec2(568.0f, 130.0f));
    this->addChild(startButton);
    startButton->addTouchEventListener(CC_CALLBACK_2(TitleScene::touchEvent, this));

    return true;
}

//ボタンのタッチイベント
void TitleScene::touchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
    switch(type)
    {
        case ui::Widget::TouchEventType::BEGAN:
        {
            CCLOG("ボタンが押されました");
            break;
        }

        default:
        break;
    }
}