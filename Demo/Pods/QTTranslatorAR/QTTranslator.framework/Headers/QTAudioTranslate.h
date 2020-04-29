//
//  QTAudioTranslate.h
//  QTTranslator
//
//  Created by yiqiwang(王一棋) on 2019/10/30.
//  Copyright © 2019 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QTTextTranslate.h"

NS_ASSUME_NONNULL_BEGIN

@interface QTAudioTranslateReq : NSObject

/**
 * 本次翻译的唯一识别, 建议填写
 */
@property (nonatomic, copy) NSString *sessionUUID;

/**
 * 翻译的源语言类型，具体种类见 QTLangType
 * 通过 langAbbrFromType(QTLangType) 方法构造
 * 语音翻译支持 中文到（英、日、韩、俄、法、德、泰、越、印尼、马来、西班牙、葡萄牙、意大利、土耳其）的互译
*/
@property (nonatomic, copy, nullable) NSString *sourceLang;

/**
 * 翻译的目标语言类型，具体种类见 QTLangType
 * 通过 langAbbrFromType(QTLangType) 方法构造
 * 语音翻译支持 中文到（英、日、韩、俄、法、德、泰、越、印尼、马来、西班牙、葡萄牙、意大利、土耳其）的互译
*/
@property (nonatomic, copy, nullable) NSString *targetLang;

/**
 * 翻译策略是否启用词典翻译, 默认为 NO
 * YES 启用词典翻译，且优先词典翻译，仅针对内部业务
 * NO 纯文本翻译
*/
@property (nonatomic, assign) BOOL enableDic;

/**
* 判断参数合法性
*/
- (BOOL)isValid;

@end

@interface QTAudioTranslateRsp : NSObject

/**
 * 语音翻译的文本结果
 */
@property (nonatomic, strong) QTTextTranslateRsp *translateRsp;

/**
 * 语音翻译的录音文件路径
 */
@property (nonatomic, copy) NSString *audioPath;

@end

NS_ASSUME_NONNULL_END
