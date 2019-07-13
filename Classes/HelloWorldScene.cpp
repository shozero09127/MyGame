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
	// �e�N�X�`���t�@�C�������w�肵�āA�X�v���C�g���쐬

	//�����̏������i�������ł���Random=new Random();
		//sprite[i]->setPosition(Vec2((width), (height)));//���W�i�n�_�͍����j
		//float mx, my;
		//mx = (rand()*600/RAND_MAX)-300;//���̂܂܂��ƂƂ�ł��Ȃ��ł������l�ɁE�E�E�B
		//my = (rand()*600 / RAND_MAX)-300;
		/*MoveTo* action1 = MoveTo::create(1.0f, Vec2(0,height));
		MoveTo* action2 = MoveTo::create(1.0f, Vec2(0, 0));*/
		/*
		MoveTo* action1 = MoveTo::create(1.0f, Vec2(width/2, 0));
		JumpBy* action2 = JumpBy::create(1.0f, Vec2(100.0f, 0.0f),200.0f,1);*/

		//Sequence* action5 = Sequence::create(action1, action2, action3, action4, nullptr);
		//Repeat* action2 = Repeat::create(action1,3);//�񐔂��w�肵�Ĕ���
		//RepeatForever* action2 = RepeatForever::create(action1);//�i���ɔ���
		/*Sequence* action3 = Sequence::create(action1, action2, nullptr);
		FadeTo *action4 = FadeTo::create(1.0f,0000);
		FadeTo *action5 = FadeTo::create(1.0f, 255);
		Sequence* action6 = Sequence::create(action4, action5, nullptr);
		Spawn* action7 = Spawn::create(action3, action6, nullptr);
		Repeat* action8 = Repeat::create(action7, 5);*/
		//Repeat *action3 = Repeat::create(action2,100);
		//Sequence *action4 = Sequence::create(action1, action3, nullptr);//���ꂾ��RepeatForever�̃A�N�V�������Ăяo����Ȃ��B
		//
		//���ԂŎ��s����B
		/*sprite[i]->runAction(action4);*/
		/*
		MoveTo* action3 = MoveTo::create(1.0f, Vec2(width, height));
		EaseIn* action4 = EaseIn::create(action3, 2.0f);
		sprite[i]->runAction(action4);*
	// �V�[���O���t�ɂȂ�
	/*sprite[1] = Sprite::create("shien.png");
	this->addChild(sprite[1]);
	sprite[1]->setScaleX(0.25f);
	sprite[1]->setScaleY(0.3f);
	sprite[1]->setPosition(Vec2((width ) / 2, (height ) / 2));
	sprite[1]->setOpacity(0x00);
	FadeTo*action3 = FadeTo::create(1.0f, 255);
	EaseIn* action4 = EaseIn::create(action3, 2.0f);
	sprite[1]->runAction(action4);*/
	//MoveBy=�w�肵�����W���ړ�����B
	//MoveTo=�w�肵�����W�Ɉړ�����B
	
	//EaseIn ���ɂȂ�A�N�V�������w�肵�A���������������B
	//FadeTo �w�肵���t�F�[�h�ɕω�����B
	//ScaleBy �w�肵���傫���֕ω�����BTo�͕ύX�̉e�����󂯂�B
	//JumpBy �w�肵�����W�֎w�肵�������ɓ��B�����W�����v�֎w�肵���񐔍s���ړ�����B
	//RotateBy �w�肵�����W����]����B�Ή����鎲�ŕύX����B�x���Q�ƁB
	//Blink �w��񐔓_�ł���B�w�i�ɐԉ摜�ł��̂͐�΂ɂ�߂悤�i���^�j

	//spriterect->setPosition(Vec2(width / 2, height / 2));
	//sprite->setAnchorPoint(Vec2(0.5f, 0.5f));//�摜�̍�����0,0�E�オ1,0�̍��W�n
	////sprite2->setPosition(Vec2(width / 2, height / 2));//���W�i�n�_�͍����j
	////sprite2->setAnchorPoint(Vec2(1.0f, 0.0f));//�摜�̍�����0,0�E�オ1,0�̍��W�n
	
	//sprite2->setOpacity(0);
	////sprite->setRotation(45.0f);
	//sprite->setFlippedX(true);//���E���]
	////sprite->setFlippedY(true);//�㉺���]
	//sprite->setVisible(true);//�\�����邩�ۂ�
	//sprite->setVisible(true);//�\�����邩�ۂ�
	//scenewidth = width - spritewidth;
	//sceneheight = height - spriteheight;
	//sprite->setColor(Color3B(0.0f, 0.0f, 255.0f));//�F�����̐ݒ�
	//

	////sprite->setOpacity(0x80);//�s�����x�̐ݒ�
	////�Ō�̐ݒ肪���f�����
	//state = 0;
	//walk = 0;
	/*CallFunc*action = CallFunc::create(CC_CALLBACK_0(HelloWorld::myFunction, this));
	this->runAction(action);*/
	field = Sprite::create("senjo.png");
	field->setPosition(Vec2(width / 2, height / 2));
	this->addChild(field);
	CallFunc*maction = CallFunc::create(CC_CALLBACK_0(HelloWorld::dokanPop, this));
	CallFunc*kaction = CallFunc::create(CC_CALLBACK_0(HelloWorld::warpStar, this));
	Sequence* action3 = Sequence::create(maction, kaction, nullptr);
	CallFunc*countaction = CallFunc::create(CC_CALLBACK_0(HelloWorld::countdown, this));
	this->runAction(countaction);
	this->runAction(action3);
	
	this->scheduleUpdate();//Update�̗L����
	
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
//	Vec2 pos ;//���ݍ��W�̊l��
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
//	//�����ɍX�V�����������B
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
//	//�l�����������������f�@����̃��[�v
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
void HelloWorld::dokanPop()
{
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
	this->addChild(marioawake);
	this->addChild(dokan);
}
void HelloWorld::warpStar()
{
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
	this->addChild(warpstark);
}

void HelloWorld::kirbyStand()
{
	warpstark->setTexture("kkk.png");
	JumpBy* action1 = JumpBy::create(0.5f, Vec2(-20, 0), 70, 1);
	warpstark->runAction(action1);
}

void HelloWorld::marioStand()
{
	marioawake->setTexture("mariostand.png");
	marioawake->setScale(1.5f);
}
void HelloWorld::countdown()
{
	audioID = experimental::AudioEngine::play2d("countdowncut.mp3");
	countmoji[3] = Sprite::create("3.png");
	countmoji[2] = Sprite::create("2.png");
	countmoji[1] = Sprite::create("1.png");
	countmoji[0] = Sprite::create("GO!.png");
	for (int i = 0; i < 4; i++)
	{
		countmoji[i]->setPosition(Vec2((width * 50) / 100, (height * 90) / 100));
		countmoji[i]->setOpacity(0);
		this->addChild(countmoji[i]);
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