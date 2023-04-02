uniform sampler2D tex;
uniform sampler2D tex2;
uniform vec2 resolution;
uniform float threshold;

void main()
{
    vec2 position = { gl_FragCoord.x / resolution.x, gl_FragCoord.y / resolution.y };
    vec4 color = texture2D(tex, position);
    vec4 color2 = texture2D(tex2, position);
    vec4 final = color * color2;
    float average = (final[0] + final[1] + final[2]) / 3;

    if (average < threshold) {
        final[0] = 0;
        final[1] = 0;
        final[2] = 0;
        final[3] = 0;
    }

    gl_FragColor = final;
}