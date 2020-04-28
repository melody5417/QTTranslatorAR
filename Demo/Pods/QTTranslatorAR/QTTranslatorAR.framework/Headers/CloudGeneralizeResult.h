//
//  CloudGeneralizeResult.h
//  tar
//
//  Created by carmzhu on 2017/12/25.
//  Copyright © 2017年 carmzhu. All rights reserved.
//

#ifndef CloudGeneralizeResult_h
#define CloudGeneralizeResult_h

#import "JSONDecoder.h"
#import "CloudGeneralizeDetails.h"

@interface CloudgeneralizeResult : NSObject<JSONJoy>
@property(nonatomic, readonly) NSString* result_code;
@property(nonatomic, readonly) NSArray<CloudGeneralizeDetails*>* results;
-(instancetype)init:(JSONDecoder*)decoder;
@end

#endif /* CloudGeneralizeResult_h */
