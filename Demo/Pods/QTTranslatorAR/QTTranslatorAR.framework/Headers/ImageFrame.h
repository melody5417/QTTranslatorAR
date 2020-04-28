//
//  ImageFrame.h
//  tarengine
//
//  Created by carmzhu on 2018/4/18.
//  Copyright © 2018年 carmzhu. All rights reserved.
//

#ifndef ImageFrame_h
#define ImageFrame_h
#import <AVFoundation/AVFoundation.h>

#define IMAGE_FORMAT_RGB 0
#define IMAGE_FORMAT_BGR 1
#define IMAGE_FORMAT_GRAY 2
#define IMAGE_FORMAT_NV21 3
#define IMAGE_FORMAT_YV12 4
#define IMAGE_FORMAT_BGRA 5

@interface ImageFrame : NSObject
@property (nonatomic, readwrite) CVPixelBufferRef data;
@property (nonatomic, readwrite) int width;
@property (nonatomic, readwrite) int height;
@property (nonatomic, assign) float brightness;
@property (nonatomic, readwrite) long frameId;
@property (nonatomic, readwrite) unsigned long long callbackTimestamp;
@end

#endif /* ImageFrame_h */
