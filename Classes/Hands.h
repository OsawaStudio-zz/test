//
//  Hands.hpp
//  NewCocosProject
//
//  Created by developer on 2016/07/01.
//
//

#ifndef Hands_hpp
#define Hands_hpp

#include "Card.h"
#include "Common.h"

class Hands : public cocos2d::Ref
{
public:
    CREATE_FUNC(Hands);
    void setCard(int n, Card *card);    //手札のn番目にカードをセット
    Card *getCard(int n) const;         //手札のn番目のカードを取得
    
    bool toggleHold(int n);             //HOLD状態を切り替える
    bool isHold(int n) const;           //HOLD状態を取得
    
    void dicisionHand();                //役の確定
    Hand getHand() const;               //役の取得
    int getRate() const;                //配当の取得
    
private:
    Hands();        //コンストラクタ
    ~Hands();       //デストラクタ
    bool init();    //初期化処理
    
//構造体
struct CardState : Ref
{
    Card *card;
    bool hold;
        
    static CardState *create(Card *card, bool hold)
    {
        CardState *cardState = new CardState();
        CC_SAFE_RETAIN(cardState);
        cardState->card = card;
        CC_SAFE_RETAIN(cardState->card);
        cardState->hold = hold;
            
        return std::move(cardState);
    }
};
    
    cocos2d::Map<int, CardState*> cards {};
    Hand hand { Hand::NOTHING };            //役
    
};

#endif /* Hands_hpp */
