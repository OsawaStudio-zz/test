//
//  Card.hpp
//  NewCocosProject
//
//  Created by developer on 2016/06/30.
//
//

#ifndef Card_hpp
#define Card_hpp

#include "Common.h"
#include "cocos2d.h"

class Card : public cocos2d::Ref
{
public:
    static Card *create(Suit suit, int number);
    Suit getSuit() const;                   //マークを取得
    int getNumber() const;                  //数字を取得
    std::string getFileName() const;        //ファイル名を取得
    
private:
    Card();     //コンストラクタ
    ~Card();    //デストラクタ
    bool init(Suit suit, int number);       //初期化処理

    Suit suit;      //カードのマーク
    int number;     //カードの数学
};

#endif /* Card_hpp */
