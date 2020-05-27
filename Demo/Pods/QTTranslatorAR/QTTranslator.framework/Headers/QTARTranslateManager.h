//
//  QTARTranslateManager.h
//  QTTranslator
//
//  Created by yiqiwang(王一棋) on 2019/2/19.
//  Copyright © 2019 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QTLanguageDefine.h"

NS_ASSUME_NONNULL_BEGIN



@protocol QTARTranslateManagerDelegate <NSObject>

/**
 * AR翻译开启的回调
 * AR引擎的回调 一定会收到
 */
- (void)didStart;

/**
 * AR翻译状态切换的回调
 * @param status AR翻译状态 类型为 QTTranslateARStatus 见文件 QTTranslateDefine.h
 * NOTE：为UI线程，在这个回调做大量操作可能阻塞camera图片渲染
 */
- (void)statusDidChange:(QTTranslateARStatus)status;

/**
 * AR翻译关闭的回调
 * AR引擎的回调 有时会收不到
 */
- (void)didStop;

@end

@interface QTARTranslateManager : NSObject

/**
 * 初始化AR翻译引擎
 * @param controller 传入依赖的viewController用来展示
 */
- (instancetype)initWithController:(UIViewController * _Nonnull )controller
                          delegate:(id<QTARTranslateManagerDelegate> _Nullable)delegate;

/**
 * 配置AR翻译引擎
 * @param source 翻译的源语言类型。具体种类见 QTLangType，通过 langAbbrFromType(QTLangType) 方法构造
 * @param target 翻译的目标语言类型。具体种类见 QTLangType，通过 langAbbrFromType(QTLangType) 方法构造
 * AR翻译支持中文到 （英、日、韩、西班牙、法、德、越、马来、意大利、葡萄牙）的互译
 */
- (void)configureWithSource:(NSString *)source target:(NSString *)target;

/**
 * 获取当前视频帧
 */
- (UIImage *)getCurrentFrame;

/**
 * 开始AR翻译引擎
 */
- (void)resume;
/**
 * 暂停AR翻译引擎
 */
- (void)pause;
/**
 * 释放AR翻译引擎
 */
- (void)releaseEngine;

@end

NS_ASSUME_NONNULL_END
