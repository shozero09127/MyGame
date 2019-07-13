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

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
	int state;//0=��,1=��,2=��,3=��
	int walk;//0=stay,1=right,2=stay,3=left
	int audioID;
	int timer = 60;
	int randomscorex;
	int randomscorey;
	float width;
	float height;
	float spritewidth;
	float spriteheight;
	float spritewidthano;
	float spriteheightano;
	float scenewidth;
	float sceneheight;
    virtual bool init();
	void update(float delta)override;
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	void countdown();
	void dokanPop();
	void warpStar();
	void kirbyStand();
	void marioStand();
	void myFunction();
	void soundPlay();
	void setRandom();
	void lastSmashmario();
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
	cocos2d::Sprite*sprite;//update���ł�sprite�̑���
	cocos2d::Sprite*sprite2;
	cocos2d::Sprite*spriterect;
	cocos2d::Sprite*field;
	cocos2d::Sprite*dokan;
	cocos2d::Sprite*warpstark;
	cocos2d::Sprite*marioawake;
	cocos2d::Sprite*mariofinal[5];
	cocos2d::Sprite*urtlasword[10];
	cocos2d:: Sprite*countmoji[4];
};

#endif // __HELLOWORLD_SCENE_H__
