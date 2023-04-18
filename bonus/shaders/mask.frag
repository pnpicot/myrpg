uniform sampler2D texture;
uniform sampler2D add_texture;

void main(void){
    vec4 tex_color = texture2D(texture, gl_TexCoord[0].xy);
    vec4 add_color = texture2D(add_texture, gl_TexCoord[0].xy);
    vec4 res = add_color;

    if (tex_color[0] == 0.0 && tex_color[1] == 0.0 && tex_color[2] == 0.0) {
        res[0] = 0.0;
        res[1] = 0.0;
        res[2] = 0.0;
        res[3] = 0.0;
    }

    gl_FragColor = res;
}