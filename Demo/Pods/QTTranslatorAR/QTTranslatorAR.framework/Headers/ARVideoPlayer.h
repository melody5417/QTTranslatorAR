//
//  VRDisplayer.h
//  tar
//
//  Created by carmzhu on 2017/12/25.
//  Copyright © 2017年 carmzhu. All rights reserved.
//

#ifndef VRDisplayer_h
#define VRDisplayer_h

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "VRGLKView.h"
@interface ARVideoPlayer : UIView<VRGLKViewDelegate>
-(instancetype)init:(CGRect)frame;
-(void)configureOutput;
-(void)playEnd;
-(void)update:(bool)visible projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix corners:(float*)corners;
//protocol 0  url
//protocol 1 file
-(void)setUrl:(int)protocol url:(NSString*)url;
-(void)pause;
-(void)resume;
-(void)releaseVideo;
-(BOOL)isPlaying;
@end

#endif /* VRDisplayer_h */
