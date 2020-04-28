//
//  Config.h
//  tarengine
//
//  Created by carmzhu on 2018/4/18.
//  Copyright © 2018年 carmzhu. All rights reserved.
//

#ifndef Config_h
#define Config_h

#import "ConfigConsts.h"

typedef NS_ENUM(NSInteger, ARType) {
    MARKER,
    FACE,
    LOCATION_2D,
    MARKERLESS_WITH_OBJECT_RECOGNITION
};

@interface Config : NSObject
@property(nonatomic,readwrite) int screenOrientation;
@property(nonatomic,readwrite) int frameWidth;
@property(nonatomic,readwrite) int frameHeight;
@property(nonatomic,readwrite) int inputImageFormat;
@property(nonatomic,readonly) int cameraFace;
@property(nonatomic,readonly) int maxMarkerNumber;
@property(nonatomic,readwrite) NSString* ntfConfigFilePath;
@property(nonatomic,readwrite) int cloudRequestType;
@property(nonatomic,readwrite) int cloudRequestIntervalMs;
@property(nonatomic,readwrite) int cloudRequestRetryIntervalMs;
@property(nonatomic,readwrite) int cloudDetectFeatureMinNum;
@property(nonatomic,readwrite) int cloudDetectMaxPointNum;
@property(nonatomic,readwrite) NSString* cloudAppId;
@property(nonatomic,readwrite) NSString* cloudAppKey;
@property(nonatomic,readwrite) NSString* cloudImageSetId;
@property(nonatomic,readwrite) NSString* cloudUrl;
@property(nonatomic,readwrite) NSString* cloudUserId;
@property(nonatomic,readwrite) NSString* faceConfFilePath;
@property(nonatomic,readwrite) OSType videoOutputFormat;

@property(nonatomic,readwrite) BOOL enableCamera;
@property(nonatomic,readwrite) BOOL needImu;
@property(nonatomic,readwrite) BOOL needImage;
@property(nonatomic,readwrite) BOOL enableDump;
@property(nonatomic,readwrite) BOOL enableRawDump;
@property(nonatomic,readwrite) BOOL enableExternalSource;
@property(nonatomic,readwrite) BOOL enableLogger;
@property(nonatomic,readwrite) BOOL enableCloud;
@property(nonatomic,readwrite) BOOL enableCloudMarker;
@property(nonatomic,readwrite) BOOL enableMotionDetect;
@property(nonatomic,readwrite) BOOL enableFeatureDetect;
@property(nonatomic,readwrite) BOOL enableCloudImageSaving;
@property(nonatomic,readonly) BOOL enablePermissionVerify;

-(void)enableMarker;
-(BOOL)markerEnabled;
-(void)enableMarkerless;
-(BOOL)markerlessEnabled;
-(void)enableFace;
-(BOOL)faceEnabled;
-(instancetype)init;
//-(void)enable:(int)code;
//-(void)disable:(int)code;
//-(BOOL)isEnabled:(int)code;
//-(void)setIntegerValue:(int)code;
//-(int)getIntegerValue:(int)code;
//-(void)setStringValue:(int)code;
//-(NSString*)getStringValue:(int)code;
@end


#endif /* Config_h */
