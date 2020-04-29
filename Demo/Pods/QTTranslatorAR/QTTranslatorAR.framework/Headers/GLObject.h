//
//  GLObject.h
//  sdkDemo
//
//  Created by kyzhan－mac on 2017/11/14.
//  Copyright © 2017年 kyzhan－mac. All rights reserved.
//

#ifndef GLObject_h
#define GLObject_h
#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>

@interface GLObject : NSObject
- (void)glDraw:(GLKMatrix4)projectMatrix viewM:(GLKMatrix4)cameraMatrix;
@end

#endif /* GLObject_h */
