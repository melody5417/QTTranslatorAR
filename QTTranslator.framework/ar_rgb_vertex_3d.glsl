attribute vec3 position;
attribute vec2 texcoord;

uniform mat4 u_Matrix;

varying vec2 v_texcoord;

void main()
{
    gl_Position = u_Matrix * vec4(position.xy, 0.0, 1.0);
    gl_Position.z = -1.0;
    v_texcoord = texcoord;
}
