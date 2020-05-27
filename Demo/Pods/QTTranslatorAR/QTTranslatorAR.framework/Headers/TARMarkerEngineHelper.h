//
//  TARMarkerEngineHelper.h
//  tarengine
//
//  Created by carmzhu on 2018/4/23.
//  Copyright © 2018年 carmzhu. All rights reserved.
//

#ifndef TARMarkerEngineHelper_h
#define TARMarkerEngineHelper_h

#include "MarkerResource.h"
@protocol TAREngineMarkerDelegate<NSObject>
@optional
-(void)arFound:(int)mid;
@optional
-(void)arLost:(int)mid;
@optional
-(void)onMarkerAdded:(MarkerResource*)markerResource succeed:(BOOL)succeed;
@optional
-(void)onMarkerDeleted:(int)mid succeed:(BOOL)succeed;
@end

@interface TAREngineMarkerHelper:NSObject
@property(nonatomic, weak, readwrite) id<TAREngineMarkerDelegate> delegate;
-(instancetype)initWithEngine:(id)engine;
-(void)addMarker:(MarkerResource*)markerResource;
-(void)deleteMarker:(int)mid;
- (void)clearMarkers;
-(void)setMarkerStatus:(int)mid status:(BOOL)status;
-(void)updateVisibility:(NSMutableArray*)recognitions;
/*-(void)setVideoUrl:(NSString*)url;
-(void)setVideoPath:(NSString*)path;
-(void)pauseVideo;
-(void)resumeVideo;*/
@end


#endif /* TARMarkerEngineHelper_h */
