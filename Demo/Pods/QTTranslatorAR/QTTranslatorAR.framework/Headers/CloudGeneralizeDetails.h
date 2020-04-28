//
//  CloudGeneralizeDetails.h
//  tar
//
//  Created by carmzhu on 2017/12/25.
//  Copyright © 2017年 carmzhu. All rights reserved.
//

#ifndef CloudGeneralizeDetails_h
#define CloudGeneralizeDetails_h

#import "JSONDecoder.h"
#import "CloudLocationCorner.h"

@interface CloudGeneralizeDetails : NSObject<JSONJoy>
@property(nonatomic,readonly) NSString* sInferenceLabel;
@property(nonatomic,readonly) NSString* vImage;
@property(nonatomic,readonly) int lInferenceNo;
@property(nonatomic,readonly) CloudLocationCorner* stBox;
-(instancetype)init:(JSONDecoder*)decoder;
@end

#endif /* CloudGeneralizeDetails_h */
