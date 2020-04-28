attribute vec3 position;
attribute vec3 color;
attribute vec2 texcoord;
uniform mat4 u_Matrix;

varying vec2 v_texcoord;

void main()
{
    const float degree = radians(-90.0);
   
    const mat3 rotate = mat3(
        cos(degree), sin(degree), 0.0,
        -sin(degree), cos(degree), 0.0,
        0.0, 0.0, 1.0
    );
    
    gl_Position = u_Matrix * vec4(position, 1.0);
    v_texcoord = texcoord;
}
