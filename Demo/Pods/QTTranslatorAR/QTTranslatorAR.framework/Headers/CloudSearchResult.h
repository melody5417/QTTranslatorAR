//
//  CloudSearchResult.h
//  tar
//
//  Created by carmzhu on 2017/12/25.
//  Copyright © 2017年 carmzhu. All rights reserved.
//

#ifndef CloudSearchResult_h
#define CloudSearchResult_h

#import "JSONDecoder.h"
#import "CloudGeneralizeDetails.h"
#import "CloudSearchDetails.h"

@interface CloudSearchResult : NSObject<JSONJoy>
@property(nonatomic,readonly) NSString* result_code;
@property(nonatomic,readonly) NSArray<CloudSearchDetails*>* result;
-(instancetype)init:(JSONDecoder*)decoder;
@end

#endif /* CloudSearchResult_h */
