//
//  QTTtsManager.h
//  QTTranslator
//
//  Created by yiqiwang(王一棋) on 2019/10/24.
//  Copyright © 2019 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QTTtsServiceReq.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^TtsEndBlock)(void);

@interface QTTtsManager : NSObject

+ (instancetype)shared;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-property-synthesis"
/**
 * 废弃，请使用 readTtsReq: endBlock
 */
- (BOOL)readText:(nonnull NSString *)text
        withLang:(QTLangType)lang
        endBlock:(nullable TtsEndBlock)end NS_UNAVAILABLE;
#pragma clang diagnostic pop

/**
 * tts服务接口
 * @return 操作是否成功
 */
- (BOOL)readTtsReq:(QTTtsServiceReq *)req
          endBlock:(nullable TtsEndBlock)end;

- (void)stopReading;

- (BOOL)isReading;

@end

NS_ASSUME_NONNULL_END
