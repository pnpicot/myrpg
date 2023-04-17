#version 330

uniform sampler2D tex;
uniform vec2 resolution;
uniform vec2 pos;
uniform float max_dist;

void main()
{
    vec2 position = { gl_FragCoord.x / resolution.x, gl_FragCoord.y / resolution.y };
    vec4 color = texture2D(tex, position);

    position.x *= resolution.x;
    position.y *= resolution.y;
    pos.y = resolution.y - pos.y;

    float dist = distance(pos, position);
    float factor = 1.0 - (((dist * 0.95) / max_dist) * 1.0);

    if (factor < 0) factor = 0;

    color[3] = factor;
    gl_FragColor = color;
}