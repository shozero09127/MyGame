/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	width = visibleSize.width;
	height = visibleSize.height;
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");
    //if (sprite == nullptr)
    //{
    //    problemLoading("'HelloWorld.png'");
    //}
    //else
    //{
    //    // position the sprite on the center of the screen
    //    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    //    // add the sprite as a child to this layer
    //    this->addChild(sprite, 0);
    //}
	// テクスチャファイル名を指定して、スプライトを作成

	//乱数の初期化（あっちでいうRandom=new Random();
	srand(time(nullptr));
	Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("sample01.png");
	SpriteFrame* frame0 = SpriteFrame::createWithTexture(texture, Rect(32 * 0, 32 * 2, 32, 32));
	SpriteFrame* frame1 = SpriteFrame::createWithTexture(texture, Rect(32 * 1, 32 * 2, 32, 32));
	SpriteFrame* frame2 = SpriteFrame::createWithTexture(texture, Rect(32 * 2, 32 * 2, 32, 32));
	SpriteFrame* frame3 = SpriteFrame::createWithTexture(texture, Rect(32 * 1, 32 * 2, 32, 32));
	Vector<SpriteFrame*>animFrames(4);
	animFrames.pushBack(frame0);
	animFrames.pushBack(frame1);
	animFrames.pushBack(frame2);
	animFrames.pushBack(frame3);
	for (int i=0;i<1;i++)
	{
		sprite[i] = Sprite::create("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa.png");
		this->addChild(sprite[i]);
		//sprite[i]->setPosition(Vec2((width), (height)));//座標（始点は左下）
		//float mx, my;
		//mx = (rand()*600/RAND_MAX)-300;//このままだととんでもなくでかい数値に・・・。
		//my = (rand()*600 / RAND_MAX)-300;
		/*MoveTo* action1 = MoveTo::create(1.0f, Vec2(0,height));
		MoveTo* action2 = MoveTo::create(1.0f, Vec2(0, 0));*/
		MoveTo* action1 = MoveTo::create(1.0f, Vec2(width/2, 0));
		JumpBy* action2 = JumpBy::create(1.0f, Vec2(100.0f, 0.0f),200.0f,1);

		//Sequence* action5 = Sequence::create(action1, action2, action3, action4, nullptr);
		//Repeat* action2 = Repeat::create(action1,3);//回数を指定して反復
		//RepeatForever* action2 = RepeatForever::create(action1);//永遠に反復
		/*Sequence* action3 = Sequence::create(action1, action2, nullptr);
		FadeTo *action4 = FadeTo::create(1.0f,0000);
		FadeTo *action5 = FadeTo::create(1.0f, 255);
		Sequence* action6 = Sequence::create(action4, action5, nullptr);
		Spawn* action7 = Spawn::create(action3, action6, nullptr);
		Repeat* action8 = Repeat::create(action7, 5);*/
		Repeat *action3 = Repeat::create(action2,100);
		Sequence *action4 = Sequence::create(action1, action3, nullptr);//これだとRepeatForeverのアクションが呼び出されない。
		
		//順番で実行する。
		sprite[i]->runAction(action4);
		/*
		MoveTo* action3 = MoveTo::create(1.0f, Vec2(width, height));
		EaseIn* action4 = EaseIn::create(action3, 2.0f);
		sprite[i]->runAction(action4);*/
	}
	// シーングラフにつなぐ
	/*sprite[1] = Sprite::create("shien.png");
	this->addChild(sprite[1]);
	sprite[1]->setScaleX(0.25f);
	sprite[1]->setScaleY(0.3f);
	sprite[1]->setPosition(Vec2((width ) / 2, (height ) / 2));
	sprite[1]->setOpacity(0x00);
	FadeTo*action3 = FadeTo::create(1.0f, 255);
	EaseIn* action4 = EaseIn::create(action3, 2.0f);
	sprite[1]->runAction(action4);*/
	//MoveBy=指定した座標分移動する。
	//MoveTo=指定した座標に移動する。
	
	//EaseIn 元になるアクションを指定し、それを加速させる。
	//FadeTo 指定したフェードに変化する。
	//ScaleBy 指定した大きさへ変化する。Toは変更の影響を受ける。
	//JumpBy 指定した座標へ指定した高さに到達したジャンプへ指定した回数行い移動する。
	//RotateBy 指定した座標分回転する。対応する軸で変更する。度数参照。
	//Blink 指定回数点滅する。青背景に赤画像でやるのは絶対にやめよう（迫真）

	//sprite->runAction(action1);
	
	//this->addChild(sprite2);
	//this->addChild(spriterect);
	//
	//spriterect->setAnchorPoint(Vec2(1.0f, 1.0f));
	//spriterect->setTextureRect(Rect(0.0f, 48.0f, 32.0f, 32.0f));
	//spritewidth = (sprite->getContentSize().width / 2);
	//spriteheight = (sprite->getContentSize().height / 2);/*
	//spritewidthano = (sprite2->getContentSize().width / 2);
	//spriteheightano = (sprite2->getContentSize().height / 2);*/
	
	//spriterect->setPosition(Vec2(width / 2, height / 2));
	//sprite->setAnchorPoint(Vec2(0.5f, 0.5f));//画像の左下が0,0右上が1,0の座標系
	////sprite2->setPosition(Vec2(width / 2, height / 2));//座標（始点は左下）
	////sprite2->setAnchorPoint(Vec2(1.0f, 0.0f));//画像の左下が0,0右上が1,0の座標系
	
	//sprite2->setOpacity(0);
	////sprite->setRotation(45.0f);
	//sprite->setFlippedX(true);//左右反転
	////sprite->setFlippedY(true);//上下反転
	//sprite->setVisible(true);//表示するか否か
	//sprite->setVisible(true);//表示するか否か
	//scenewidth = width - spritewidth;
	//sceneheight = height - spriteheight;
	//sprite->setColor(Color3B(0.0f, 0.0f, 255.0f));//色合いの設定
	//

	////sprite->setOpacity(0x80);//不透明度の設定
	////最後の設定が反映される
	//state = 0;
	//walk = 0;
	this->scheduleUpdate();//Updateの有効化
	
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::update(float delta)
{


//	Vec2 pos ;//現在座標の獲得
//	switch (state)
//	{
//	case 0:
//		pos = sprite->getPosition();
//		pos += Vec2(-5.0f, 0.0f);
//		sprite->setPosition(pos);
//		if (pos.x <= 0)
//		{
//			state = 1;
//			sprite->setFlippedX(false);
//		}
//			
//		break;
//	case 1:
//			state = 2;
//		break;
//	case 2:
//		pos = sprite->getPosition();
//		pos += Vec2(5.0f, 0.0f);
//		sprite->setPosition(pos);
//		if (pos.x>=width)
//		{
//			state = 3;
//			sprite->setFlippedX(true);
//		}
//		break;
//	case 3:
//			state = 0;
//		break;
//	}
//
//	switch (walk)
//	{
//	case 0:
//		
//		spriterect->setTextureRect(Rect(40.0f, 48.0f, 32.0f, 32.0f));
//		walk = 1;
//		break;
//	case 1:
//		spriterect->setTextureRect(Rect(0.0f, 48.0f, 32.0f, 32.0f));
//		walk = 2;
//		break;
//	case 2:
//		spriterect->setTextureRect(Rect(40.0f, 48.0f, 32.0f, 32.0f));
//		walk = 3;
//		break;
//	case 3:
//		spriterect->setTextureRect(Rect(80.0f, 48.0f, 32.0f, 32.0f));
//		walk = 0;
//		break;
//	}
//	//ここに更新処理を書く。
//	
//	
//	//float rotate = sprite->getRotation();
//	//float opacity = sprite->getOpacity();
//
//
//	float b = sprite->getColor().b;
//	float r = sprite->getColor().r;
//	float g = sprite->getColor().g;
//	b-=1.0f;
//	r+=1.0f;
//	sprite->setColor(Color3B(r,g,b));
//
///*
//	opacity -= 51.0f/60.0f;*/
//	/*if (pos.x>=0&&pos.x<width&&pos.y==0)
//		vel= Vec2(1.0f, 0.0f);
//
//	else if (pos.x ==width  && pos.y >=0&&pos.y<height)
//		vel= Vec2(0.0f, 1.0f);
//
//	else if (pos.x <=width && pos.x > 0&&pos.y == height)
//		vel= Vec2(-1.0f, 0.0f);
//
//	else if (pos.x == 0&& pos.y <= height&&pos.y > 0)
//		vel= Vec2(0.0f, -1.0f);*/
//	/*rotate += 1.0f;
//	sprite->setOpacity(opacity);
//	sprite2->setOpacity(-opacity);*/
//	//sprite->setRotation(rotate);
//	//獲得→書き換え→反映　これのループ
}
