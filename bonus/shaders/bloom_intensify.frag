uniform sampler2D texture;
uniform vec2 resolution;

void main()
{
    vec2 position = { gl_FragCoord.x / resolution.x, gl_FragCoord.y / resolution.y };
    vec4 color = texture2D(texture, position);

    float avg = (color[0] + color[1] + color[2]) / 3;

    if (avg < 0.9 && (color[0] != color[1] && color[1] != color[2] && color[0] != color[2])) {
        color[0] += 0.4;
        color[1] += 0.4;
        color[2] += 0.4;
    }

    gl_FragColor = color;
}