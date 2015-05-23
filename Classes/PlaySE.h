//
//  CCPlaySE.h
//  Mario
//
//  Created by 藍口康希 on 2015/05/17.
//
//

#ifndef Mario_CCPlaySE_h
#define Mario_CCPlaySE_h

#include "cocos2d.h"

class PlaySE : public cocos2d ::ActionInstant
{
public:
    PlaySE(std::string sound);
    virtual ~PlaySE(){}
    
    virtual void update(float time);
    virtual FiniteTimeAction* reverse(void);
//    virtual cocos2d::CCObject* copyWithZone(cocos2d::CCZone* pZone);
    
public:
    static PlaySE* create(std:: string sound);
    
protected:
    std::string m_sound;
};

#endif
