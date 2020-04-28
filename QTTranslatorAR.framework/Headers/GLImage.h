//
//  GLRender
//  sdkDemo
//
//  Created by kyzhan－mac on 2017/11/6.
//  Copyright © 2017年 kyzhan－mac. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GLImageTexture.h"
#import "GLUtil.h"

@interface GLImage : NSObject
@property (nonatomic, assign) GLuint program;
@property (nonatomic, assign) GLuint vertexVBO;
@property (nonatomic, assign) int vertCount;
@property (nonatomic, readonly) int width;
@property (nonatomic, readonly) int height;
- (void)setTexture:(GLImageTexture *)texture;
- (void)update: (id)image format:(int)format;
- (void)glDraw:(bool)isLandscape;
- (instancetype) initWithSize:(int)width height:(int)height;
@end

@interface GLImageRGB : GLImage
@property(nonatomic, assign, readonly) GLuint rgb;
@end

@interface GLImageYUV : GLImage
@property(nonatomic, assign, readonly) GLuint y;
@property(nonatomic, assign, readonly) GLuint u;
@property(nonatomic, assign, readonly) GLuint v;
@end
