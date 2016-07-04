//
//  TitleScene.cpp
//  NewCocosProject
//
//  Created by developer on 2016/06/30.
//
//

#include "TitleScene.h"
#include "GameScene.h"

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
    Sprite *bgsprite { Sprite::create("title_bg.png") };
    bgsprite->setPosition(visibleSize / 2);
    this->addChild(bgsprite);
    
    //ロゴ
    Sprite *logosprite { Sprite::create("title_logo.png") };
    logosprite->setPosition(Vec2(568.0f, 400.0f));
    this->addChild(logosprite);
    
    //スタートボタン
    ui::Button *startButton { ui::Button::create("title_start.png") };
    startButton->setPosition(Vec2(568.0f, 130.0f));
    this->addChild(startButton);
    
    startButton->addTouchEventListener(CC_CALLBACK_2(TitleScene::touchEvent, this));
    
    return true;
}

//ボタンのタッチイベント
void TitleScene::touchEvent(Ref *ref, ui::Widget::TouchEventType type)
{
    switch (type)
    {
        case ui::Widget::TouchEventType::BEGAN:
        {
            Scene *gameScene { GameScene::CreateScene() };
            TransitionFade *fade = TransitionFade::create(1.0f, gameScene);
            Director::getInstance()->replaceScene(fade);
            break;
        }
            
        default:
            break;
    }
}












