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

@interface QTARTranslateManager : NSObject

/**
 * 初始化AR翻译引擎
 * @param controller 传入依赖的viewController用来展示
 */
- (instancetype)initWithController:(UIViewController * _Nonnull )controller;

/**
 * 配置AR翻译引擎
 * @param source 翻译的源语言类型。具体种类见 QTLangType，通过 langAbbrFromType(QTLangType) 方法构造
 * @param target 翻译的目标语言类型。具体种类见 QTLangType，通过 langAbbrFromType(QTLangType) 方法构造
 * AR翻译支持中文到 （英、日、韩、西班牙、法、德、越、马来、意大利、葡萄牙）的互译
 */
- (void)configureWithSource:(NSString *)source target:(NSString *)target;

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
