//
//  QTLanguageManager.h
//  QBTranslator
//
//  Created by Charles Chen on 2018/3/14.
//  Copyright © 2018年 k. All rights reserved.
//

#import "QTLanguageDefine.h"

/**
 * 当前选择语言时会post该通知，调用方可监控该通知
 */
extern NSString *const kQTLanguageDidChangeNotification;

@interface QTLanguageManager : NSObject

// 当前语言对，默认 "中 — 英"
@property (nonatomic, strong) QTLanguagePair * _Nonnull languagePair;

// 支持的语言对，详见 @QTLangType
@property (nonatomic, strong) NSArray<QTLanguagePair *> * _Nonnull supportedLanguagePairs;

+ (instancetype _Nonnull)shared;

@end
