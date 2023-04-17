#version 330

uniform sampler2D tex;
uniform vec2 resolution;

void main()
{
    vec2 position = { gl_FragCoord.x / resolution.x, gl_FragCoord.y / resolution.y };
    vec4 color = texture2D(tex, position);

    if (color[0] == 1.0) {
        color[0] = 0;
        color[2] = 0;
    }

    gl_FragColor = color;
}