//
//  GLCube.h
//  sdkDemo
//
//  Created by kyzhan－mac on 2017/11/10.
//  Copyright © 2017年 kyzhan－mac. All rights reserved.
//

#ifndef GLCube_h
#define GLCube_h
#import <GLKit/GLKit.h>
#import "GLUtil.h"
#import "GLObject.h"

@interface GLCube : GLObject
@property (nonatomic, assign) GLuint program;
@property (nonatomic, assign) GLuint vertexVBO;
@property (strong, nonatomic) GLKTextureInfo *diffuseTexture;
@property (assign, nonatomic) GLKMatrix4 modelMatrix;

- (void)glDraw:(GLKMatrix4)projectMatrix viewM:(GLKMatrix4)cameraMatrix;

@end


#endif /* GLCube_h */
