//
//  Shader.vsh
//
//  Created by  on 11/8/15.
//  Copyright © 2015 Hanton. All rights reserved.
//

attribute vec4 position;
attribute vec2 textCoordinate;

varying vec2 v_textureCoordinate;

uniform mat4 modelViewProjectionMatrix;

void main() {
    v_textureCoordinate = textCoordinate.xy ;
    gl_Position = modelViewProjectionMatrix * position;
    //float x = gl_Position.x;
    //float y = gl_Position.y;
    //gl_Position.y = -x;
    //gl_Position.x = y;
}
/*attribute vec2 position;
attribute vec2 textCoordinate;
varying lowp vec3 varyClearColor;
varying lowp vec2 varyTextCoord;
uniform vec3 uClearColor;
uniform mat4 uMVPMatrix;

void main()
{
    varyTextCoord = textCoordinate;
    gl_Position =  uMVPMatrix * vec4(position.xy, 0.0, 1.0);
    //gl_Position =  vec4(position.xy, 0.0, 1.0);
    // gl_Position.z = 1.0;
    //    ferris:3-dimention should chang x-y
    float x = gl_Position.x;
    float y = gl_Position.y;
    gl_Position.y = -x;
    gl_Position.x = y;
    varyClearColor = uClearColor;
}*/
