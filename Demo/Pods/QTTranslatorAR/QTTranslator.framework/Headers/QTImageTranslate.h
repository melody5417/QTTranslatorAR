//
//  QTImageTranslate.h
//  QTTranslator
//
//  Created by yiqiwang(王一棋) on 2018/12/10.
//  Copyright © 2018 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class QTImageTranslateRecord;

NS_ASSUME_NONNULL_BEGIN

@interface QTImageTranslateReq : NSObject

/**
 * 本次翻译的唯一识别, 建议填写
 */
@property (nonatomic, copy) NSString *sessionId;

/**
 * 翻译的源图片
 */
@property (nonatomic, strong) UIImage *sourceImage;

/**
 * 翻译的源语言类型，具体种类见 QTLangType
 * 通过 langAbbrFromType(QTLangType) 方法构造
 * 图片翻译支持中文到 （英、日、韩、西班牙、法、德、越、马来、意大利、葡萄牙）的互译
 * 不指定sourceLang和targetLang时，采用candidateLangPair
 */
@property (nonatomic, copy, nullable) NSString *sourceLang;

/**
 * 翻译的目标语言类型，具体种类见 QTLangType
 * 通过 langAbbrFromType(QTLangType) 方法构造
 * 图片翻译支持中文到 （英、日、韩、西班牙、法、德、越、马来、意大利、葡萄牙）的互译
 * 不指定sourceLang和targetLang时，采用candidateLangPair
 */
@property (nonatomic, copy, nullable) NSString *targetLang;

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
 * 判断参数合法性
 */
- (BOOL)isValid;


@end

@interface QTImageTranslateRsp : NSObject

/**
 * 本次翻译请求的UUID
 */
@property (nonatomic, copy) NSString *sessionId;

/**
 * 翻译的源图片
 */
@property (nonatomic, strong) UIImage *sourceImage;

/**
 * 翻译的结果图片
 */
@property (nonatomic, strong) UIImage *targetImage;

/**
 * 图片的OCR及文本翻译结果
 */
@property (nonatomic, strong) NSArray<QTImageTranslateRecord *> *records;

/**
 * 翻译的源语言类型，具体种类见 QTLangType
 * 通过 langAbbrFromType(QTLangType) 方法构造
 * 图片翻译支持中文到 （英、日、韩、西班牙、法、德、越、马来、意大利、葡萄牙）的互译
 * 不指定sourceLang和targetLang时，采用candidateLangPair
*/
@property (nonatomic, copy) NSString *sourceLang;

/**
 * 翻译的目标语言类型，具体种类见 QTLangType
 * 通过 langAbbrFromType(QTLangType) 方法构造
 * 图片翻译支持中文到 （英、日、韩、西班牙、法、德、越、马来、意大利、葡萄牙）的互译
 * 不指定sourceLang和targetLang时，采用candidateLangPair
*/
@property (nonatomic, copy) NSString *targetLang;

/**
 * 错误码，成功时为0
 */
@property (nonatomic) int errCode;

/**
 * 错误信息
 */
@property (nonatomic, copy) NSString *errMsg;

@end

@interface QTImageTranslateRecord : NSObject

@property (nonatomic, copy) NSString *sourceText;
@property (nonatomic, copy) NSString *targetText;
@property (nonatomic) CGRect rect;
@property (nonatomic) NSUInteger rowCount;
@property (nonatomic) NSUInteger fontSize;
@property (nonatomic) NSUInteger lineSpace;
@property (nonatomic) double angle;

@end

NS_ASSUME_NONNULL_END
