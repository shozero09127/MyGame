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
#include"AudioEngine.h"

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
	//experimental::AudioEngine::play2d("cyrf_satellite_reactor.mp3");
	
	//audioID=experimental::AudioEngine::play2d("shortbomb.mp3");
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
		//sprite[i]->setPosition(Vec2((width), (height)));//座標（始点は左下）
		//float mx, my;
		//mx = (rand()*600/RAND_MAX)-300;//このままだととんでもなくでかい数値に・・・。
		//my = (rand()*600 / RAND_MAX)-300;
		/*MoveTo* action1 = MoveTo::create(1.0f, Vec2(0,height));
		MoveTo* action2 = MoveTo::create(1.0f, Vec2(0, 0));*/
		/*
		MoveTo* action1 = MoveTo::create(1.0f, Vec2(width/2, 0));
		JumpBy* action2 = JumpBy::create(1.0f, Vec2(100.0f, 0.0f),200.0f,1);*/

		//Sequence* action5 = Sequence::create(action1, action2, action3, action4, nullptr);
		//Repeat* action2 = Repeat::create(action1,3);//回数を指定して反復
		//RepeatForever* action2 = RepeatForever::create(action1);//永遠に反復
		/*Sequence* action3 = Sequence::create(action1, action2, nullptr);
		FadeTo *action4 = FadeTo::create(1.0f,0000);
		FadeTo *action5 = FadeTo::create(1.0f, 255);
		Sequence* action6 = Sequence::create(action4, action5, nullptr);
		Spawn* action7 = Spawn::create(action3, action6, nullptr);
		Repeat* action8 = Repeat::create(action7, 5);*/
		//Repeat *action3 = Repeat::create(action2,100);
		//Sequence *action4 = Sequence::create(action1, action3, nullptr);//これだとRepeatForeverのアクションが呼び出されない。
		//
		//順番で実行する。
		/*sprite[i]->runAction(action4);*/
		/*
		MoveTo* action3 = MoveTo::create(1.0f, Vec2(width, height));
		EaseIn* action4 = EaseIn::create(action3, 2.0f);
		sprite[i]->runAction(action4);*
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
	/*CallFunc*action = CallFunc::create(CC_CALLBACK_0(HelloWorld::myFunction, this));
	this->runAction(action);*/

	countdownID = experimental::AudioEngine::play2d("senjo.mp3", true);
	field = Sprite::create("senjo.png");
	field->setPosition(Vec2(width / 2, height / 2)); 
	staffroll = Sprite::create("endroll.png");
	staffroll->setPosition(Vec2(width / 2, -(height*55)/100));
	isEndFlag = false;
	this->addChild(field,1);
	CallFunc*maction = CallFunc::create(CC_CALLBACK_0(HelloWorld::dokanPop, this));
	CallFunc*kaction = CallFunc::create(CC_CALLBACK_0(HelloWorld::warpStar, this));
	Sequence* action3 = Sequence::create(maction, kaction, nullptr);
	CallFunc*countaction = CallFunc::create(CC_CALLBACK_0(HelloWorld::countdown, this));
	CallFunc*actionviran = CallFunc::create(CC_CALLBACK_0(HelloWorld::viranapproach, this));
	CallFunc*screen = CallFunc::create(CC_CALLBACK_0(HelloWorld::screenmapper, this));
	CallFunc*challenging = CallFunc::create(CC_CALLBACK_0(HelloWorld::challengerapproach, this));
	CallFunc*bowserjumping = CallFunc::create(CC_CALLBACK_0(HelloWorld::bowserjump, this));
	CallFunc*kirbylast = CallFunc::create(CC_CALLBACK_0(HelloWorld::lastSmashkirby, this));
	
	DelayTime*delays = DelayTime::create(3.2f);
	DelayTime*cutdelays = DelayTime::create(0.5f);
	Sequence*virandelay = Sequence::create(delays, actionviran,screen,cutdelays,challenging,bowserjumping, nullptr);
	Sequence*countset = Sequence::create(countaction, virandelay, nullptr);

	black = Sprite::create("black.png");
	black->setPosition(Vec2((width / 2), (height / 2)));
	black->setScale(1.5f);
	black->setOpacity(0);
	this->addChild(staffroll, 160);
	this->addChild(black, 150);
	this->runAction(countset);
	this->runAction(action3);
	//this->runAction(mariolast);
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
	float opacity = black->getOpacity();
	Vec2 pos = staffroll->getPosition();
	if (isEndFlag == true)
	{
		if (opacity < 254)
		{

			opacity = opacity + 2;
		}
		else
		{
			opacity = 255;
		}

		black->setOpacity(opacity);

	}
	if (opacity == 255)
	{
		pos = pos + Vec2(0.0f, 1.5f);
		
	}
	staffroll->setPosition(pos);
	/*timer--;
	if (timer == 0)
	{
		CallFunc*action = CallFunc::create(CC_CALLBACK_0(HelloWorld::setRandom, this));
		this->runAction(action);
		CallFunc*action1 = CallFunc::create(CC_CALLBACK_0(HelloWorld::myFunction, this));
		this->runAction(action1);
		CallFunc*action2 = CallFunc::create(CC_CALLBACK_0(HelloWorld::soundPlay, this));
		this->runAction(action2);
		timer = 60;
	}*/
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

void HelloWorld::myFunction()
{
	sprite->setPosition(Vec2(randomscorex, randomscorey));
}

void HelloWorld::soundPlay()
{
	experimental::AudioEngine::play2d("shortbomb.mp3");
}
void HelloWorld::setRandom()
{
	randomscorex = cocos2d::random<int>(1, width / 10) * 10;
	randomscorey = cocos2d::random<int>(1, height / 10) * 10;
}
void HelloWorld::bowserjump()
{
	DelayTime*delays = DelayTime::create(4.0f);
	JumpBy*jump = JumpBy::create(5.0f, Vec2(0, 0), 50, 15);
	RotateBy*rotate = RotateBy::create(2.0f, Vec3(0, 720, 0));

	Sequence* dededeaction = Sequence::create(delays, rotate, nullptr);
	CallFunc*superjump = CallFunc::create(CC_CALLBACK_0(HelloWorld::bowsertyoshinoru, this));

	Sequence* jumpnagare = Sequence::create(dededeaction, superjump, nullptr);
	bowser->runAction(jump);
	dedede->runAction(jumpnagare);
}
void HelloWorld::dokanPop()
{
	marioAudioID = experimental::AudioEngine::play2d("mariostandVOICE.mp3");
	dokan = Sprite::create("s_dokan.png");
	marioawake = Sprite::create("s_marioawake.png");
	dokan->setPosition(Vec2((width * 20) / 100, (height * 25) / 100));
	dokan->setScale(0.7f);
	marioawake->setPosition(Vec2((width * 20) / 100, (height * 30) / 100));
	
	MoveBy* action1 = MoveBy::create(0.5f, Vec2(0, 20));
	MoveBy* action2 = MoveBy::create(0.5f, Vec2(0, -40));
	JumpBy* maction1 = JumpBy::create(1.0f, Vec2(0, 0),120,1);
	CallFunc*maction2 = CallFunc::create(CC_CALLBACK_0(HelloWorld::marioStand, this));
	Sequence* maction3 = Sequence::create(maction1, maction2, nullptr);
	RemoveSelf*action3 = RemoveSelf::create();
	Sequence* action4 = Sequence::create(action1, action2,action3, nullptr);
	dokan->runAction(action4);
	marioawake->runAction(maction3);
	this->addChild(marioawake,5);
	this->addChild(dokan,6);
}
void HelloWorld::warpStar()
{

	kirbyAudioID = experimental::AudioEngine::play2d("kirbyUP.mp3");
	warpstark = Sprite::create("kirbywarpstar.png");
	warpstark->setPosition(Vec2((width * 105) / 100, (height * 105) / 100));
	warpstark->setScale(0.5f);

	DelayTime* action1 = DelayTime::create(1.0f);
	MoveTo* action2 = MoveTo::create(0.5f, Vec2((width * 80) / 100, (height * 30) / 100));
	CallFunc*action3 = CallFunc::create(CC_CALLBACK_0(HelloWorld::kirbyStand, this));
	Sequence* action4 = Sequence::create(action1, action2,action3,  nullptr);
	warpstark->runAction(action4);
	/*
	dokan->setScale(0.7f);
	MoveBy* action1 = MoveBy::create(0.5f, Vec2(0, 40));
	MoveBy* action2 = MoveBy::create(0.5f, Vec2(0, -40));
	Sequence* action4 = Sequence::create(action1, action2, nullptr);*//*
	dokan->runAction(action4);*/
	this->addChild(warpstark,5);
}

void HelloWorld::kirbyStand()
{
	warpstark->setTexture("kkk.png");
	JumpBy* action1 = JumpBy::create(0.5f, Vec2(-20, 0), 70, 1);
	warpstark->runAction(action1);
}

void HelloWorld::kirbyNeutral()
{
	warpstark->setTexture("kkk.png");

}

void HelloWorld::kirbySideB()
{
	kirbyAudioID = experimental::AudioEngine::play2d("kirbyVOICESB.mp3");
	warpstark->setTexture("hammer.png");
	DelayTime*delays = DelayTime::create(0.5f);
	CallFunc*kirbystand = CallFunc::create(CC_CALLBACK_0(HelloWorld::kirbyNeutral, this));

	Sequence*kirbyposition = Sequence::create(delays, kirbystand, nullptr);
	marioawake->runAction(kirbyposition);
}

void HelloWorld::kirbylastStandBy()
{
	warpstark->setTexture("kirbyfc.png");
	warpstark->setFlippedX(true);
	JumpBy* maction1 = JumpBy::create(1.0f, Vec2(0, (height * 30) / 100), 100, 1);
	CallFunc*mariolast = CallFunc::create(CC_CALLBACK_0(HelloWorld::lastSmashkirby, this));
	DelayTime*delays = DelayTime::create(0.25f);
	CallFunc*smashremove = CallFunc::create(CC_CALLBACK_0(HelloWorld::smashdisappear, this));
	Sequence*smashmove = Sequence::create(delays, smashremove, nullptr);
	CallFunc*frameout = CallFunc::create(CC_CALLBACK_0(HelloWorld::dededeframeOut, this));
	Spawn*smashcrow = Spawn::create(maction1, smashmove, nullptr);
	Sequence*marioposition = Sequence::create(smashcrow, delays, mariolast, nullptr);
	warpstark->runAction(marioposition);
}

void HelloWorld::kirbyBack()
{
	JumpTo*stand = JumpTo::create(0.5f, Vec2((width * 50) / 100, (height * 30) / 100), 10, 1);

	MoveTo*mariomove = MoveTo::create(0.4f, Vec2((width * 80) / 100, (height * 30) / 100));
	CallFunc*marioDash = CallFunc::create(CC_CALLBACK_0(HelloWorld::kirbyNeutral, this));
	Sequence*kirbyposition = Sequence::create(stand, marioDash, mariomove, nullptr);
	warpstark->runAction(kirbyposition);
}

void HelloWorld::marioStand()
{
	marioawake->setTexture("mariostand.png");
	marioawake->setScale(1.5f);
}
void HelloWorld::marioNB()
{
	marioawake->setTexture("mariofireball.png");

	DelayTime*delays = DelayTime::create(0.5f);
	CallFunc*mariostandup = CallFunc::create(CC_CALLBACK_0(HelloWorld::marioStand, this));

	Sequence*marioposition = Sequence::create(delays,mariostandup, nullptr);
	marioawake->runAction(marioposition);

}
void HelloWorld::marioDash()
{
	marioawake->setTexture("mariorun.png");
	marioawake->setScale(0.8f);
	MoveTo*actionMove1 = MoveTo::create(0.4f, Vec2((width * 50) / 100, (height * 30) / 100));
	
	marioawake->runAction(actionMove1);

}
void HelloWorld::kirbyRun()
{
	
	MoveTo*actionMove1 = MoveTo::create(0.4f, Vec2((width * 50) / 100, (height * 30) / 100));

	warpstark->runAction(actionMove1);

}
void HelloWorld::marioDashRunL()
{
	marioawake->setTexture("mariorun.png");
	marioawake->setScale(0.8f);
	marioawake->setFlippedX(true);
}
void HelloWorld::marioBack()
{
	JumpTo*stand = JumpTo::create(0.5f, Vec2((width * 50) / 100, (height * 30) / 100), 10, 1);

	MoveTo*mariomove = MoveTo::create(0.4f, Vec2((width * 20) / 100, (height * 30) / 100));
	CallFunc*marioDash= CallFunc::create(CC_CALLBACK_0(HelloWorld::marioDashRunL, this));
	CallFunc*mariostanding = CallFunc::create(CC_CALLBACK_0(HelloWorld::marioStand, this));
	CallFunc*nextflame = CallFunc::create(CC_CALLBACK_0(HelloWorld::dededeaseru, this));
	Sequence*marioposition = Sequence::create(stand,marioDash, mariomove, mariostanding,nextflame,nullptr);
	marioawake->runAction(marioposition);
	
}
void HelloWorld::mariolastStandby()
{
	marioawake->setTexture("s_marioawake.png");

	JumpBy* maction1 = JumpBy::create(1.0f, Vec2(0, (height*30)/100), 100, 1);
	CallFunc*mariolast = CallFunc::create(CC_CALLBACK_0(HelloWorld::lastSmashmario, this));
	DelayTime*delays = DelayTime::create(0.25f);
	CallFunc*smashremove = CallFunc::create(CC_CALLBACK_0(HelloWorld::smashdisappear, this));
	Sequence*smashmove = Sequence::create(delays, smashremove, nullptr);
	CallFunc*frameout = CallFunc::create(CC_CALLBACK_0(HelloWorld::bowserframeOut, this));
	Spawn*smashcrow = Spawn::create(maction1, smashmove, nullptr);
	Sequence*marioposition = Sequence::create(smashcrow,delays,mariolast,nullptr);
	marioawake->runAction(marioposition);
}
void HelloWorld::countdown()
{
	countdownID = experimental::AudioEngine::play2d("countdowncut.mp3");
	countmoji[3] = Sprite::create("3.png");
	countmoji[2] = Sprite::create("2.png");
	countmoji[1] = Sprite::create("1.png");
	countmoji[0] = Sprite::create("GO!.png");
	for (int i = 0; i < 4; i++)
	{

		countmoji[i]->setPosition(Vec2((width * 50) / 100, (height * 90) / 100));
		countmoji[i]->setOpacity(0);
		this->addChild(countmoji[i],100);
	}
	FadeTo*actionout = FadeTo::create(0.8f, 255);
	FadeTo*actionin = FadeTo::create(0.2f, 0);
	RemoveSelf*remove = RemoveSelf::create();
	DelayTime*delayone = DelayTime::create(1.0f);
	DelayTime*delaytwo = DelayTime::create(2.0f);
	DelayTime*delaythree = DelayTime::create(3.0f);
	FadeTo*actiongoout = FadeTo::create(0.2f, 255);
	ScaleBy*scaleaction = ScaleBy::create(1.0f, 2.0f);
	Spawn*fadeon = Spawn::create(actiongoout, scaleaction, nullptr);

	Sequence*action = Sequence::create(actionout, actionin, remove, nullptr);
	Sequence*actiontwo = Sequence::create(delayone, action, remove, nullptr);
	Sequence*actionone = Sequence::create(delaytwo, action, remove, nullptr);
	Sequence*actiongo = Sequence::create(delaythree, fadeon,actionin, remove, nullptr);
	countmoji[3]->runAction(action);
	countmoji[2]->runAction(actiontwo);
	countmoji[1]->runAction(actionone);
	countmoji[0]->runAction(actiongo);
}

void HelloWorld::lastSmashkirby()
{
	
	black->setOpacity(0);
		// アニメーションパターンからSpriteを生成
		ultrasword = Sprite::create("ultrasword10.png");
		ultrasword->setPosition(Vec2(width / 2, height / 2));
		ultrasword->setScale(0.75f);	// 拡大

		Animation* animation = Animation::create();
		for (int i = 1; i <= 2; i++)
		{
			char szName[100] = { 0 };
			sprintf(szName, "ultrasword%d.png", i);
			animation->addSpriteFrameWithFile(szName);
			
		}
		animation->setDelayPerUnit(0.3f);
		animation->setRestoreOriginalFrame(true);

		Animation* animation2 = Animation::create();
		for (int i = 3; i <= 3; i++)
		{
			char szName[100] = { 0 };
			sprintf(szName, "ultrasword%d.png", i);
			animation2->addSpriteFrameWithFile(szName);

		}
		animation2->setDelayPerUnit(0.85f);
		animation2->setRestoreOriginalFrame(true);

		Animation* animation3 = Animation::create();
		for (int i = 3; i <= 9; i++)
		{
			char szName[100] = { 0 };
			sprintf(szName, "ultrasword%d.png", i);
			animation3->addSpriteFrameWithFile(szName);

		}
		animation3->setDelayPerUnit(0.25f);
		animation3->setRestoreOriginalFrame(true);

		Animation* animation4 = Animation::create();
		for (int i = 9; i <= 9; i++)
		{
			char szName[100] = { 0 };
			sprintf(szName, "ultrasword%d.png", i);
			animation4->addSpriteFrameWithFile(szName);

		}
		animation4->setDelayPerUnit(1.2f);
		animation4->setRestoreOriginalFrame(true);

		// アニメーションデータからアニメーションアクションを生成
		Animate* animate = Animate::create(animation);
		Animate* animate2 = Animate::create(animation2);
		Animate* animate3 = Animate::create(animation3);
		Animate* animate4 = Animate::create(animation4);
		MoveBy*action1 = MoveBy::create(0.03f, Vec2(20, 40));
		MoveBy*action2 = MoveBy::create(0.05f, Vec2(-30, -30));
		MoveBy*action3 = MoveBy::create(0.05f, Vec2(30, 30));
		MoveBy*action4 = MoveBy::create(0.03f, Vec2(-20, -40));
		CallFunc*frameout = CallFunc::create(CC_CALLBACK_0(HelloWorld::dededeframeOut, this));
		Sequence*actionquake = Sequence::create(action2, action3, nullptr);
		Sequence*actionflip = Sequence::create(action1, actionquake, actionquake, actionquake, actionquake, action4, nullptr);
		Sequence*anim = Sequence::create(animate, animate2,animate3,animate4,actionflip, frameout
			,nullptr);
		// アクションの実行
		CallFunc*seset = CallFunc::create(CC_CALLBACK_0(HelloWorld::lastkirbyset, this));
		Spawn*animset = Spawn::create(anim, seset, nullptr);
		ultrasword->runAction(animset);

		this->addChild(ultrasword,200);
	
}
void HelloWorld::burstOut()
{
	burstID = experimental::AudioEngine::play2d("burst.mp3");
	//black->setOpacity(0);
	// アニメーションパターンからSpriteを生成
	burst = Sprite::create("burst7.png");
	burst->setPosition(Vec2(width / 2, height / 2));
	burst->setScale(1.0f);	// 拡大

	Animation* animation = Animation::create();
	for (int i = 1; i <=7; i++)
	{
		char szName[100] = { 0 };
		sprintf(szName, "burst%d.png", i);
		animation->addSpriteFrameWithFile(szName);

	}
	animation->setDelayPerUnit(0.1f);
	animation->setRestoreOriginalFrame(true);

	


	// アニメーションデータからアニメーションアクションを生成
	Animate* animate = Animate::create(animation);
	RemoveSelf*remove = RemoveSelf::create();
	Sequence*burstanim = Sequence::create(animate, remove, nullptr);
	// アクションの実行
	burst->runAction(burstanim);

	this->addChild(burst, 200);

}
void HelloWorld::burstOut2()
{
	burstID = experimental::AudioEngine::play2d("burst.mp3");
	//black->setOpacity(0);
	// アニメーションパターンからSpriteを生成
	burst = Sprite::create("burst7.png");
	burst->setPosition(Vec2((width-20) / 2, (height-20) / 2));
	burst->setScale(1.0f);	// 拡大
	burst->setFlippedX(true);

	Animation* animation = Animation::create();
	for (int i = 1; i <= 7; i++)
	{
		char szName[100] = { 0 };
		sprintf(szName, "burst%d.png", i);
		animation->addSpriteFrameWithFile(szName);

	}
	animation->setDelayPerUnit(0.1f);
	animation->setRestoreOriginalFrame(true);




	// アニメーションデータからアニメーションアクションを生成
	Animate* animate = Animate::create(animation);
	RemoveSelf*remove = RemoveSelf::create();
	Sequence*burstanim = Sequence::create(animate, remove, nullptr);
	// アクションの実行
	burst->runAction(burstanim);

	this->addChild(burst, 200);

}
void HelloWorld::lastSmashmario()
{
	marioAudioID = experimental::AudioEngine::play2d("mariofinal.mp3");
	black->setOpacity(0);
	// アニメーションパターンからSpriteを生成
	mariofinal = Sprite::create("mariofinal5.png");
	mariofinal->setPosition(Vec2(width / 2, height / 2));
	mariofinal->setScale(0.6f);	// 拡大
	mariofinal->setFlippedX(true);

	Animation* animation = Animation::create();
	for (int i = 1; i <= 1; i++)
	{
		char szName[100] = { 0 };
		sprintf(szName, "mariofinal%d.png", i);
		animation->addSpriteFrameWithFile(szName);

	}
	animation->setDelayPerUnit(1.1f);
	animation->setRestoreOriginalFrame(true);

	Animation* animation2 = Animation::create();
	for (int i = 2; i <= 3; i++)
	{
		char szName[100] = { 0 };
		sprintf(szName, "mariofinal%d.png", i);
		animation2->addSpriteFrameWithFile(szName);

	}
	animation2->setDelayPerUnit(0.5f);
	animation2->setRestoreOriginalFrame(true);

	Animation* animation3 = Animation::create();
	for (int i = 3; i <= 4; i++)
	{
		char szName[100] = { 0 };
		sprintf(szName, "mariofinal%d.png", i);
		animation3->addSpriteFrameWithFile(szName);

	}
	animation3->setDelayPerUnit(0.5f);
	animation3->setRestoreOriginalFrame(true);

	

	// アニメーションデータからアニメーションアクションを生成
	Animate* animate = Animate::create(animation);
	Animate* animate2 = Animate::create(animation2);
	Animate* animate3 = Animate::create(animation3);
	MoveBy*action1 = MoveBy::create(0.03f, Vec2(20, 40));
	MoveBy*action2 = MoveBy::create(0.05f, Vec2(-30, -30));
	MoveBy*action3 = MoveBy::create(0.05f, Vec2(30, 30));
	MoveBy*action4 = MoveBy::create(0.03f, Vec2(-20, -40));
	CallFunc*frameout = CallFunc::create(CC_CALLBACK_0(HelloWorld::bowserframeOut, this));
	Sequence*actionquake = Sequence::create(action2, action3, nullptr);
	Sequence*actionflip = Sequence::create(action1, actionquake, actionquake, actionquake, actionquake, action4, nullptr);
	Sequence*anim = Sequence::create(animate, animate2, animate3,frameout, nullptr);
	CallFunc*seset = CallFunc::create(CC_CALLBACK_0(HelloWorld::lastmarioset, this));
	Spawn*animset = Spawn::create(anim, seset, nullptr);
	// アクションの実行
	mariofinal->runAction(animset);

	this->addChild(mariofinal, 200);

}

void HelloWorld::lastmarioset()
{
	CallFunc*lastseOn = CallFunc::create(CC_CALLBACK_0(HelloWorld::lastmarioSEset, this));
	CallFunc*lastseOn2 = CallFunc::create(CC_CALLBACK_0(HelloWorld::lastmarioSEset2, this));
	DelayTime*delays = DelayTime::create(1.1f);
	DelayTime*delays2 = DelayTime::create(0.125f);
	Sequence*flameon = Sequence::create(lastseOn, delays2, lastseOn2, delays2, nullptr);
	Repeat*flameRepeat = Repeat::create(flameon, 8);
	Sequence*mariofinalon= Sequence::create(delays,lastseOn,flameRepeat, nullptr);
	mariofinal->runAction(mariofinalon);

}

void HelloWorld::lastmarioSEset()
{
	mariolastID = experimental::AudioEngine::play2d("mariolastSE.mp3");
}
void HelloWorld::lastmarioSEset2()
{
	mariolastID = experimental::AudioEngine::play2d("mariolastSE2.mp3");
}

void HelloWorld::lastkirbyset()
{
	kirbyAudioID= experimental::AudioEngine::play2d("kirbylastVOICE1.mp3");
	CallFunc*lastseOn = CallFunc::create(CC_CALLBACK_0(HelloWorld::lastkirbySEset, this));
	CallFunc*lastseOn2 = CallFunc::create(CC_CALLBACK_0(HelloWorld::lastkirbySEset2, this));
	CallFunc*lastseOn3 = CallFunc::create(CC_CALLBACK_0(HelloWorld::lastkirbySEset3, this));
	DelayTime*delays = DelayTime::create(0.3f);
	DelayTime*delays2 = DelayTime::create(0.25f);
	Sequence*slash = Sequence::create( lastseOn,delays2,nullptr);
	Repeat*slashRepeat = Repeat::create(slash, 7);
	DelayTime*delays3 = DelayTime::create(0.85f);
	DelayTime*delays4 = DelayTime::create(1.2f);
	
	Sequence*ultraswordon = Sequence::create(delays,lastseOn,delays2,delays3,slashRepeat,lastseOn2,delays4,lastseOn3,nullptr);
	ultrasword->runAction(ultraswordon);

}

void HelloWorld::lastkirbySEset()
{
	mariolastID = experimental::AudioEngine::play2d("slashSE1.mp3");
}
void HelloWorld::lastkirbySEset2()
{
	
	kirbyAudioID = experimental::AudioEngine::play2d("kirbylastVOICE2.mp3");
}
void HelloWorld::lastkirbySEset3()
{
	mariolastID = experimental::AudioEngine::play2d("slashSE2.mp3");
	kirbyAudioID = experimental::AudioEngine::play2d("kirbylastVOICE3.mp3");
}
void HelloWorld::viranapproach()
{
	dedede = Sprite::create("dededestand.png");

	bowser = Sprite::create("bowserstand.png");
	CallFunc*powsound = CallFunc::create(CC_CALLBACK_0(HelloWorld::powset, this));;
	dedede->setPosition(Vec2((width * 75) / 100, (height * 130) / 100));

	bowser->setPosition(Vec2((width * 25) / 100, (height * 130) / 100));
	JumpBy* actionjump = JumpBy::create(0.3f, Vec2(0, -(height * 65) / 100), 70, 1);
	Sequence*actionbowser= Sequence::create(actionjump, powsound, nullptr);
	JumpBy* actionjump2 = JumpBy::create(0.3f, Vec2(0, -(height * 65) / 100), 70, 1);
	Sequence*actiondedede = Sequence::create(actionjump2, powsound, nullptr);
	dedede->runAction(actionbowser);
	bowser->runAction(actiondedede);
	this->addChild(dedede,5);
	this->addChild(bowser,5);
}

void HelloWorld::powset()
{
	POWID = experimental::AudioEngine::play2d("POWSE.mp3");
}

void HelloWorld::bowserlaugh()
{
	POWID = experimental::AudioEngine::play2d("POWSE.mp3");
}
void HelloWorld::bowserlaugh2()
{
}
void HelloWorld::screenmapper()
{

	DelayTime*delays = DelayTime::create(0.3f);
	MoveBy*action1 = MoveBy::create(0.02f, Vec2(6, 12));
	MoveBy*action2 = MoveBy::create(0.04f, Vec2(-8, -8));
	MoveBy*action3 = MoveBy::create(0.04f, Vec2(8, 8));
	MoveBy*action4= MoveBy::create(0.02f, Vec2(-6,- 12));
	Sequence*actionquake = Sequence::create(action2, action3, nullptr);
	Sequence*actionflip = Sequence::create(delays, action1,actionquake, actionquake, actionquake, actionquake,action4, nullptr);
	field->runAction(actionflip);
}

void HelloWorld::challengerapproach()
{

	
	challenger = Sprite::create("challengers.png");
	challenger->setPosition(Vec2((width / 2)+width, height / 2));
	this->addChild(challenger,20);
	MoveTo* action = MoveTo::create(0.75f, Vec2(width / 2 , height / 2));

	MoveTo* action2 = MoveTo::create(1.0f, Vec2(-((width / 2)+width), height / 2));
	DelayTime*delays = DelayTime::create(2.0f);
	
	RemoveSelf*remove = RemoveSelf::create();
	Sequence*actioncut = Sequence::create(action, delays, action2,remove, nullptr);
	challenger->runAction(actioncut);
}

void HelloWorld::bowsertyoshinoru()
{
	JumpBy* actionjump = JumpBy::create(2.0f, Vec2(0, 0), 500, 1);
	dedede->runAction(actionjump);
	DelayTime*delays = DelayTime::create(2.0f);
	MoveBy*action1 = MoveBy::create(0.02f, Vec2(30, 40));
	MoveBy*action2 = MoveBy::create(0.04f, Vec2(-20, -20));
	MoveBy*action3 = MoveBy::create(0.04f, Vec2(20, 20));
	MoveBy*action4 = MoveBy::create(0.02f, Vec2(-30, -40));
	Sequence*actionquake = Sequence::create(action2, action3, nullptr);
	CallFunc*smashcammon = CallFunc::create(CC_CALLBACK_0(HelloWorld::smashappear, this));
	Sequence*actionflip = Sequence::create(delays, smashcammon,action1, actionquake, actionquake, actionquake, actionquake, action4, nullptr);
	
	
	field->runAction(actionflip);
}

void HelloWorld::dededeaseru()
{
	dedede->setTexture("dededebug.png");
	dedede->setFlippedX(true);
	DelayTime*delays = DelayTime::create(3.0f);
	JumpBy* actionjump = JumpBy::create(1.0f, Vec2(0, 0), 20, 5);
	JumpBy* actionjump2 = JumpBy::create(2.0f, Vec2(0, 0), 500, 1);
	Sequence*jumpaction = Sequence::create(actionjump, actionjump2, nullptr);
	dedede->runAction(jumpaction);
	MoveBy*action1 = MoveBy::create(0.02f, Vec2(30, 40));
	MoveBy*action2 = MoveBy::create(0.04f, Vec2(-20, -20));
	MoveBy*action3 = MoveBy::create(0.04f, Vec2(20, 20));
	MoveBy*action4 = MoveBy::create(0.02f, Vec2(-30, -40));
	Sequence*actionquake = Sequence::create(action2, action3, nullptr);
	CallFunc*smashcammon = CallFunc::create(CC_CALLBACK_0(HelloWorld::smashappear2, this));
	Sequence*actionflip = Sequence::create(delays, smashcammon, action1, actionquake, actionquake, actionquake, actionquake, action4, nullptr);


	field->runAction(actionflip);

}

void HelloWorld::smashappear()
{
	smashball = Sprite::create("smashball.png");

	smashball->setPosition(Vec2(width / 2, (height / 2)+height));
	DelayTime*delays = DelayTime::create(0.2f);
	DelayTime*delaysmini = DelayTime::create(0.05f);
	MoveTo*action1 = MoveTo::create(0.5f, Vec2(width / 2, height / 2));
	MoveTo*actionMove1 = MoveTo::create(1.0f, Vec2((width * 32) / 100, (height * 30) / 100));
	EaseIn*actionEase1 = EaseIn::create(actionMove1, 2.0f);
	MoveTo*actionMove2 = MoveTo::create(0.5f, Vec2((width * 66) / 100, (height * 30) / 100));
	EaseOut*actionEase2 = EaseOut::create(actionMove2, 2.0f);
	MoveTo*actionMove3 = MoveTo::create(0.3f, Vec2((width * 50) / 100, (height * 60) / 100));
	EaseOut*actionEase3 = EaseOut::create(actionMove3, 2.0f);
	
	CallFunc*mariofire = CallFunc::create(CC_CALLBACK_0(HelloWorld::marioNB, this));
	CallFunc*hammer = CallFunc::create(CC_CALLBACK_0(HelloWorld::kirbySideB, this));
	CallFunc*mariorun = CallFunc::create(CC_CALLBACK_0(HelloWorld::marioDash, this));
	CallFunc*mariolast = CallFunc::create(CC_CALLBACK_0(HelloWorld::mariolastStandby, this));
	Sequence*smashcome = Sequence::create(action1, delays, actionEase1,mariofire, actionEase2,delaysmini, mariorun, hammer,actionEase3,mariolast, nullptr);
	smashball->runAction(smashcome);
	this->addChild(smashball,80);
}

void HelloWorld::smashappear2()
{
	marioawake->setFlippedX(false);
	smashball = Sprite::create("smashball.png");

	smashball->setPosition(Vec2(width / 2, (height / 2) + height));
	DelayTime*delays = DelayTime::create(0.2f);
	DelayTime*delaysmini = DelayTime::create(0.05f);
	MoveTo*action1 = MoveTo::create(0.5f, Vec2(width / 2, height / 2));
	MoveTo*actionMove1 = MoveTo::create(1.0f, Vec2((width * 66) / 100, (height * 30) / 100));
	EaseIn*actionEase1 = EaseIn::create(actionMove1, 2.0f);
	MoveTo*actionMove2 = MoveTo::create(0.5f, Vec2((width * 32) / 100, (height * 30) / 100));
	EaseOut*actionEase2 = EaseOut::create(actionMove2, 2.0f);
	MoveTo*actionMove3 = MoveTo::create(0.3f, Vec2((width * 50) / 100, (height * 60) / 100));
	EaseOut*actionEase3 = EaseOut::create(actionMove3, 2.0f);

	CallFunc*mariofire = CallFunc::create(CC_CALLBACK_0(HelloWorld::marioNB, this));
	CallFunc*hammer = CallFunc::create(CC_CALLBACK_0(HelloWorld::kirbySideB, this));
	CallFunc*kirbydash = CallFunc::create(CC_CALLBACK_0(HelloWorld::kirbyRun, this));
	CallFunc*mariolast = CallFunc::create(CC_CALLBACK_0(HelloWorld::kirbylastStandBy, this));
	Sequence*smashcome = Sequence::create(action1, delays, actionEase1, hammer, actionEase2, delaysmini, kirbydash, mariofire, actionEase3, mariolast, nullptr);
	smashball->runAction(smashcome);
	this->addChild(smashball, 80);
}

void HelloWorld::smashdisappear()
{
	RemoveSelf*removesmash = RemoveSelf::create();
	smashball->runAction(removesmash);
	
	black->setOpacity(100);
}

void HelloWorld::bowserframeOut()
{
    RemoveSelf*remove = RemoveSelf::create();
	
	mariofinal->runAction(remove);
	MoveBy*futtobi = MoveBy::create(0.8f, Vec2(-width, (height*20)/100));
	EaseIn*actionEase1 = EaseIn::create(futtobi, 2.0f);
	DelayTime*delays = DelayTime::create(0.2f);
	CallFunc*burst = CallFunc::create(CC_CALLBACK_0(HelloWorld::bowserdisappear, this));
	Sequence*smashcome = Sequence::create(actionEase1,burst,nullptr);
	bowser->runAction(smashcome);
}

void HelloWorld::dededeframeOut()
{
	RemoveSelf*remove = RemoveSelf::create();

	ultrasword->runAction(remove);
	MoveBy*futtobi = MoveBy::create(0.8f, Vec2(width*2, (height * 20) / 100));
	EaseIn*actionEase1 = EaseIn::create(futtobi, 2.0f);
	DelayTime*delays = DelayTime::create(0.2f);
	CallFunc*burst = CallFunc::create(CC_CALLBACK_0(HelloWorld::dedededisappear, this));
	Sequence*smashcome = Sequence::create(actionEase1, burst, nullptr);
	dedede->runAction(smashcome);
}

void HelloWorld::bowserdisappear()
{
	CallFunc*mariocome = CallFunc::create(CC_CALLBACK_0(HelloWorld::marioBack, this));
	marioawake->runAction(mariocome);
	RemoveSelf*remove = RemoveSelf::create();
	CallFunc*burstbowser = CallFunc::create(CC_CALLBACK_0(HelloWorld::burstOut, this));
	Sequence*burston = Sequence::create(remove, burstbowser, nullptr);
	bowser->runAction(burston);
	MoveBy*action1 = MoveBy::create(0.02f, Vec2(30, 40));
	MoveBy*action2 = MoveBy::create(0.04f, Vec2(-20, -20));
	MoveBy*action3 = MoveBy::create(0.04f, Vec2(20, 20));
	MoveBy*action4 = MoveBy::create(0.02f, Vec2(-30, -40));
	Sequence*actionquake = Sequence::create(action2, action3, nullptr);
	Sequence*actionflip = Sequence::create( action1, actionquake, actionquake, actionquake, actionquake, action4, nullptr);
	field->runAction(actionflip);
}

void HelloWorld::dedededisappear()
{
	CallFunc*kirbycome = CallFunc::create(CC_CALLBACK_0(HelloWorld::kirbyBack, this));
	marioawake->runAction(kirbycome);
	RemoveSelf*remove = RemoveSelf::create();
	CallFunc*burstbowser = CallFunc::create(CC_CALLBACK_0(HelloWorld::burstOut2, this));
	Sequence*burston = Sequence::create(remove, burstbowser, nullptr);
	dedede->runAction(burston);
	MoveBy*action1 = MoveBy::create(0.02f, Vec2(30, 40));
	MoveBy*action2 = MoveBy::create(0.04f, Vec2(-20, -20));
	MoveBy*action3 = MoveBy::create(0.04f, Vec2(20, 20));
	MoveBy*action4 = MoveBy::create(0.02f, Vec2(-30, -40));
	Sequence*actionquake = Sequence::create(action2, action3, nullptr);
	CallFunc*endroll = CallFunc::create(CC_CALLBACK_0(HelloWorld::ending, this));
	Sequence*actionflip = Sequence::create(action1, actionquake, actionquake, actionquake, actionquake, action4,endroll,nullptr);
	field->runAction(actionflip);
}

void HelloWorld::ending()
{
	isEndFlag = true;
}

