uniform sampler2D tex;
uniform vec2 resolution;
uniform float threshold;

void main()
{
    vec2 position = { gl_FragCoord.x / resolution.x, gl_FragCoord.y / resolution.y };
    vec4 color = texture2D(tex, position);
    // float average = (color[0] + color[1] + color[2]) / 3;

    if (!(color[0] >= threshold || color[1] >= threshold || color[2] >= threshold)) {
        color[0] = 0;
        color[1] = 0;
        color[2] = 0;
        color[3] = 0;
    }

    gl_FragColor = color;
}