//
//  TitleScene.cpp
//  NewCocosProject
//
//  Created by developer on 2016/06/30.
//
//

#include "TitleScene.h"
#include "GameScene.h"
#include "audio/include/AudioEngine.h"

USING_NS_CC;

Scene *TitleScene::createScene()
{
    //シーンオブジェクトを生成
    Scene *scene { Scene::create() };
    
    //レイヤーオブジェクトを生成
    Layer *layer { TitleScene::create() };
    
    //レイヤーオブジェクトをシーンに配置

    scene->addChild(layer);
    
    return scene;
}
bool TitleScene::init()
{
    //初期化処理に失敗したらfalseを返す
    if(!Layer::init())
    {
        return false;
    }
    
    //画面サイズを取得
    Size visibleSize { Director::getInstance()->getVisibleSize() };
    
    //背景画像の表示
    Sprite *bgsprite { Sprite::create("title_bg.png") };        //スプライトの生成
    bgsprite->setPosition(visibleSize / 2);                     //スプライトの表示位置を設定
    this->addChild(bgsprite);                                   //スプライトを画面に配置
    
    //ロゴ
    Sprite *logosprite { Sprite::create("title_logo.png") };
    logosprite->setPosition(Vec2(568.0f, 400.0f));
    this->addChild(logosprite);
    
    //スタートボタン
    ui::Button *startButton { ui::Button::create("title_start.png") };
    startButton->setPosition(Vec2(568.0f, 130.0f));
    this->addChild(startButton);
    
    startButton->addTouchEventListener(CC_CALLBACK_2(TitleScene::touchEvent, this));
    
    //BGMを鳴らす
    cocos2d::experimental::AudioEngine::play2d("title.wav", true);
    
    return true;
}

//ボタンのタッチイベント
void TitleScene::touchEvent(Ref *ref, ui::Widget::TouchEventType type)
{
    switch (type)
    {
        case ui::Widget::TouchEventType::BEGAN:
        {
            //音楽を止める
            cocos2d::experimental::AudioEngine::stopAll();
            
            //SEを鳴らす
            cocos2d::experimental::AudioEngine::play2d("se_coin.wav", false);
            
            Scene *gameScene { GameScene::CreateScene() };                      //シーンオブジェクトを生成
            TransitionFade *fade = TransitionFade::create(1.0f, gameScene);     //フェード処理
            Director::getInstance()->replaceScene(fade);                        //シーンを置き換える
            break;
        }
            
        default:
            break;
    }
}