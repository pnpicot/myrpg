uniform sampler2D texture;
uniform vec2 resolution;

void main()
{
    vec2 position = { gl_FragCoord.x / resolution.x, gl_FragCoord.y / resolution.y };
    vec4 color = texture2D(texture, position);
    float bright = 0.1;

    float avg = (color[0] + color[1] + color[2]) / 3;

    if (avg < 0.7 && (color[0] != color[1] && color[1] != color[2] && color[0] != color[2])) {
        color[0] += bright;

        if (color[0] > 1.0) color[0] = 1.0;

        color[1] += bright;

        if (color[1] > 1.0) color[1] = 1.0;

        color[2] += bright;

        if (color[2] > 1.0) color[2] = 1.0;
    }

    gl_FragColor = color;
}