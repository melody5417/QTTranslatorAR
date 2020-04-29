//
//  FaceSessionHelper.h
//  tarengine
//
//  Created by carmzhu on 2018/4/20.
//  Copyright © 2018年 carmzhu. All rights reserved.
//

#ifndef FaceSessionHelper_h
#define FaceSessionHelper_h
#import "SessionHelper.h"
@interface FaceSessionHelper : SessionHelper
-(instancetype)initWithPlugin:(id)plugin;
-(void)setFaceMin:(float)min;
-(void)setThreadNum:(int)num;
-(NSArray*)detectFace:(int)width height:(int)height format:(int)format data:(Byte*)data byteLen:(int)byteLen;
@end

#endif /* FaceSessionHelper_h */
