
attribute vec4 vPosition;
attribute vec4 vColor;
attribute float sPointSize;
varying vec4 _vColor;
void main() {
  _vColor = vColor;
  gl_Position = vec4(vPosition.xy, -0.99, 1.0);
  gl_PointSize = sPointSize;
}
