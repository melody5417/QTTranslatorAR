//
//  MarkerRecognition.h
//  tarengine
//
//  Created by carmzhu on 2018/4/19.
//  Copyright © 2018年 carmzhu. All rights reserved.
//

#ifndef MarkerRecognition_h
#define MarkerRecognition_h
#import <GLKit/GLKit.h>
#import "ARRecognition.h"

@interface MarkerRecognition : ARRecognition
@property(nonatomic,readwrite) GLKMatrix4 modelViewMatrix;
@property(nonatomic,readwrite) float* corners;
@end

#endif /* MarkerRecognition_h */
