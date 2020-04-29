//
//  Session.h
//  tarengine
//
//  Created by carmzhu on 2018/4/19.
//  Copyright © 2018年 carmzhu. All rights reserved.
//

#ifndef Session_h
#define Session_h

@protocol SessionDelegate<NSObject>
@required
-(void)onStarted;
@required
-(void)onUpdate;
@optional
-(void)onPaused;
@optional
-(void)onReset;
@end

@interface Session : NSObject
@property(nonatomic,readwrite) id<SessionDelegate> delegate;
-(instancetype)initWithConfig:(id)config;
-(void)configure;
-(void)resume;
-(void)pause;
-(void)reset;
-(void)releaseSession;
-(id)update;
-(id)getSessionHelper;
-(id)getCloudHelper;
@end

#endif /* Session_h */
