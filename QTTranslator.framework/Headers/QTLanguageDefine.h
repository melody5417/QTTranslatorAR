//
//  QTLanguageDefine.h
//  QBTranslator
//
//  Created by Charles Chen on 2018/3/14.
//  Copyright © 2018年 k. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AVSpeechSynthesisVoice;

typedef NS_ENUM(NSInteger, QTLangType) {
    QTLangTypeUnknown = -1,
    QTLangTypeZh      = 0,  // Chinese
    QTLangTypeEn      = 1,  // English
    QTLangTypeJp      = 2,  // Japanese
    QTLangTypeKr      = 3,  // Korean
    QTLangTypeEs      = 4, // 西班牙
    QTLangTypeRu      = 5,  // Russian
    QTLangTypeFr      = 6,  // French
    QTLangTypeDe      = 7,  // German
    QTLangTypeTh      = 8,  // 泰国
    QTLangTypeVn      = 9,  // 越南
    QTLangTypeId      = 10,  // 印度尼西亚
    QTLangTypeMy      = 11, // 马来西亚
    QTLangTypeIt      = 12, // 意大利
    QTLangTypePt      = 13, // 葡萄牙
    QTLangTypeTr      = 14  // 土耳其
};

NSDictionary * _Nonnull langAbbrMapper(void);

// 缩写转语言类型，eg. "zh" --> QTLangTypeZh
QTLangType langTypeFromAbbr(NSString * _Nonnull abbr);

// 语言类型转缩写，eg. QTLangTypeZh --> "zh"
NSString * _Nonnull langAbbrFromType(QTLangType langType);

// 获取语音合成
NSString * _Nullable langSpeechFromType(QTLangType langType);

// 获取语言名称国际化文案（系统），eg. zh --> "中文" or "Chinese"
NSString * _Nonnull langNameFromType(QTLangType langType);

// 获取拍照翻译语言名称国际化文案（系统），eg. zh --> "中文" or "Chinese"
NSString * _Nonnull langPhotoNameFromType(QTLangType langType);

// 获取语言简写国际化文案（系统），eg. zh --> "中" or "Chinese"
NSString * _Nonnull langLogogramFromType(QTLangType langType);

// 获取搜索栏下部语种切换
NSString * _Nonnull langSearchBarFromType(QTLangType langType);

// 获取按住说话国际化文案，eg. zh --> "按住说话" or en --> "Hold to Talk" ...
NSString * _Nonnull langHoldToTalkFromType(QTLangType langType);

// 获取点击翻译国际化文案，eg. zh --> "点击翻译" or en --> "Tap to translate" ...
NSString * _Nonnull langTapToTranslateFromType(QTLangType langType);

// 获取松手翻译国际化文案，eg. zh --> "松手翻译 上滑取消" or en --> "Release to translate, slide up to cancel" ...
NSString * _Nonnull langReleaseToTranslateFromType(QTLangType langType);

// 获取松手取消国际化文案，eg. zh --> "松开手指 取消翻译" or en --> "Release to cancel" ...
NSString * _Nonnull langReleaseToCancelFromType(QTLangType langType);

// 获取翻译中国际化文案，eg. zh --> "正在翻译成" or en --> "Translating into" ...
NSString * _Nonnull langTranslatingFromType(QTLangType langType, QTLangType targetLangType);

// 获取请说某种语言国际化文案，eg. zh --> "请说中文" or en --> "Please speak English" ...
NSString * _Nonnull langSpeakSomeFromType(QTLangType langType);

// 获取聆听中国际化文案，eg. zh --> "正在聆听..." or en --> "Listening..." ...
NSString * _Nonnull langListeningFromType(QTLangType langType);

BOOL langIsValid(QTLangType langType);

@interface QTLanguagePair : NSObject <NSCoding>

@property (nonatomic, assign) QTLangType source;
@property (nonatomic, assign) QTLangType target;

- (instancetype _Nonnull)initWithSource:(QTLangType)source target:(QTLangType)target;
- (BOOL)isValid;

// 语言对简写，eg. "中 — 英"
- (NSString * _Nonnull)logogram;

// 语言对简写，eg. "zh2en"
- (NSString * _Nonnull)stataValue;

// 语言对简写，eg. "zh|en"
- (NSString * _Nonnull)reqValue;

// 语言对 icon，首页切换语言按钮 icon
- (UIImage * _Nonnull)icon;

@end
