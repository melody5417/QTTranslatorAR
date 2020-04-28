//
//  ARRecognition.h
//  tarengine
//
//  Created by carmzhu on 2018/4/18.
//  Copyright © 2018年 carmzhu. All rights reserved.
//

#ifndef ARRecognition_h
#define ARRecognition_h

@interface ARRecognition : NSObject
@property(nonatomic,readonly) int mid;
@property(nonatomic,readonly) int type;
-(instancetype)init:(int)mid type:(int)type;
@end

#endif /* ARRecognition_h */
