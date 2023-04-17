uniform sampler2D tex;
uniform sampler2D add;
uniform vec2 resolution;

void main()
{
    vec2 position = { gl_FragCoord.x / resolution.x, gl_FragCoord.y / resolution.y };
    vec4 color = texture2D(tex, position);
    vec4 add_color = texture2D(add, position);

    color[0] *= add_color[0];
    color[1] *= add_color[1];
    color[2] *= add_color[2];

    gl_FragColor = color;
}