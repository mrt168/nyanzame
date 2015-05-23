//
//  Config.h
//  Mario
//
//  Created by 藍口康希 on 2015/05/17.
//
//

#ifndef __Mario__Config__
#define __Mario__Config__

enum kBlock
{
    kBlockRed,
    kBlockBlue,
    kBlockYellow,
    kBlockGreen,
    kBlockGray,
    kBlockCount,
};

#define ccsf(...) String::createWithFormat(__VA_ARGS__)->getCString()

#endif /* defined(__Mario__Config__) */
