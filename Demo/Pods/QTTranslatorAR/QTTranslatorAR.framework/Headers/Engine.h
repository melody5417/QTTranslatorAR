//
//  TarEngine.h
//  tarengine
//
//  Created by carmzhu on 2018/4/23.
//  Copyright © 2018年 carmzhu. All rights reserved.
//

#ifndef TarEngine_h
#define TarEngine_h

#import <UIKit/UIKit.h>

@protocol TAREngineRenderDelegate<NSObject>
-(void)onDrawRect:(CGRect)rect frame:(id)frame projectionMatrix:(float*)projectionMatrix;
@end

@protocol TAREngineStatusDelegate<NSObject>
@optional
-(void)onStarted;
@optional
-(void)onPaused;
@end

@interface TAREngine : NSObject
@property(nonatomic,readonly) id markerHelper;
//@property(nonatomic,readonly) id faceHelper;
@property(nonatomic,readonly) id cloudHelper;
@property(nonatomic,readonly) id config;
@property(nonatomic,readwrite) BOOL useDefaultRender;
@property(nonatomic, weak, readwrite) id<TAREngineRenderDelegate> renderDelegate;
@property(nonatomic, weak, readwrite) id<TAREngineStatusDelegate> statusDelegate;
@property(nonatomic,readonly) id session;
-(instancetype)initWithController:(UIViewController*)controller;
-(void)configure;
-(void)resume;
-(void)pause;
//Should better call this when no needed
-(void)releaseTAR;
//when playing video, you should control the video status yourself
//And you should never put two markers in one sight or we will account trouble
-(void)setVideoUrl:(NSString*)url withMarker:(int)mid;
-(void)setVideoPath:(NSString*)path withMarker:(int)mid;
-(void)pauseVideo;
-(void)resumeVideo;

//set model
-(void)setUserDefineModel:(id)model;

//
- (id)getCurrentFrame;
@end


#endif /* TarEngine_h */
