//
//  Shader.fsh
//
//  Created by  on 11/8/15.
//  Copyright © 2015 Hanton. All rights reserved.
//

precision mediump float;

uniform sampler2D SamplerY;
uniform sampler2D SamplerUV;

varying mediump vec2 v_textureCoordinate;

uniform mat3 colorConversionMatrix;

void main() {
    mediump vec3 yuv;
    lowp vec3 rgb;
    
    yuv.x = texture2D(SamplerY, v_textureCoordinate).r - (16.0/255.0);
    yuv.yz = texture2D(SamplerUV, v_textureCoordinate).rg - vec2(0.5, 0.5);
    
    rgb = colorConversionMatrix * yuv;
    
    gl_FragColor = vec4(rgb, 1);
}
/*varying lowp vec2 varyTextCoord;
varying lowp vec3 varyClearColor;
uniform sampler2D colorMap;
void main()
{
    gl_FragColor = texture2D(colorMap, varyTextCoord);
    if(varyClearColor.x >= 0.0){
        if(abs(gl_FragColor.x - varyClearColor.x) < 0.1 && abs(gl_FragColor.y - varyClearColor.y) < 0.1 && abs(gl_FragColor.z - varyClearColor.z) < 0.1){
            gl_FragColor.a = 0.0;
        }else{
            gl_FragColor.a = 1.0;
        }
    }
}*/
