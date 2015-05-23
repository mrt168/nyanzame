//
//  GameScene.h
//  Mario
//
//  Created by 藍口康希 on 2015/05/17.
//
//

#ifndef __Mario__GameScene__
#define __Mario__GameScene__

#include "cocos2d.h"
#include "Config.h"

#define MAX_BLOCK_X 8
#define MAX_BLOCK_Y 8
#define REMOVING_TIME 0.1f
#define MOVING_TIME 0.2f

#define KEY_HIGHSCORE "HighScore"


#define PNG_BACKGROUND "background.png"
#define PNG_GAMEOVER "gameover.png"
#define PNG_RESET "reset1.png"
#define MP3_REMOVE_BLOCK "removeBlock.mp3"

#define FONT_RED "fonts/redFont.fnt"
#define FONT_BLUE "fonts/blueFont.fnt"
#define FONT_YELLOW "fonts/yellowFont.fnt"
#define FONT_GREEN "fonts/greenFont.fnt"
#define FONT_GRAY "fonts/grayFont.fnt"
#define FONT_WHITE "fonts/whiteFont.fnt"

class GameScene : public cocos2d::Layer
{
protected:
    enum kTag
    {
        KTagBackground = 1,
        kTagRedLabel,
        kTagBlueLabel,
        kTagYellowLabel,
        kTagGreenLabel,
        kTagGrayLabel,
        kTagScoreLabel,
        kTagGameOver,
        kTagHighScoreLabel,
        kTagBaseBlock = 10000,
    };
    
    enum kZOrder
    {
        kZOrderBackground,
        kZOrderLabel,
        kZOrderBlock,
        kZOrderGameOver,
    };
    
    struct PositionIndex
    {
        PositionIndex(int x1, int y1)
        {
            x = x1;
            y = y1;
        }
        int x;
        int y;
    };
    //2-2-3
    cocos2d::Sprite* m_background;
    void showBackground();
    
    //2-2-4
    float m_blockSize;
    std::map<kBlock , std::list<int>> m_blockTags;
    void initForVariables();
    void showBlock();
    cocos2d::Point getPosition(int posIndexX , int posIndexY);
    int getTag(int posIndexX, int posIndexY);
    
    //2-2-5
    
    void getTouchBlockTag(cocos2d::Point touchPoint, int &tag, kBlock &blockType);
    std::list<int> getSameColorBlockTags(int baseTag, kBlock blockType);
    void removeBlock(std::list<int> blockTags, kBlock blockType);
    bool hasSameColorBlock(std::list<int> blockTagList, int searchBlockTag);
    
    //2-3-1
    void removingBlock(cocos2d::Node* block);
    
    //2-3-2
    std::vector<kBlock> blockTypes;
    PositionIndex getPositionIndex(int tag);
    void setNewPosition1(int tag, PositionIndex posIndex);
    void searchNewPosition1(std::list<int> blocks);
    void moveBlock();
    void movingBlocksAnimation1(std::list<int> blocks);
    
    //2-3-3
    bool m_animating;
    void movedBlocks(float delta);
    std::map<int, bool> getExistsBlockColumn();
    void searchNewPosition2();
    void setNewPosition2(int tag, PositionIndex posIndex);
    void movingBlocksAnimation2(float delta);
    
    //2-4-1
    void showLabel();
    
    //2-4-2
    int m_score;
    
    //2-4-3
    bool existsSameBlock();
    
    //2-4-4
    void saveHighScore();
    void showHighScoreLabel();
    
    //2-4-5
    void menuResetCallback(cocos2d::Object* pSender);
    void showResetButton();
    
    
public:
    virtual bool init();
    static cocos2d::Scene* scene();
    CREATE_FUNC(GameScene);
    
    virtual bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
    virtual void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
};


#endif /* defined(__Mario__GameScene__) */
