#version 120  //告诉编译器我们的目标GLSL编译器版本是1.2

varying vec4 v_fragmentColor;
void main()
{
    gl_FragColor = v_fragmentColor;
}