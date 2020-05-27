//
//  QTTranslateDefine.h
//  QTTranslator
//
//  Created by yiqiwang(王一棋) on 2019/9/18.
//  Copyright © 2019 tencent. All rights reserved.
//

#ifndef QTTranslateDefine_h
#define QTTranslateDefine_h

typedef NS_ENUM(NSInteger, UseNetworkSendingMode){
    UseNetworkSendingModeAll,
    UseNetworkSendingModeOnlyWup,
    UseNetworkSendingModeOnlyWebsocket,
};

typedef NS_ENUM(NSInteger, QTTranslateEnv){
    QTTranslateEnvRelease,  // 发布模式
    QTTranslateEnvDebug,    // 开发模式
};

typedef NS_ENUM(NSInteger, QTTranslateARStatus){
    QTTranslateARStatusMove,    // 设备移动
    QTTranslateARStatusStable,  // 设备稳定
    QTTranslateARStatusRequest, // 发起AR翻译
    QTTranslateARStatusTrack,   // AR翻译成功，跟踪Marker
    QTTranslateARStatusError,   // 设备长期稳定且未识别到有效文本,不再进行AR识别
};

#endif /* QTTranslateDefine_h */
