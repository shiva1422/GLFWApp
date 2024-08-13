#version 330

//TODO improve this shader can simplify later
precision highp float;

in vec2 verts;

in vec2 textureCoords;

out vec2 textCoordsOut;

void main()
{
    gl_Position = vec4(verts, 0.0, 1.0);
    textCoordsOut = textureCoords;
}

