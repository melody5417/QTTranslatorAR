//
//  Frame.h
//  tarengine
//
//  Created by carmzhu on 2018/4/19.
//  Copyright © 2018年 carmzhu. All rights reserved.
//

#ifndef Frame_h
#define Frame_h

@interface Frame:NSObject
@property(nonatomic,readwrite) id image;
@property(nonatomic,readwrite) NSMutableArray* recognitions;
@property(nonatomic,readwrite) unsigned long long timestamp;
@end

#endif /* Frame_h */
