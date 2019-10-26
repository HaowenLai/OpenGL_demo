#version 120  //告诉编译器我们的目标GLSL编译器版本是1.2

attribute vec4 a_position;
attribute vec4 a_color;
varying vec4 v_fragmentColor;

void main()
{
    gl_Position = a_position;

    float tmp = step(a_position.x, 0);
    float r = (1-tmp)*a_position.x;
    float b = -tmp*a_position.x;
    v_fragmentColor = vec4(r, a_position.y, b, 1.0);
}