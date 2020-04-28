//
//  QTTextTranslate.h
//  QTTranslator
//
//  Created by yiqiwang(王一棋) on 2018/12/7.
//  Copyright © 2018 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface QTTranslateDictInterpretation : NSObject

/**
 * 翻译的目标文本
 */
@property (nonatomic, copy) NSString *targetText;

/**
 * 词类
 */
@property (nonatomic, copy) NSString *category;

@end



@interface QTTranslateDict : NSObject

/**
 * 翻译的源语言
 */
@property (nonatomic, copy) NSString *sourceLang;

/**
 * 翻译的目标语言
 */
@property (nonatomic, copy) NSString *targetLang;

/**
 * 翻译的源文本
 */
@property (nonatomic, copy) NSString *sourceText;

/**
 * 翻译的目标文本
 */
@property (nonatomic, strong) NSArray <QTTranslateDictInterpretation *> *targetInterpretations;

/**
 * 美式发音 默认发音
 */
@property (nonatomic, copy) NSString *amPronunciation;

/**
* 英式发音
*/
@property (nonatomic, copy) NSString *brPronunciation;

@end


@interface QTTextTranslateReq : NSObject

/**
 * 本次翻译的唯一识别, 建议填写
 */
@property (nonatomic, copy) NSString *sessionUUID;

/**
 * 翻译的源文本
 */
@property (nonatomic, copy) NSString *sourceText;

/**
 * 翻译的源语言类型，具体种类见 QTLangType
 * 通过 langAbbrFromType(QTLangType) 方法构造
 * 文本翻译支持 中文到（英、日、韩、俄、法、德、泰、越、印尼、马来、西班牙、葡萄牙、意大利、土耳其）的互译
 * 不指定sourceLang和targetLang时，采用candidateLangPair
 */
@property (nonatomic, copy, nullable) NSString *sourceLang;

/**
 * 翻译的目标语言类型，具体种类见 QTLangType
 * 通过 langAbbrFromType(QTLangType) 方法构造
 * 文本翻译支持 中文到（英、日、韩、俄、法、德、泰、越、印尼、马来、西班牙、葡萄牙、意大利、土耳其）的互译
 * 不指定sourceLang和targetLang时，采用candidateLangPair
 */
@property (nonatomic, copy, nullable) NSString *targetLang;

/**
 * 翻译的语言对类型，具体种类见 QTLangType
 * 构造方法：
 * QTLanguagePair *langPair = [[QTLanguagePair alloc] initWithSource:QTLangTypeZh tar get:QTLangTypeEn];
 * candidateLangPair = [langPair reqValue];
 * sourceLang targetLang 优先级更高
 * 若 sourceLang, targetLang 有值，则以 sourceLang, targetLang 为准
 * 若 sourceLang, targetLang 有值，且 candidateLangPair 非空，以 candidateLangPair 为准
 */
@property (nonatomic, copy) NSString *candidateLangPair;

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



@interface QTTextTranslateRsp : NSObject

/**
 * 本次翻译的唯一识别
 */
@property (nonatomic, copy) NSString *sessionUUID;

/**
 * 错误码，成功时为0
 */
@property (nonatomic) int errCode;

/**
 * 错误信息
 */
@property (nonatomic, copy) NSString *errMsg;

/**
 * 翻译的源文本
 */
@property (nonatomic, copy) NSString *sourceText;

/**
 * 翻译的目标文本
 */
@property (nonatomic, copy) NSString *targetText;

/**
 * 翻译的源语言类型，具体种类见 QTLangType
 * 通过 langAbbrFromType(QTLangType) 方法构造
 * 文本翻译支持 中文到（英、日、韩、俄、法、德、泰、越、印尼、马来、西班牙、葡萄牙、意大利、土耳其）的互译
 * 不指定sourceLang和targetLang时，采用candidateLangPair
*/
@property (nonatomic, copy) NSString *sourceLang;

/**
 * 翻译的目标语言类型，具体种类见 QTLangType
 * 通过 langAbbrFromType(QTLangType) 方法构造
 * 文本翻译支持 中文到（英、日、韩、俄、法、德、泰、越、印尼、马来、西班牙、葡萄牙、意大利、土耳其）的互译
 * 不指定sourceLang和targetLang时，采用candidateLangPair
*/
@property (nonatomic, copy) NSString *targetLang;

/**
 * 翻译的语言对类型，具体种类见 QTLangType
 * 自动识别语言对方向
 * 构造方法：
 * QTLanguagePair *langPair = [[QTLanguagePair alloc] initWithSource:QTLangTypeZh tar get:QTLangTypeEn];
 * candidateLangPair = [langPair reqValue];
 * sourceLang targetLang 优先级更高
 * 若 sourceLang, targetLang 有值，则以 sourceLang, targetLang 为准
 * 若 sourceLang, targetLang 有值，且 candidateLangPair 非空，以 candidateLangPair 为准
*/
@property (nonatomic, copy) NSString *candidateLangPair;

/**
 * 翻译的词典信息
 */
@property (nonatomic, strong) NSArray <QTTranslateDict *> *targetDics;

@end


NS_ASSUME_NONNULL_END
