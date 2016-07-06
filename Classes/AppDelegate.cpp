#include "AppDelegate.h"
#include "TitleScene.h"

USING_NS_CC;

//コンストラクタ
AppDelegate::AppDelegate()
{}

//デストラクタ
AppDelegate::~AppDelegate() 
{}

//OpneGLのコンテキストを初期化
void AppDelegate::initGLContextAttrs()
{
    //初期化 : {RED, GREEN, BLUE, ALPHA, DEPTH, STENCIL}
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    //設定
    GLView::setGLContextAttrs(glContextAttrs);
}

//Directorクラスとシーンの初期化
bool AppDelegate::applicationDidFinishLaunching()
{
    auto director = Director::getInstance();        //Directorクラスの初期化
    auto glview = director->getOpenGLView();        //OpenGLViewの機能を取得
    
    //glviewがNULLではない場合
    if(!glview)
    {
        //ウィンドウの名前と画面サイズを設定 : ("WindowName", Rect(x, y, width, height))
        glview = GLViewImpl::createWithRect("HelloCpp", Rect(0, 0, 960, 640));
        
        //OpenGLViewを設定
        director->setOpenGLView(glview);
    }

    //ウィンドウの解像度を設定
    director->getOpenGLView()->setDesignResolutionSize(1136, 640, ResolutionPolicy::SHOW_ALL);

    //ウィンドウにFPSを表示 true : false
    director->setDisplayStats(true);

    //FPSを設定。デフォルトは[1.0 / 60]
    director->setAnimationInterval(1.0 / 60);
    
    //絶対パスが指定されていない場合、Resourceフォルダがデフォルト
    //Resouece配下のフォルダをSearchPathに追加する
    FileUtils::getInstance()->addSearchPath("card");
    FileUtils::getInstance()->addSearchPath("fonts");
    FileUtils::getInstance()->addSearchPath("game");
    FileUtils::getInstance()->addSearchPath("sound");
    FileUtils::getInstance()->addSearchPath("text");
    FileUtils::getInstance()->addSearchPath("title");
    FileUtils::getInstance()->addSearchPath("res");

    //シーンを描画
    Scene *scene { TitleScene::createScene() };

    //メインループ開始
    director->runWithScene(scene);

    return true;
}

//アプリケーションがバックグラウンドで実行状態になった際に呼ばれる処理
void AppDelegate::applicationDidEnterBackground()
{
    //アニメーションを停止
    Director::getInstance()->stopAnimation();

    //SimpleAudioEngineを使用している場合, 停止するには以下を記述すること
    //SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

//アプリケーションがフォアグラウンドで実行状態になった際に呼ばれる処理
void AppDelegate::applicationWillEnterForeground()
{
    //アニメーションを再開
    Director::getInstance()->startAnimation();

    //SimpleAudioEngineを使用している場合,再開するには以下を記述すること
    //SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}