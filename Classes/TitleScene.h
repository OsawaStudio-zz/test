//
// Created by mk2382 on 2016/06/30.
//

#ifndef _TITLESCENE_H
#define _TITLESCENE_H

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class TitleScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene *createScene();
    virtual bool init();
    CREATE_FUNC(TitleScene);

    //ボタンのタッチイベント
    void touchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);


};

#endif
