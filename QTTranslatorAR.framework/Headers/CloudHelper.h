//
//  CloudHelper.h
//  tarengine
//
//  Created by carmzhu on 2018/4/19.
//  Copyright © 2018年 carmzhu. All rights reserved.
//

#ifndef CloudHelper_h
#define CloudHelper_h

@protocol CloudResultDelegate<NSObject>
@optional
-(void)onCloudSearchResult:(id)vMarker;
@optional
-(void)onMotionDetectionResult:(BOOL)isMotionStable points:(int*)points num:(int)num;
@end

@interface CloudHelper:NSObject
@property(nonatomic,readwrite) id<CloudResultDelegate> delegate;
-(instancetype)initWithCloudManager:(id)cloudManager;
-(void)resume;
-(void)pause;
@end

#endif /* CloudHelper_h */
