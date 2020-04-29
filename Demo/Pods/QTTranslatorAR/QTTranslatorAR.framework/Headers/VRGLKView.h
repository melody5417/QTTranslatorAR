//
//  VRGLKView.h
//  tar
//
//  Created by carmzhu on 2017/12/25.
//  Copyright © 2017年 carmzhu. All rights reserved.
//

#ifndef VRGLKView_h
#define VRGLKView_h
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>
//#import "ARVideoPlayer.h"

@protocol VRGLKViewDelegate<NSObject>
-(CVPixelBufferRef)dataSource;
@end

@interface VRGLKView: GLKView<GLKViewDelegate>
@property(nonatomic,readwrite)id<VRGLKViewDelegate> glkDelegate;
-(void)show;
-(void)hide;
-(void)update:(bool)visible projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix corners:(float*)corners;
@end

#endif /* VRGLKView_h */
