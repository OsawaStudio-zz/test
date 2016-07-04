//
//  GameScene.hpp
//  NewCocosProject
//
//  Created by developer on 2016/06/30.
//
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include <stdio.h>
#include "ui/CocosGUI.h"
#include "Deck.h"
#include "Hands.h"

USING_NS_CC;

class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene *CreateScene();
    
private:
    GameScene();                //コンストラクタ
    ~GameScene();               //デストラクタ
    virtual bool init();        //初期化処理
    void setupScreen();         //画面の設定
    void setupGame();           //ゲームの初期設定
    void changeScreen();        //ゲームのステータスに応じた画面制御
    void updateCredit();        //creditを更新する
    void setHandSprite();       //役に応じた画像を設定する
    void betAction();           //BETした時のアクション
    
    void onBetButtonTouched(Ref *pSender, ui::Widget::TouchEventType type);     //BETボタンがタッチされた
    void onDealButtonTouched(Ref *pSender, ui::Widget::TouchEventType type);    //DEALボタンがタッチされた
    void onHoldButtonTouched(Ref *pSender, ui::Widget::TouchEventType type);    //HOLDボタンがタッチされた
    
    void dealAction();                      //DEAL時のアクション
    
    void cardAction(Sprite *sprite, GameStatus nextStatus, bool isLast);     //カードのアクションを実行する
    
    
    CREATE_FUNC(GameScene);
    
    GameStatus gameStatus;                  //ゲームのステータス
    
    int credit { 0 };                       //クレジット数
    int win { 0 };                          //WIN数
    
    Deck *deck { nullptr };                 //デッキ
    Hands *hands { nullptr };               //手札
    
    Label *winLabel { nullptr };            //WINラベル
    Label *creditLabel { nullptr };         //Creditラベル
    
    Sprite *rateText { nullptr };           //役名
    Sprite *rateBg { nullptr };             //役名の背景
    
    Vector<Sprite*> cardSprites {};          //手札のスプライト
    
    ui::Button *betButton { nullptr };      //BETボタン
    ui::Button *dealButton { nullptr };     //DEALボタン
    Vector<ui::Button *> holdButtons {};    //HOLDボタン
    
    Vector<Sprite *> holdSprites;           //HOLD画像
};

#endif /* GameScene_hpp */
