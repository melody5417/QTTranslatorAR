//
//  CloudResult.h
//  tar
//
//  Created by carmzhu on 2017/12/25.
//  Copyright © 2017年 carmzhu. All rights reserved.
//

#ifndef CloudResult_h
#define CloudResult_h

#import "JSONDecoder.h"
#import "CloudSSDInfo.h"
#import "CloudRetrievaMarkerInfo.h"
@interface CloudResult : NSObject<JSONJoy>
@property(nonatomic, readonly) int iRetCode;
@property(nonatomic, readonly) NSString* sMsg;
@property(nonatomic, readonly) int iResponsType;
@property(nonatomic, readonly) NSString* sKey;
@property(nonatomic, readonly) NSArray<CloudSSDInfo*>* vRetrievalInfo;
@property(nonatomic, readonly) NSArray<CloudRetrievaMarkerInfo*>* vMarker;
-(instancetype)init:(JSONDecoder*)decoder;
@end


#endif /* CloudResult_h */
