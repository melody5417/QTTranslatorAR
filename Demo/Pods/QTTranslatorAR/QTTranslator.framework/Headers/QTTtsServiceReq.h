//
//  QTTtsServiceReq.h
//  QTTranslator
//
//  Created by yiqiwang(王一棋) on 2019/11/7.
//  Copyright © 2019 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, QTTtsVoice) {
    QTTtsVoiceNone,
    QTTtsVoiceBr,
    QTTtsVoiceAm
};

@interface QTTtsServiceReq : NSObject

/**
 * 本次服务的唯一识别, 建议填写
 */
@property (nonatomic, copy) NSString *sessionUUID;

/**
 * 待朗读的文本
 */
@property (nonatomic, copy) NSString *text;

/**
 * 朗读的语言类型，具体种类见 QTLangType
 * 支持中、英、日、韩、俄、法、德、泰、越、印尼、马来、西班牙、葡萄牙、意大利、土耳其
 */
@property (nonatomic, assign) QTLangType lang;

/**
 * 朗读的音色
 * 英语若无指定默认美式
 * 其他语言设置无效
 */
@property (nonatomic, assign) QTTtsVoice voice;

/**
 * 服务引擎
 */
@property (nonatomic, copy, readonly) NSString *provider;

/**
 * 音色名称
 */
@property (nonatomic, copy, readonly) NSString *voiceName;

/**
 * 语音速率 默认1.0
 * 取值范围 0.5 到 2.0
 */
@property (nonatomic, assign) CGFloat rate;

/**
* 判断参数合法性
*/
- (BOOL)isValid;

@end

NS_ASSUME_NONNULL_END
