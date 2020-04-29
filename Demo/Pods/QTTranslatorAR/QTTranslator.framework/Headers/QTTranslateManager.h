//
//  QTTranslateManager.h
//  QTTranslator
//
//  Created by yiqiwang(王一棋) on 2018/12/7.
//  Copyright © 2018 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QTTextTranslate.h"
#import "QTImageTranslate.h"
#import "QTTranslateDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface QTTranslateManager : NSObject

/**
 * AppId， 产品接入唯一标识，必须在 setup 之前填写
 */
@property (nonatomic, copy) NSString *appId;
/**
 * 网络设置 默认ALL
 * 仅限内网调试用，接入方不用设置
 */
@property (nonatomic, assign) UseNetworkSendingMode networkSendingStatus;
/**
 * 开发环境 默认Release
 * Debug 模式仅支持内网调试
 */
@property (nonatomic, assign) QTTranslateEnv envMode;

/**
 * 是否打开Log， 默认NO
 */
@property (nonatomic, assign) BOOL enableLog;

/**
 * 翻译单例
 */
+ (instancetype)shared;

/**
 * 初始设置
 * 必须调用，且在 appId 设置后调用
 */
- (void)setup;

/**
 * 文本翻译
 * @return 操作是否成功
 */
- (BOOL)translateText:(QTTextTranslateReq *)req
             complete:(void (^)(QTTextTranslateRsp *))completeHandler;

/**
 * 图片翻译
 * @return 操作是否成功
 */
- (BOOL)translateImage:(QTImageTranslateReq *)req
              complete:(void (^)(QTImageTranslateRsp *))completeHandler;

@end

NS_ASSUME_NONNULL_END
