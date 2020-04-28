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

#endif /* QTTranslateDefine_h */
