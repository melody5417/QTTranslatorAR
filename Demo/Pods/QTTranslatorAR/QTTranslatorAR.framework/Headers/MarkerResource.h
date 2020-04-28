//
//  MarkerResource.h
//  tarengine
//
//  Created by carmzhu on 2018/4/19.
//  Copyright © 2018年 carmzhu. All rights reserved.
//

#ifndef MarkerResource_h
#define MarkerResource_h

typedef NS_ENUM(NSInteger, MarkerType) {
    MARKER_TYPE_NFT,
    MARKER_TYPE_CLOUD,
    MARKER_TYPE_STD,
    MARKER_TYPE_NONE
};

@interface MarkerResource : NSObject
@property(nonatomic,readwrite) int mid;
@property(nonatomic,readwrite) NSString* name;
@property(nonatomic,readwrite) NSString* dir;
@property(nonatomic,readwrite) int type;
@property(nonatomic,readwrite) NSData* jpegData;
@property(nonatomic,readwrite) int jpegLength;
@end

#endif /* MarkerResource_h */
