//
//  FaceRecognition.h
//  tarengine
//
//  Created by carmzhu on 2018/4/20.
//  Copyright © 2018年 carmzhu. All rights reserved.
//

#ifndef FaceRecognition_h
#define FaceRecognition_h

#import "ARRecognition.h"

@interface FaceRecognition : ARRecognition
@property(nonatomic,readwrite) float* rect;
@property(nonatomic,readwrite) float score;
@property(nonatomic,readwrite) float* landMarks;
@property(nonatomic,readwrite) float* angles;
@end

#endif /* FaceRecognition_h */
