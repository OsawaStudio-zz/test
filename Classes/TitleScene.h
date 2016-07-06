//
//  TitleScene.hpp
//  NewCocosProject
//
//  Created by developer on 2016/06/30.
//
//

#ifndef TitleScene_hpp
#define TitleScene_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"

class TitleScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene *createScene();
    virtual bool init();        //初期化処理
    CREATE_FUNC(TitleScene);    //クリエイト関数
    
    //ボタンのタッチイベント
    void touchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
};

#endif /* TitleScene_hpp */
