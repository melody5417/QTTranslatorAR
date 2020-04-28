//
//  QTAudioTranslateManager.h
//  QTTranslator
//
//  Created by yiqiwang(王一棋) on 2019/2/27.
//  Copyright © 2019 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QTAudioTranslate.h"

NS_ASSUME_NONNULL_BEGIN

@protocol QTAudioTranslateManagerDelegate <NSObject>

/**
 * 语音翻译已开始
 */
- (void)didStartTranslate;

/**
 * 语音翻译已结束
 */
- (void)didStopTranslate;

/**
 * 收到语音识别的文本结果
 */
- (void)didReceiveRecognizingText:(NSString *)text;

/**
 * 语音识别错误 在此回调里主动结束本次语音翻译
 */
- (void)didReceiveRecognizeFail:(NSError *)error;

/**
 * 收到翻译结果
 */
- (void)didReceiveTranslateRsp:(QTAudioTranslateRsp *)rsp;

/**
 * 收到语音音量数据，可用于绘制波形图
 */
@optional
- (void)didReceiveVoicePower:(CGFloat)value;

@end

@interface QTAudioTranslateManager : NSObject

+ (instancetype)shared;

/**
 * 是否启动本地Vad， 默认不启用
 * 启用vad，语音翻译中发送静音片10s即主动结束语音翻译
 * 不启用vad，语音翻译本地一直发送直到后台终止session
 */
@property (nonatomic, assign) BOOL enableLocalVad;

/**
 * 语音翻译状态回调
 */
@property (nonatomic, weak) id<QTAudioTranslateManagerDelegate> delegate;

/**
 * 录音状态
 */
@property (nonatomic, readonly) BOOL isRecording;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-property-synthesis"
/**
 * 废弃，请使用 startWith:
 */
- (void)startWithSourceLang:(NSString *)source targetLang:(NSString *)target NS_UNAVAILABLE;
#pragma clang diagnostic pop

/**
 * 开启语音翻译
 * 和 startWith:audio:completion: 方法会互相抢占
 * @return 操作是否成功
 * 语音翻译支持 中文到其他语法，及其他语言到中文的互译
*/
- (BOOL)startWith:(QTAudioTranslateReq *)rep;

/**
 * 结束本次语音翻译服务，务必调用
 */
- (void)stop;

/**
 * 取消本次语音翻译服务
 */
- (void)cancel;

@end

NS_ASSUME_NONNULL_END
