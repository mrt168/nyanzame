//
//  CCPlaySE.cpp
//  Mario
//
//  Created by 藍口康希 on 2015/05/17.
//
//

#include "PlaySE.h"


#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

PlaySE::PlaySE(std::string sound)
{
    m_sound = sound;
}

PlaySE* PlaySE::create(std::string sound)
{
    PlaySE* pRet = new PlaySE(sound);
    if(pRet)
    {
        pRet->autorelease();
    }
    return pRet;
}

void PlaySE::update(float time)
{
    CC_UNUSED_PARAM(time);
    SimpleAudioEngine::getInstance()->playEffect(m_sound.c_str());
}

FiniteTimeAction* PlaySE::reverse()
{
    return (FiniteTimeAction*)(PlaySE::create(m_sound));
}

//CCObject* CCPlaySE::copyWithZone(CCZone* pZone){
//    CCZone* pNewZone = NULL;
//    CCPlaySE* pRet = NULL;
//    if(pZone && pZone->m_pCopyObject){
//        pRet = (CCPlaySE*) (pZone->m_pCopyObject);
//    }
//    else
//    {
//        pRet = new CCPlaySE(m_sound);
//        pZone = pNewZone = new CCZone(pRet);
//    }
//    
//    cocos2d::Clonable::clone();
//    CC_SAFE_DELETE(pNewZone);
//    return pRet;
//}


