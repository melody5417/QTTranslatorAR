//
//  CloudRetrievaMarkerInfo.h
//  tar
//
//  Created by carmzhu on 2017/12/25.
//  Copyright © 2017年 carmzhu. All rights reserved.
//

#ifndef CloudRetrievaMarkerInfo_h
#define CloudRetrievaMarkerInfo_h

#import "JSONDecoder.h"
@interface CloudRetrievaMarkerInfo : NSObject<JSONJoy>
@property(nonatomic, readonly) NSString* sTid;
@property(nonatomic, readonly) NSString* sUrl;
@property(nonatomic, readonly) NSString* sTargetName;
@property(nonatomic, readonly) NSString* vMetaData;
@property(nonatomic, readonly) NSString* sModifyTime;
-(instancetype)init:(JSONDecoder*)decoder;
@end

#endif /* CloudRetrievaMarkerInfo_h */
