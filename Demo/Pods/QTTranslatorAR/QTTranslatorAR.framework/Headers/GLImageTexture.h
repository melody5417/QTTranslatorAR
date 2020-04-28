//
//  GLTexture
//  sdkDemo
//
//  Created by kyzhan－mac on 2017/11/6.
//  Copyright © 2017年 kyzhan－mac. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GLImageTexture : NSObject
@property (assign, nonatomic) int width;
@property (assign, nonatomic) int height;
@end

@interface GLImageTextureRGB : GLImageTexture
@property (nonatomic, assign) uint8_t *RGBA;
@end

@interface GLImageTextureYUV : GLImageTexture
@property (nonatomic, assign) uint8_t *Y;
@property (nonatomic, assign) uint8_t *U;
@property (nonatomic, assign) uint8_t *V;
@end
