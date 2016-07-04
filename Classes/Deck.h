//
//  Deck.hpp
//  NewCocosProject
//
//  Created by developer on 2016/06/30.
//
//

#ifndef Deck_hpp
#define Deck_hpp

#include <stdio.h>
#include "Common.h"
#include "Card.h"

class Deck : public cocos2d::Ref
{
public:
    CREATE_FUNC(Deck);
    
    void setAllCard();      //デッキにカードをセット
    Card * dealCard();      //カードを1枚配る
    void shuffle();         //シャッフル
    
private:
    Deck();         //コンストラクタ
    ~Deck();        //デストラクタ
    bool init();    //初期化処理
    
    cocos2d::Vector<Card *> deckData;
};

#endif /* Deck_hpp */
